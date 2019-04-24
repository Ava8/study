//
//  main.swift
//  dpsa-practice
//
//  Created by MacBook Air on 17.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

var list1 = [1,9,4,5,1,0]
var list2 = [9,3,-7,0,3]
var list3 = [1,-2,3,-4,5,6,7,-8,9,10]
var list4 = [10,9,8,7,6,5,4,3,2,1]

func runningTime<T>(f: @autoclosure () -> T) -> (result:T, duration: String) {
    let startTime = CFAbsoluteTimeGetCurrent()
    let result = f()
    let endTime = CFAbsoluteTimeGetCurrent()
    return (result, "время работы \(endTime - startTime) секунд")
}

print("\n")
print("сортировка вставками, метод 1:")
print(runningTime(f: insertionSort1(list2)))
print("сортировка вставками, метод 2:")
print(runningTime(f: insertionSort2(list2)))
print("сортировка вставками, метод 3:")
print(runningTime(f: insertionSort3(list2)))

print("\n")
print("сортировка бинарными вставками:")
print(binaryInsertionSort(list2))


print("\n")
print("поиск 4 минимальных элементов:")
print("массив: \(list4)")
print("результат: \(list4.findMin(count: 4))")


var oneHundredArray: [Int] = []
for _ in 0...99 {
    oneHundredArray.append(Int(arc4random_uniform(100)))
}

print(oneHundredArray)

print("\n")
print("сортировка выбором:")
print(runningTime(f: selectionSort(oneHundredArray)))
print("шейкерная сортировка:")
print(runningTime(f: shakerSort(oneHundredArray)))
print("сортировка Шелла:")
print(runningTime(f: shellSort(oneHundredArray)))
print("\n")
