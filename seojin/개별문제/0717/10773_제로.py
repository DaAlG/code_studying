import sys
input = sys.stdin.readline

k = int(input())
stack = []

for i in range(k):
  now = int(input())
  if now == 0:
    stack.pop()
  else:
    stack.append(now)

print(sum(stack))