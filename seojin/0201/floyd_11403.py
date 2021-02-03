import sys
input = sys.stdin.readline
# 플로이드 워셜
n = int(input())

# 2차원 리스트를 만들고 모든 값ㄱ을 무한으로 초기화
graph = [[0] for _ in range(n+1)]
# print(graph)
for a in range(1,n+1):
    temp = list(map(int, input().split()))
    # 리스트의 덧셈은 리스트 합치기~
    graph[a] = graph[a]+temp
# print(graph)

# k : 어디를 거쳐갈건지
for k in range(1, n+1):
  for a in range(1, n+1):
    for b in range(1,n+1):
      graph[a][b] = max(graph[a][b], graph[a][k]&graph[k][b])

# 결과 출력
for a in range(1,n+1):
  for b in range(1, n+1):
    if graph[a][b] == 0:
      print(0, end=' ')
    else:
      print(1, end=' ')
  print()
