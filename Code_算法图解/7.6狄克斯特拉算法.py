graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2
'''
print(graph["start"].keys())
print (graph["start"]["a"])
print (graph["start"]["b"])
'''
graph["a"] = {}
graph["a"]["fin"] = 1

graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["fin"] = 5

graph["fin"] = {}
#表示无穷大
infinity = float("inf")
#开销散列表
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity
#父节点散列表
parents = {}
parents["a"] = "start"
parents["b"] = "start"
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
#通过list将字典中的keys和values转化为列表
#values = list(parents.values())
#无语啦processed[]就是给出的路线啊=。=

print("起点到终点最短路径的总权重是："+str(costs["fin"]))
#print("最优路径是：start→"+str(processed[])+"→"+str(values[-2] )+"→终点")
print("起点到终点最短路径的总权重是：%s"%(costs["fin"]))
#%s字符串 %d整型数据
#print("xxx", end=' ')指定属性不换行
# 打印最优路径
print("最优路径是：start",end='')
for i in processed:    
    print("→%s"%i, end='')
    












