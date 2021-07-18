N = int(input())
inf = int(1e9)+9
# 처음 수는 2개 마지막 수는 0/1/2 중 무조건 하나.. 그래서 2*3^N-2*1
if N == 1:
  print(0)
else: 
  ans = (2*3**(N-2))%inf
  print(ans)