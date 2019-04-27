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
    @IBOutlet weak var errorLbl: UILabel!
    

    override func viewDidLoad() {
        super.viewDidLoad()
        
        newStudent.becomeFirstResponder()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        errorLbl.text = ""
    }
    
//    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
//        self.view.endEditing(true)
//    }

    @IBAction func addNewRecord(_ sender: Any) {
        if (newStudent.text?.components(separatedBy: " ").count)! >= 3 {
            if ManagerDB.getSchemaVersion() < 1 {
                ManagerDB.saveStudent(Student(fio: newStudent.text!))
            } else {
                let student = newStudent.text?.components(separatedBy: " ")
                ManagerDB.saveStudent(Student(surname: student![0], name: student![1], lastname: student![2]))
            }
            newStudent.text?.removeAll()
            
            dismiss(animated: true)
            newStudent.resignFirstResponder()
        } else {
            errorLbl.text = "you schould write full student fio!"
            newStudent.text?.removeAll()
            
            shake(label: errorLbl)
        }
    }
    
    func shake(label: UILabel, for duration: TimeInterval = 1, withTranslation translation: CGFloat = 10) {
        let propertyAnimator = UIViewPropertyAnimator(duration: duration, dampingRatio: 0.3) {
            label.transform = CGAffineTransform(translationX: translation, y: 0)
        }
        
        propertyAnimator.addAnimations({
            label.transform = CGAffineTransform(translationX: 0, y: 0)
        }, delayFactor: 0.2)
        
        propertyAnimator.startAnimation()
    }
}

