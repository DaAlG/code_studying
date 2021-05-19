from collections import deque

n,m,v = map(int, input().split())
graph = [[] for i in range(n+1)]
for i in range(m):
  x,y = map(int, input().split())
  graph[x].append(y)
  graph[y].append(x)

visited_dfs = [0]*(n+1)
# print(visited_dfs)
visited_dfs[v] = 1

for i in range(n):
  graph[i].sort()

def dfs(graph, v, visited):
  visited[v] = True
  print(v, end=" ")
  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)

dfs(graph, v, visited_dfs)
print()

visited_bfs = [0]*(n+1)
queue = deque()
queue.append(v)
visited_bfs[v] = 1

while(queue):
  now = queue.popleft()
  print(now, end=" ")
  for i in graph[now]:
    if not visited_bfs[i]:
      queue.append(i)
      visited_bfs[i] = 1
      # break
