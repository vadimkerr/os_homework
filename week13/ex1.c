#include <stdio.h>
#include <stdlib.h>

#define n 5
#define m 3

#define input "input_ok.txt"
#define output "output_ok.txt"


int main() {
    FILE *f = fopen(input, "r");
    if (f == NULL) {
        printf("error while opening file");
        return 1;
    }

    int e[m], a[m];

    for (int i = 0; i < m; i++) {
        fscanf(f, "%d", &e[i]);
    }
    for (int i = 0; i < m; i++) {
        fscanf(f, "%d", &a[i]);
    }

    int c[n][m], r[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &c[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &r[i][j]);
        }
    }

    int is_deadlock = 0;
    int *is_ok = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) is_ok[i] = 0;

    for (int out_loop = 0; out_loop < n; out_loop++) {
        int is_chosen = 0;
        for (int i = 0; i < n; i++) {
            if (is_ok[i]) continue;

            int is_can_run = 1;
            for (int j = 0; j < m && is_can_run; j++) {
                is_can_run = (c[i][j] + a[j] >= r[i][j]);
            }
            if (is_can_run) {
                is_ok[i] = is_chosen = 1;
                for (int j = 0; j < m; j++) {
                    a[j] += c[i][j];
                    c[i][j] = 0;
                }
                break;
            }
        }
        if (!is_chosen) is_deadlock = 1;
    }

    FILE *out = fopen(output, "w");
    if (is_deadlock) {
        fprintf(out, "Deadlock exists with processes ");
        for (int i = 0; i < n; i++) {
            if (!is_ok[i]) fprintf(out, "%d, ", i+1);
        }
        printf("\n");
    } else {
        fprintf(out, "Deadlock doesn't exist");
    }

    fclose(out);

    return 0;
}

