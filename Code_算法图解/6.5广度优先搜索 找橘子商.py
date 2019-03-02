from collections import deque
search_queue = deque()
search_queue += graph["you"]

while search_queue:
    #取出第一个人
    person = search_queue.popleft()
    #检查是否芒果商
    if person_is_seller(person):
        print person + "is a mango seller"
        return True
    else:
        #继续搜索s_q = s_q + graph[person] 后面一项是person的邻居
        search_queue +=graph[person]
return False

def person_id_seller(name):
    return name[-1] == 'm'
