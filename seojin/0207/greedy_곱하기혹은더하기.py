# 문자열 s
s = input()

# 결과 저장
res = 0

for now in s:
  if res == 0 or res ==1 or now == '0' or now =='1':
      res =  res + int(now)
  else:
    res = res*int(now)

print(res)

# # 모범답안
# data = input()

# # 첫번째 문자를 숫자로 변경하여 대입
# res = int(data[0])

# for i in range(1, len(data)):
#   # 두 수 중에서 하나라도 '0'이거나 '1'인 경우, 곱하기보다는 더하기 수행
#   num = int(data[i])

#   if num<=1 or res<=1:
#     res += num
#   else:
#     res *= num
# print(res)