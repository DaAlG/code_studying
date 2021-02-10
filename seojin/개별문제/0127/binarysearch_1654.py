import sys
k, n = map(int, sys.stdin.readline().rstrip().split())
a = []                          
for i in range(k):
  a.append(int(sys.stdin.readline().rstrip()))

a.sort()  
start = 1
end = max(a)
result = 0

while start<=end:
  total_cnt = 0
  mid = (start+end)//2
  for i in a:
    # if i > mid: # 얘 썼더니 문제 생겼어 왜지
    total_cnt += (i//mid)
  # if total_cnt == k:
  #   continue

  if total_cnt >= n:
    result = mid
    start = mid + 1
  else:
    end = mid - 1

print(result)
# print(total)
