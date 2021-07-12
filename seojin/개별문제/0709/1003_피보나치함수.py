import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
  search = int(input())
  check = [0,0]
  fibo = [[0,0] for i in range(41)]

  fibo[0] = 1,0
  fibo[1] = 0,1

  for i in range(2,search+1):
    fibo[i] = fibo[i-1][0]+fibo[i-2][0],fibo[i-1][1]+fibo[i-2][1]
  
  print(fibo[search][0], fibo[search][1])