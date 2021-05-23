# 문제 이해 - https://kau-algorithm.tistory.com/151 참고함...
# 1) 백트래킹으로 뒤집을 카드 쌍의 순서를 정한다.
# 2) 카드 쌍마다 A/B 중 먼저 뒤집을 애를 정한다
# 3) 순서가 정해졌다면 그에 따라 bfs
# 4) 각 순서 쌍마다 해보면서 가장 낮게 나온 거 최단거리로~
# https://walwal234.tistory.com/37 코드 보고 함...

from collections import deque

d = [(1,0),(-1,0),(0,1),(0,-1)]

def end_game(b):
  if b.count("0") == 16: # 다 뒤집었다면 0이니까 종료
    return True
  return False

def remove_element(b,e):
  b = b.replace(e,"0")
  return b

def move(b,y,x,dy,dx):
  ny, nx = y+dy, x+dx

  # 각 방향으로 1칸씩 이동하는데 이미 지워진 칸이라면 다시 함수 호출..
  if 0<=ny<4 and 0<=nx<4 and b[ny*4+nx]=="0":
    return move(b,ny,nx,dy,dx)
  else:
    # 이동했을 때 카드 발견되면 그 위치 반환
    if 0<=ny<4 and 0<=nx<4:
      return (ny,nx)
    else:
      # 이동했는데 카드 위치 벗어나면 구냥 그대로 반환?
      return (y,x)

def solution(board,r,c):
  answer = 0
  b = "" # deepcopy 귀찮아서 문자열로 변경
  for i in range(4):
    for j in range(4):
      b += str(board[i][j])

  q = deque([])

  cnt = 0
  enter = -1
  q.append((r,c,b,cnt,enter))
  s = set()

  while q:
    y,x,b,c,e = q.popleft()
    pos = 4*y+x # 문자열에서 현재위치

    if (y,x,b,e) in s:
      continue  
    s.add((y,x,b,e))

    if end_game(b):
      return c

    # 4방향 이동
    for (dy,dx) in d:
      ny,nx = y+dy, x+dx
      if 0<=ny<4 and 0<=nx<4:
        q.append((ny,nx,b,c+1,e))

    # ctrl+4 방향 이동
    for (dy,dx) in d:
      ny,nx = move(b,y,x,dy,dx)
      if ny == y and nx == x:
        continue
      q.append((ny,nx,b,c+1,e))
    
    # enter를 하는 경우
    if b[pos] != 0: # 카드가 있다면
      if e == -1: # enter 시작점일 때
        n_e = pos # 현재 위치 칸까지 이동
        q.append((y,x,b,c+1,n_e)) 
      else: # 시작점이 아니라면
        if e!=pos and b[e] == b[pos]: # enter가 현재 위치에 없고 enter 위치랑 현재 위치의 카드가 같을 경우
          b = remove_element(b,b[e]) # 삭제한다
          q.append((y,x,b,c+1,-1)) # 근데 enter를 왜 -1로 하는걸까...
  return answer