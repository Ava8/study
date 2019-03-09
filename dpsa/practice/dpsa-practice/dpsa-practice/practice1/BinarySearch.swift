//
//  BinarySearch.swift
//  algorithms
//
//  Created by MacBook Air on 20.07.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

import Foundation

func binarySearch<T: Comparable>(_ list: [T], searchElem: T) -> Bool {
    var topIndex = list.count - 1
    var bottomIndex = 0
    
    var isFound = false
    
    while bottomIndex <= topIndex {
        let currentIndex = bottomIndex + (topIndex - bottomIndex)/2
        if list[currentIndex] == searchElem {
            isFound = true
            break
        } else if list[currentIndex] < searchElem {
            bottomIndex = currentIndex + 1
        } else {
            topIndex = currentIndex - 1
        }
    }
    
    return isFound
}

//O(logn)

func binaryGoldenSearch<T: Comparable>(_ list: [T], searchElem: T) -> Bool {
    var topIndex = list.count - 1
    var bottomIndex = 0
    let goldenRatio = Int((1 + sqrt(5))/2)
    
    var isFound = false
    
    while bottomIndex <= topIndex {
        let currentIndex = bottomIndex + (topIndex-bottomIndex)/goldenRatio
        if list[currentIndex] == searchElem {
            isFound = true
            break
        } else if list[currentIndex] < searchElem {
            bottomIndex = currentIndex + 1
        } else {
            topIndex = currentIndex - 1
        }
    }
    
    return isFound
}
