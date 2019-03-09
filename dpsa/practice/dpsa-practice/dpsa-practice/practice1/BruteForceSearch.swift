//
//  BruteForceSearch.swift
//  ADS
//
//  Created by MacBook Air on 15.02.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

func bruteForceSearch<T: Comparable>(_ list: [T], searchElem: T) -> (resault: Bool, comparsionCount: Int) {
    var isFound = false
    var counter = 0
    
    for i in list.indices {
        if list[i] == searchElem {
            isFound = true
            break
        } else {
            counter += 1
        }
    }
    
//    for element in list where element == searchElem {
//        isFound = true
//    }
    
    return (isFound, counter)
}

// O(n)
