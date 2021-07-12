def plus_123(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 4
    else:
        return plus_123(n-1) + plus_123(n-2) + plus_123(n-3)
    
test = int(input())

for num in range(test):
    answer = plus_123(int(input()))
    print(answer)