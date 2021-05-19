from itertools import combinations
l, c = map(int, input().split())
data = list(input().split())
vowel = ['a','e','i','o','u']
a = [] # 모음 리스트
b = [] # 자음 리스트

for i in range(c):
  if data[i] in vowel:
    a.append(data[i])
  else:
    b.append(data[i])

a.sort()
b.sort()
# print(a)
# print(b)

answer = []

for i in range(1,l-1):
  if 1<=i<=min(len(a),l-2) and 2<=l-i<=min(len(b),l-1):
    combi_a = list(combinations(a,i))
    combi_b = list(combinations(b,l-i))
    
    tempa = []
    tempb = []
    for ca in combi_a: 
      for w in ca:
        tempa.append(w)
      for cb in combi_b:
        for w in cb:
          tempb.append(w)
        # print(ca,cb)
        # print(tempb)  
        temp = tempa+tempb
        temp.sort()
        answer.append(temp)
        tempb = []
      tempa = []

answer.sort()
for word in answer:
  temp = ''.join(word)
  print(temp)