# 다익스트라로 시작점->모든 노드에 대한 거리 구해서 최단거리가 k인 애들만 찾자
import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

n,m,k,x = map(int,input().split())
graph = [[] for _ in range(n+1)]
for i in range(m):
  a,b = map(int,input().split())
  graph[a].append((b,1))
distance = [INF]*(n+1)

def dist(start):
  q = []
  heapq.heappush(q,(0, start))
  distance[start] = 0

  while q:
    dist, now = heapq.heappop(q)

    # 무시
    if distance[now] < dist:
      continue

    for i in graph[now]:
      cost = dist + i[1]
      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q, (cost,i[0]))


dist(x)

flag =  0
for i in range(1, n+1):
  if distance[i] == k:
    print(i)
    flag = 1

if flag == 0:
  print(-1)
  

      