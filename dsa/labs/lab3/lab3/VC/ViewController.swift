//
//  ViewController.swift
//  lab3
//
//  Created by MacBook Air on 23.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var updateDB: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if ManagerDB.getSchemaVersion() > 0 {
            updateDB.isEnabled = false
            updateDB.backgroundColor = #colorLiteral(red: 0.9098039269, green: 0.4784313738, blue: 0.6431372762, alpha: 1)
        }
        generateStudentsList()
    }

    func generateStudentsList() {
        let fios = ["Mamaeva Arina Borisovna","Nikiforova Maria Andreevna", "Ignatenko Artem Yakovlevich", "Medvedev Vadim Artemovich", "Vinter Ruslan Romanovich", "Lavrentyava Irina Andreevna", "Pavlov Pavel Alexsandrovich", "Medyanik Alexandr Olegovich", "Kuznetsov Michail Vadimovich"]
        ManagerDB.clear()
        for _ in 0 ..< 5 {
            if ManagerDB.getSchemaVersion() == 0 {
                ManagerDB.saveStudent(Student(fio: fios.randomElement()!))
            } else {
                let student = fios.randomElement()?.components(separatedBy: " ")
                ManagerDB.saveStudent(Student(surname: student![0], name: student![1], lastname: student![2]))
            }
        }
        
    }
    
    @IBAction func changeLastRecord(_ sender: Any) {
        ManagerDB.updateLast()
    }
    @IBAction func updateDB(_ sender: Any) {
        updateDB.isEnabled = false
        updateDB.backgroundColor = #colorLiteral(red: 0.9098039269, green: 0.4784313738, blue: 0.6431372762, alpha: 1)
        ManagerDB.upgradeDB()
    }
    
}

