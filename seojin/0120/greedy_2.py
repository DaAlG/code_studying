import time
s_time = time.time()
# n = 3 
# m = 3
# a = [[3,1,2],[4,1,4],[2,2,2]]

n,m = map(int, input().split())
a = list()

for _ in range(n):
  a.append(list(map(int,input().split())))
# 데이터 다 받았다

data_min = 0
for i in range(n): # 한 줄씩 읽기
  temp = min(a[i]) # 그 줄에서 제일 작은 수
  if data_min < temp: # 작은 수들 중에서 큰 수 찾기
    data_min = temp
print(data_min)
e_time = time.time()
print('time: ', e_time - s_time)
