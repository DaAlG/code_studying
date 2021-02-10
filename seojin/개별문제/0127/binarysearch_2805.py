# 이 문제 함수로 풀었었는데 비교 연산 하나 더 들어간 것 때문에 시간 초과 되었던 것 같다...
import sys
n,m = map(int,sys.stdin.readline().rstrip().split())
height = list(map(int, sys.stdin.readline().rstrip().split()))
# print(height)
# 얘도 이진탐색으로 풀 수 있다.
# 적어도 M 미터의 나무를 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값....

height.sort()

start = 0
end = max(height)

result = 0
while start<=end:                                
  total = 0
  # print(arr)
  mid = (start+end)//2
  # print(mid)

  for i in height:
    if mid < i:
      total += i-mid
      # print('total',total)

  # 잘라야 하는 것보다 더 잘랐어! 
  if total >= m:
    # 일단 더 많이 주는거니까 부족하진 않아 
    result = mid
    start = mid+1
  else:
    # total<target이니까 mid를 왼쪽으로 옮겨야해
    end = mid -1
  # print(result)20

print(result)
