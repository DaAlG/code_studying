# 풀이 보고 풀었음..
# DP 문제 연습 필요함
n = int(input())
w = [0]
for i in range(n):
  w.append(int(input()))

d = [0]*(n+1)

d[1] = w[1]
if n>1:
  d[2] = w[1]+w[2]
if n>2:
  for i in range(3,n+1):
    d[i] = max(d[i-1], d[i-2]+w[i], d[i-3]+w[i-1]+w[i])

print(d[n])