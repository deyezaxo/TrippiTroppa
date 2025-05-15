#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

#define MAX_INPUT 256
#define MAX_ARGS 5

void print_help() {
    printf("Доступные команды:\n");
    printf("  создать <имя_файла> <содержимое>\n");
    printf("  удалить <имя_файла>\n");
    printf("  изменить <имя_файла> <новое_содержимое>\n");
    printf("  посмотреть <имя_файла>\n");
    printf("  выход\n");
}

int main() {
    char input[MAX_INPUT];
    char* args[MAX_ARGS];
    char* token;
    int i;

    printf("Файловая система v1.0\n");
    print_help();

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = '\0';

        i = 0;
        token = strtok(input, " ");
        while (token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        if (i == 0) continue;

        if (strcmp(args[0], "создать") == 0 && i >= 3) {
            fs_create_new_file(args[1], args[2], "data.fs");
            printf("Файл '%s' создан.\n", args[1]);
        }
        else if (strcmp(args[0], "удалить") == 0 && i >= 2) {
            fs_delete_file("data.fs", args[1]);
            printf("Файл '%s' удален.\n", args[1]);
        }
        else if (strcmp(args[0], "изменить") == 0 && i >= 3) {
            fs_modify_file(args[1], args[2], "data.fs", "data.fs");
            printf("Файл '%s' изменен.\n", args[1]);
        }
        else if (strcmp(args[0], "посмотреть") == 0 && i >= 2) {
            char* content = fs_view_file("data.fs", args[1]);
            if (content) {
                printf("< %s\n", content);
                free(content);
            } else {
                printf("Файл не найден.\n");
            }
        }
        else if (strcmp(args[0], "выход") == 0) {
            break;
        }
        else {
            printf("Неверная команда. Введите 'помощь' для списка команд.\n");
        }
    }

    return 0;
}
