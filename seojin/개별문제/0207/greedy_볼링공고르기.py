n,m = map(int, input().split())
data = list(map(int, input().split()))
data.sort()

cnt = [0]*(m+1)

# 각 무게에 해당하는 볼링공 개수 세기
for i in data:
  cnt[i]+=1
# print(cnt)

remain = 0
res = 0
for i in range(1,m):
  for j in range(i+1,m+1):
    remain += cnt[j]
  res += cnt[i]*remain
  remain = 0

print(res)

# 답안의 n을 이용한 아이디어
# for i in range(1, m+1):
#   n-=cnt[i] #무게가 i인 볼링공의 개수 제외
#   res += cnt[i]*n
#   #오왕 이렇게 하면 시간복잡도 감소!