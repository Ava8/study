//
//  ViewController.swift
//  lab1
//
//  Created by MacBook Air on 08.03.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit

class MainVC: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    func rundomizePic() -> String {
        let imgArr = ["view1", "view2", "view3", "view4", "view5"]
        return imgArr.randomElement()!
    }

}

extension MainVC: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 1000000
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        if let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "feedCell", for: indexPath) as? MainCVCell {
            cell.img.image = UIImage(named: rundomizePic())
            cell.text.text = (indexPath.item + 1).name
            
            if indexPath.item % 2 == 0 {
                cell.view.backgroundColor = #colorLiteral(red: 0.3333333433, green: 0.3333333433, blue: 0.3333333433, alpha: 0.7)
                cell.text.textColor = #colorLiteral(red: 1.0, green: 1.0, blue: 1.0, alpha: 1.0)
            } else {
                cell.view.backgroundColor = #colorLiteral(red: 0.9999960065, green: 1, blue: 1, alpha: 0.7)
                cell.text.textColor = #colorLiteral(red: 0.3333333433, green: 0.3333333433, blue: 0.3333333433, alpha: 1)
            }

            return cell
        }
        return UICollectionViewCell()
    }
}

extension MainVC: UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let size = collectionView.bounds.size
        let space: CGFloat = 10
        
        if UIDevice.current.orientation == .portrait {
        return CGSize(width: size.width/2 - space*2, height: size.width/2 - space*2)
        }
        return CGSize(width: size.height/2, height: size.height/2)
    }
}

extension Int {
    var name: String {
        let numberFormatter = NumberFormatter()
        numberFormatter.numberStyle = .spellOut
        numberFormatter.locale = Locale(identifier: "ru_RU")
        let name = numberFormatter.string(from: NSNumber(value: self))
        return name!
    }
}

// "en_US_POSIX"


