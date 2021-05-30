t = int(input())
for _ in range(t):
  n = int(input())
  phone = []
  setlist = set() # 전화번호 넣을건데 중복 피하려고
  for _ in range(n):
    phone.append(input())
  
  for num in phone:
    for k in range(1,len(num)):
      setlist.add(num[0:k])
    # print(setlist)
  flag = 0
  for i  in phone:
    if i in setlist:
      flag = 1
      print("NO")
      break
  if flag == 0:
    print("YES")

