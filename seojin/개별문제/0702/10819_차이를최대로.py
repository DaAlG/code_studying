# 완전탐색
from itertools import permutations
n = int(input())
data = list(map(int, input().split()))

# n개 순열 모두 구하기
per = list(permutations(data,n))
# print(per)
ans = 0
for p in per:
  temp = 0
  cell = list(p)
  for i in range(1, n):
    temp += abs(cell[i]-cell[i-1])
  ans = max(temp, ans)

print(ans)