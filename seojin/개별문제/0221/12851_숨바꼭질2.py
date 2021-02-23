from collections import deque
# data 배열을 잘 활용했어야 했음. queue는 지금 방문중인 애들을 이용하기 위해 사용.
# 근데 내가 푸는 재귀적 방법은 왜 안되는 걸까 ㅠ

# def goto(su, don, cnt):
#   if su == don:
#     data[cnt]+=1
#     # if queue:
#     #   tim, count = queue.popleft()
#     #   if tim > cnt:
#     #     queue.append((cnt,1))
#     #   elif tim == cnt:
#     #     count += 1
#     #     queue.append((tim, count))
#     #   else:
#     #     queue.append((tim, count))
#     # else:
#     #   queue.append((cnt,1))
#     return 0
#   else:
#     # cnt += 1
#     if su > don:
#       goto(su-1, don, cnt+1)
#     else:
#       if su*2 <= 100000:
#         goto(su*2, don, cnt+1)
#       if su+1 <= 100000:
#         goto(su+1, don, cnt+1)
#       if su != 0:
#         goto(su-1, don, cnt+1)
#   return 0

su, don = map(int,input().split())
max_size = 100001
data = [-1]*100001 # 현재위치에서 걸린 시간
queue = deque()
queue.append(su)
# goto(su, don, 0)
# # print(queue)

cnt = 0 # 방법의 수
data[su] = 0

while queue: # queue가 빌 때까지
  s = queue.popleft()
  if s == don:
    cnt += 1 # 방법 수 늘어남
  for y in [s*2, s+1, s-1]:
    if 0<=y<max_size:
      if data[y] == -1 or data[y]>=data[s]+1: # 방문한 적이 없거나, 만약 y가 6, data[6]=1로 이미 다른 숫자를 지날 때 6까지의 시간이 1인걸 찾았는데, 다른 수에서 넘어올 경우에 얘를 또 지날 수도 있잖아? 그런데 이게 6에 도달하는 시간이 1보다 커버리면 얘를 거쳐서 정답에 도달하는 시간이 무조건 이전보다 커지는거니까 걔는 볼 필요가 없는거야! 그래서 data[y]보다 작은 애들만 본다.
        data[y] = data[s]+1
        queue.append(y)
print(data[don])
print(cnt)

# for i in range(len(data)):
#   if data[i]!=0:
#     print(i)
#     print(data[i])
#     break
