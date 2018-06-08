//: Playground - noun: a place where people can play

import UIKit
import Foundation

var list1 = [1,9,4,5,1,0]
var list2 = [9,3,-7,0,3]
var list3 = [1,-2,3,-4,5,6,7,-8,9,10]
var list4 = [10,9,8,7,6,5,4,3,2,1]
var list5 = [0,1,2,3,4]

//var tmp = [356, 876, 0, 4, 378, 45, 23, 100, 36, 5, 1, 10, 67, 456, 342, 35, 21, 34, 68, 567, 234, 34, 1098]

var count = 0
func quickSort<T: Comparable>(_ list: [T]) -> [T] {
    // если в нашем массиве больше, чем один элемент, то имеет смысл его фильтровать
    if list.count > 1 {

        //определяем опорный элемент - середина массива
        let pivot = list[0+(list.count - 0)/2]

        //создаём массив элементов меньших, чем опорный
        var less:[T] = []
        //создаём массив элементов эквивалентных опорному
        var equal:[T] = []
        //создаём массив элементов больших, чем опроный
        var greater:[T] = []

        //проходим по массиву и сортируем элементы по группам
        for element in list {
            if element < pivot {
                less.append(element)
            } else if element == pivot {
                equal.append(element)
            } else if element > pivot {
                greater.append(element)
            }
            count += 1
        }
        return quickSort(less) + equal + quickSort(greater)
    } else {
        return list
    }
}

print("исходный массив: \(list2), отсортированный массив: \(quickSort(list2))")
print("количество операций сравнения - \(count)")


//func quickSort<T: Comparable>(_ list: [T]) -> [T] {
//    if list.isEmpty {
//        return list
//    } else {
//        let pivot = list[0]
//        let subList = list[1..<list.count]
//        let left = quickSort(subList.filter({$0 < pivot}))
//        let right = quickSort(subList.filter({$0 >= pivot}))
//        return left + [pivot] + right
//    }
//}
//
//quickSort(list1)


//func quickSort (_ list: inout [Int],_ start: Int,_ end: Int) {
//
//    if end - start < 2 {return}
//
//    let pivot = list[start+(end-start)/2]
//    var low = start
//    var high = end
//    var countMerge = 0
//
//    while(low<=high) {
//        countMerge += 1
//
//        if list[low] < pivot {
//            low += 1
//            continue
//        }
//
//        if list[high] > pivot {
//            high -= 1
//            continue
//        }
//
//        let tmp = list[low]
//        list[low] = list[high]
//        list[high] = tmp
//
//        low+=1
//        high-=1
//    }
//
//    quickSort(&list, start, high+1)
//    quickSort(&list, low+1, end)
//}
//
//quickSort(&list1, 0, list1.count-1)
//quickSort(&list3, 0, list3.count-1)

