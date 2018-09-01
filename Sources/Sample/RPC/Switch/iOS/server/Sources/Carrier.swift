//
//  CarrierListener.swift
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/27.
//

import Foundation

func bridge(_ obj : Carrier) -> UnsafeRawPointer {
    return UnsafeRawPointer(Unmanaged.passUnretained(obj).toOpaque())
}

func bridge(_ ptr : UnsafeRawPointer) -> Carrier? {
    return Unmanaged.fromOpaque(ptr).takeUnretainedValue()
}

protocol CarrierStateDelegate: class {
    func didRecieveCarrierStateChange()
}

class Carrier: NSObject {
    weak var delegate: CarrierStateDelegate?

    private var cOnline: DarwinBoolean = false
    public var online: Bool {
        carrierIsOnline(cCarrier, &cOnline)
        return cOnline.boolValue
    }

    private var cMyAddress: UnsafePointer<CChar>? = nil
    public var myAddress: String? {
        carrierGetAddress(cCarrier, &cMyAddress)
        return (cMyAddress != nil) ? String.init(cString: cMyAddress!) : nil
    }

    private var cListener: OpaquePointer!
    private var cCarrier: OpaquePointer!

    func startService(withPath path: String) {

        // Void pointer to `self`:
        let mySelfRawPtr = bridge(self)

        cListener = createCarrierListener(mySelfRawPtr)
        registerCarrierListenerOnConnectionChanged(
            cListener,
            { (selfRawPrt, online) -> ECode in
                // Extract pointer to `self` from void pointer:
                let mySelf = bridge(selfRawPrt!)
                // Call instance method:
                return mySelf!.OnConnectionChanged(online)
            })
        cCarrier = startCarrier(
            path.cString(using: String.Encoding.utf8),
            cListener);
    }

    func OnConnectionChanged(_ online: DarwinBoolean) -> ECode {
        self.cOnline = online
        delegate?.didRecieveCarrierStateChange()
        return 0
    }
}
