n = int(input())

data = []

for i in range(n):
  name, kor, math, eng = (list(input().split()))
  data.append((name, int(kor), int(math), int(eng)))

for i in range(n):
  print(data[i]) 

# lamda 이용 !!!!!!!
stu = sorted(data, key=lambda x:(-x[1],x[2],-x[3],x[0]))
# print(data)
# print('*'*30)
for i in range(n):
  print(stu[i][0])