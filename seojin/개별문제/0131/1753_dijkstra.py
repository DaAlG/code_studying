import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

v,e = map(int, input().split())
k = int(input())
# 정점, 간선 정보 담을 그래프
# 정점 개수만큼 만들어야하는데 1~v까지 쓸거라서 v+1
graph = [[] for i in range(v+1)]
for i in range(e):
  a,b,c = map(int,input().split())
  # a -> b로 가는데 드는 비용 = c
  graph[a].append((b,c))
distance = [INF]*(v+1)  


def dijkstra(start):
  q = []
  # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여 큐에 삽입
  # start가 1이었다면 1(나 자신)까지의 최단경로는 0
  distance[start] = 0
  heapq.heappush(q, (0,start))
  cost = 0
  # 이제 시작이야~
  while q:
    # q인 힙에서 pop
    edge, vert = heapq.heappop(q)

    # 이미 한 번 본거면
    if distance[vert] < edge:
      continue

    # vert에 연결되어 있는 애들
    for i in graph[vert]:
      cost = edge + i[1] 

      # 원래보다 더 빨리 갈 수 있으면
      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q,(cost, i[0]))

# 시작노드 = k
dijkstra(k)

for i in range(1, v+1):
  if distance[i] == INF:
    print("INF")
  else:
    print(distance[i])