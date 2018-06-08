import Foundation


func knapsack_problem_solution(capacity: Int, items: [(weight: Int, value: Int)]) -> Int {
    let n = items.count
    var solutions = [[Int]](repeating: [Int](repeating: 0, count: capacity + 1), count: n + 1)
    for i in 1...n {
        for w in 1...capacity {
            if items[i - 1].weight > w {
                solutions[i][w] = solutions[i - 1][w]
            } else {
                let with = items[i - 1].value + solutions[i - 1][w - items[i - 1].weight]
                let without = solutions[i - 1][w]
                solutions[i][w] = max(with, without)
            }
        }
    }
    return solutions[n][capacity]
}

let maxWeight = 11
var items = [(1,6),(2,8),(6,5),(4,9),(8,8)]
let maxValue = knapsack_problem_solution(capacity: maxWeight, items: items)
print("Max value: \(maxValue)")

