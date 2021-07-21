from collections import deque
INF = int(1e9)

def solution(board):
  def bfs(start):
    n = len(board)  
    ccost = [[INF]*n for i in range(n)]
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]

    q = deque([start])
    ccost[0][0] = 0
    while q:
      c,y,x,head = q.popleft()

      # 지금 위치에서 상하좌우 보고
      for k in range(4):
        ny = y + dy[k] 
        nx = x + dx[k]
        # 직선도로 -> 100원
        cost = c+600 if k!=head else c+100
        if 0<=ny<n and 0<=nx<n and board[ny][nx]!=1 and cost < ccost[ny][nx]:
            ccost[ny][nx] = cost
            q.append((cost,ny,nx,k))
    # print(ccost)
    return ccost[n-1][n-1]
  return min(bfs((0,0,0,1)),bfs((0,0,0,3)))

board = [[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]
print(solution(board))