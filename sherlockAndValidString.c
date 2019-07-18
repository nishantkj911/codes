#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();

// Complete the isValid function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char *isValid(char *s)
{
    int *arr = calloc(26, sizeof(int));

    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        arr[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

    int max = -1, oneChanceGiveFlag = 0, secMax = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
        {
            printf("Checking for %c\n", i + 'a');
            if (max < 0) //executes once for the first time it encounters a letter
            {
                max = arr[i];
                // printf("max: %i\n", max);
            }
            else if (arr[i] == 1 && !oneChanceGiveFlag)
            {
                oneChanceGiveFlag = 1;
                secMax = -1;
                continue;
            }
            else if (arr[i] == max - 1 || max == 1)
            {
                if (secMax == 0)
                {
                    printf("Let's see if we get max - 1 or another max again\n");
                    if (max != 1)
                    {
                        secMax = 1;
                    }
                    else
                    {
                        secMax = arr[i];
                    }
                }
                else if (secMax == -1)
                {
                    printf("Encountered max - 1 twice or once after max occurring twice\n");
                    return "NO";
                }
                else if (secMax >= 1)
                {
                    printf("Yes we did so now changing max to max - 1\n");
                    if (max > 1)
                    {
                        max--;
                        oneChanceGiveFlag = 1;
                        secMax = -1;
                    }
                    else if (arr[i] == secMax)
                    {
                        max = arr[i];
                        secMax = -1;
                        oneChanceGiveFlag = 1;
                    }
                    else
                    {
                        printf("Already given one chance, now bye\n");
                        return "NO";
                    }
                }
            }
            else if (arr[i] == max || arr[i] == max + 1)
            {
                // printf("MAX\n");
                if (max != 2)
                {
                    if (secMax == 1)
                    {
                        printf("Not the same as the max ones\n");
                        return "NO";
                    }
                    else
                    {
                        secMax = -1;
                    }
                }

                if (arr[i] == max + 1 && !oneChanceGiveFlag)
                {
                    oneChanceGiveFlag = 1;
                    secMax = -1;
                    printf("Found one max + 1\n");
                }
                else if (arr[i] == max + 1 && secMax > 0)
                {
                    printf("values vary from max - 1 to max + 1\n");
                    return "NO";
                }
                else if (arr[i] == max)
                {
                    continue;
                }
                else if (max == 1)
                {
                    max = 2;
                }
                else
                {
                    printf("Encountered multiple max + 1 letters at letter '%c'\n", i + 'a');
                    return "NO";
                }
            }
            
            else
            {
                printf("Not the same as the max ones at letter '%c'\n", i + 'a');
                return "NO";
            }
        }
    }

    printf("max: %i\n", max);
    return "YES";
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char *s = readline();

    char *result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data)
        {
            break;
        }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
