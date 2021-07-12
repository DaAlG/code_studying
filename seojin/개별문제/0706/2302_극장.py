# 피보나치랑 같다!
n = int(input())
m = int(input()) # 고정석 개수

vip = [] # 고정석
for i in range(m):
    k = int(input())
    vip.append(k)

sit = [1,1,2]
for i in range(3,41):
    sit.append(sit[i-2]+sit[i-1])

ans = 1
if m >= 1: # 고정석이 있다면 계산 필요
    pre = 0
    for i in range(m):
        ans *= sit[vip[i]-pre-1]
        pre = vip[i]
    ans *= sit[n-pre]
else:
    ans = sit[n]
print(ans)