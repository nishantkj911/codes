def merge(arr, left, middle, right):
    tempArr = []
    i, j = left, middle
    while i < middle and j < right:
        if arr[i] < arr[j]:
            tempArr.append(arr[i])
            i += 1
        else:
            tempArr.append(arr[j])
            j += 1

    while i < middle:
        tempArr.append(arr[i])

    while j < right:
        tempArr.append(arr[j])

    arr[left:right] = tempArr

def mergeSort(arr, i, j):
    print("i:", i, "\tj:", j)

    if i < j:
        middle = (i + j) // 2
        mergeSort(arr, i, middle)
        mergeSort(arr, middle + 1, j)
        merge(arr, i, middle, j)

    return arr


mergeSort([100 - i for i in range(100)], 0, 99)
print(arr)