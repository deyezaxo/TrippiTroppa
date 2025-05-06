#ifndef FILESYSTEM_H
#define FILESYSTEM_H

int create_file(const char* filename);

int delete_file(const char* filename);

int write_file(const char* filename, const char* data);

char* read_file(const char* filename);

void list_files();

#endif
