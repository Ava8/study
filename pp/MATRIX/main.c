//
//  main.c
//  Matrix
//
//  Created by MacBook Air on 12.10.17.
//  Copyright © 2017 AKS&CO. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


int main() {
    
    
    //Step 1: create a random matrix
    //m - is number of rows
    //n - is number columns
    
    unsigned int n,m;
    srand((unsigned int) time(NULL));
    
    n = rand()%(10)+4;
    m = rand()%(10)+3;
    
    int matrix[m][n];
    unsigned int i,j = 0;
    
    printf("CREATED MATRIX\n\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%6d ", matrix[i][j] = (-9 +rand()%19)); //generate random numbers from (-10;10)
        printf("\n\n");
    }
   
    
    //Step 2: swap lines and revers
    
    printf("SWAP FIRST AND LAST ROWS AND REVERS\n\n");
    
    int array[n];
    for(i=0;i<n;i++)
        array[i] = matrix[0][n-1-i];
    for(i=0;i<n;i++)
        matrix[0][i] = matrix[m-1][n-1-i];
    for(i=0;i<n;i++)
        matrix[m-1][i] = array[i];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n\n");
    }
    
    //Step 3: delete rows and column with the min element
    
    
    int min = matrix[0][0];
    int minm = 0;
    int minn = 0;
    for(int i = 0; i<m ; i++ ){
        for (int j = 0; j<n; j++){
            if  (matrix[i][j] < min ){
                min = matrix[i][j];
                minm = i;
                minn = j;
            }
        }
    }
    
     printf("DELETE ROW AND COLUMN WITH THE MIN ELEMENT (%d) \n\n", min);
    
    int **matrix_2 = (int**)malloc((m-1) * sizeof(int*));
    for(int i = 0; i<m-1 ; i++ ){
        matrix_2[i] = malloc((n-1) * sizeof(int));
    }
    for(int I = 0, i = 0; I<m-1; I++, i++){
        if (i == minm){
            I--;
            continue;
        }
        for (int J = 0, j = 0; J<n-1;J++, j++){
            if (j == minn){
                J--;
                continue;
            }
            matrix_2[I][J] = matrix[i][j];
            printf("%6d ", matrix_2[I][J]);
        }
        printf("\n\n");
    }
    printf("\n");
    
    //Step 4: enter new matrix

    printf("ENTER MATRIX WITH %d ROWS \n\n", n-1);
    
    char *mat = NULL;
    size_t s = 0;
    int count=0,cc=-1; //count is number of rows, cc is number of columns
    
    getline(&mat, &s, stdin);
    for (int i=0, flag=0, current_count=0; i<strlen(mat) && flag==0; i++){
        switch (mat[i]) {
            case '.':
                flag = 1;
                count++;
                break;
            case ',':
                count++;
                if (cc == -1) {
                    cc = current_count;
                }
                else if (cc != current_count) {
                    printf("\n INPUT ERROR\n\n");
                    return 1;
                }
                current_count = 0;
                break;
            default:
                break;
        }
        if (isspace(mat[i])){
            current_count++;
        } else
            continue;
    }
    
    
    if (count != n-1) {
        printf("\n COUNT OF ROWS(%d) IS NOT EQUAL TO REQUIRED COUNT(%d)\n\n", count, n-1);
        return 2;
    }
    
    int matrix_04[count][cc];
    for (int i=0,j=0,k=0; i<strlen(mat); i++ ) {
        if (isdigit(mat[i])) {
            char *tmp;
            int number = (int) strtol(mat+i, &tmp, 10);
            int offset = (int) (tmp-(mat+i));
            i+= offset;
            matrix_04[j][k] = number;
            k++;
        }
        else if (mat[i] == ','){
            j++;
            continue;
        }
        else if (mat[i] == '.') {
            break;
        }
    }
    printf("\n entered marix\n\n");
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < cc; j++) {
            printf("%d ", matrix_04[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // matrix multiplication
 
    int mult_matrix[m-1][cc];
    printf("\n MULTIPLY MATRIX\n\n");
    for(i=0; i<m-1; i++)
    {
        for(j=0; j<cc; j++)
        {
            mult_matrix[i][j] = 0;
            for(int k=0; k< m-1; k++)
                mult_matrix[i][j] += matrix[i][k] * matrix_04[k][j];
            printf("%6d ", mult_matrix[i][j]);
        }
        printf("\n\n");
    }
    printf ("\n");
    return 0;
}

