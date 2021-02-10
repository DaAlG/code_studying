x = int(input())
d = [0]*1000001

for i in range(2,x+1):
  # 현재 수에서 1 빼는 경우
  d[i] = d[i-1]+1
  # 현재 수가 2로 나누어 떨어질 때
  if i%2==0:
    d[i] = min(d[i], d[i//2]+1)
  # 현재의 수가 3으로 나누어 떨어질 때
  if i%3 ==0:
    d[i] = min(d[i], d[i//3]+1)
print(d[x])
