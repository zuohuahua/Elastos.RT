//
//  MyRootViewController.swift
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/26.
//

import Foundation
import UIKit

let carrier = Carrier()

class MyRootViewController : UIViewController {

    @IBOutlet weak var connectionLabel: UILabel!
    var friendListsViewController: MyTableViewController?

    override func viewDidLoad() {
        super.viewDidLoad()
        if let documentsPathString = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true).first {

            carrier.startService(withPath: documentsPathString)

            updateView()
            carrier.delegate = self
        }
    }

    func updateView() -> Void {
        connectionLabel.text = carrier.online
            ? "Connected to p2p network!" : "Connecting..."
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "MyQRCodeIdentifier" {
            if let vc = segue.destination as? MyQRCodeViewController {
                vc.qrCodeString = carrier.myAddress
            }
        } else if segue.identifier == "friendListIdentifier" {
            friendListsViewController = segue.destination as? MyTableViewController
        }
    }
}

extension MyRootViewController : CarrierStateDelegate {

    func didRecieveCarrierStateChange() {
        carrier.updateFriendList()
        DispatchQueue.main.async {
            self.updateView()
            self.friendListsViewController?.tableView.reloadData()
        }
    }

    func didRecieveFriendConnectionChange(_ uid: String, _ online: Bool) {
        for friend in carrier.friends! {
            if friend.uid == uid {
                friend.online = online
                break
            }
        }
        DispatchQueue.main.async {
            self.friendListsViewController?.tableView.reloadData()
        }
    }

    func didRecieveFriendRequest(_ uid: String, _ hello: String) {
        DispatchQueue.main.async {
            // create the alert
            let alert = UIAlertController(title: "Add Friend Request", message: hello, preferredStyle: UIAlertControllerStyle.alert)

            // add the actions (buttons)
            alert.addAction(UIAlertAction(title: "Accept", style: UIAlertActionStyle.default, handler: { action in
                carrier.AccpetFriendRequest(uid)
            }))
            alert.addAction(UIAlertAction(title: "Cancel", style: UIAlertActionStyle.cancel, handler: nil))

            // show the alert
            self.present(alert, animated: true, completion: nil)
        }
    }
}
