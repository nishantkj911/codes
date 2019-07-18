#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIG_PRIME 1000000007
#define x 257

char* readline();
char** split_string(char*);

long calcHashValue(char *word)
{
    int hashValue = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashValue = ((hashValue + i * word[i]) * x) % BIG_PRIME;
    }

    return hashValue;
}

// Complete the checkMagazine function below.
void checkMagazine(int magazine_count, char** magazine, int note_count, char** note) {

    int *mag_arr = calloc(magazine_count, sizeof(int));
    long *mag_hash = calloc(magazine_count, sizeof(long));
    

    for (int i = 0; i < magazine_count; i++)
    {
        mag_hash[i] = calcHashValue(magazine[i]);
    }

    for (int i = 0; i < note_count; i++)
    {
        long tempHash = calcHashValue(note[i]);
        int matchFound = 0;
        for (int j = 0; j < magazine_count; j++)
        {
            long tempHash2 = mag_hash[j];
            if(tempHash == tempHash2 && strcmp(note[i], magazine[j]) == 0 && mag_arr[j] != 1)
            {
                matchFound = 1;
                mag_arr[j] = 1;
                break;
                // printf("Found match for %s with %s\n", note[i], magazine[j]);
            }
        }

        if(!matchFound)
        {
            printf("No\n");
            return;
        }
    }

    printf("Yes\n");
}

/* int main()
{
    char** mn = split_string(readline());

    char* m_endptr;
    char* m_str = mn[0];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n_endptr;
    char* n_str = mn[1];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** magazine_temp = split_string(readline());

    char** magazine = malloc(m * sizeof(char*));

    for (int i = 0; i < m; i++) {
        char* magazine_item = *(magazine_temp + i);

        *(magazine + i) = magazine_item;
    }

    int magazine_count = m;

    char** note_temp = split_string(readline());

    char** note = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* note_item = *(note_temp + i);

        *(note + i) = note_item;
    }

    int note_count = n;

    checkMagazine(magazine_count, magazine, note_count, note);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

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
 */

int main()
{
    char *word1, *word2;
    scanf("%s", word1);
    scanf("%s", word2);

    printf("The hash values of %s and %s is %i and %i resp.\n", word1, word2, calcHashValue(word1), calcHashValue(word2));
}