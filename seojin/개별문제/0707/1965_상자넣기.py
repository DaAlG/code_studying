n = int(input())
box = list(map(int, input().split()))
dp = [1 for _ in range(n)]

for i in range(1,n):
  for j in range(i):
    if box[i] > box[j]: # 이전 박스가 현재 박스보다 작다면
      dp[i] = max(dp[i], dp[j]+1) # 현재 값, 이전 박스가 가지고 있는 개수+1 중 큰 쪽을 선택

print(max(dp))