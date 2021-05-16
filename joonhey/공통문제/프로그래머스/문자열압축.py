# -*- coding:utf-8 -*-

def solution(s):
    answer = 0
    
    #최대 기록(abcdef)으로 초기화
    minLength = len(s)
    
    for size in range(1, len(s)//2 + 1):
        #size는 부분 문자열의 길이, 최소 1개부터 최대 전체 문장 //2 까지 묶을 수 있다.
        i = 0
        
        #사이즈별로 이 안에 넣어서 비교.
        stack = []
        
        #여기에 압축된 문자열 저장해서 그 크기 알아보자.
        pre_sentence = [] 
        
        #s 훑기 - i는 부분 문자열의 시작 인덱스, size 단위로 비교.
        while i + size <= len(s):
            part = s[i:i+size]
            
            #아직 아무것도 없음
            if len(stack)==0:
                stack.append(part)
            
            #무언가 있음 - 지금 것과 비교.
            else:       
                #지금과 다름 - 압축 불가. 내보내고 들어가기.
                if stack[-1] != part:
                    ##하나밖에 없으면 숫자 안붙이고,
                    if len(stack)==1:
                        pre_sentence.append(stack.pop())
                    ##2개 이상이면 걔네 압축.
                    else:
                        pre_sentence.append(str(len(stack)) + stack.pop())
                        #다 내보내~
                        stack.clear()
                stack.append(part)
            #다음 묶음 살펴보기.
            i += size
            
        #stack에 남은 것 처리 -> 하나만 있으면 그냥
        if len(stack) == 1:
            pre_sentence.append(stack.pop())
        elif len(stack) > 1: #하나 이상이면 다 동일한 것이므로 처리해주기
            pre_sentence.append(str(len(stack)) + stack.pop())
        
        #묶음이 사이즈보다 남은 것 도 처리...->그대로 이어붙이기
        
        if i < len(s):
            pre_sentence.append(s[i:])
        
        
        #pre_sentence 완성됨 
        #묶음별 리스트니까 이걸 하나의 문장으로
        listToStr = ''.join(pre_sentence)
        #길이 비교
        if len(listToStr) < minLength:
            minLength = len(listToStr)
        
    
    #size별로 다 해봤음
    answer = minLength
    
    
    return answer