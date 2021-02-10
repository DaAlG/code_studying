import sys

input = sys.stdin.readline
INF = int(1e9)

n = int(input())
m = int(input())

graph = [[INF]*(n+1) for _ in range(n+1)]

for i in range(m):
  a,b,c = map(int,input().split())
  # 가는 길이 여러가지일 경우, 제일 비용이 작은 애 선택하기
  if graph[a][b] != INF:
    if c < graph[a][b]:
      graph[a][b] = c
    else:
      continue
  else:
    graph[a][b] = c

for i in range(1, n+1):
  for j in range(1, n+1):
    if i==j:
      graph[i][j] = 0

for k in range(1, n+1):
  for a in range(1, n+1):
    for b in range(1, n+1):
      graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])

for a in range(1, n+1):
    for b in range(1, n+1):
      if graph[a][b] != INF:
        print(graph[a][b], end=' ')
      else:
        print(0, end=' ')
    print()