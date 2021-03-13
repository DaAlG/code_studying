from collections import deque
n, l, r = map(int,input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

dx = [-1,0,1,0]
dy = [0,-1,0,1]

def process(x,y,index):
    united = [] # 연합하는 애들이 들어갈거야
    united.append((x,y))
    q = deque() 
    q.append((x,y))
    union[x][y] = index # 현재 위치의 연합번호
    summary = graph[x][y] 
    count=1 # 현재 연합국 수

    while q:
        x,y = q.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]

            if 0<=nx<n and 0<=ny<n and union[nx][ny]==-1: # 아직 연합 아닌 국가들 보기
                if l<=abs(graph[nx][ny]-graph[x][y])<=r:
                    q.append((nx,ny))
                    union[nx][ny] = index # 같은 연합번호 부여
                    count+=1
                    summary+=graph[nx][ny]
                    united.append((nx,ny))

    for i,j in united:
        graph[i][j] = summary//count


total_count = 0
while True:
    union = [[-1]*n for _ in range(n)] # 각 지역에 무슨 번호의 연합으로 이루어져있는지
    index = 0
    for i in range(n):
        for j in range(n):
            if union[i][j] == -1: # 아직 처리되지 않았을 때
                process(i,j,index)
                index+= 1
    if index == n*n: # for문 다 돌았을 때 index가 n*n이라면 더이상 인구이동이 일어나지 않았다는 의미
        break # 그러면 이제 다 끝났으니까 나가자
    total_count += 1 # 몇 일동안 인구이동 일어나는지

print(total_count)