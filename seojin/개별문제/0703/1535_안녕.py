# knapsack.. 근데 풀이를 모르겠어!
# https://sangminlog.tistory.com/entry/boj-1535

N = int(input()) 
L = [int(x) for x in input().split()] 
J = [int(x) for x in input().split()] 
L, J = [0] + L, [0] + J 
dp = [[0 for _ in range(101)] for _ in range(N+1)] 

for i in range(1, N+1): 
  for j in range(1, 101): 
    if j-L[i] > 0 :  # i번째 사람에게 인사를 할 수 있을 떄(내 체력이 남을 때)
      dp[i][j] = max(dp[i-1][j], dp[i-1][j-L[i]] + J[i]) 
    else: # i번째 사람에게 인사를 할 수 없을 떄
      dp[i][j] = dp[i-1][j] 

print(dp[N][100]) 