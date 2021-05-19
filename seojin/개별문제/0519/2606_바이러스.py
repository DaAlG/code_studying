from collections import deque

n = int(input())
m = int(input())

computer = [[] for i in range(n+1)]
for i in range(m):
  x,y = map(int, input().split())
  computer[x].append(y)
  computer[y].append(x)

# print(computer)
visited = [0]*(n+1)
queue = deque()
queue.append(1)
answer = 0
visited[1] = 1

while queue:
  now = queue.popleft()
  for i in computer[now]:
    if not visited[i]:
      queue.append(i)
      visited[i] = 1
      answer+=1

print(answer)