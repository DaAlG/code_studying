# 규칙 찾아서 풀면 쉬움
# 1) KBS1 KBS2 순서
# 2) KBS2 KBS1 순서

n = int(input())

for i in range(n):
  now = input()
  if now == 'KBS1':
    idx1 = i
  elif now == 'KBS2':
    idx2 = i

res = ''
# KBS1은 그냥 인덱스 개수 만큼 이동하면됨
res = '1'*idx1+'4'*idx1

# KBS2는 위치에 따라 다름
if idx1>idx2: # kbs1이 더 아래에 있다면
  idx2+=1
res += '1'*idx2+'4'*(idx2-1)

print(res)