from collections import deque
# queue가 아니라 스택을 써야 바로 이전 껄 볼 수 있자나..? 
def solution(s):
    answer = 0
    answer = 1000 #max
    for unit in range(1,len(s)//2+2): # 문자열 길이가 1일 때 range(1, len(s//2)+1)은 range(1,1)이 되어 버려서 +2해줘야한다고함.
        stack = deque()
        stack.append([s[:unit],1])
        for i in range(0, len(s)-unit, unit):
            now, cnt = stack.pop()
            next = s[i+unit:i+unit*2]
            if now == next:
                cnt+=1
                stack.append([now,cnt])
            else:
                stack.append([now, cnt]) # 꺼낸건 다시 넣어줘야지
                stack.append([next,1])

        compress = '' # 압축된 문자열 저장하는 곳
        while stack:
            v,c = stack.popleft() # v:'ab'이런거 c: 몇 번
            if c != 1: 
                compress += str(c) + v
            else: # 1은 세지 않음
                compress += v
        
        if answer > len(compress):
            answer = len(compress)
    
    return answer