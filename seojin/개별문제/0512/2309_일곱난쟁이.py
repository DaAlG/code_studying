from itertools import combinations

nine_dwarf = []
for i in range(9):
  nine_dwarf.append(int(input()))

total = sum(nine_dwarf) # 전체 합
combi=list(combinations(nine_dwarf,2)) # 뺄 2명 조합 생성
# print(combi)

for i in combi:
  a,b = i
  temp = a+b # 뺄 애들 합
  if total-temp == 100: # 뺐는데 100이라면
    nine_dwarf.remove(a) # 지워
    nine_dwarf.remove(b) # 지워
    break 

nine_dwarf.sort()
for i in nine_dwarf:
  print(i)