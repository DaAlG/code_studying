# -*- coding:utf-8 -*-
from queue import PriorityQueue # 우선순위 큐

def solution(N, road, K):
    answer = 0
    ###################### 못 가는 길
    INF = 500001 #c 기준(두 길 사이 최대 연결 길이) 가 아니라 K(최대 소요 가능 시간)으로 해야함.
    #C보다 크면 알아서 안가는게 아니고, 비용으로 판단하기 때문.
    #인접행렬 초기화.
    adj_matrix = list([INF for _ in range(N + 1)] for _ in range(N + 1) )
    #INF -> float('inf')로 대체할 것.
    
    #자기로 가는 길은 0
    for i in range (1, N + 1):
        for j in range (1, N + 1):
            if i == j:
                adj_matrix[i][j] = 0

     #1~각 정점까지의 거리
    dist = [INF] * (N + 1)
    dist[1] = 0

        #우선순위 큐
    queue = PriorityQueue()

    #road 스캔
    for r in road:
        #같은 길 두번 있는 경우 고려
        adj_matrix[r[0]][r[1]] = min(r[2], adj_matrix[r[0]][r[1]])
        #반대방향도
        adj_matrix[r[1]][r[0]] =adj_matrix[r[0]][r[1]]
        #dist도 함께 초기화
        if r[0] == 1:
            dist[r[1]] = r[2]
            queue.put([r[1], r[2]]) #queue.put([selected, dist[selected]])

        elif r[1] == 1:
            dist[r[0]] = r[2]
            queue.put([r[0], r[2]]) #queue.put([selected, dist[selected]])




    while not queue.empty() : #N개 정점을 다 방문할 떄 까지(출발지 포함)
        #다음 출발지 (selected 찾기)

        #현재까지 최소 노드와 1~비용
        selected, current = queue.get()

        #dist 업데이트
        for i in range(2, N+1):
            #1~ 그 지점 / 1~ selected + selected~ 그 지점
            #방문하지 않은 곳에대해서만 실행 (어차피 비용 양수임)
            if dist[i] > current + adj_matrix[selected][i] :
                    dist[i] = current + adj_matrix[selected][i]
                    queue.put([i,dist[i]])
                    #갱신됐으니까 put

    #본인 포함
    for i in range(1, N+1):
        if dist[i] <= K:
            answer += 1

    return answer