//
//  main.swift
//  dpsa-practice
//
//  Created by MacBook Air on 28.03.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

func runningTime<T>(f: @autoclosure () -> T) -> (result:T, duration: String) {
    let startTime = CFAbsoluteTimeGetCurrent()
    let result = f()
    let endTime = CFAbsoluteTimeGetCurrent()
    return (result, "time \(endTime - startTime) second")
}

print("write a text:")
var text = readLine()
print("\n")

print("write a pattern:")
var pattern = readLine()
print("\n")

print(runningTime(f: text?.matchWithBF(forPattern: &pattern!, caseInsensitive: true)))
print(runningTime(f: text?.matchWithKMP(forPattern: &pattern!, caseInsensitive: true)))
print(runningTime(f: text?.matchWithBM(forPattern: &pattern!, caseInsensitive: true)))
//print(runningTime(f: text?.contains(pattern!)))
//print(runningTime(f: text?.searchRK(forPattern: pattern!)))
