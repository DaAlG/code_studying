# https://smoothieking.tistory.com/17  보고함 엉엉
import heapq
import sys
input = lambda:sys.stdin.readline().rstrip()
INF = int(1e9)

n,m = map(int,input().split())

graph = [[] for i in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

a, b = map(int, input().split())


def dijkstra(start):
    costs = [INF] * (n+1)
    heap = []

    heapq.heappush(heap,(0,start))
    costs[start] = 0

    while heap:
        dist, now = heapq.heappop(heap)
        if costs[now] < dist:
            continue

        for x in graph[now]:
            cost = dist + x[1]

            if cost < costs[x[0]]:
                costs[x[0]] = cost
                heapq.heappush(heap,(cost,x[0]))

    return costs


dist1 = dijkstra(1)
dist2 = dijkstra(a)
dist3 = dijkstra(b)

answer = min(
    dist1[a] + dist2[b] + dist3[n],
    dist1[b] + dist3[a] + dist2[n]
)

print(answer if answer < INF else -1)