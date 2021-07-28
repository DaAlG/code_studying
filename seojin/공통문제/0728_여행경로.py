from collections import defaultdict

INF = int(1e9)
routes = defaultdict(list) # 연결리스트처럼 만들 수 있음.
res = []

def dfs(i):
  global routes, res
  while routes[i]:
    dfs(routes[i].pop(0)) # 알파벳 순서로 정렬된 상태니까 앞에꺼 먼저.
  res.append(i)
  

def solution(tickets):
  for key, value in sorted(tickets):
    # print(key, value)
    routes[key].append(value)
  
  dfs("ICN")

  return res[::-1]

