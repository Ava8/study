//
//  TodayViewController.swift
//  DaysBefore
//
//  Created by MacBook Air on 18.05.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit
import NotificationCenter

class TodayViewController: UIViewController, NCWidgetProviding {
        
    @IBOutlet weak var label: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view from its nib.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if let date = UserDefaults.init(suiteName: "group.AksCompany.lab4")?.value(forKey: "selectedDate") {
            let now = Date()
            let dateDiff = now.days(to: date as! Date)
            label.text = "days before selected date: \(dateDiff + 1)"
            
        } else {
            label.text = "date hasn't been selected"
        }
    }
        
    func widgetPerformUpdate(completionHandler: (@escaping (NCUpdateResult) -> Void)) {
        // Perform any setup necessary in order to update the view.
        
        // If an error is encountered, use NCUpdateResult.Failed
        // If there's no update required, use NCUpdateResult.NoData
        // If there's an update, use NCUpdateResult.NewData
        
        completionHandler(NCUpdateResult.newData)
    }
    
    
    
}

extension Date {
    func days(to selectedDate: Date) -> Int {
        let calendar = Calendar.current
        return calendar.dateComponents([.day], from: self, to: selectedDate).day!
    }
}
