# https://velog.io/@titiman1013/Python-BOJ-%EC%83%81%EC%96%B4-%EC%A4%91%ED%95%99%EA%B5%9021609
import sys
from collections import deque
input = sys.stdin.readline

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def search(tmp_arr, N):
    global dy,dx
    visited = [[False]*N for _ in range(N)]
    selected_blocks = [] # 블럭 그룹
    rbw_cnt = 0 # 무지개 블럭 count
    sy, sx = -1,-1 # 시작 위치

    for i in range(N):
        for j in range(N):
            if tmp_arr[i][j] > 0 and visited[i][j] == False:  # 일반 블럭이면서 아직 방문하지 않았다면
                tmp_sel_blocks = [] # 찾은 블록들을 저장할 필요가 있음
                tmp_rbw_cnt = 0
                rbws = [] 
                q = deque()  # 연결되어 있는 블록들의 탐색을 위함
                q.append((i,j))

                # 연결된 블록들 탐색, 블록 그룹 구하기
                while q:
                    y, x = q.popleft()

                    for k in range(4):
                        ny = y+ dy[k]
                        nx = x + dx[k]

                        if ny<0 or ny>=N or nx<0 or nx>=N:  continue #  벗어날 때
                        # 무지개 블럭이고 아직 보지 않았거나 이전 블럭과 색이 같고, 아직 방문하지 않았다면
                        if (tmp_arr[ny][nx] ==0 and (ny, nx) not in rbws) or (tmp_arr[ny][nx] == tmp_arr[i][j] and visited[ny][nx] == False):
                            if tmp_arr[ny][nx] == 0: # 무지개 블럭일 때
                                tmp_rbw_cnt +=1 # 무지개 블럭 개수
                                rbws.append((ny,nx)) # 무지개 블럭 배열
                            else: # 기준에 맞는 일반 블럭일 때 => 이미 얘는 다른 위치에서 시작할 땐 연결될 수 없는 곳이니까 true로 바꾸면 이미 확인한 곳들을 여러번 다시 찾게 되는 일이 없어짐
                                visited[ny][nx] = True
                            q.append((ny,nx)) 
                            tmp_sel_blocks.append((ny,nx))

                if len(tmp_sel_blocks) < len(selected_blocks):
                    continue
                elif len(tmp_sel_blocks) == len(selected_blocks):
                    if tmp_rbw_cnt < rbw_cnt:
                        continue
                    elif tmp_rbw_cnt == rbw_cnt:
                        if i < sy:
                            continue
                        elif i == sy:
                            if j < sx:
                                continue
                rbw_cnt = tmp_rbw_cnt
                sy, sx = i, j
                selected_blocks = tmp_sel_blocks

    return selected_blocks, len(selected_blocks)

def delete_block(tmp_arr, blocks):
    for y,x in blocks:
        tmp_arr[y][x] = -5 # 비움 처리 : -5
    return tmp_arr

def gravity(tmp_arr):
    global N
    for j in range(N-1, -1, -1):
        for i in range(N):
            if tmp_arr[j][i] == -5: # 비어있다면
                mx, my = i, j
                
                # 윗줄을 보는데 범위를 벗어나지 않고, 검은색 블록이 아닌 경우
                while 0<=my-1 and tmp_arr[my-1][mx] != -1: 
                    my -= 1 # 위로 올라간다.
                    if tmp_arr[my][mx] >=0: break # 비어있지 않으면 종료

                if my != j:  # 위쪽이 비어있었다면
                    tmp_arr[j][i] = tmp_arr[my][i] # 현재 위치로 중력 적용해준다.
                    tmp_arr[my][i] = -5 # 값이 있었던 곳은 비워준다.
    return tmp_arr
        

def rotate(tmp_arr):
    for _ in range(3):
        tmp_arr = [list(elem) for elem in zip(*tmp_arr[::-1])]
    return tmp_arr


# 입력
N, M = map(int, input().split())
arr = [[] for i in range(N)]
for i in range(N):
    arr[i] = list(map(int, input().split()))

answer = 0 # 결과값

while True:
    selected_blocks, selected_length = search(arr,N) # 블록 그룹, 블록 개수 반환

    #  블록 그룹 조건 : 2개 보다 작으면 안된다. 
    if selected_length < 2:
        break
    answer += selected_length ** 2 # 제곱한 값..
    arr = gravity(rotate(gravity(delete_block(arr, selected_blocks)))) 

print(answer)
    


