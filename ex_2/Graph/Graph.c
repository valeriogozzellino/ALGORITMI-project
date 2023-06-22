#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int max_height;
    double sorting_time;
} TestData;

void draw_graph(TestData* data, int num_tests) {
    int i;
    const int max_width = 50;

    printf("Efficienza dell'algoritmo in base a max_height:\n\n");

    for (i = 0; i < num_tests; i++) {
        printf("%-3d |", data[i].max_height);

        if (data[i].sorting_time > 20.0) {
            printf("............> time = %.2f (not good)\n", data[i].sorting_time);
            printf("\n");
        } else {
            double bar_ratio = data[i].sorting_time / 0.03;
            int num_points = (int)(bar_ratio);

            int j;
            for (j = 0; j < num_points; j++) {
                printf(".");
            }

            printf("Rating: %d (%f)\n", num_points, data[i].sorting_time);
            printf("\n");
        }
    }
}

int main() {
    const int num_tests = 30;
    TestData data[num_tests];

    // Populating test data
    data[0].max_height = 10;
    data[0].sorting_time = 102.918764;

    data[1].max_height = 11;
    data[1].sorting_time = 4.455456;

    data[2].max_height = 12;
    data[2].sorting_time = 23.701403;

    data[3].max_height = 13;
    data[3].sorting_time = 1.186649;

    data[4].max_height = 14;
    data[4].sorting_time = 3.554731;

    data[5].max_height = 15;
    data[5].sorting_time = 0.597735;

    data[6].max_height = 16;
    data[6].sorting_time = 0.998677;

    data[7].max_height = 17;
    data[7].sorting_time = 0.519251;

    data[8].max_height = 18;
    data[8].sorting_time = 0.704333;

    data[9].max_height = 19;
    data[9].sorting_time = 0.517249;

    data[10].max_height = 20;
    data[10].sorting_time = 0.581874;

    data[11].max_height = 21;
    data[11].sorting_time = 0.512013;

    data[12].max_height = 22;
    data[12].sorting_time = 0.581350;

    data[13].max_height = 23;
    data[13].sorting_time = 0.505698;

    data[14].max_height = 24;
    data[14].sorting_time = 0.568175;

    data[15].max_height = 25;
    data[15].sorting_time = 0.523213;

    data[16].max_height = 26;
    data[16].sorting_time = 0.583792;

    data[17].max_height = 27;
    data[17].sorting_time = 0.511100;

    data[18].max_height = 28;
    data[18].sorting_time = 0.561899;

    data[19].max_height = 29;
    data[19].sorting_time = 0.508992;

    data[20].max_height = 30;
    data[20].sorting_time = 0.576566;

    data[21].max_height = 50;
    data[21].sorting_time = 0.412708;

    data[22].max_height = 60;
    data[22].sorting_time = 0.402586;

    data[23].max_height = 70;
    data[23].sorting_time = 0.399046;

    data[24].max_height = 80;
    data[24].sorting_time = 0.409580;

    data[25].max_height = 90;
    data[25].sorting_time = 0.409747;

    data[26].max_height = 100;
    data[26].sorting_time = 0.409180;

    data[27].max_height = 150;
    data[27].sorting_time = 0.398509;

    data[28].max_height = 200;
    data[28].sorting_time = 0.405981;

    data[29].max_height = 300;
    data[29].sorting_time = 0.39614;

    draw_graph(data, num_tests);

    return 0;
}
