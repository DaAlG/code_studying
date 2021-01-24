n = int(input()) #몇 명
time = list(map(int, input().split())) # 각 사람 인출하는데 걸리는 시간

# 오름차순 정렬
time.sort()

result = [0]*n
for i in range(n):
    for j in range(i+1):
        result[i] += time[j]

# print(result)       
print(sum(result))
