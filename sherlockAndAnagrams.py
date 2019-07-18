#!/bin/python3

import math
import os
import random
import re
import sys
import collections

"""
Working but naive soln. of the same problem
def toSortedString(str1):
    str2 = list(str1)
    str2.sort()
    final = ""
    for substr in str2:
        final += substr

    return final

def checkAnagrams(str1, str2):
    assert isinstance(str1, str)
    assert isinstance(str2, str)

    if toSortedString(str1) == toSortedString(str2):
        return True

    return False


def sherlockAndAnagrams(s):
    pass
    strlen = len(s)
    noOfAnagrams = 0
    # loop for setting the length of the substring
    for tempLen in range(1, strlen):
        for startIndex in range(strlen - tempLen + 1):
            for secondStartIndex in range(startIndex + 1, strlen - tempLen + 1):
                if checkAnagrams(s[startIndex:startIndex + tempLen], s[secondStartIndex: secondStartIndex + tempLen]) == True:
                    noOfAnagrams += 1
                else:
                    print(s[startIndex:startIndex + tempLen],
                      s[secondStartIndex: secondStartIndex + tempLen])

    return noOfAnagrams
"""


# not working for cases 4 and 5 due to timeout
# Complete the sherlockAndAnagrams function below.
def sherlockAndAnagrams(s):
    strlen = len(s)
    print(strlen)
    noOfAnagrams = 0

    for tempLen in range(1, strlen):  # loop for setting the length of the substring
        bigDict = {}
        for startIndex in range(strlen - tempLen + 1):
            substr = s[startIndex:startIndex + tempLen]

            flag = False

            for string in bigDict.keys():
                # print(bigDict)
                if tempLen == 1 and string == substr or tempLen > 1 and collections.Counter(string) == collections.Counter(substr):
                    bigDict[string] += 1
                    print(string, substr)
                    flag = True

            if flag == False:
                bigDict.update({substr: 1})

        print(bigDict)
        for val in bigDict.values():
            if val > 1:
                noOfAnagrams += (val * (val - 1)) // 2

        print(noOfAnagrams)

    return noOfAnagrams


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = sherlockAndAnagrams(s)

        fptr.write(str(result) + '\n')

    fptr.close()
