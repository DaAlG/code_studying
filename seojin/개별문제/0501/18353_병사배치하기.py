# LIS 알고리즘
n = int(input())
power = list(map(int,input().split()))
power.reverse()
# print(power)
dp = [1]*n
for i in range(1,n):
  for j in range(0,i):
    if power[j] < power[i]:
      dp[i] = max(dp[i], dp[j]+1)
      # print(power[i],power[j],dp)
  # print('*'*20)

print(n-max(dp))