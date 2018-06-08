//
//  main.c
//  RPN Calculate
//
//  Created by MacBook Air on 28.09.17.
//  Copyright © 2017 AKS&CO. All rights reserved.
//

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100 // Максимальная лубина стека

//Значения, возвращаемые функцией parse
#define VAL  0  // В стек занесено новое значение
#define ADD  1  // Сложение
#define SUB  2  // Вычитание
#define MUL  3  // Умножение
#define DIV  4  // Деление
#define SOF -1  // Переполнение стека
#define SUF -2  // В стеке недостаточно операндов
#define UNK -3  // Неопознанное значение

int sc=0;                   //следущее свободное значение стека
double stack[MAXVAL];       //стек


int parse(char *);  //функция распознования аргумента

int main(int argc, char **argv)
{

    while (*++argv) {
        
       
        switch (parse(*argv)) {
            case VAL: continue;
                
            
            case ADD:
                stack[sc - 1] += stack[sc];
                break;
                
            case SUB:
                stack[sc - 1] -= stack[sc];
                break;
                
            case MUL:
                stack[sc - 1] *= stack[sc];
                break;
                
            case DIV:
                if (stack[sc] != 0) {
                    stack[sc - 1] /= stack[sc];
                    break;
                }
            case SUF:
                fprintf(stderr, "Недостаточно операндов!\n");
                return(1);
                
            case SOF:
                fprintf(stderr, "Переполнение стека!\n");
                return(1);
                
            case UNK:
                fprintf(stderr, "Неопознанный аргумент!\n");
                return(1);
        }
    }
    
    auto int i;
    for (i = 0; i < sc; i++) printf("%0.3f\n", stack[i]);
    
    return(0);
}

int parse(char *s)
{
    double tval = 0;
    char * endptr;
    
    
    switch (*s) {
        case '-':
            if (*(s+1) != '\0') break;
            if (sc >= 2) {
                sc -= 1;
                return(SUB);
            }
            else return(SUF);
            
        case '+':
            if (*(s+1) != '\0') break;
            if (sc >= 2) {
                sc -= 1;
                return(ADD);
            }
            else return(SUF);
            
        case '*':
            if (*(s+1) != '\0') break;
            if (sc >= 2) {
                sc -= 1;
                return(MUL);
            }
            else return(SUF);
            
        case '/':
            if (*(s+1) != '\0') break;
            if (sc >= 2) {
                sc -= 1;
                return(DIV);
            }
            else return(SUF);
    }
    
    errno = 0;
    
    // Пытаемся сконвертировать строковый аргумент в число
    tval = strtod(s, &endptr);
    
    // Вернуть ошибку `неопознанный аргумент' в случае неудачи
    if (errno != 0 || *endptr != '\0') return(UNK);
    
    // Проверяем, есть ли свободное место в стеке и сохраняем в нем операнд, иначе возвращаем ошибку переполнения
    if (sc < MAXVAL) stack[sc++] = tval;
    else return(SOF);
    
    return(VAL);
}
