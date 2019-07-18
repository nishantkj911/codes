#!/bin/python3

import math
import os
import random
import re
import sys
import collections

# Complete the commonChild function below.


def commonChild(s1, s2):
    pass
    dict1 = set(s1)
    dict2 = set(s2)

    list1 = list(s1)
    list2 = list(s2)

    inter = dict1.intersection(dict2)
    for i in s1:
        if i not in inter:
            list1.remove(i)

    for i in s2:
        if i not in inter:
            list2.remove(i)

    print(list1)
    print(list2)

    if len(list1) == 0 or len(list2) == 0:
        return 0 
    else:
        pass

    max1 = 0
    if len(list1) > len(list2):
        list1, list2 = list2, list1

    ansList = []
    maxList = []
    for i, char in enumerate(list1):
        tempLen = 1
        ansList = []
        j = list2.index(char)
        ansList.append(list2[j])
        tempIndex = i + 1
        while tempIndex < len(list1):
            try:
                j2 = list2.index(list1[tempIndex], j + 1, len(list2)) 
            except ValueError:
                tempIndex += 1
                continue
            if j > j2:
                pass
            else:
                j = j2
                tempLen += 1
                ansList.append(list1[tempIndex])
            tempIndex += 1
        if tempLen > max1:
            max1 = tempLen
            maxList = ansList

    print(maxList)
    return max1

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr = open("abc.txt", 'w')

    s1 = input()

    s2 = input()

    result = commonChild(s1, s2)

    fptr.write(str(result) + '\n')

    fptr.close()
