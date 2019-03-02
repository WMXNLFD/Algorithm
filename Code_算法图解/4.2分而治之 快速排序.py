def quicksort(array):
    if len(array) < 2:
        return array
    else:        
        pivot = array[0]
        '''        
        for i in array[1:]:
            if i <= pivot:
                less = [i]   #这样做是错的 less无法递归
        '''
        less = [i for i in array[1:] if i<=pivot]        
        greater = [i for i in array[1:] if i>pivot]      
        return  quicksort(less) + [pivot] + quicksort(greater)

print(quicksort([10,5,2,3]))
print(quicksort([10,5,2,3,11,15,12]))
        
         
        
        
        
