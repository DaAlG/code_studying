import sys
import heapq

INF = int(1e9)
input = sys.stdin.readline

def dijkstra(start,N,K,graph,distance):
  q = []
  
  heapq.heappush(q,(0,start))
  distance[start] = 0

  while q:
    dist, now = heapq.heappop(q)
    if distance[now] < dist:
      continue
    
    for i in graph[now]:
      cost = dist + i[1]
      if cost<distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q,(cost, i[0]))


def solution(N, road, K):
  graph = [[] for i in range(N+1)]
  distance = [INF]*(N+1)

  for i in range(len(road)):
    a,b,c = road[i]
    graph[a].append((b,c))
    graph[b].append((a,c))
  start = 1

  dijkstra(start,N,K,graph,distance)
  
  cnt = N
  # print(distance)
  # print(graph)
  for i in range(1,N+1):
    if distance[i] > K:
      cnt -= 1

  return cnt 

# N = 5
# road = [[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]
# K = 3

# print(solution(N, road, K))