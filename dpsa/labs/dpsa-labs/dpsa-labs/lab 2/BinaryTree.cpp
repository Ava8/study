//
//  BinaryTree.cpp
//  dpsa-labs
//
//  Created by MacBook Air on 30.03.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//


#include <cstdio>
#include <iostream>

//The node class
class Node {
public:
    Node () {
        left = NULL;
        right = NULL;
        value = 0;
    }
    Node (int _value, Node* _left, Node* _right) {
        left = _left;
        right = _right;
        value = _value;
    }
    
public:
    Node* left;
    Node* right;
    int value;
};

//Structure to help return the data needed
class retstruct {
public:
    retstruct () {
        path = NULL;
        value = 0;
        sum = 0;
    }
    retstruct (retstruct* _path, int _value, int _sum) {
        path = _path;
        value = _value;
        sum = _sum;
    }
    
public:
    retstruct* path;
    int value;
    int sum;
};

//Function to help delete the "lighter" path
void delete_retstruct (retstruct* path) {
    if (path->path == NULL) {
        delete path;
    } else {
        delete_retstruct(path->path);
    }
}

retstruct* heavierPath ( Node * tree ) {
    if ( ! tree ) return new retstruct();
    
    //Get both paths
    retstruct* leftWeight = heavierPath( tree->left );
    retstruct* rightWeight= heavierPath( tree->right );
    
    //Find the "heavier" path
    if ( leftWeight->sum >= rightWeight->sum ) {
        //Delete lighter path
        delete_retstruct(rightWeight);
        //Pass up the better path with the correct data
        return new retstruct(leftWeight, tree->value, tree->value + leftWeight->sum);
    } else {
        //Delete lighter path
        delete_retstruct(leftWeight);
        //Pass up the better path with the correct data
        return new retstruct(rightWeight, tree->value, tree->value + rightWeight->sum);
    }
};

//Function to print the path
void printPath (retstruct* path) {
    if (path->path != NULL) {
        std::cout << " - " << path->value;
        printPath(path->path);
    }
}

//int main() {
//
//    /*
//
//            6
//           / \
//          9   6
//         /   / \
//        3   1   31
//
//     */
//
//    //Your tree
//    Node* tree = new Node(6,new Node(9,new Node(3,NULL,NULL),NULL),
//                          new Node(6,new Node(31, NULL,NULL),
//                                   new Node(19,NULL,NULL)));
////    Node* tree = new Node(0,
////                                new Node(2, new Node(4, NULL, NULL), new Node(9, NULL, NULL)),
////                                new Node(6, new Node(1, NULL, NULL), new Node(0, NULL, NULL)));
//    
//    /*
//     
//            0
//           / \
//          /   \
//         2     6
//        / \   / \
//       4   9 1   0
//     
//     */
//
//
//    retstruct* path = heavierPath(tree);
//
//    //Print sum
//    std::cout << "Sum: " << path->sum << std::endl;
//
//    //Print path
//    std::cout << "Path: " << path->value;
//    printPath(path->path);
//    std::cout << std::endl;
//
//    return 0;
//}

