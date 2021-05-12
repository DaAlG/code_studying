# main
n,k = map(int,input().split())
data = []
for i in range(n):
  data.append(list(map(int,input().split())))

# sort
data.sort(key=lambda x:(-x[1],-x[2],-x[3]))
# print(data)

grade = 1
s = 0
for i in range(n):
  if i!=0:
    if data[i-1][1:] == data[i][1:]: # 이전과 비교해서 같다면(동일 등수라면)
      s+=1
    else: # 다르다면
      if s: # 이전에 동일 랭크 있었다면 처리해주기
        grade += s
        s = 0
      grade += 1

  if data[i][0] == k:
    print(grade)
    break
