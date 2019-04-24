//
//  SearchElems.swift
//  dpsa-practice
//
//  Created by MacBook Air on 17.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

extension Array where Element: Comparable {
    
    mutating func findMin(count toFind: Int) -> [Element] {
        
        var result = [Element]()
        let array = self.sorted()
        
        result = Array(array[0...toFind-1])
        
        
        return result
    }
}
