import heapq
import sys

def dijkstra(i,j):
  global dx, dy, graph, distance
  q = []
  heapq.heappush(q,(graph[i][j],(i,j)))
  # distance[i][j] = 0

  while q:
    ruppi, (nowx, nowy) = heapq.heappop(q)
    # print(ruppi, nowx, nowy)
    # 만약 현재 노드가 이미 처리된 적이 있다면 이미 최단거리이므로 무시

    if distance[nowx][nowy] < ruppi:
      # print(3)
      continue

    # 지금 위치에서 상하좌우를 보며
    for i in range(4):
      nx = nowx+dx[i]
      ny = nowy+dy[i]

      if 0<=nx<n and 0<=ny<n:
        cost = ruppi + graph[nx][ny]
        # print("2")
        if cost < distance[nx][ny]:
          # print("1")
          distance[nx][ny] = cost
          heapq.heappush(q,(cost,(nx,ny)))

input = sys.stdin.readline
INF = int(1e9)

cnt = 1

while True:
  n = int(input().rstrip())
  if n == 0:
    break

  graph = []
  for _ in range(n):
    graph.append(list(map(int, input().split()))) 
  # 최단 거리 테이블
  distance = [[INF]*n for _ in range(n)]

  dx = [-1,1,0,0]
  dy = [0,0,-1,1]

  dijkstra(0,0)
  print("Problem "+str(cnt)+": "+str(distance[n-1][n-1]))
  cnt += 1