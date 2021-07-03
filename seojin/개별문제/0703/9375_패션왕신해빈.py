# 종류별로 안 입는 경우 포함(1씩 더하기)해서 곱한 후 모두 안 입는 경우(1가지) 빼 주면 됨
t = int(input())

for i in range(t):
  n = int(input())
  clothes = dict()

  for j in range(n):
    c_name, c_type = input().split()
    # 새로운 종류를 발견했다면
    if c_type not in clothes.keys():
      clothes[c_type] = 1
    else:
      clothes[c_type] += 1
  temp = 1
  for k in clothes.values():
    temp *= (k+1)

  ans = temp-1
  print(ans)
  
