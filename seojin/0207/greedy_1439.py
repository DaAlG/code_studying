data = input()

cnt0 = 0 # 0을 1로 뒤집어야하는경우
cnt1 = 0 # 1을 0으로 뒤집어야하는경우

if int(data[0]) == 0:
  cnt0 += 1
else:
  cnt1 += 1

for i in range(len(data)-1):
  if int(data[i])^int(data[i+1]) == 1:
    if int(data[i+1]) == 0:
      cnt0 += 1
    else:
      cnt1 += 1

if cnt0 < cnt1:
  print(cnt0)
else:
  print(cnt1)