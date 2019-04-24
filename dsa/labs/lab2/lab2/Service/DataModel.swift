//
//  DataModel.swift
//  lab2
//
//  Created by MacBook Air on 06.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation
import SwiftyJSON

class Data {
    var graphic = ""
    var name = ""
    
    let imgURL = "https://raw.githubusercontent.com/wesleywerner/ancient-tech/02decf875616dd9692b31658d92e64a20d99f816/src/images/tech/"
    
    init(json: JSON) {
        graphic = imgURL+json["graphic"].stringValue
        name = json["name"].stringValue
    }
}
