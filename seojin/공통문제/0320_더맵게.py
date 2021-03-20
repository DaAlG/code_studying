import heapq
def solution(scoville, K):
    answer = 0

    q = []
    for i in scoville:
        heapq.heappush(q,i)

    while q:
        if len(q)>=2:
            first = heapq.heappop(q)
            second = heapq.heappop(q)
            if first<K or second<K: 
                new = first+ (second*2)
                heapq.heappush(q,new)
                answer+=1
            else: 
                break
        else:
            if heapq.heappop(q)<K:
                answer = -1
                break

    return answe