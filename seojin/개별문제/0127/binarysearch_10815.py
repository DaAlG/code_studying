# 가지고 있는 카드의 개수 n
n = int(input())
# 숫자 카드에 적힌 정수
# python에서 음수 처리를 어떻게 하지..?
a = list(map(int, input().split()))
# m 
m = int(input())
b = list(map(int, input().split()))

#2천만,, 데이터 1000만개 이상->이진 탐색

def binary_search(arr, target, start, end):
  while start<=end:
    mid = (start+end)//2

    if arr[mid] == target:
      return mid
    if arr[mid]>target:
      end = mid -1
    else:
      start = mid + 1
    
  return None

a.sort()
for i in b:
  result = binary_search(a,i,0,n-1)
  if result != None:
    print(1, end=" ")
  else:
    print(0, end=" ")
