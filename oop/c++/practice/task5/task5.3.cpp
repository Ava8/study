//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 26.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

// сортировка вставками
void insert(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int cur = a[i];
        int j = i;
        while (j > 0 && cur < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = cur;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert(double *a, int n) {
    for (int i = 1; i < n; i++) {
        double cur = a[i];
        int j = i;
        while (j > 0 && cur < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = cur;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int i_array[] = {5,8,9,4,6,3};
    double d_array[] = {6.6, 6.9, 3.2, 4.9, 5.8, 0};
    
    insert(i_array, 6);
    insert(d_array, 6);
    
    return 0;
}
