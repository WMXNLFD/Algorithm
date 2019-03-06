graph = {}
graph["start"] = {}
graph["start"]["a"] = 5
graph["start"]["b"] = 2

'''
print(graph["start"].keys())
print (graph["start"]["a"])
print (graph["start"]["b"])
'''
graph["a"] = {}
graph["a"]["c"] = 4
graph["a"]["d"] = 2

graph["b"] = {}
graph["b"]["a"] = 8
graph["b"]["d"] = 7

graph["c"] = {}
graph["c"]["d"] = 6
graph["c"]["fin"] = 3

graph["d"] = {}
graph["d"]["fin"] = 1
#终点没有任何邻居
graph["fin"] = {}
#表示无穷大
infinity = float("inf")
#开销散列表
costs = {}
costs["a"] = 5
costs["b"] = 2
costs["c"] = infinity
costs["d"] = infinity
costs["fin"] = infinity
#父节点散列表
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["c"] = None
parents["d"] = None
parents["fin"] = None
#记录处理过的节点 这里是方括号
processed = []

def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node

# 找到最短路径
def find_shortest_path():
    node = "fin"
    shortest_path = ["fin"]
    while parents[node] != "start":        
        shortest_path.append(parents[node])
        #从后面玩前面递推，和我之前想的一样
        node = parents[node]
    shortest_path.append("start")
    return shortest_path

node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new_cost = cost +neighbors[n]
        if costs[n] > new_cost:
            costs[n] = new_cost
            parents[n] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)
shortest_path = find_shortest_path()
#翻转
shortest_path.reverse()
print(shortest_path)
#循环打印，更加直观
print("最优路径是：",end='')
for i in shortest_path:
    print("→%s"%i,end='')
print("")
#循环打印，更加直观，更加美化(*^__^*)
print("最优路径是：",end='')
for i in shortest_path[:-1]:
    print("%s→"%i,end='')
print("→fin")
    

print("起点到终点最短路径的总权重是："+str(costs["fin"]))

print("起点到终点最短路径的总权重是：%s"%(costs["fin"]))
# 打印最优路径
'''
print("最优路径是：start",end='')
for i in processed:    
    print("→%s"%i, end='')
'''
    
















