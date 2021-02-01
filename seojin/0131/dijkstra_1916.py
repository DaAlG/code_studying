import sys
import heapq

INF = int(1e9)
input = sys.stdin.readline

n = int(input())
m = int(input())

# 정보 저장할 그래프 1~n
graph = [[] for i in range(n+1)]

for i in range(m):
  a,b,c = map(int, input().split())
  # a -> b로 가는데 c만큼 든다.
  graph[a].append((b,c))

s, f = map(int, input().split())

# 최소비용 저장
distance = [INF]*(n+1)

def dijkstra(start):
  q = []
  distance[start] = 0
  # 맨 처음에 일단 start지점에서 나 자신까지의 경로는 0, start
  heapq.heappush(q,(0,start))
  cost = 0

  while q:
    dist, vertex = heapq.heappop(q)

    # 이미 봤다면~ 원래는INF였을거고, 봤다면 최단거리 들어갔을거고 내가 그것보다 크다면 의미  x
    if dist > distance[vertex]:
      continue

    #vertex에 연결된 애들 봐야지
    for i in graph[vertex]:
      cost = dist + i[1]

      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q,(cost,i[0]))

dijkstra(s)

print(distance[f])
