def max(list):
    big = list[0]
    i = 1
    while i < len(list):
        if big < list[i]:
            big = list[i]
        i+=1
    return big

print(max([1,2,3,4]))
#上面是自己写的非递归版本
#下面是答案递归版本，牛比
def max1(list):
    if len(list) == 2:
        return list[0] if list[0] > list[1] else list[1]
    sub_max = max(list[1:])
    return list[0] if list[0] > sub_max else sub_max

print(max1([1,2,3,4]))
