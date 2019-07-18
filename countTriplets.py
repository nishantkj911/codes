#!/bin/python3

import math
import os
import random
import re
import sys
import collections

# Complete the countTriplets function below.


def countTriplets(arr, r):

    noOfTriplets = 0
    rightDict = dict(collections.Counter(arr))
    leftDict = {}
    for val in arr:
        rightDict[val] -= 1
        if rightDict[val] == 0:
            rightDict.pop(val)

        if val // r in leftDict and val * r in rightDict:
            # print("value = ", val)
            noOfTriplets += leftDict[val // r] * rightDict[val * r]

        if val not in leftDict:
            leftDict.update({val: 1})
        else:
            leftDict[val] += 1

        """ print("Left Dict: ", leftDict)
        print("Right Dict: ", rightDict) """

    return noOfTriplets


""" 
giving timeout for cases 4 to 10 excl. 8
O(n2)
def countTriplets(arr, r):
    noOfTriplets = 0
    myDict = dict(collections.Counter(arr))
    keys = list(myDict.keys())
    if r == 1:
        for i in range(len(keys)):
            n = myDict[keys[i]]
            n = (n * (n-1) * (n-2)) // 6
            noOfTriplets += max([n, 0])

        return noOfTriplets

    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] * r == arr[j]:
                dict2 = dict(collections.Counter(arr[j+1:]))
                try:
                    no = dict2[arr[j] * r]
                except:
                    continue
                noOfTriplets += no
    return noOfTriplets """


if __name__ == '__main__':
    fptr = open("abc.txt", 'w')

    nr = input().rstrip().split()

    n = int(nr[0])

    r = int(nr[1])

    arr = list(map(int, input().rstrip().split()))

    ans = countTriplets(arr, r)

    fptr.write(str(ans) + '\n')

    fptr.close()
