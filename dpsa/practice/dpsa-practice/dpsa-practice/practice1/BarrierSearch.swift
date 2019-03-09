//
//  BarrierSearch.swift
//  ADS
//
//  Created by MacBook Air on 15.02.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

func barrierSearch<T: Comparable>(_ list: inout [T], searchElem: T) -> (resault: Bool, comparsionCount: Int) {
    var isFound = false
    var counter = 0
    
    if list[list.count-1] != searchElem {
        list.append(searchElem)
        
        var i = 0
        while list[i] != searchElem {
            i += 1
            counter += 1
        }
        if i != list.count-1 {
            isFound = true
        }
    } else {
        isFound = true
        counter = 1
    }
    
    return (isFound, counter)
}

// O(n)
