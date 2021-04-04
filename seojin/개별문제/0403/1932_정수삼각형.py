from collections import deque

N = int(input())

triangle = []

for i in range(N):
  triangle.append(list(map(int,input().split())))

# print(triangle)

queue = deque()
queue.append(triangle[0][0])

for i in range(1,N): #첨에 큐에 젤 위에꺼 넣어줬으니까 1부터 시작!
  before = 0
  for j in range(len(queue)): # 한 depth 에서 큐에서 다 뺄 때까지
    temp = queue.popleft() #popleft해야 선입선출 큐 된다잉

    first = temp+triangle[i][j]
    second = temp+triangle[i][j+1]

    if before<first:
      queue.append(first)
    else:
      queue.append(before)

    before = second
  queue.append(before) # 마지막 second가 안들어가거등..넣어줘야지!
  # print(queue)
print(max(queue))
