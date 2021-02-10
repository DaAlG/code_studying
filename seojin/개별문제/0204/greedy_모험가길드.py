# 처음에 낮은 순으로 해보려다가 아이디어 안나와서 이렇게 했음
n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
# print(a)

group = 0
index = 0
max_group = 0

# 공포도 높은 애 제외하면서 그룹 수 확인하기
for j in range(n,0,-1):
  remain = j
  while remain > 0:
    if remain-a[index]>=0:
      remain = remain - a[index]
      group +=1
      index += a[index]
  if max_group < group: 
    max_group = group
  a.pop(0)

  group = 0
  index = 0

print(max_group)

# 모범답안
# n = int(input())
# data = list(map(int, input().split()))
# data.sort()

# result = 0 # 총 그룹의 수
# count = 0 # 현재 그룹에 포함된 모험가의 수

# for i in data:
#   count += 1 # 현재 그룹에 모험가를 포함시키기
#   if count >= i: #현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면 그룹 결성!
#     result += 1
#     count = 0
# print(result)
