#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.


def arrayManipulation(n, queries):
    arr = [0 for i in range(n+2)]
    # print(arr)
    for row in queries:
        # print(row)
        arr[row[0]] += row[2]
        try:
            arr[row[1] + 1] += -row[2]
        except IndexError:
            print("Query where end is the last index")

    temp = 0
    maxArr = 0
    for i in arr:
        temp += i
        if temp > maxArr:
            maxArr = temp

    return maxArr


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')
    # print(str(result) + '\n')
    fptr.close()
