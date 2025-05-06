#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

int main() {
    fs_create_new_file("test.txt", "Пример содержимого файла", "data.fs");
    
    char* content = fs_view_file("data.fs", "test.txt");
    if (content) {
        printf("Содержимое файла:\n%s\n", content);
        free(content);
    }
    
    fs_modify_file("test.txt", "Обновленное содержимое", "data.fs", "data.fs.new");
    
    fs_delete_file("data.fs", "test.txt");
    
    FILE* file = fs_open_or_create("example.txt");
    fclose(file);
    
    return 0;
}
