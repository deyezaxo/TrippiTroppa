#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

FILE* open_or_create_fs(const char* filename) {
    FILE* file = fopen(filename, "a+"); 
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        exit(EXIT_FAILURE);
    }
    return file;
}


char* read_file_in_fs(const char* fs_content, const char* target_file) {
    char* content = strdup(fs_content);
    char* line = strtok(content, "\n");
    int found = 0;
    char* result = NULL;

    while (line != NULL) {
        if (strcmp(line, target_file) == 0) {
            found = 1;
            line = strtok(NULL, "\n");
            result = malloc(strlen(line) + 1);
            strcpy(result, line);
            break;
        }
        line = strtok(NULL, "\n");
    }

    free(content);
    return found ? result : NULL;
}


void delete_file_in_fs(const char* filename, const char* fs_content, const char* output_filename) {
    FILE* output = fopen(output_filename, "w");
    char* content = strdup(fs_content);
    char* line = strtok(content, "\n");
    int skip = 0;

    while (line != NULL) {
        if (strcmp(line, filename) == 0) {
            skip = 1;
        } else if (line[0] == '/') {
            skip = 0;
        }

        if (!skip) {
            fprintf(output, "%s\n", line);
        }
        line = strtok(NULL, "\n");
    }

    free(content);
    fclose(output);
}

 
void create_new_file(const char* filename, const char* content, const char* fs_filename) {
    FILE* fs_file = fopen(fs_filename, "a");
    fprintf(fs_file, "%s\n%s\n/\n", filename, content);
    fclose(fs_file);
}


void modify_file_in_fs(const char* filename, const char* new_content, const char* fs_content, const char* output_filename) {
    FILE* output = fopen(output_filename, "w");
    char* content = strdup(fs_content);
    char* line = strtok(content, "\n");
    int inside_target = 0;

    while (line != NULL) {
        if (strcmp(line, filename) == 0) {
            inside_target = 1;
            fprintf(output, "%s\n%s\n", line, new_content);
            while (line != NULL && line[0] != '/') {
                line = strtok(NULL, "\n");
            }
        } else {
            fprintf(output, "%s\n", line);
            line = strtok(NULL, "\n");
        }
    }

    free(content);
    fclose(output);
}
