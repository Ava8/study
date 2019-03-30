//
//  StringMatch.swift
//  dpsa-practice
//
//  Created by MacBook Air on 28.03.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

import Foundation

// MARK: Brute Force match string extension

extension String {
    mutating func  matchWithBF( forPattern pattern : inout String, caseInsensitive: Bool) ->(matched : Bool, atIndex : Int) {
        
        pattern = pattern.trimmingCharacters(in: .whitespaces)
        
        if caseInsensitive {
            self = self.lowercased()
            pattern = pattern.lowercased()
        }
        
        
        for i in indices {
            var j = i
            var matched = true
            for p in pattern.indices {
                guard j != endIndex && self[j] == pattern[p] else { matched = false; break }
                j = index(after: j)
            }
            
            if matched {
                return (true, i.encodedOffset)
            }
        }
        return (false, -1)
    }
}

// MARK: Knuth Morris Pratt match string extension

extension String {
    private struct KMPTableContent {
        var index: Int;
        var char: Character?;
        var value: Int;
    }
    
    private func initKMPTable (withPattern pattern : String) -> [KMPTableContent] {
        var table = [KMPTableContent]()
        var p_char: Character?
        
        // make sure pattern is not empty string.
        if (pattern != "") {
            table.append(KMPTableContent(index: 0, char: pattern.first, value: 1))
            for k in 1..<pattern.count {
                p_char = pattern[pattern.index(pattern.startIndex, offsetBy: k)]
                table.append(KMPTableContent(index: k, char: p_char, value: 0))
            }
        }
        return table
    }
    
    private func kmpTable (forPattern pattern : String) -> [KMPTableContent]
    {
        var table = initKMPTable(withPattern: pattern)
        var i = 1, j=0 // i = 1 to move pointer one char forward.
        while (i+j<pattern.count)
        {
            if table[i+j].char == table[j].char {
                // chars of i + j and j indexes are the same
                table[i+j].value = i
                j+=1
            } else {
                // chars at i + j and j indexes are not the same
                if j==0 {
                    table[i].value = i + 1;
                }
                
                // checks for negative values
                if (j-1 < 0) {
                    j = 1
                }
                i = i + table[j-1].value
                j = j - table[j-1].value
            }
        }
        return table
    }
    
    mutating func matchWithKMP(forPattern pattern : inout String, caseInsensitive: Bool) ->(matched : Bool, fromIndex : Int, toIndex : Int) {
        
        pattern = pattern.trimmingCharacters(in: .whitespaces)
        
        if caseInsensitive {
            self = self.lowercased()
            pattern = pattern.lowercased()
        }
        
        let textLength = self.count
        let patternLength = pattern.count
        var toIndex = -1
        let st = kmpTable(forPattern: pattern) // swift table for this pattern
        var i = 0, j=0
        var tchar: Character
        while (i + j < textLength) {
            tchar = self[self.index(self.startIndex, offsetBy: i+j)] // char from text at i + j index
            
            // while the char at index i + j of the text is equal to the char at index j of pattern
            // then, increment j
            while ( tchar == st[j].char ) {
                j+=1
                if (j>=patternLength) {
                    // First ocurrence of pattern found at index i of text
                    toIndex = i + (patternLength - 1)
                    return (true, i, toIndex)
                }
                // pattern not found completely, then update char of text to the next char
                if textLength > i+j {
                    tchar = self[self.index(self.startIndex, offsetBy: i+j)]
                }
            }
            
            if (j-1 <= 0) {
                // check for negative values
                i = i + 1
                j = 0
            } else {
                i = i + st[j-1].value // increment i
                j = j - st[j-1].value // decrement j
            }
        }
        
        return (false, -1, toIndex) // pattern not found.
    }
    
}

// MARK: Boyer Moore match string extension

extension String {
    mutating func matchWithBM(forPattern pattern : inout String, caseInsensitive: Bool) ->(matched : Bool, atIndex : Int) {
        
        pattern = pattern.trimmingCharacters(in: .whitespaces)
        
        if caseInsensitive {
            self = self.lowercased()
            pattern = pattern.lowercased()
        }
        
        let patternLength = pattern.count
        guard patternLength > 0, patternLength <= self.count else { return (false, -1) }
        
        var skipTable = [Character: Int]()
        for (index, char) in pattern.enumerated() {
            skipTable[char] = patternLength - 1 - index
        }
        
        let lastPatternIndex = pattern.index(before: pattern.endIndex)
        let lastPatternChar = pattern[lastPatternIndex]
        
        var currentIndex = self.index(self.startIndex, offsetBy: patternLength - 1)
        
        func backwardCheck() -> Index? {
            var tempPatternIndex = lastPatternIndex
            var tempIndex = currentIndex
            while tempPatternIndex > pattern.startIndex {
                tempIndex = self.index(before: tempIndex)
                tempPatternIndex = pattern.index(before: tempPatternIndex)
                
                if self[tempIndex] != pattern[tempPatternIndex] { return nil }
            }
            
            return tempIndex
        }
        
        while currentIndex < self.endIndex {
            let currentChar = self[currentIndex]
            
            if currentChar == lastPatternChar {
                if let matchIndex = backwardCheck() { return (true, matchIndex.encodedOffset) }
                
                currentIndex = self.index(after: currentIndex)
            } else {
                currentIndex = self.index(currentIndex, offsetBy: skipTable[currentChar] ?? patternLength, limitedBy: self.endIndex) ?? self.endIndex
            }
        }
        
        return (false, -1)
    }
}

