//
//  CarrierListener.swift
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/27.
//

import Foundation

func bridge(_ obj : CarrierState) -> UnsafeRawPointer {
    return UnsafeRawPointer(Unmanaged.passUnretained(obj).toOpaque())
}

func bridge(_ ptr : UnsafeRawPointer) -> CarrierState? {
    return Unmanaged.fromOpaque(ptr).takeUnretainedValue()
}

protocol CarrierStateDelegate: class {
    func didRecieveCarrierStateChange()
}

class CarrierState: NSObject {
    var cListener: OpaquePointer!
    weak var delegate: CarrierStateDelegate?
    var online: DarwinBoolean = false

    override init() {
        super.init()

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
    }

    func OnConnectionChanged(_ online: DarwinBoolean) -> ECode {
        self.online = online
        delegate?.didRecieveCarrierStateChange()
        return 0
    }
}
