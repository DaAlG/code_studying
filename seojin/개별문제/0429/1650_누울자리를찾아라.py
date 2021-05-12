n = int(input())
graph =[]
for i in range(n):
  graph.append(list(input()))

row_cnt = 0
col_cnt = 0
rcnt = 0
ccnt = 0

for i in range(n):
  for j in range(n):
    if graph[i][j] == 'X':
      if rcnt>=2:
        row_cnt +=1
      rcnt = 0
    else:
      rcnt += 1
    if graph[j][i] == 'X':
      if ccnt>=2:
        col_cnt +=1
      ccnt = 0
    else:
      ccnt += 1
  if rcnt>=2:
    row_cnt+=1
  if ccnt>=2:
    col_cnt+=1
  rcnt = 0
  ccnt = 0
print(row_cnt, end=' ')
print(col_cnt)