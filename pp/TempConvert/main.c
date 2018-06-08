/*  main.c
 TempConvert
 Created by MacBook Air on 06.09.17.
 Copyright © 2017 AKS&CO. All rights reserved. */

#include <stdio.h>


int main (int argc, char *argv[]) {
    
    double d;
    char s;
    
    if(argc == 3) {
        sscanf(argv[1], "%lf", &d);
        sscanf(argv[2], "%c", &s);
        
        switch(s) {
            case 'C':
            case 'c':
                if (d > -273.15)
                    printf("%7.2f F\n%7.2f K\n", d*1.8+32, d+273.15);
                else
                    printf ("The temperature is equal to absolute zero\n");
                break;
            case 'F':
            case 'f':
                if(d > -459.67)
                    printf("%7.2f C\n%7.2f K\n", (d-32)*(5.0/9.0), (d-32)*(5.0/9.0)+273.15);
                else
                    printf ("The temperature is equal to absolute zero\n");
                break;
            case 'K':
            case 'k':
                if (d > 0)
                    printf("%7.2f C\n%7.2f F\n", d-273.15, (d-273.15)*1.8+32);
                else
                    printf ("The temperature is equal to absolute zero\n");
                break;
        }
    }
    else if (argc == 2){
        sscanf(argv[1], "%lf", &d);
        printf ("IN CASE IF C: \n");
        if (d > -273.15)
            printf("%7.2f C\n%7.2f F\n%7.2f K\n\n", d, d*1.8+32, d+273.15);
        else
            printf ("The temperature is equal to absolute zero\n\n");
        printf ("IN CASE IF F: \n");
        if(d > -459.67)
            printf("%7.2f F\n%7.2f C\n%7.2f K\n\n", d, (d-32)*(5.0/9.0), (d-32)*(5.0/9.0)+273.15);
        else
            printf ("The temperature is equal to absolute zero\n\n");
        printf ("IN CASE IF K: \n");
        if (d > 0)
            printf("%7.2f K\n%7.2f C\n%7.2f F\n\n", d, d-273.15, (d-273.15)*1.8+32);
        else
            printf ("The temperature is equal to absolute zero\n\n");
    }
    
}


