from collections import deque

n = int(input()) # 보드의 크기
k = int(input()) # 사과의 개수
apple = [] # 사과의 위치를 튜플로 담는다
for i in range(k):
  r,c = map(int,input().split())
  apple.append((r,c))

l = int(input()) # 뱀의 방향 전환 횟수
turn = dict() # 뱀의 방향 전환 정보 ->딕셔너리로 저장하는게 불러오기가 편할 듯
for i in range(l): 
  x,c = input().split()
  turn[x] = c
# print(turn)

# 동, 남, 서, 북(e,s,w,n) -> 이래야 왼쪽/오른쪽으로 푸는 거 수월하게 됨
r = [0,1,0,-1]
c = [1,0,-1,0]
t = ['e','s','w','n']
# 딕셔너리는 인덱스 참조가 안되니까 리스트로 간다~
# 각 위치에서 왼쪽 인덱스는 왼쪽간거고, 오른쪽 인덱스는 오른쪽 간거임

# 한번 지나간 길은 또 갈 수도 있기 때문에 방문했냐 안했냐 방법은 안쓸게
# 한칸씩 더 늘려서 벽을 만든다.
board = [[-1]*(n+2) for i in range(n+2)]
for i in range(1,n+1):
  for j in range(1,n+1):
    board[i][j] = 0

for i in apple:
  row,col = i
  board[row][col] = 1

# for i in range(0,n+2):
#   for j in range(0,n+2):
#     print(board[i][j], end=' ')
#   print()


head = [1,1] # start head
tail = [1,1] # start tail
where = 'e' # start - 오른쪽
result = 0 # time
route = deque()
route.append((1,1))
outflag = 0
while result<=10000:
  now_r, now_c = head[0],head[1]

  result += 1 # 1초씩 증가
  goto_r, goto_c = r[t.index(where)],c[t.index(where)] # 방향에 맞춰 가야할 정도를 받아옴
  head[0],head[1] = now_r+goto_r, now_c+goto_c

  # 내 몸과 부딪힌다면 break
  data = list(route)
  for i in data:
    data_r, data_c = i
    if data_r == head[0] and data_c == head[1]:
      outflag = 1
  if outflag == 1:
    break

   # 움직임에 따른 길이 변화
  if board[head[0]][head[1]] == 0: # 사과가 없고, 벽이 아니라면
    # goto_r, goto_c = r[t.index(where)],c[t.index(where)] # 방향에 맞춰 가야할 정도를 받아옴
    # head[0],head[1] = now_r+goto_r, now_c+goto_c
    route.append((head[0],head[1])) # 지금 가는 정보 입력해둠

    tail_r, tail_c = route.popleft() # 꼬리 정보 업데이트 
    tail = [tail_r,tail_c]
  elif board[head[0]][head[1]] == 1: # 사과가 있고, 벽이 아니라면
    # goto_r, goto_c = r[t.index(where)],c[t.index(where)] # 방향에 맞춰 가야할 정도를 받아옴
    # head[0],head[1] = now_r+goto_r, now_c+goto_c
    route.append((head[0],head[1])) # 지금 가는 정보 입력해둠
    # 꼬리는 그대로 있음
    # 사과는 먹었으니까 사라지겠지!! ***** 이거 놓쳐서 한참 찾음
    board[head[0]][head[1]] = 0
  elif board[head[0]][head[1]] == -1: #벽이라면 game over
    break
  

  # print('time is '+str(result))
 # 시간 정보에 따른 방향 전환
  if str(result) in turn: # 현재 time에 방향 전환이 필요하면
    whereindex = t.index(where)
    
    if turn[str(result)] == 'L':
      whereindex = whereindex-1
      if whereindex == -1: 
        whereindex = 3 
      where = t[whereindex]
    elif turn[str(result)] == 'D':
      whereindex = whereindex+1
      if whereindex == 4: 
        whereindex = 0 
      where = t[whereindex]

  #   print(where, turn[str(result)])
  # print()

print(result)

# 꼬리는 뒤로 길어지는게 아니기 때문에 관련이 없는 듯 ! 고려하지 않아도 되는 대상인 것 같다.
