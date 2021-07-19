A,B = map(int,input().split())

# (1+2+3+...+n) => 1000보다 작으려면 44<45사이
problem = [0 for i in range(1001)]

cnt = 1
for i in range(1,45+1):
  for j in range(1,i+1):
    problem[cnt] = i
    if cnt == 1000:
      break
    cnt += 1

print(sum(problem[A:B+1]))