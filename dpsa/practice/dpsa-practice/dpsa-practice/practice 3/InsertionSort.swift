//
//  InsertionSort.swift
//  dpsa-practice
//
//  Created by MacBook Air on 17.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

func insertionSort1<T:Comparable>(_ list: [T]) -> [T] {
    guard list.count > 1 else {return list}
    
    var sortList = [T]()
    
    for item in list {
        if sortList.isEmpty {
            sortList.append(item)
        } else {
            for index in 0...sortList.count-1 {
                if item < sortList[index] {
                    sortList.insert(item, at: index)
                    break
                }
            }
        }
    }
    
    return sortList
}

func insertionSort2<T:Comparable>(_ list: [T]) -> [T] {
    guard list.count > 1 else {return list}
    
    var sortList = [T]()
    
    for unsorted in list {
        if sortList.isEmpty {
            sortList.append(unsorted)
        } else {
            var insert = false
            for (index, sorted) in sortList.enumerated() {
                if unsorted < sorted {
                    sortList.insert(unsorted, at: index)
                    insert = true
                    break
                }
            }
            if !insert {
                sortList.append(unsorted)
            }
        }
    }
    
    return sortList
}

func insertionSort3<T:Comparable>(_ list: [T]) -> [T] {
    guard list.count > 1 else {return list}
    
    var sortList = list
    
    for i in 1 ..< list.count {
        var currentIndex = i
        
        // take a copy of the current item
        let itemToInsert = sortList[currentIndex]
        
         // keep going around until at the start of the array or find an item that's greater or equal
        while currentIndex > 0 && itemToInsert < sortList[currentIndex-1] {
            // move this item to the right
            sortList[currentIndex] = sortList[currentIndex-1]
            currentIndex -= 1
        }
        // place item into its newly sorted place
        sortList[currentIndex] = itemToInsert
    }
    
    return sortList
}


func binaryInsertionSort<T:Comparable>(_ list: [T]) -> [T] {
    guard list.count > 1 else {return list}
    
    var sortList = list
    
    for i in 1 ..< list.count {
        var (left, right, itemToInsert) = (0, i-1, sortList[i])
        
        while left <= right {
            let middle = (left+right)/2
            
            if itemToInsert < sortList[middle] {
                right = middle - 1
            } else {
                left = middle + 1
            }
        }
        
        for j in stride(from: i-1, through: left, by: -1) {
            sortList[j+1] = sortList[j]
        }
        sortList[left] = itemToInsert
    }
    
    return sortList
}
