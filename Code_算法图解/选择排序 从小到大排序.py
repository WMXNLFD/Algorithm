def findSmallest(arr):
    smallest = arr[0] #先假设第一个值最小
    smallest_index = 0
    for i in range(1,len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index #返回索引

def selectionSort(arr):
    newArr = []
    for i in range(len(arr)):
        smallest = findSmallest(arr)
        #找出最小值，并加入新数组中
        newArr.append(arr.pop(smallest))
    return newArr

print (selectionSort([5,3,6,2,10]))
    
        
    
