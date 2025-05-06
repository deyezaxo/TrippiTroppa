#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>

FILE* fs_open_or_create(const char* filename);
char* fs_read_file(const char* fs_content, const char* target_file);
void fs_delete_file(const char* filename, const char* fs_content, const char* output_filename);
void fs_create_file(const char* filename, const char* content, const char* fs_filename);
void fs_modify_file(const char* filename, const char* new_content, const char* fs_content, const char* output_filename);

#endif
