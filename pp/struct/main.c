
/*  main.c
 struct
 Created by MacBook Air on 14.10.17.
 Copyright © 2017 AKS&CO. All rights reserved.
*/

#include<stdio.h>
#include<stdlib.h>

struct pakcet {
    int a;
    char str[255];
    float b;
};


int main(int argc, char **argv) {
    struct pakcet pack;
    FILE *file = fopen(argv[1], "rb");  /* open and read binary file */
    
    if (file == NULL) {                 /* check if a file exists */
        printf("FILE NOT FOUND \n\n");
        return 0;
    }
    while (fread(&pack, sizeof(struct pakcet), 1, file)) {
        printf("%d %s %f\n", pack.a, pack.str, pack.b);
    }
    fseek(file, 0, SEEK_SET);   /* go to the end of file */
    fseek(file, 0, SEEK_END);   /* get the size in byte */
    long size = ftell(file);
    
    printf("\n\n FILE SIZE IS %ld BYTES \n\n", size);
    fclose(file);
    return 0;
}
