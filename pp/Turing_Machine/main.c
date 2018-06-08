/*
  main.c
  TuringMachine
  Created by MacBook Air on 04.12.2017.
  Copyright © 2017 MacBook Air. All rights reserved.
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size_m 10
#define resizing_k 1.5

int i;

typedef struct turing_tape_s {
    unsigned char *pos_array;
    unsigned char *neg_array;
    unsigned long int pos_size;
    unsigned long int neg_size;
    int sign;
    unsigned long int current_element;
} turing_tape;

/*create*/

turing_tape *create_turing_tape() {
    turing_tape *tape = (turing_tape *) malloc(sizeof(turing_tape));
    tape->pos_array = (unsigned char *) calloc(size_m, sizeof(unsigned char));
    tape->neg_array = (unsigned char *) calloc(size_m, sizeof(unsigned char));
    tape->sign = 1;
    tape->pos_size = size_m;
    tape->neg_size = size_m;
    tape->current_element = 0;
    return tape;
}
void free_turing_tape(turing_tape *tape) {
    if(tape->pos_array)
        free(tape->pos_array);
    if(tape->neg_array)
        free(tape->neg_array);
    if(tape)
        free(tape);
}
void resize_turing_tape(turing_tape *tape, int tape_type) {
    if(tape_type == 1) {
        unsigned char *tmp_array = (unsigned char *) calloc(tape->pos_size*resizing_k, sizeof(unsigned char));
        memcpy(tmp_array, tape->pos_array, tape->pos_size);
        free(tape->pos_array);
        tape->pos_array = tmp_array;
        tape->pos_size = tape->pos_size*resizing_k;
    } else if(tape_type == -1) {
        unsigned char *tmp_array = (unsigned char *) calloc(tape->neg_size*resizing_k, sizeof(unsigned char));
        memcpy(tmp_array, tape->neg_array, tape->neg_size);
        free(tape->neg_array);
        tape->neg_array = tmp_array;
        tape->neg_size = tape->neg_size*resizing_k;
    }
}

void movl(turing_tape *tape) {
    if(tape->sign == 1) {
        if(tape->current_element == 0) {
            tape->sign = -1;
        } else {
            tape->current_element--;
        }
    } else if(tape->sign == -1) {
        if(tape->current_element == tape->neg_size-1) {
            resize_turing_tape(tape, tape->sign);
            tape->current_element++;
        } else {
            tape->current_element++;
        }
    }
}
void movr(turing_tape *tape) {
    if(tape->sign == 1) {
        if(tape->current_element == tape->pos_size-1) {
            resize_turing_tape(tape, tape->sign);
            tape->current_element++;
        } else {
            tape->current_element++;
        }
    } else if(tape->sign == -1) {
        if(tape->current_element == 0) {
            tape->sign = 1;
        } else {
            tape->current_element--;
        }
    }
}
/* ++ */
void inc(turing_tape *tape) {
    if(tape->sign == 1) {
        tape->pos_array[tape->current_element]++;
    } else if(tape->sign == -1) {
        tape->neg_array[tape->current_element]++;
    }
}

/* -- */
void dec(turing_tape *tape) {
    if(tape->sign == 1) {
        tape->pos_array[tape->current_element]--;
    } else if(tape->sign == -1) {
        tape->neg_array[tape->current_element]--;
    }
}
void print(turing_tape *tape) {
    if(tape->sign == 1) {
        printf("%u\n", tape->pos_array[tape->current_element]);
    } else if(tape->sign == -1) {
        printf("%u\n",tape->neg_array[tape->current_element]);
    }
}
void get(turing_tape *tape) {
    if(tape->sign == 1) {
        tape->pos_array[tape->current_element] = getchar();
    } else if(tape->sign == -1) {
        tape->neg_array[tape->current_element] = getchar();
    }
}
unsigned char cur(turing_tape *tape) {
    if(tape->sign == 1) {
        return tape->pos_array[tape->current_element];
    } else if(tape->sign == -1) {
        return tape->neg_array[tape->current_element];
    }
    return 0;
}
void printc(turing_tape *tape) {
    if(tape->sign == 1) {
        printf("%c\n", tape->pos_array[tape->current_element]);
    } else if(tape->sign == -1) {
        printf("%c\n",tape->neg_array[tape->current_element]);
    }
}

int array_length(char **array) {
    if(!array)
        return 0;
    
    int length = 0;
    while(*array++) {
        length++;
    }
    return length;
}
char **read_all_commands(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        return NULL;
    }
    const double mult = 1.5;
    int index = 0;
    int array_size = 10;
    char **array = (char **) calloc(array_size, sizeof(char *));
    char *line;
    size_t size;
    while(!feof(file)) {
        line = NULL;
        size = 0;
        getline(&line, &size, file);
        array[index++] = line;
        if(index == array_size) {
            array_size = (int) (array_size*mult);
            array = (char **) realloc(array, sizeof(char *)*array_size);
        }
    }
    array[index] = NULL;
    return array;
}
void check(char** t, turing_tape *pointer, int start, int end){
    int cycle;
    for(i = cycle = start; i< end; i++) {
        if (strstr(t[i], "movl")){
            movl(pointer);
        }
        if (strstr(t[i], "movr")){
            movr(pointer);
        }
        if (strstr(t[i], "inc")){
            inc(pointer);
        }
        if (strstr(t[i], "dec")){
            dec(pointer);
        }
        if (strstr(t[i], "print")){
            print(pointer);
            
        }
        if (strstr(t[i], "get")){
            get(pointer);
        }
        if (strstr(t[i], "printc")){
            printc(pointer);
        }
        if (strstr(t[i], "begin")){
            cycle = i+1;
            
        }
        if (strstr(t[i], "end")){
            while(cur(pointer)){
                check(t, pointer, cycle, i);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char **t = read_all_commands(argv[1]);
    turing_tape tape;
    turing_tape *point = &tape;
    tape = *create_turing_tape();
    check(t, point, 0,array_length(t));
    return 0;
}
