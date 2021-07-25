import heapq
import sys

INF = int(1e9)
input = sys.stdin.readline

def dijkstra(i,j):
  global room, distance
  dy = [-1,1,0,0]
  dx = [0,0,-1,1]
  q = []
  heapq.heappush(q,(0,(i,j)))

  while q:
    # cost, (y, x) = heapq.heappop(q)
    cnt, (y, x) = heapq.heappop(q)
    # if distance[y][x] < cost:
    #   continue
    if distance[y][x] < cnt:
      continue
    for k in range(4):
      ny = y + dy[k]
      nx = x + dx[k]
   
      # if 0<=ny<n and 0<=nx<n:
      #   n_cost = cost + room[ny][nx]*-1
      #   if n_cost < distance[ny][nx]:
      #     distance[ny][nx] = n_cost
      #     heapq.heappush(q,(n_cost,(ny,nx)))
      if 0<=ny<n and 0<=nx<n:
        if room[ny][nx] == 0:
          n_cnt = cnt + 1
        else: 
          n_cnt = cnt
        if n_cnt < distance[ny][nx]:
          distance[ny][nx] = n_cnt
          heapq.heappush(q,(n_cnt,(ny,nx)))

n = int(input())
room = []
distance = [[INF]*n for i in range(n)]
for i in range(n):
  room.append(list(map(int,input().rstrip())))
# print(room)
dijkstra(0,0)
print(distance[n-1][n-1])