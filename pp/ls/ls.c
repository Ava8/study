#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int check_path(const char *path) {
    struct stat st;
    if(stat(path, &st) == -1) {
        printf("unable to open %s\n", path);
        return 0;
    }
    
    return 1;
}

int is_dir(const char *path) {
    struct stat st;
    stat(path, &st);
    return (st.st_mode & S_IFMT) & S_IFDIR;
}

void ls(const char *path) {
    if(!check_path(path))
        return;
    
    if(is_dir(path)) {
        DIR *dir = opendir(path);
        
        struct dirent *entry;
        
        for(entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
            printf("%s\t", entry->d_name);
        }
        
        closedir(dir);
    } else {
        printf("%s\t", path);
    }
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        char *cur_dir = getwd(NULL);
        ls(cur_dir);
        free(cur_dir);
        printf("\n");
        return 0;
    } else {
        int i;
        for(i = 1; i < argc; i++) {
            ls(argv[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}
