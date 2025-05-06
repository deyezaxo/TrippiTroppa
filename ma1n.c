#include <stdio.h>
#include "filesystem.h"

int main() {
    create_file("test.txt");
    write_file("test.txt", "Hello, File System!");
    char* content = read_file("test.txt");
    printf("File content: %s\n", content);
    list_files();
    
    return 0;
}
