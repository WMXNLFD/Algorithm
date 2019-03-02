from collections import deque

def search(name):    
    search_queue = deque()
    search_queue += graph[name]
    #这个数组用于记录检查过的人
    searched = []
    while search_queue:
        #取出第一个人
        person = search_queue.popleft()
        #仅当这个人没检查过时才检查
        if not person in searched:
            #检查是否芒果商
            if person_is_seller(person):
                print (person + " is a mango seller")
                return True                
            else:
                #继续搜索s_q = s_q + graph[person] 后面一项是person的邻居
                search_queue +=graph[person]
                #将这个人标记为检查过
                searched.append(person)
    print("not found")
    return False
    
def person_is_seller(name):
    return name[-1] == 'm'

#测试
graph ={}
graph["you"] = ["alice","bob","c"]
graph["alice"] =[]
graph["bob"] = []
graph["c"] = []
search("you")



