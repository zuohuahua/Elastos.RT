//
//  Friend.swift
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/30.
//

import Foundation

class Friend: NSObject {
    var cFriend: OpaquePointer!

    public private(set) var uid: String?
    var online: Bool

    init(_ cFriend: OpaquePointer?,
         _ cUid: UnsafePointer<CChar>?,
         _ cOnline: DarwinBoolean) {
        self.cFriend = cFriend
        self.uid = (cUid != nil) ? String.init(cString: cUid!) : nil
        self.online = cOnline.boolValue
    }
}
