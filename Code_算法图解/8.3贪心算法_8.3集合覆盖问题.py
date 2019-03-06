#传入一个数组，他被转换为集合
states_needed = set(["mt","wa","or","id","nv", "ut","ca", "az"])
#可供选择的广播台清单，用散列表
#键为广播台的名称，值为广播台覆盖的州
stations = {}
stations["kone"] = set(["id","nv","ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])
#储存最终选择的广播台
final_stations = set()

#循环，直到states_needed为空
while states_needed:
    #选择覆盖了最多的未覆盖州的广播台
    best_station = None
    states_covered = set()
    for station,states_for_station in stations.items():
        #计算交集
        covered = states_needed & states_for_station    
        if len(covered) > len(states_covered):
            best_station = station
            states_covered = covered
            
    states_needed -= states_covered
    final_stations.add(best_station)

print(final_stations)


  
        








        
