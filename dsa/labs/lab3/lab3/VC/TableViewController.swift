//
//  TableViewController.swift
//  lab3
//
//  Created by MacBook Air on 23.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit
import RealmSwift


class TableViewController: UITableViewController {
    
    var students: Results<Student>?

    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    override func viewWillAppear(_ animated: Bool) {
        students = ManagerDB.loadStudents()
        print("DEBUG: \(students![0].name)")
        self.tableView.reloadData()
    }
    
    // MARK: - Table view data source

 
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return students?.count ?? 0
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "TableCell", for: indexPath)
        
        let student = students![indexPath.row]
        
        cell.textLabel?.textColor = #colorLiteral(red: 1.0, green: 1.0, blue: 1.0, alpha: 1.0)
        cell.textLabel?.textAlignment = .center
        
        if ManagerDB.getSchemaVersion() < 1 {
            cell.textLabel?.text = student.fio
        } else {
            cell.textLabel?.text = "\(student.surname) \(student.name) \(student.lastname)"
        }
        
        
        return cell
    }
   
}
