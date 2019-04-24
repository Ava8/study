//
//  AddNewRecordVC.swift
//  lab3
//
//  Created by MacBook Air on 23.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit

class AddNewRecordVC: UIViewController {
    
    @IBOutlet weak var newStudent: UITextField!
    

    override func viewDidLoad() {
        super.viewDidLoad()
        
        newStudent.becomeFirstResponder()
    }

    @IBAction func addNewRecord(_ sender: Any) {
        if ManagerDB.getSchemaVersion() == 0 {
            ManagerDB.saveStudent(Student(fio: newStudent.text!))
        } else {
            let student = newStudent.text?.components(separatedBy: " ")
            ManagerDB.saveStudent(Student(surname: student![0], name: student![1], lastname: student![2]))
        }
        newStudent.text?.removeAll()
        
        dismiss(animated: true)
        newStudent.resignFirstResponder()
    }
}
