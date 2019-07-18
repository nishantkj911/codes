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
    int *str1 = calloc(26, sizeof(int));
    int different = 0;
    char *ans;
    int k = 1, flag = 0, num1 = 1, num2 = 0;
    int len = strlen(s);

    if (len == 1)
        return "YES";

    for (int i = 0; i < len; i++)
    {
        str1[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) //print freq dict
    {
        if (str1[i])
            printf("\n%c:%d", i + 'a', str1[i]);
    }

    while (k < len)
    {
        if (str1[s[0] - 'a'] != str1[s[k] - 'a'])
        {
            printf("bruh");
            flag = 1;
            break;
        }
        k++;
    }
    printf("\nlen: %d", len);

    if (!flag)
        return "YES";
    for (int i = 1; i < len; i++)
    {
        if (str1[s[i] - 'a'] == str1[s[0] - 'a'])
            num1++;
        else if (str1[s[i] - 'a'] == str1[s[k] - 'a'])
        {
            num2++;
            printf("\ns[k]: %c\ts[i]: %c\n,i:%d", s[k], s[i], i);
        }
        else
        {

            ans = "NO";

            return ans;
        }
    }
    printf("num1:%d,num2:%d", num1, num2);

    if (num1 == 1)
        return "YES";
    if (num2 == 1)
        return "YES";
    if (str1[s[k] - 'a'] == num2)
    {
        if (str1[s[k] - 'a'] - str1[s[0] - 'a'] == 1)
            return "YES";
    }
    if (str1[s[0] - 'a'] == num1)
    {
        if (str1[s[0] - 'a'] - str1[s[k] - 'a'] == 1)
            return "YES";
    }

    return "NO";
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
