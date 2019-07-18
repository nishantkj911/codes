#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the freqQuery function below.


def freqQuery(queries):

    arrOP = []
    myDict = {}
    noOfIncrements = 0
    for row in queries:

        if row[0] == 1:
            noOfIncrements+=1
            if row[1] in myDict:
                myDict[row[1]] += 1
            else:
                myDict[row[1]] = 1

        elif row[0] == 2:
            noOfIncrements -= 1
            try:
                myDict[row[1]] -= 1
                if myDict[row[1]] == 0:
                    myDict.pop(row[1])
            except:
                pass
                # print("Exception encountered")

        elif row[0] == 3 and noOfIncrements > row[1]:
            arrs = list(myDict.values())
            temp = row[1] in arrs
            if temp == True:
                arrOP.append(1)
            else:
                arrOP.append(0)

        # print(myDict)
    return arrOP


if __name__ == '__main__':
    # fptr = open("abc.txt", 'w')
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    ans = freqQuery(queries)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()
