import copy 

n = int(input())
a = []
present=[-1]

for i in range(n):
  a.append(list(map(int, input().split())))
# print(a)

for i in range(n):
  if a[i][0] == 0:
    print(present[0])
    if present[0]>0:
      present.pop(0)
    # pass
  else:
    temp = copy.deepcopy(a[i][1:])
    present += temp
    # print(present)
    present.sort(reverse=True)
