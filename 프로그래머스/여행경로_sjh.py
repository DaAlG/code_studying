def solution(tickets):
    answer = []
    edges =  {}
    
    for t in tickets:
        edges[t[0]] = edges.get(t[0],[]) + [t[1]]
    for e in edges:
        edges[e].sort() #알파벳 순으로 value 소팅
        
    stack = ["ICN"] #출발지로 초기화
    
    while len(stack)>0:
        top = stack[-1]
        
        #티켓 있나 조사
        if top not in edges or len(edges[top])<1:
            #갈 수 없음
            answer.append(stack.pop())
        else:
            stack.append(edges[top].pop(0))
      
    answer = answer[::-1]
    return answer