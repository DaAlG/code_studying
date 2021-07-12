# https://mygumi.tistory.com/336 
# 시작 방향 : 4가지, 10세대까지 갈 수 있고 세대가 늘어날수록 커브 수 2배로 늘어남.
# 각 방향별로 드래곤 커브를 10세대까지 미리 설정해두자!
pattern = [[0 for _ in range(1024)] for i in range(4)]
pattern[0][0] = 0 # 오른쪽(x,+1)
pattern[1][0] = 1 # 위쪽(y,-1)
pattern[2][0] = 2 # 왼쪽(x,-1)
pattern[3][0] = 3 # 아래쪽(y,+1)

# 현 세대 드래곤커브 = (이전세대)+ (이전세대 역방향+1)
for k in range(4):
  for i in range(1,11):
    # 역방향+1해서 이전세대값에 붙여주기
    start = 2**(i-1)
    end = 2**i
    jump = 1
    for j in range(start, end):
      # 방향이 0~3이니까 4되면 0으로 바꿔주기
      pattern[k][j] = (pattern[k][j-jump] + 1) % 4
      jump += 2

# 드래곤 커브 그리기
n = int(input())
data = [[0 for _ in range(101)] for _ in range(101)]

for i in range(n):
  x,y,d,g = map(int, input().split()) # d: 시작방향
  end = 2**g # 드래곤 세대->pattern에서 어디까지 볼 지 정하기
  
  cur_x = x
  cur_y = y
  data[cur_y][cur_x] = True

  # 시작 방향에 맞춰서 드래곤 커브 위치 찾아서 정점 찍어주기
  for j in range(end):
    if pattern[d][j] == 0: # 오른쪽
      cur_x += 1
    elif pattern[d][j] == 1: # 위쪽
      cur_y -= 1
    elif pattern[d][j] == 2: # 왼쪽
      cur_x -= 1
    else: # 아래
      cur_y += 1
    data[cur_y][cur_x] = True
  
# 다 그렸으면 정사각형 존재하는지 확인!
# 정사각형이 99,99에서 시작하는 점까지만 만들어지니까 range(100)
cnt = 0
for i in range(100):
  for j in range(100):
    if data[i][j] and data[i+1][j] and data[i][j+1] and data[i+1][j+1]:
      cnt += 1

print(cnt)