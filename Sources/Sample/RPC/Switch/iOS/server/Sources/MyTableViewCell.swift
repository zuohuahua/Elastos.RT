//
//  MyTableViewCell.swift
//  SwitchServer
//
//  Created by Joel Liang on 2018/9/1.
//

import UIKit

class MyTableViewCell: UITableViewCell {

    @IBOutlet weak var friendUidLabel: UILabel!
    @IBOutlet weak var friendStatusLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
