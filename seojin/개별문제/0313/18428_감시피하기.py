from itertools import combinations
import copy

n = int(input())
data = []
wall = []
teacher = []
for i in range(n):
    data.append(list(input().split()))
    for j in range(n):
        if data[i][j] == 'X': #비어 있는 곳이라면
            wall.append((i,j))
        if data[i][j] == 'T': #선생님 있는 곳이라면
            teacher.append((i,j))

wall_combi = list(combinations(wall,3)) # 벽을 세우는 3가지 조합들 

dx=[-1,0,1,0] # 상 좌 하 우
dy=[0,-1,0,1]

def dfs(x,y,i):
    global res
    # for k in range(n):
    #     print(wall_data[k])
    # print('-'*30)

    if 0<=x<n and 0<=y<n :
        if wall_data[x][y] == 'S': # 학생을 만났다면 걸렸으니까
            res+=1 # 늘려주기
        if wall_data[x][y] =='O': # 벽을 만났다면
            return 0  # 그만해
        dfs(x+dx[i], y+dy[i],i) # 그 방향으로 계속 탐색

    return 0

for i in wall_combi:
    wall_data = copy.deepcopy(data)

    # 벽 조합에서 하나 꺼내서 벽 세우기
    for x,y  in i:
        wall_data[x][y] = 'O' 
    res = 0
    for x,y in teacher: # 선생님 위치에서 탐색
        # print('선생님 위치 '+str(x)+','+str(y))
        for a in range(4): # 상하좌우로 보기
            nx = x+dx[a]
            ny = y+dy[a]
            # print('몇 회째 '+str(a))
            dfs(nx,ny,a)
        # break
        if res > 0: # 학생 발견했으면 의미없으니까 그만해
            break
    if res == 0: # 선생님들이 다 봤는데 한명도 못봤으면 안전한 조합이니까 정답 말하고 그만둬
        print('YES')
        break
    # print('*'*50)
if res != 0: # 다 돌았는데도 여전히 걸렸으면 NO
    print('NO')
# print(data)
# print(wall_combi)