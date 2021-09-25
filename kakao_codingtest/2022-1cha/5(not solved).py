from collections import defaultdict

edges_info = defaultdict(list)
visit = []
nodes = []
def dfs(root, info):
  global nodes, visit, edges_info, max_cnt
  for child in edges_info[root]:
    tmp_child_nodes_0 = nodes[root][0]
    tmp_child_nodes_1 = nodes[root][1]
    if not visit[child]:
      if info[child] == 0:
        tmp_child_nodes_0 = tmp_child_nodes_0 + 1
      elif info[child] == 1:
        tmp_child_nodes_1 = tmp_child_nodes_1 + 1
        
    if tmp_child_nodes_0 > tmp_child_nodes_1:
      nodes[child][0] = tmp_child_nodes_0
      nodes[child][1] = tmp_child_nodes_1
      visit[child] = True
      tmp = dfs(child, info)
      if nodes[root][0] - nodes[root][1] <= tmp[0] - tmp[1]:
        nodes[root][0], nodes[root][1] = tmp[0], tmp[1]
    
  return [nodes[root][0], nodes[root][1]]
  
def solution(info, edges):
  answer = 0
  global nodes, visit, edges_info
  nodes = [[0,0] for _ in range(len(info))]
  visit = [False for _ in range(len(info))]
  nodes[0] = [1,0] # nodes : [양, 늑대]
  visit[0] = True
  for edge in edges:
    u, v = edge[0], edge[1]
    edges_info[u].append(v)
  
  while True:
    origin_nodes = nodes[0][:]
    new_nodes = dfs(0, info)
    
    # for idx, value in enumerate(nodes):
    #   print(idx, ":", value)
    # print("try more!")
    if new_nodes[0] - new_nodes[1] > origin_nodes[0] - origin_nodes[1]:
      continue
    elif new_nodes[0] - new_nodes[1] == origin_nodes[0] - origin_nodes[1] and new_nodes[0] > origin_nodes[0]:
      continue
    else:
      break
  
  answer = max([node[0] for node in nodes])
  return answer

# print(solution([0,0,1,1,1,0,1,0,1,0,1,1], [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))
print(solution([0,1,0,1,1,0,1,0,0,1,0], [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[4,8],[6,9],[9,10]]))
# print(solution([0,1,1,0,0,0,0,0,0,0,1], [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[4,8],[6,9],[9,10]]))