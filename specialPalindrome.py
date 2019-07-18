#!/bin/python3

import math
import os
import random
import re
import sys
import collections      

# Complete the substrCount function below.
def substrCount(n, s):
    noOfSpPal = 0

    for i, char in enumerate(s):
        print("single char")
        noOfSpPal+=1
        leftOddIndex = rightOddIndex = i
        middleChar = char
        while True:
            
            print("middle character: ", middleChar)
            print(leftOddIndex, rightOddIndex)
            # even part
            if rightOddIndex + 1 < n and s[rightOddIndex + 1] == middleChar:
                print(s[leftOddIndex:rightOddIndex+2], "accepted")
                noOfSpPal += 1
            
            """ if leftOddIndex - 1 >= 0 and s[leftOddIndex - 1] == middleChar:
                print(s[leftOddIndex - 1:rightOddIndex+1], "accepted")
                noOfSpPal += 1 """
            

            # odd part
            leftOddIndex -= 1
            rightOddIndex += 1
            if leftOddIndex < 0 or rightOddIndex > n-1:
                break
            if s[rightOddIndex] == s[leftOddIndex]:
                if rightOddIndex - leftOddIndex == 2:
                    middleChar = s[rightOddIndex]
                    print(s[leftOddIndex:rightOddIndex+1], "accepted")
                    noOfSpPal+=1
                    continue
                elif s[rightOddIndex] == middleChar:
                    print(s[leftOddIndex:rightOddIndex+1], "accepted")
                    noOfSpPal += 1
                    continue
                else:
                    print(s[leftOddIndex:rightOddIndex+1])
                    break
            else:
                print(s[leftOddIndex:rightOddIndex+1])
                break

    return noOfSpPal

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr = open("abc.txt", "w")

    n = int(input())

    s = input()

    result = substrCount(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
