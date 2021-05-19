n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort(reverse=True)

index = 0
answer = 0
for i in b:
  answer += i*a[index]
  index+=1

print(answer)