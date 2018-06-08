//: Playground - noun: a place where people can play

import Foundation

func isPowerOfTwo (value: Int) -> Bool {
    return value > 0 && (value & (value - 1) == 0)
}

func complete_operation (cost: Int) -> Int {
    return cost
}

func count_operations_cost (operations_count: Int) -> Int {
    var sum: Int = 0
    for i in 1...operations_count {
        var cost: Int
        if isPowerOfTwo(value: i) == true {
            cost = i
        } else {
            cost = 1
        }
        sum += cost
    }
    return sum
}

print(count_operations_cost(operations_count: 8))




