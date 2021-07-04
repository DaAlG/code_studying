from collections import deque

t = int(input())
answer = []
for i in range(t):
  # m이 몇 번째로 나갈지 궁금해
  n, m = map(int, input().split())
  data = deque(map(int, input().split()))
  cnt = 0

  while data:
    # 현재 큐에서 제일 큰 수
    pri = max(data)
    now = data.popleft()
    m -= 1 
    
    if now != pri:
      data.append(now)
      if m<0:
        m = len(data)-1
    else: # 같다면
      cnt += 1
      if m == -1: # m이 제일 처음 오면
        break
  answer.append(cnt)

for i in answer:
  print(i)

