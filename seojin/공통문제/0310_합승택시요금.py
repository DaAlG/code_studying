def solution(n, s, a, b, fares):
    answer = 0
    INF = int(1e9)
    graph = [[INF]*(n+1) for _ in range(n+1)]
    
    for i in range(1,n+1):
        graph[i][i] = 0 # 나 자신으로 가는 건 0
        
    for c,d,f in fares:
        graph[c][d] = f
        graph[d][c] = f
    # for i in graph: 
    #     print(i)
    
    # print('*'*10)
    
    # 플로이드 워셜 써서 모든 최단거리? 구해놓기
    for k in range(1, n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                
                # graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j])
                # min 이거 직접 비교하는 것보다 시간이 훨씬 오래 걸리나봐!!!!

                if graph[i][j] > graph[i][k]+graph[k][j]:
                    graph[i][j] = graph[i][k]+graph[k][j]
                
    # for i in graph: 
    #     print(i)
    
    # A, B 각각 제 갈길 갈 때
    # answer = graph[s][a]+graph[s][b]
    # print('제 갈길 갈 때 값은 A '+str(graph[s][a])+'B '+str(graph[s][b])+'= '+ str(answer) )
    
    # 시작점에서-> 1~n까지 바꿔가면서 어디까지 같이가는게 제일 좋은지 알아내기
    # 여기서 같이 가는 경로를 알아야하는게 아니니까 최소비용의 합승목적지만 이용해서 구하면 됨.
    answer = INF
    for i in range(1,n+1):
        answer = min(answer, graph[s][i]+graph[i][a]+graph[i][b])
    answer = min(answer,graph[s][a]+graph[s][b])
    return answer

# 다익스트라로 푼 것
# import heapq 
# INF = int(1e9)

# def dijkstra(s,f,n):
#     q = []
#     heapq.heappush(q,(0,s))
#     distance = [INF]*(n+1)
#     distance[s] = 0
    
#     while q:
#         dist, now = heapq.heappop(q)
        
#         if dist > distance[now]:
#             continue
            
#         for i in graph[now]:
#             cost = dist+i[1]
            
#             if cost < distance[i[0]]:
#                 distance[i[0]] = cost
#                 heapq.heappush(q,(cost,i[0]))
                
#     return distance[f]

                     

# def solution(n, s, a, b, fares):
#     answer = 0
#     global graph
#     graph = [[] for _ in range(n+1)]

#     for i in fares:
#         c,d,f = i
#         graph[c].append((d,f))
#         graph[d].append((c,f))
    
#     answer=INF
#     for i in range(1,n+1):
#         answer = min(answer, dijkstra(s,i,n)+ dijkstra(i,a,n)+ dijkstra(i,b,n))
#     return answer