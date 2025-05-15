#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "app.h"


void print_menu() {
    printf("Выберите операцию:\n");
    printf("1. Перекодировать в верхний регистр\n");
    printf("2. Перекодировать в нижний регистр\n");
    printf("3. Получить подстроку\n");
    printf("4. Конкатенация строк\n");
    printf("5. Запустить тесты\n");
    printf("0. Выход\n");
}

int main (void) {
    setlocale(LC_ALL, "Rus");
    char input[256], operation[30], start[30], end[30];
    int c, i, j, flag;
    string str1, str2;
    while (1) {
        print_menu();
        fgets(operation, 30, stdin);
        while (operation[0] != '0' & operation[0] != '1' & operation[0] != '2' & 
                operation[0] != '3' & operation[0] != '4' & operation[0] != '5' || operation[1] != '\n') {
            printf("Нет такой операции!\n");
            print_menu();
            fgets(operation, 30, stdin);
        }
        if (operation[0] == '0') {
            printf("Завершение работы");
            break;
        } else if (operation[0] == '5') {
            run_tests();
        } else {
            while (1) {
                printf("Введите строку: ");
                fgets(input, 256, stdin);
                input[strlen(input)-1] = 0;
                if (strlen(input) != 0) {
                    break;
                }
            }
            if (operation[0] == '1') {
                str1 = new(input);
                printf("Ваш результат: %s\n", upper(str1).data);
            } else if (operation[0] == '2') {
                str1 = new(input);
                printf("Ваш результат: %s\n", lower(str1).data);
            } else if (operation[0] == '3') {
                str1 = new(input);
                while (1) {
                    while (1) {
                        printf("Введите начальный индекс: ");
                        fgets(start, 30, stdin);
                        flag = 1;
                        for (c = 0; c < strlen(start)-1; c++) {
                            if (!isdigit(start[c])) {
                                printf ("Это не целое положительное число!\n");
                                flag = 0;
                                break;
                            }
                        }
                        if (flag) {
                            break;
                        }
                    }
                    i = atoi(start);
                    while (1) {
                        printf("Введите конечный индекс: ");
                        fgets(end, 30, stdin);
                        flag = 1;
                        for (c = 0; c < strlen(end)-1; c++) {
                            if (!isdigit(end[c])) {
                                printf ("Это не целое положительное число!\n");
                                flag = 0;
                                break;
                            }
                        }
                        if (flag) {
                            break;
                        }
                    }
                    j = atoi(end);
                    if (0 <= i & i <= j & j < str1.len) {
                        break;
                    } else {
                        printf("Неверные индексы!\n");
                    }
                }
                printf("Ваш результат: %s\n", substring(str1, i, j).data);
            } else if (operation[0] == '4') {
                str1 = new(input);
                printf("Введите вторую строку: ");
                fgets(input, 256, stdin);
                input[strlen(input)-1] = 0;
                str2 = new(input);
                printf("Ваш результат: %s\n", concatenation(str1, str2).data);
                clear(&str2);
            }
            clear(&str1);
        }
        printf("\n");
    }
    return 0;
}
