#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    swaps = 0
    print(arr)
    for i in range(len(arr)):
        if arr[i] != i+1:
            temp = arr.index(i+1)
            arr[temp], arr[i] = arr[i], arr[temp]
            swaps += 1

    return swaps


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
