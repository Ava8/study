//
//  ViewController.swift
//  lab4
//
//  Created by MacBook Air on 16.05.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit
import UserNotifications

class ViewController: UIViewController {

    @IBOutlet weak var dateInput: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if dateIsSelected() {
            let date = UserDefaults.init(suiteName: "group.AksCompany.lab4")?.value(forKey: "selectedDate") as! Date
            let now = Date()
            if  now.day == date.day &&
                now.month == date.month &&
                now.hour == 9 &&
                now.minute == 0 &&
                now.second == 10 {
                UserDefaults.init(suiteName: "group.AksCompany.lab4")?.removeObject(forKey: "selectedDate")
                dateInput.reloadInputViews()
            } else {
                dateInput.setTitle(dateFormatter(date), for: .normal)
            }
        }
    }
    
    
    
    @IBAction func inputBegin(_ sender: Any) {
        let alert = UIAlertController(style: .actionSheet, title: "Select date")
        alert.addDatePicker(mode: .date, date: Date(), minimumDate: Date().tomorrow, maximumDate: nil) { date in
            
            self.dateInput.setTitle(self.dateFormatter(date), for: .normal)
            
            UserDefaults.init(suiteName: "group.AksCompany.lab4")?.set(date, forKey: "selectedDate")
            self.setReminder(to: date)
        }
        alert.addAction(title: "OK", style: .cancel)
        alert.show()
    }
    
    func setReminder(to date: Date) {
        let notification = UNUserNotificationCenter.current()
        
        let content = UNMutableNotificationContent()
        content.title = "Reminder"
        content.body = "Today"
        content.sound = .default
        
        var components = Calendar.current.dateComponents([.day, .month, .year], from: date)
        components.hour = 9
        components.minute = 0
        
        let trigger = UNCalendarNotificationTrigger(dateMatching: components, repeats: false)
        print("TRIGGER: \(trigger.nextTriggerDate()!)")
        
        let request = UNNotificationRequest(identifier: "reminder", content: content, trigger: trigger)
        
        notification.add(request) { (error) in
            print(error?.localizedDescription as Any)
        }
    }
    
    private func dateIsSelected() -> Bool {
        let dateDefaultStatus = UserDefaults.init(suiteName: "group.AksCompany.lab4")?.value(forKey: "selectedDate")
        return dateDefaultStatus != nil
    }
    
    private func dateFormatter(_ date: Date) -> String {
        let formatter = DateFormatter()
        formatter.dateStyle = .long
        formatter.dateFormat = "MMM dd, yyyy"
        return formatter.string(from: date)
    }
}


extension Date {
    var tomorrow:  Date { return Date().dayAfter }

    var dayAfter: Date {
        return Calendar.current.date(byAdding: .day, value: 1, to: noon)!
    }
    var noon: Date {
        return Calendar.current.date(bySettingHour: 12, minute: 0, second: 0, of: self)!
    }
}
