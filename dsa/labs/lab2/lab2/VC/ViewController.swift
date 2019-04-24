//
//  ViewController.swift
//  lab2
//
//  Created by MacBook Air on 06.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON
import Kingfisher


var data = [Data]()
var i = 0

struct Connectivity {
    private static let sharedInstance = NetworkReachabilityManager()!
    static var isConnectedToInternet:Bool {
        return self.sharedInstance.isReachable
    }
}

class ViewController: UIViewController {

    let manager = Service()
    var refreshControl: UIRefreshControl?

    @IBOutlet weak var tableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        manager.getData(){ [weak self] response in
            data = response
            self?.tableView.reloadData()
        }
        addRefreshControl()
    }
    
    func addRefreshControl() {
        refreshControl = UIRefreshControl()
        refreshControl?.tintColor = #colorLiteral(red: 0.521568656, green: 0.1098039225, blue: 0.05098039284, alpha: 1)
        refreshControl?.addTarget(self, action: #selector(refresh), for: .valueChanged)
        tableView.addSubview(refreshControl!)
    }
    
    @objc func refresh() {
        manager.getData(){ [weak self] response in
            data = response
            self?.tableView.reloadData()
        }
        refreshControl?.endRefreshing()
        tableView.reloadData()
    }
}

extension ViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if Connectivity.isConnectedToInternet {
            return data.count-1
        } else {
            return 1
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if Connectivity.isConnectedToInternet{
            let cell = tableView.dequeueReusableCell(withIdentifier: "TableCell",for: indexPath) as! TableViewCell
            
            let response = Array(data.dropFirst())[indexPath.row]
            
            cell.txt.text = response.name
            cell.img.kf.indicatorType = .activity
            cell.img.kf.setImage(with: URL(string: response.graphic), placeholder: #imageLiteral(resourceName: "placeholder"))
            return cell
        } else {
            let cell = UITableViewCell()
            cell.textLabel?.textAlignment = .center
            cell.textLabel?.text = "no connection, try to reload"
            return cell
        }
    }
    
    func tableView(_ tableView: UITableView, didEndDisplaying cell: UITableViewCell, forRowAt indexPath: IndexPath) {
        let cell = tableView.dequeueReusableCell(withIdentifier: "TableCell",for: indexPath) as! TableViewCell
        cell.img.kf.cancelDownloadTask()
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if Connectivity.isConnectedToInternet {
            i = indexPath.row
            performSegue(withIdentifier: "segue", sender: self)
        }
    }
    
}
