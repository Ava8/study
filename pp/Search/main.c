/*
  main.c
  textSearch

  Created by MacBook Air on 08.12.2017.
  Copyright © 2017 MacBook Air. All rights reserved.
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

void string_to_lower(char *string) {
    while(*string) {
        *string = tolower(*string);
        string++;
    }
}

char *c_strings(int argc, char *args[]) {
    char *full_string = strdup("");
    asprintf(&full_string, "%s%s", full_string, args[0]);
    int i;
    for(i = 1; i < argc; i++) {
        asprintf(&full_string, "%s %s", full_string, args[i]);
    }
    return full_string;
}

int suffix_match(const char *aim, size_t aim_len, size_t offset, size_t suffix_len) {
    if (offset > suffix_len)
        return aim[offset - suffix_len - 1] != aim[aim_len - suffix_len - 1] &&
        strncmp(aim + aim_len - suffix_len, aim + offset - suffix_len, suffix_len) == 0;
    else
        return strncmp(aim + aim_len - offset, aim, offset) == 0;
}

size_t max(size_t a, size_t b)
{
    return a > b ? a : b;
}

const char* boyer_moore_search(const char *string, const char *search)
{
    size_t string_len = strlen(string);
    size_t search_len = strlen(search);
    
    size_t *suffix_table = (size_t *) malloc(sizeof(size_t) * search_len);
    size_t *stop_table = (size_t *) malloc(sizeof(size_t) * (UCHAR_MAX + 1));
    
    if(search_len > string_len || search_len <= 0 || !string || !search)
        return NULL;
    
    
    size_t index;
    for(index = 0; index < UCHAR_MAX + 1; index++)
        stop_table[index] = -1;
    
    
    for(index = 0; index < search_len - 1; index++)
        stop_table[(size_t) search[index]] = index;
    
    
    for(index = 0; index < search_len; index++) {
        size_t offset = search_len;
        while(offset && !suffix_match(search, search_len, offset, index))
            --offset;
        suffix_table[search_len - index - 1] = search_len - offset;
    }
    
    size_t string_position;
    for(string_position = 0; string_position <= string_len - search_len; ) {
        
        size_t search_position = search_len - 1;
        while(search[search_position] == string[search_position + string_position]) {
            if(search_position == 0)
                return string + string_position;
            
            --search_position;
        }
        
        string_position += max(suffix_table[search_position], search_position - stop_table[(size_t) string[search_position + string_position]]);
    }
    
    return NULL;
}

int string_find(const char *string, const char *aim, const char * (*find_algorithm)(const char *, const char *)) {
    const char *tmp = find_algorithm(string, aim);
    
    return tmp ? (int) (tmp - string) : -1;
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        fprintf(stderr, "input error. follow this format: filename string \n");
        exit(EXIT_FAILURE);
    }
    
    FILE *file = fopen(argv[1], "r");
    if(!file) {
        fprintf(stderr, "file not found\n");
        exit(EXIT_FAILURE);
    }
    
    int words_start = 2;
    int verbose = 1;
    
    if(strcmp(argv[words_start], "-s") == 0 && argc >= 4) {
        words_start++;
        
        verbose = 0;
    }
    
    char *full_string = c_strings(argc-words_start, argv+words_start);
    
    printf("search for: %s\n\n", full_string);
    
    int found = 0;
    int line_number = 1;
    while(!feof(file)) {
        char *line = NULL;
        size_t size = 0;
        getline(&line, &size, file);
        string_to_lower(line);
        
        int offset = 0;
        
        while(string_find(line + offset, full_string, boyer_moore_search) != -1) {
            offset += string_find(line + offset, full_string, boyer_moore_search) + 1;
            
            found = 1;
            
            if(verbose) {
                printf("string %d, position %d:\n\n %s\n", line_number, offset, line + offset - 1);
            }
        }
        
        line_number++;
        
        free(line);
    }
    
    if(!found) {
        printf("no matches\n");
    }
    
    free(full_string);
    
    return 0;
}
