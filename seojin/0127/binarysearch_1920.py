# 이진탐색!
n = int(input())
a = list(map(int, input().split()))

m = int(input())
b = list(map(int, input().split()))

# b가 a안에 존재하는가??
# 존재하면 1
# 그렇지 않으면 0

def binary_search(arr, target, start, end):
  while start<=end:
    mid = (start+end)//2

    if arr[mid] == target:
      return mid
    if arr[mid]>target:
      end = mid - 1
    else:
      start = mid + 1
  return None

a.sort()
# b.sort()

for i in b:
  result = binary_search(a,i,0,n-1)

  if result != None:
    print(1)
  else:
    print(0)
