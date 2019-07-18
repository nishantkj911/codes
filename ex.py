arr = [1, 2, 3, 2, 1, 1, 2, 2, 3, 3, 2, 1 ,2, 3]
myDict = {}
for i in arr:
    try:
        myDict[i] += 1 
    except KeyError:
        myDict.update({i:1})

print(myDict)
print(arr.index(3))

myTime = Time