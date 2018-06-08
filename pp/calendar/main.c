/*
  main.c
  CALENDAR

  Created by MacBook Air on 17.11.17.
  Copyright © 2017 AKS&CO. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct calendar {
    int day;
    int month;
    int year;
} date;

typedef enum day_name_e {sunday, monday, tuesday, wednesday, thursday, friday, saturday} week;

int selected_day(const struct calendar* date) {
    int a = (14 - date->month) / 12;
    int y = date->year - a;
    int m = date->month + 12 * a - 2;
    
    return (7000 + (date->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
}

void check_date(date d) {
    if(d.day <= 0 || d.day > 31) {
        printf("wrong day number: %d\n", d.day);
        
        exit(EXIT_FAILURE);
    } else if(d.month <= 0 || d.month > 12) {
        printf("wrong month number: %d\n", d.month);
        
        exit(EXIT_FAILURE);
    } else if(d.year < 1583) {
        printf("unsupported year number: %d\n", d.year);
        
        exit(EXIT_FAILURE);
    }
    
    int leap_year = d.year % 4 == 0 && d.year % 100 != 0 ? 1 : 0;
    
    if(d.month == 2) {
        if(leap_year && d.day > 29) {
            printf("wrong day number in leap year(%d) in month(%d): %d\n", d.year, d.month, d.day);
            
            exit(EXIT_FAILURE);
        } else if(!leap_year && d.day > 28){
            printf("wrong day number in not leap year(%d) in month(%d): %d\n", d.year, d.month, d.day);
            
            exit(EXIT_FAILURE);
        }
    } else {
        int magic_month = d.month < 8 ? d.month : d.month - 8 + 1;
        if(magic_month % 2 == 1 && d.day > 31) {
            printf("wrong day number: %d\n", d.day);
            
            exit(EXIT_FAILURE);
        } else if(magic_month % 2 == 0 && d.day > 30) {
            printf("wrong day number: %d\n", d.day);
            
            exit(EXIT_FAILURE);
        }
    }
}

const char *get_day_string(week day) {
    switch(day) {
        case 0: return "SUNDAY";
        case 1: return "MONDAY";
        case 2: return "TUESDAY";
        case 3: return "WEDNESDAY";
        case 4: return "THURSDAY";
        case 5: return "FRIDAY";
        case 6: return "SATURDAY";
    }
    
    return "";
}

int main() {
    date d;
    
    printf("enter date: dd.mm.yyyy\n ");
    
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    
    if(sscanf(line, "%d.%d.%d", &d.day, &d.month, &d.year) != 3) {
        printf("can not parse date correctly\n");
        
        return 1;
    }
    
    check_date(d);
    
    week day = selected_day(&d);
    
    const char *day_string = get_day_string(day);
    
    printf("\nday number: %d\nweek: %s\n\n", day == 0 ? 7 : day, day_string);
    
    return 0;
}
