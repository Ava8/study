//
//  ManagerDB.swift
//  lab3
//
//  Created by MacBook Air on 23.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation
import RealmSwift

class ManagerDB {
    
    class func getSchemaVersion() -> UInt64 {
        do {
            let realm = try Realm()
            return realm.configuration.schemaVersion
        } catch {
            print(error)
            return 404
        }
    }
    
    class func saveStudent(_ student: Student) {
        do {
            let realm = try Realm()
            
            try realm.write {
                realm.add(student)
            }
        } catch {
            print(error)
        }
    }
    
    class func loadStudents() -> Results<Student>? {
        do {
            let realm = try Realm()
            let students = realm.objects(Student.self)
            return students
        } catch {
            print(error)
            return nil
        }
    }
    
    class func clear() {
        do {
            let realm = try Realm()
            let students = realm.objects(Student.self)
            
            realm.beginWrite()
            realm.delete(students)
            try realm.commitWrite()
            
        } catch {
            print(error)
        }
    }
    
    class func updateLast() {
        do {
            let realm = try Realm()
            let students = realm.objects(Student.self)
            
            if realm.configuration.schemaVersion < 1 {
                if let lastStudent = students.last {
                    try realm.write {
                        lastStudent.fio = "Ivanov Ivan Ivanovich"
                    }
                }
            } else {
                if let lastStudent = students.last {
                    try realm.write {
                        lastStudent.surname = "Ivanov"
                        lastStudent.name = "Ivan"
                        lastStudent.lastname = "Ivanovich"
                    }
                }
            }
            
        } catch {
            print("error")
        }
    }
    
    class func upgradeDB() {
        Realm.Configuration.defaultConfiguration = Realm.Configuration(
            schemaVersion: 1,
            migrationBlock: { migration, oldSchemaVersion in
                if (oldSchemaVersion < 1) {
                    
                    migration.enumerateObjects(ofType: Student.className()) { oldObject, newObject in

                        let fio = oldObject!["fio"] as! String
                        let splitFIO = fio.components(separatedBy: [" "])
                        
                        let surname = splitFIO[0] as String
                        let name = splitFIO[1] as String
                        let lastname = splitFIO[2] as String
                        
                        newObject!["surname"] = surname
                        newObject!["name"] = name
                        newObject!["lastname"] = lastname
                    }
                }
        })
        
    }
    
}
