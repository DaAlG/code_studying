#https://velog.io/@sangjin98/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EB%B0%B1%EC%A4%80-1915%EB%B2%88-%EA%B0%80%EC%9E%A5-%ED%81%B0-%EC%A0%95%EC%82%AC%EA%B0%81%ED%98%95 참고

n,m = map(int, input().split())
graph = []
for i in range(n):
  graph.append(list(map(int, input())))
# print(graph)
res = 0

for i in range(n):
  for j in range(m):
    if i>0 and j>0 and graph[i][j] == 1:
      # 최대가 될 수 있는 정사각형의 크기 저장
      graph[i][j] += min(graph[i][j-1], graph[i-1][j], graph[i-1][j-1])
    res = max(res, graph[i][j])

print(res*res)
