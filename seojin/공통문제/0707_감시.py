# 너무 복잡해........................... 방향 다 세는 거 어렵지는 않았는데 이런 건 이렇게 리스트로 만들어버리는게 더 쉬운 방법인듯! 
# https://gingerkang.tistory.com/111
import copy
INF = int(1e9)

# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
direction = [[], [[0], [1], [2], [3]], [[0, 1], [2, 3]], [[0, 2], [2, 1], [1, 3], [3, 0]],
             [[3, 0, 2], [1, 3, 0], [0, 2, 1], [2, 1, 3]], [[0, 1, 2, 3]]]

def watch(y, x, direction, tmp):
    for d in direction:
        nx = x
        ny = y
        while True: # 벽이나 배열의 양 끝에 닿일 때까지 계속 그 방향으로 이동
            nx += dx[d]
            ny += dy[d]
            if nx >= 0 and nx < m and ny >= 0 and ny < n and tmp[ny][nx] != 6:
                if tmp[ny][nx] == 0: 
                    tmp[ny][nx] = '#' # cctv에 의해 보이는 영역으로 변경!
            else:
                break

def dfs(office, cnt):
    global ans

    tmp = copy.deepcopy(office)
    if cnt == cctv_cnt: # cctv를 다 확인했다면
        c = 0
        for i in tmp:
            c += i.count(0) # 사각지대 수 세기
        ans = min(ans, c)
        return
    y, x, cctv = q[cnt]
    for i in direction[cctv]:
        watch(y, x, i, tmp) # cctv가 볼 수 있는 방향 탐색
        dfs(tmp, cnt + 1)
        tmp = copy.deepcopy(office) # 사각지대 다시 원래대로 바꾸기

n, m = map(int, input().split())
office = []
cctv_cnt = 0
q = [] # cctv 정보
ans = INF
for i in range(n):
    input_data = list(map(int, input().split()))
    office.append(input_data)
    for j in range(len(input_data)):
        if input_data[j] != 0 and input_data[j] != 6:
            cctv_cnt += 1
            q.append([i, j, input_data[j]]) # cctv 정보 넣기

dfs(office, 0)
print(ans)