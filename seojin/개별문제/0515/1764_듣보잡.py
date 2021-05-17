def binsearch(s,f,target):
  global no_listen
  while s<=f:
    mid = (s+f)//2
    if no_listen[mid]==target:
      return target
    elif no_listen[mid]<target:
      s = mid + 1
    else:
      f = mid -1

n,m = map(int, input().split())
no_listen = []
no_see = []
no_hearsee = []
for i in range(n):
  no_listen.append(input())
no_listen.sort()
for i in range(m):
  no_see.append(input())

for i in range(m):
  t = binsearch(0,len(no_listen)-1,no_see[i])
  if t!=None:
    no_hearsee.append(t)

print(len(no_hearsee))
no_hearsee.sort()
for i in no_hearsee:
  print(i)