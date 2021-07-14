# 아이디어 틀은 잡았는데..! 
# dp를 더 풀어봐야 연습이 될 것 같다.
import sys 

S1 = sys.stdin.readline().strip().upper() 
S2 = sys.stdin.readline().strip().upper() 

len1 = len(S1) 
len2 = len(S2) 

matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)] 
for i in range(1, len1 + 1): 
  for j in range(1, len2 + 1): 
    if S1[i - 1] == S2[j - 1]: 
      matrix[i][j] = matrix[i - 1][j - 1] + 1 
    else: 
      matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]) 

# print(matrix)
print(matrix[-1][-1])

# 출처: https://suri78.tistory.com/11 [공부노트]
# # 두 가지 케이스
# matrix[i][j] = matrix[i-1][j-1]+1
# matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j])