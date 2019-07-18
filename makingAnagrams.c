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

// Complete the makeAnagram function below.
int makeAnagram(char *a, char *b)
{
    int l1 = strlen(a);
    int l2 = strlen(b);

    /* if(l1 > l2)
    {
        int temp = l1;
        l1 = l2;
        l2 = temp;

        char *temp2 = a;
        a = b;
        b = temp2;
    }
 */
    int *arr = calloc(26, sizeof(int));
    for (int i = 0; i < l1; i++)
    {
        arr[a[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    for (int i = 0; i < l2; i++)
    {
        arr[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        count += abs(arr[i]);
    }

    return count;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char *a = readline();

    char *b = readline();

    int res = makeAnagram(a, b);

    fprintf(fptr, "%d\n", res);

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

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line)
        {
            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    }
    else
    {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}
