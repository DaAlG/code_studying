n = int(input())
A = list(map(int, input().split()))
dp = [1 for i in range(n)] 


for i in range(n):
  for j in range(i):
    if A[i] > A[j]: #현재 가장 긴 수열의 값과 A[i]보다 작은 수가 가진 값+1 비교
      dp[i] = max(dp[i], dp[j]+1)

print(max(dp))