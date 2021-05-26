n = int(input())
stairs = [0]
for i in range(n):
  stairs.append(int(input()))
dp = [0]*(n+1)

# print(stairs)

dp[0] = 0
dp[1] = stairs[1]
if n>1:
  dp[2] = stairs[1]+stairs[2]
# print(dp)
if n>2:
  for i in range(3,n+1):
    print(dp)
    dp[i] = max(dp[i-2]+stairs[i],dp[i-3]+stairs[i-1]+stairs[i])
print(dp[n])

# 문제에서 마지막 계단을 무조건 밟는다고 생각하니까 그 마지막 계단을 n이라고 생각하면 n은 밟았을 때, 그 전의 계단을 밟았을 경우와 밟지 않은 경우를 생각해서 문제를 풀면 된대...

# 풀이를 위한 조건 간단하게 정리
# 1. 계단은 한 칸 혹은 두 칸씩 오를 수 있다.
# 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. => 두 번 "한" 칸씩 올랐다면 무조건 그다음은 "두" 칸을 올라감.
# 3. 마지막 도착 계단은 반드시 밟아야 한다. => 뒤에서 시작하면서 풀이를 시작하면 된다.

# 밟은 계단이 "END - 1"일 경우 반드시 "END - 2" 계단을 밟으면 안 된다. - case_A
# 밟은 계단이 "END - 2"일 경우 그 전 계단은 신경 쓰지 않는다. - case_B



# 나는 마지막 계단을 밟는 건 ㄹㅇ n번째일때만 해야한다고 생각했는데..아닌가봐
# if n==i:
#   dp[i] = max(dp[i-2],dp[i-3]+stairs[i-1])+stairs[i]
#   break
# dp[i] = max(dp[i-1],dp[i-2]+stairs[i], dp[i-3]+stairs[i-1]+stairs[i])
