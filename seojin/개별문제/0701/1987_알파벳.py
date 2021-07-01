# bfs인줄 알았는데 dfs로 해야 가는 길에 방문한 알파벳 처리를 할 수 있음
r,c = map(int, input().split())
board = []
for i in range(r):
  board.append(input())

dx = [-1,1,0,0]
dy = [0,0,-1,1]

# visited 배열을 26으로 잡고 ord(board[nx][ny]-65)해서 있는지없는지 확인(in 사용하면 이게 dfs라서 안그래도 시간 걸리는데 더 걸림 그래서 그냥 배열을 1/0 으로 해서 체크)
visited = [0 for i in range(26)]
# print(visited)
visited[ord(board[0][0])-65] = 1
max_len = 0

def dfs(s,x,y):
  global dx, dy, max_len
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if 0<=nx<r and 0<=ny<c:
      # 아직 방문하지 않은 알파벳이라면
      if visited[ord(board[nx][ny])-65] != 1:
        visited[ord(board[nx][ny])-65] = 1
        dfs(s+1,nx,ny)
        visited[ord(board[nx][ny])-65] = 0
      if s > max_len:
        max_len = s

dfs(1,0,0)

print(max_len)