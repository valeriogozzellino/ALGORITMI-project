#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int k;
    double integer1_time;
    double integer2_time;
    double float_time;
    double string_time;
} TestData;

void draw_bar_chart(TestData* data, int num_tests) {
    int i, j;
    const int bar_width = 40;

    printf("Efficienza dell'algoritmo in base a k:\n");

    for (i = 0; i < num_tests; i++) {
        printf("k = %d\n", data[i].k);
        printf("Integer1: ");
        for (j = 0; j < (int)(data[i].integer1_time * bar_width); j++) {
            printf("#");
        }
        printf(" %d\n", (int)(data[i].integer1_time * bar_width));

        printf("Integer2: ");
        for (j = 0; j < (int)(data[i].integer2_time * bar_width); j++) {
            printf("#");
        }
        printf(" %d\n", (int)(data[i].integer2_time * bar_width));

        printf("Float:    ");
        for (j = 0; j < (int)(data[i].float_time * bar_width); j++) {
            printf("#");
        }
        printf(" %d\n", (int)(data[i].float_time * bar_width));

        printf("String:   ");
        for (j = 0; j < (int)(data[i].string_time * bar_width); j++) {
            printf("#");
        }
        printf(" %d\n", (int)(data[i].string_time * bar_width));

        printf("\n");
    }
}

int main() {
    const int num_tests = 5;
    TestData data[num_tests];

    // Populating test data
    data[0].k = 10;
    data[0].integer1_time = 0.787035;
    data[0].integer2_time = 1.188323;
    data[0].float_time = 1.214796;
    data[0].string_time = 1.840879;

    data[1].k = 50;
    data[1].integer1_time = 0.894251;
    data[1].integer2_time = 1.425659;
    data[1].float_time = 1.413704;
    data[1].string_time = 2.259132;

    data[2].k = 100;
    data[2].integer1_time = 0.992230;
    data[2].integer2_time = 0.992230;
    data[2].float_time = 1.703707;
    data[2].string_time = 2.388913;

    data[3].k = 150;
    data[3].integer1_time = 1.120134;
    data[3].integer2_time = 1.937940;
    data[3].float_time = 1.966621;
    data[3].string_time = 2.718319;

    data[4].k = 200;
    data[4].integer1_time = 1.117166;
    data[4].integer2_time = 1.948400;
    data[4].float_time = 1.960602;
    data[4].string_time = 2.865065;

    draw_bar_chart(data, num_tests);

    return 0;
}
