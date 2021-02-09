import heapq

def solution(scoville, K):
    answer = 0
    
    heapq.heapify(scoville)
    #힙의 크기가 2 이상일 때만시행
    while len(scoville)>1:
        min1 = heapq.heappop(scoville)
        min2 = heapq.heappop(scoville)
        
        #더이상 push 해줄 필요 없음
        if min1 >=K:
            break
            
        newScoville = min1 + min2 * 2
        answer+=1
        
        heapq.heappush(scoville, newScoville)
        
    #답을 구했거나, 배열의 크기가 1이 됨
    if len(scoville)==1:
        minScoville = heapq.heappop(scoville)
        #하나 남은 게 K를 넘지 못하면 -1 리턴
        if minScoville<K:
            answer = -1
        #넘으면 pass
        
    return answer