import time
s_time = time.time()
n,k = map(int, input().split())

cnt = 0
while True:
  if n % k != 0:
    n -= 1
    cnt += 1
    if n==1:
      break
  else:
    n = n /k
    cnt += 1
    if n==1:
      break

print(cnt)
e_time = time.time()
print('time: ', e_time-s_time)
