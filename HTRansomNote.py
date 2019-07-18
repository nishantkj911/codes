#!/bin/python3

import math
import os
import random
import re
import sys

x = 257

def calcHashes(magazine):
    arr = {}
    temp = 0
    assert isinstance(magazine[0], str)
    for word in magazine:
        for i in range(len(word)):
            temp = ((temp + (i+1) * ord(word[i])) * x)
        # print(temp)
        temp %= 1000000007
        arr[word] = temp

    return arr

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    # magHash = calcHashes(magazine)
    magArr = [0 for i in range(len(magazine))]
    # print(magHash)
    # noteHash = calcHashes(note)
    # print(noteHash)
    for word in note:
        # print("checking " + word)
        if(word in magazine and magArr[magazine.index(word)] == 0):
            magArr[magazine.index(word)] = 1
            # print(word + " found in magazine")
        else:
            # print(word + " not found")
            print("No")
            return
    
    print("Yes")
    return


if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)
