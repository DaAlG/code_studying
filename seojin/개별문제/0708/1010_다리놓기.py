# m개 중에 n개 고르는 거네! 조합인데 29 13은 오류나네.. 직접 만든다? 조합식 이용!
# from itertools import combinations
def fact(n):
  if n==0 :
    return 1
  return n*fact(n-1)

def combi(n,r):
  return fact(n)//(fact(r)*fact(n-r))

n = int(input())
for i in range(n):
  n,m = map(int, input().split())
  # m_list = [str(i) for i in range(m)]
  # a = list(combinations(m_list,n))
  # print(len(a))
  print(combi(m,n))
