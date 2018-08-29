//
//  MyQRCodeViewController.swift
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/20.
//

import Foundation
import UIKit

class MyQRCodeViewController : UIViewController {
    @IBOutlet weak var qrcodeImageView: UIImageView!
    @IBOutlet weak var qrcodeLabel: UILabel!

    @IBAction func copyToClipboard(_ sender: Any) {
        UIPasteboard.general.string = qrCodeString
    }

    var qrCodeString: String!

    func generateQRCode(from string: String, with size:CGSize) -> UIImage? {

        let data = string.data(using: String.Encoding.isoLatin1)

        if let filter = CIFilter(name: "CIQRCodeGenerator") {
            filter.setValue(data, forKey: "inputMessage")
            filter.setValue("Q", forKey: "inputCorrectionLevel")
            let qrcodeImage = filter.outputImage
            let ouputImageSize = qrcodeImage!.extent.size
            let transform = CGAffineTransform(scaleX: size.width / ouputImageSize.width,
                                                   y: size.height / ouputImageSize.height)

            if let output = qrcodeImage?.applying(transform) {
                return UIImage(ciImage: output)
            }
        }

        return nil
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        let image = generateQRCode(from: qrCodeString, with: qrcodeImageView.frame.size)
        qrcodeImageView.image = image
        qrcodeLabel.text = qrCodeString
    }
}
