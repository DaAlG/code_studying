# 모르겠음 !!!
# from itertools import combinations
# import sys
# input = sys.stdin.readline
# INF = int(1e10)

# N, C = map(int, input().split())
# house = []
# for i in range(N):
#   house.append(int(input()))

# house.sort()
# combi = list(combinations(house, C))

# answer = 0
# for i in combi:
#   minval = INF
#   # print(i)
#   for j in range(C-1): # 
#     temp = (i[j+1]-i[j])
#     if minval > temp:
#       minval = temp

#   if answer < minval:
#     answer = minval
#     # print(answer)  

# print(answer)


n,c = list(map(int, input().split()))

array = []
for _ in range(n):
  array.append(int(input()))
array.sort()

start = 1 # 최소 gap
end = array[-1] - array[0] # 최대 gap
result = 0

while(start<=end):
  mid = (start+end)//2
  value = array[0]
  count = 1

  for i in range(1,n):
    if array[i]>=value+mid:
      value = array[i]
      count+=1
  if count >= c:
    start = mid+1
    if result < mid:
      result = mid
  else:
    end = mid -1
    # if result < mid:
    # result = mid

print(result)