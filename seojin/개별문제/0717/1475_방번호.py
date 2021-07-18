import sys
input = sys.stdin.readline

number = [i for i in range(10)]
check = [0 for i in range(10)]

N = input().rstrip()

for i in range(len(N)):
  if N[i] == '9':
    if check[9] > check[6]:
      check[6] += 1
    else: 
      check[9] += 1
  elif N[i] == '6':
    if check[6] > check[9]:
      check[9] += 1
    else: 
      check[6] += 1
  else: 
    check[int(N[i])] += 1

print(max(check))