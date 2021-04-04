from collections import deque

# 상하좌우
dx = [-1,1,0,0]
dy = [0,0,-1,1]
q = deque()

def bfs(time,x1,y1,x2,y2,b):
    global q,dx,dy
    N = len(b)
    for i in range(4):
        nx1 = x1+dx[i]
        ny1 = y1+dy[i]
        nx2 = x2+dx[i]
        ny2 = y2+dy[i]
        if 0<=nx1<N and 0<=nx2<N and 0<=ny1<N and 0<=ny2<N:
            if b[nx1][ny1]==0 and b[nx2][ny2]==0:
                q.append((time+1,nx1,ny1,nx2,ny2))
        
    # 비행기가 가로로 있다면
    if x1 == x2: 
        for i in [-1,1]:
            if 0<=x1+i<N and 0<=x2+i<N: # 위/아래를 봐야하는데 범위 안벗어난다면
                if b[x1+i][y1]==0 and b[x2+i][y2]==0: # 위/아래 두 칸 모두 벽이 아니라면
                    q.append((time+1,x2+i,y2,x2,y2)) # 원래는 x1,y1이 어떻게 변했고~일일히 했는데 보니까 x2,y2기준으로 적어도 어차피 pop해서 볼거니까 이렇게 적는게 효율적이더라..
                    q.append((time+1,x1,y1,x1+i,y1))

    # 비행기가 세로로 있다면
    elif y1 == y2:
        for i in [-1,1]:
            if 0<=y1+i<N and 0<=y2+i<N: # 왼쪽/오른쪽 봐야하는데 범위 안 벗어난다면
                if b[x1][y1+i]==0 and b[x2][y2+i]==0: # 왼/오 두 칸 모두 벽이 아니라면
                    q.append((time+1,x2,y2+i,x2,y2))
                    q.append((time+1,x1,y1,x1,y1+i))


def solution(board):
    answer = 0
    global q
    
    time = 0
    # start1 = (1,1)
    # start2 = (1,2)
    visited = []
    n = len(board)-1
    
    q.append((time,0,0,0,1))
    # print(q)

    while q:
        time, x1, y1, x2, y2 = q.popleft()
        if (x1,y1,x2,y2) in visited:
            continue
        if (x1==n and y1==n) or (x2==n and y2==n):
            break
        visited.append((x1,y1,x2,y2))
        # print(q)
        bfs(time,x1,y1,x2,y2,board)

    answer = time 
    return answer


# board = [[0, 0, 0, 0, 0, 0, 1], [1, 1, 1, 1, 0, 0, 1], [0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 1, 1, 0], [0, 1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 1, 1], [0, 0, 1, 0, 0, 0, 0]] #21
# print(solution(board))