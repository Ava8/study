//
//  DetailController.swift
//  lab2
//
//  Created by MacBook Air on 07.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import UIKit

class DetailController: UIViewController {

    @IBOutlet weak var collectionView: UICollectionView!
    let indexPath = IndexPath(row: i, section: 0)
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(true)
        self.collectionView.scrollToItem(at: indexPath, at: .centeredHorizontally, animated: true)
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        self.collectionView.collectionViewLayout.invalidateLayout()
        self.collectionView.layoutIfNeeded()
    }
    

    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        coordinator.animate(alongsideTransition: nil, completion: {
            _ in
            
            self.collectionView.scrollToItem(at: self.indexPath, at: .centeredHorizontally, animated: true)
        })
    }
    
}

extension DetailController: UICollectionViewDelegate, UICollectionViewDataSource {
        
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return data.count-1
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "DetailCell",for: indexPath) as! CollectionViewCell
        
        let response = Array(data.dropFirst())[indexPath.row]
        
        cell.txt.text = response.name
        cell.img.kf.indicatorType = .activity
        cell.img.kf.setImage(with: URL(string: response.graphic), placeholder: #imageLiteral(resourceName: "placeholder"))
        return cell
    }
    
    
}

extension DetailController: UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let size = collectionView.bounds.size
        let space: CGFloat = 10
        
        
        switch UIDevice.current.orientation.isLandscape {
        case true:
            return CGSize(width: size.width-space*2, height: 300)
        default:
            return CGSize(width: size.width-space*2, height: size.height*0.8)
        }
    }
}
