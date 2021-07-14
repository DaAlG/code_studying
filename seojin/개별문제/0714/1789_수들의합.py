n = int(input())

i = 1
cnt = 0
sum = 0

while True:
  if n>=sum:
    sum += i
    i += 1
    cnt += 1 
  else:
    break

print(cnt-1)