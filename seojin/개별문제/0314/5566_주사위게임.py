n,m = map(int,input().split())
board = [-1]
for _ in range(n):
  board.append(int(input()))
dices = []
for _ in range(m):
  dices.append(int(input()))
# print(board)
# print(dices)

now = 1
cnt = 0
for i in dices:
  now += i 
  cnt+=1 # 주사위를 던진 횟수
  if now < n: # 던져서 간 곳이 도착지점이 아닐때
    if board[now]>0:
      now += board[now]
    elif board[now]<0:
      now -= abs(board[now])
    # print('now is '+str(now))
  if now >= n: # 도착지점보다 더 갔거나 도착했을 때
    print(cnt)
    break

