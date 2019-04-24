//
//  File.swift
//  dpsa-practice
//
//  Created by MacBook Air on 11.04.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation


struct Constants {
    static let hashMultiplier = 69069
}

extension Character {
    var asInt: Int {
        let s = String(self).unicodeScalars
        return Int(s[s.startIndex].value)
    }
}

precedencegroup PowerPrecedence { higherThan: MultiplicationPrecedence }
infix operator ** : PowerPrecedence
func ** (radix: Int, power: Int) -> Int {
    return Int(pow(Double(radix), Double(power)))
}
func ** (radix: Double, power: Int) -> Double {
    return pow(radix, Double(power))
}

public func hash(array: Array<Int>) -> Double {
    var total: Double = 0
    var exponent = array.count - 1
    for i in array {
        total += Double(i) * (Double(Constants.hashMultiplier) ** exponent)
        exponent -= 1
    }

    return Double(total)
}

public func nextHash(prevHash: Double, dropped: Int, added: Int, patternSize: Int) -> Double {
    let oldHash = prevHash - (Double(dropped) *
        (Double(Constants.hashMultiplier) ** patternSize))
    return Double(Constants.hashMultiplier) * oldHash + Double(added)
}

extension String {

    mutating func searchRK(forPattern pattern: String) -> (matched : Bool, atIndex : Int, comparsionCount: Int) {

        var comparsionCount = 0

        // convert to array of ints
        let patternArray = pattern.compactMap { $0.asInt }
        let textArray = self.compactMap { $0.asInt }

        if textArray.count < patternArray.count {
            return (false, -1, 0)
        }

        let patternHash = dpsa_practice.hash(array: patternArray)
        var endIdx = patternArray.count - 1
        let firstChars = Array(textArray[0...endIdx])
        let firstHash = dpsa_practice.hash(array: firstChars)

        if (patternHash == firstHash) {
            // Verify this was not a hash collision
            if firstChars == patternArray {
                return (true, 0, 0)
            }
        }

        var prevHash = firstHash
        // Now slide the window across the text to be searched
        for idx in 1...(textArray.count - patternArray.count) {
            comparsionCount += 1
            endIdx = idx + (patternArray.count - 1)
            let window = Array(textArray[idx...endIdx])
            let windowHash = nextHash(prevHash: prevHash, dropped: textArray[idx - 1], added: textArray[endIdx], patternSize: patternArray.count - 1)

            if windowHash == patternHash {
                if patternArray == window {
                    return (true, idx, comparsionCount)
                }
            }

            prevHash = windowHash
        }

        return (false, -1, comparsionCount)
    }

}

//precedencegroup PowerPrecedence { higherThan: MultiplicationPrecedence }
//infix operator ** : PowerPrecedence
//func ** (radix: Int, power: Int) -> Int {
//    return Int(pow(Double(radix), Double(power)))
//}
//func ** (radix: Double, power: Int) -> Double {
//    return pow(radix, Double(power))
//}
//
//public func hash(array: Array<Int>) -> Double {
//    var total: Double = 0
//    var exponent = array.count - 1
//    for i in array {
//        total += Double(i) * (Double(Constants.hashMultiplier) ** exponent)
//        exponent -= 1
//    }
//
//    return Double(total)
//}
//
//public func nextHash(prevHash: Double, dropped: Int, added: Int, patternSize: Int) -> Double {
//    let oldHash = prevHash - (Double(dropped) *
//        (Double(Constants.hashMultiplier) ** patternSize))
//    return Double(Constants.hashMultiplier) * oldHash + Double(added)
//}
//
//public func search(text: String , pattern: String) -> (Int, Bool) {
//    // convert to array of ints
//    let patternArray = pattern.compactMap { $0.asInt }
//    let textArray = text.compactMap { $0.asInt }
//
//    if textArray.count < patternArray.count {
//        return (-1, false)
//    }
//
//    let patternHash = hash(array: patternArray)
//    var endIdx = patternArray.count - 1
//    let firstChars = Array(textArray[0...endIdx])
//    let firstHash = hash(array: firstChars)
//
//    if (patternHash == firstHash) {
//        // Verify this was not a hash collision
//        if firstChars == patternArray {
//            return (0, true)
//        }
//    }
//
//    var prevHash = firstHash
//    // Now slide the window across the text to be searched
//    for idx in 1...(textArray.count - patternArray.count - 1) {
//        endIdx = idx + (patternArray.count - 1)
//        let window = Array(textArray[idx...endIdx])
//        let windowHash = nextHash(prevHash: prevHash, dropped: textArray[idx - 1], added: textArray[endIdx], patternSize: patternArray.count - 1)
//
//        if windowHash == patternHash {
//            if patternArray == window {
//                return (idx, true)
//            }
//        }
//
//        prevHash = windowHash
//    }
//
//    return (-1, false)
//}
