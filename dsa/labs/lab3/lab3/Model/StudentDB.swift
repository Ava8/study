//
//  StudentDB.swift
//  lab3
//
//  Created by MacBook Air on 23.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation
import RealmSwift

class Student: Object {
    @objc dynamic var id = UUID().uuidString
    @objc dynamic var fio = ""
    @objc dynamic var addTime = Date()
    
    @objc dynamic var surname = ""
    @objc dynamic var name = ""
    @objc dynamic var lastname = ""
    
    convenience init(fio: String) {
        self.init()
        self.fio = fio
    }
    
    convenience init(surname: String, name: String, lastname: String) {
        self.init()
        self.surname = surname
        self.name = name
        self.lastname = lastname
    }
    
    override static func primaryKey() -> String? {
        return "id"
    }
}
