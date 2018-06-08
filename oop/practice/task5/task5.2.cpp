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

//сортировка выбором
void select(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i]) {
                min_i = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_i];
        a[min_i] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void select(double *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i]) {
                min_i = j;
            }
        }
        double temp = a[i];
        a[i] = a[min_i];
        a[min_i] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int i_array[] = {5,8,9,4,6,3};
    double d_array[] = {6.6, 6.9, 3.2, 4.9, 5.8, 0};
    
    select(i_array, 6);
    select(d_array, 6);
    
    return 0;
}
