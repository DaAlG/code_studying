import time
start_time = time.time()
# n = [2,4,5,4,6]
# m = 8
# k = 3

a,m,k = input().split()
# a = input().split()
m = int(m) 
k = int(k)
# print(m)
# print(k)
n = input().split()
n = list(map(int,n))
n = sorted(n)
# print(n)

length = len(n)

first= n[length-1]
second = n[length-2]
# print(first)
# print(second)

result = 0
cnt = 0

while cnt<m:
  for _ in range(k):
    result += first
    cnt += 1
  result+=second
  cnt+=1

print(result)
end_time =time.time()
print('time: ', end_time-start_time)
