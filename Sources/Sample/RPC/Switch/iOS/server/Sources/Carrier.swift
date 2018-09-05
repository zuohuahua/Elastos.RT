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
    func didRecieveFriendConnectionChange(_ uid: String, _ online: Bool)
    func didRecieveFriendRequest(_ uid: String, _ hello: String)
}

class Carrier: NSObject {
    weak var delegate: CarrierStateDelegate?

    private var cReady: DarwinBoolean = false

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

    var friends: [Friend]? = nil

    func startService(withPath path: String) {

        // Void pointer to `self`:
        let mySelfRawPtr = bridge(self)

        cListener = createCarrierListener(mySelfRawPtr)
        registerCarrierListenerOnReady(
            cListener,
            { (selfRawPrt) -> ECode in
                // Extract pointer to `self` from void pointer:
                let mySelf = bridge(selfRawPrt!)
                mySelf?.cReady = true
                return 0
            })
        registerCarrierListenerOnConnectionChanged(
            cListener,
            { (selfRawPrt, online) -> ECode in
                // Extract pointer to `self` from void pointer:
                let mySelf = bridge(selfRawPrt!)
                // Call instance method:
                return mySelf!.OnConnectionChanged(online)
            })
        registerCarrierListenerOnFriendConnectionChanged(
            cListener,
            { (selfRawPrt, uid, online) -> ECode in
                // Extract pointer to `self` from void pointer:
                let mySelf = bridge(selfRawPrt!)
                // Call instance method:
                return mySelf!.OnFriendConnectionChanged(uid, online)
        })
        registerCarrierListenerOnFriendRequest(
            cListener,
            { (selfRawPrt, uid, hello) -> ECode in
                // Extract pointer to `self` from void pointer:
                let mySelf = bridge(selfRawPrt!)
                // Call instance method:
                return mySelf!.OnFriendRequest(uid, hello)
        })

        cCarrier = startCarrier(
            path.cString(using: String.Encoding.utf8),
            cListener);
    }

    func AccpetFriendRequest(_ uid: String) -> Void {
        carrierAccpetFriendRequest(cCarrier, uid.cString(using: .utf8))
    }

    func updateFriendList() {
        var length: Int32 = 0
        var cFriends: UnsafeMutablePointer<OpaquePointer?>?
        var friendsArray: [Friend] = []
        if self.cReady.boolValue {
            carrierGetFriends(cCarrier, &cFriends, &length)
            for i in 0..<length {
                let cFriend = cFriends?[Int(i)]

                var cUid: UnsafePointer<CChar>? = nil
                friendGetUid(cFriend, &cUid)

                var cOnline: DarwinBoolean = false
                friendIsOnline(cFriend, &cOnline)

                friendsArray.append(Friend(cFriend, cUid, cOnline))
            }
        }
        friends = friendsArray
    }

    func OnConnectionChanged(_ online: DarwinBoolean) -> ECode {
        self.cOnline = online
        delegate?.didRecieveCarrierStateChange()
        return 0
    }

    func OnFriendConnectionChanged(
        _ uid: UnsafePointer<CChar>?,
        _ online: DarwinBoolean) -> ECode {
        delegate?.didRecieveFriendConnectionChange(
            String.init(cString: uid!),
            online.boolValue)
        return 0
    }

    func OnFriendRequest(
        _ uid: UnsafePointer<CChar>?,
        _ hello: UnsafePointer<CChar>?) -> ECode {
        delegate?.didRecieveFriendRequest(
            String.init(cString: uid!),
            String.init(cString: hello!)
        )
        return 0
    }
}
