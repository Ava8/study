//
//  ServiceManager.swift
//  lab2
//
//  Created by MacBook Air on 06.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON

class Service {
    let serviceURL = "https://raw.githubusercontent.com/wesleywerner/ancient-tech/02decf875616dd9692b31658d92e64a20d99f816"
    let dataURL = "/src/data/techs.ruleset.json"
    let imgURL = "/src/images/tech/"
    
    func getData(completion: @escaping([Data]) -> Void) {
        AF.request(serviceURL+dataURL).responseData { response in
            guard let data = response.value else {return}
            
            let json = JSON(data)
            let result = json.compactMap({Data(json: $0.1)})
            completion(result)
        }
    }
}
