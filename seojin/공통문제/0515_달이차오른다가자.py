# 열쇠 정보를 비트마스크로 해결해야하는 문제였당...
# 각 열쇠는 a(1<<0), b(1<<1), c(1<<2), d(1<<3), e(1<<4), f(1<<5) 
# visited 배열을 다르게 적용해줘야했네...

from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

door = ['A','B','C','D','E','F']
key_list = [i.lower() for i in door]
my_keys = 0
days = 0
flag = 0
queue = deque()

N,M = map(int, input().split())
maze = []
for i in range(N):
  now = list(input())
  maze.append(now)
  for j in range(M):
    if now[j] == '0':
      startx,starty =  i,j
      

queue.append((startx,starty,my_keys,days))
maze[startx][starty]='.'
visited = [[[0]*64 for i in range(M)] for i in range(N)]
visited[startx][starty][0] = 1# 처음 위치

while queue:
  x,y,my_keys,days = queue.popleft()
  # print(x,y,my_keys,days)
  
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if nx>=0 and nx<N and ny>=0 and ny<M and visited[nx][ny][my_keys]==0 and maze[nx][ny] != '#':
      if maze[nx][ny] == '.':
        days += 1
        queue.append((nx,ny,my_keys,days))
        visited[nx][ny][my_keys]=1
        days -= 1
      elif maze[nx][ny] == '1':
        days+=1
        flag = 1
        break
      elif maze[nx][ny] in door: # 문인데
        if 1<<(ord(maze[nx][ny].lower())-97) & my_keys: # 열쇠 있다면
          days += 1
          queue.append((nx,ny, my_keys, days))
          visited[nx][ny][my_keys]=1
          days -= 1
      elif maze[nx][ny] in key_list: # 열쇠 획득~
        days += 1
        new = 1<<(ord(maze[nx][ny])-97) | my_keys
        queue.append((nx,ny,new,days))
        visited[nx][ny][new]=1
        days -= 1

    # print(queue)
  
  if flag == 1:
    break
if flag == 0:
  print(-1)
else:
  print(days)

def check(num):
    c=1
    for i in range(15):
        c *= i
        if num+1 == c:
            return i
        elif num+1 < c:
            return 0
def solution(numbers):
    answer = []
    for num in numbers:
        i = check(num) 
        if i!= 0:
            answer.append(2**(i+1)-1-2**(i-1))
        else:
            answer.append(num+1)
            
    return answer