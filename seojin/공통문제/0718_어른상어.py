# 동빈 나 풀이 봄.. 근데 봐도 너무너무 헷갈린다

n, m, k = map(int, input().split())

# 격자의 모습
array = []
for i in range(n):
  array.append(list(map(int, input().split())))

# 상어의 방향 정보
directions = list(map(int, input().split()))

# 위치마다 특정 냄새의 상어번호와 남은 시간을 저장
smell = [[[0,0]]*n for _ in range(n)]

# 상어의 회전 방향 우선순위 정보
priorities = [[] for _ in range(m)]
for i in range(m):
  for j in range(4):
    priorities[i].append(list(map(int,input().split())))

# 특정 위치에서 이동 가능한 4가지 방향
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 모든 냄새 정보 업데이트 
def update_smell():
  for i in range(n):
    for j in range(n):
      # 냄새가 존재하는 칸의 시간을 1 감소
      if smell[i][j][1] > 0:
        smell[i][j][1] -= 1  
      # 상어가 존재하는 칸의 냄새를 k로 설정
      if array[i][j] != 0:
        smell[i][j] = [array[i][j], k]

# 모든 상어 이동
def move():
  new_array = [[0]*n for _ in range(n)]

  for x in range(n):
    for y in range(n):
      # 상어가 존재하는 경우
      if array[x][y] != 0:
        direction = directions[array[x][y]-1] # 현재 상어의 방향
        found = False
        # 냄새가 존재하지 않는 곳이 있는지 확인
        for index in range(4):
          nx = x + dx[priorities[array[x][y]-1][direction-1][index]-1]
          ny = y + dy[priorities[array[x][y]-1][direction-1][index]-1]
          if 0<=nx<n and 0<=ny<n:
            if smell[nx][ny][1] == 0: # 냄새가 존재하지 않으면
              # 해당 상어의 방향 이동시키기
              directions[array[x][y]-1] = priorities[array[x][y]-1][direction-1][index]
              # 이미 다른 상어가 있다면 번호가 낮은 상어가 들어가도록 이동
              if new_array[nx][ny] == 0:
                new_array[nx][ny] = array[x][y]
              else:
                new_array[nx][ny] = min(new_array[nx][ny], array[x][y])
              found = True
              break

        if found:
          continue

        # 주변에 모두 냄새가 남아있다면, 자신의 냄새가 있는 곳으로 이동
        for index in range(4):
          nx = x + dx[priorities[array[x][y]-1][direction-1][index]-1]
          ny = y + dy[priorities[array[x][y]-1][direction-1][index]-1]
          if 0<=nx<n and 0<=ny<n:
            if smell[nx][ny][0] == array[x][y]: # 자신의 냄새이면
              # 방향 이동
              directions[array[x][y]-1] = priorities[array[x][y]-1][direction-1][index]
              # 상어 이동시키기
              new_array[nx][ny] = array[x][y]
              break
  return new_array

time = 0
while True:
  update_smell() # 모든 위치의 냄새 업데이트
  new_array = move() # 모든 상어 이동
  array = new_array
  time += 1

  # 1번 상어만 남아있는지 체크
  check = True
  for i in range(n):
    for j in range(n):
      if array[i][j] > 1: 
        check = False

  if check:
    print(time)
    break

  if time >= 1000:
    print(-1)
    break