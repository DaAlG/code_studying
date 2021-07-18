import copy
n = int(input())
A = list(map(int, input().split()))
# dp = [0 for i in range(n)] 
# dp[0] = A[0]
# 초기화도 중요하군...
dp = copy.deepcopy(A)

for i in range(n):
  for j in range(i):
    if A[i] > A[j]: 
      dp[i] = max(dp[i], dp[j]+A[i])

print(max(dp))
# print(dp)