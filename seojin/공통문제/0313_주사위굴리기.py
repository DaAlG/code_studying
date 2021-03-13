n,m,x,y,k = map(int,input().split())
maps = []
for i in range(n):
  maps.append(list(map(int,input().split())))
# print(maps)

guide = list(map(int,input().split()))
# print(guide)

dices = [[-1,0,-1],[0,0,0],[-1,0,-1],[-1,0,-1]] # 주사위 초기상태 


def dice(i):
  # i = 방향
  global dices

  if i == 1: # 동쪽이라면
    temp = dices[1][2]
    for i in range(1,-1,-1):
      dices[1][i+1] = dices[1][i]
    dices[1][0] = dices[3][1] # 서쪽 = 바닥값
    dices[3][1] = temp # 바닥값 넣어주기
  elif i == 2: # 서쪽이라면
    temp = dices[1][0]
    for i in range(0,2):
      dices[1][i] = dices[1][i+1]
    dices[1][2] = dices[3][1] # 동쪽 = 바닥값
    dices[3][1] = temp #바닥값 넣어주기
  elif i == 3: # 북쪽이라면
    temp = dices[0][1]
    for i in range(0,3):
      dices[i][1] = dices[i+1][1]
    dices[3][1] = temp
  elif i == 4: # 남쪽이라면
    temp = dices[3][1]
    for i in range(2,-1,-1):
      dices[i+1][1] = dices[i][1]
    dices[0][1] = temp

dx = [0,0,-1,1] # 동서북남 순서
dy = [1,-1,0,0]

nx = x
ny = y

for i in guide: # 어디로갈까~
  nx = nx+dx[i-1]
  ny = ny+dy[i-1] 

  # print('nx ny '+str(nx)+','+str(ny))
  if 0<=nx<n and 0<=ny<m: # 갈 수 있는 길이라면
    dice(i)
    if maps[nx][ny] == 0: 
      maps[nx][ny] = dices[3][1]
    else:
      dices[3][1] = maps[nx][ny]
      maps[nx][ny] = 0
    print(dices[1][1])
  else: # 갈 수 없는 길이라면 무시한다
    nx = nx-dx[i-1]
    ny = ny-dy[i-1] 
    continue

