#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Complete the minimumBribes function below.
void minimumBribes(int q_count, int* q) 
{
    int bribeDetected, noOfBribes = 0;
    do
    {
        bribeDetected = 0;
        for (int i = 0; i < q_count - 1; i++)
        {
            if(q[i] > q[i+1])
            {
                if(q[i] - 1 - i > 2)
                {
                    printf("Too chaotic\n");
                    return;
                }
                bribeDetected = 1;
                noOfBribes++;
                swap(&q[i], &q[i+1]);
            }
        }

    } while(bribeDetected);

    printf("%i\n", noOfBribes);
}

int main()
{
    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char** q_temp = split_string(readline());

        int* q = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            char* q_item_endptr;
            char* q_item_str = *(q_temp + i);
            int q_item = strtol(q_item_str, &q_item_endptr, 10);

            if (q_item_endptr == q_item_str || *q_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(q + i) = q_item;
        }

        int q_count = n;

        minimumBribes(q_count, q);
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
