//
//  main.swift
//  ADS
//
//  Created by MacBook Air on 15.02.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

// MARK: Task 1

let pl = ["swift", "java", "c++", "c#", "c"]

print("python search: \(bruteForceSearch(pl, searchElem: "python").resault)")
print("swift search: \(bruteForceSearch(pl, searchElem: "swift"))")

// MARK: Task 3

var a = [1,2,3,4,5]
print(bruteForceSearch(a, searchElem: 3))
print(barrierSearch(&a, searchElem: 3))

// MARK: Task 5

let array = [1,2,3,4,5,6,7,8,8,9,10]

print(binaryGoldenSearch(array, searchElem: 4))


// MARK: Task 2,4,6

func runningTime<T>(f: @autoclosure () -> T) -> (result:T, duration: String) {
    let startTime = CFAbsoluteTimeGetCurrent()
    let result = f()
    let endTime = CFAbsoluteTimeGetCurrent()
    return (result, "time \(endTime - startTime) second")
}

var oneHundredArray: [Int] = []
for _ in 0...99 {
    oneHundredArray.append(Int(arc4random_uniform(100)))
}

print("array:")
print(oneHundredArray)
print("elems: \(oneHundredArray.count)")

print("\n")

print("brute force search:")
print(runningTime(f: bruteForceSearch(oneHundredArray, searchElem: 88).resault))
print("barrier search:")
print(runningTime(f: barrierSearch(&oneHundredArray, searchElem: 88)))

print("\n")

oneHundredArray.removeLast()
oneHundredArray.sort()

print("sort array:")
print(oneHundredArray)
print("elems: \(oneHundredArray.count)")

print("\n")

print("binary search:")
print(runningTime(f: binarySearch(oneHundredArray, searchElem: 88)))


