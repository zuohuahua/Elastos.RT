//
//  MyRootViewController.swift
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/26.
//

import Foundation
import UIKit

class MyRootViewController : UIViewController {

    @IBOutlet weak var connectionLabel: UILabel!
    private let carrier = Carrier()

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
        }
    }
}

extension MyRootViewController : CarrierStateDelegate {
    func didRecieveCarrierStateChange() {
        DispatchQueue.main.async {
            self.updateView()
        }
    }
}
