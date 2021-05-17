n = int(input())
p = []
for i in range(n):
  p.append(int(input()))

leg = [1,1,1,2,2]
for i in range(5,101):
  leg.append(leg[i-1]+leg[i-5])
# print(leg)
for i in p:
  print(leg[i-1])