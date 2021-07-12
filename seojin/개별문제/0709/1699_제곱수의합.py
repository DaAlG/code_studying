# 처음엔 가장 큰 제곱수를 이용해야한다고 생각했는데, 그게 아니라 19면 1~4 제곱수를 모두 넣어봐야함
import sys
input = sys.stdin.readline
n = int(input())

dp = [i for i in range(n+1)] # 다 1을 더한 거라고 생각해두기

for i in range(2,n+1):
  for j in range(1,i+1):
    if i < j**2:  # j*j=1,4,9,16,25,49,81,,,
      break
    dp[i] = min(dp[i],dp[i-j*j]+1) # +1은 제곱수 뺐으니까 그거 개수 더해준 거. 
      # j 반복 돌면서 dp[i]가 제일 작게 나오는 값으로 저장해두기!

print(dp[n])