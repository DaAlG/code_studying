# -*- coding:utf-8 -*-

def solution(s):
    answer = 0
    
    #�ִ� ���(abcdef)���� �ʱ�ȭ
    minLength = len(s)
    
    for size in range(1, len(s)//2 + 1):
        #size�� �κ� ���ڿ��� ����, �ּ� 1������ �ִ� ��ü ���� //2 ���� ���� �� �ִ�.
        i = 0
        
        #������� �� �ȿ� �־ ��.
        stack = []
        
        #���⿡ ����� ���ڿ� �����ؼ� �� ũ�� �˾ƺ���.
        pre_sentence = [] 
        
        #s �ȱ� - i�� �κ� ���ڿ��� ���� �ε���, size ������ ��.
        while i + size <= len(s):
            part = s[i:i+size]
            
            #���� �ƹ��͵� ����
            if len(stack)==0:
                stack.append(part)
            
            #���� ���� - ���� �Ͱ� ��.
            else:       
                #���ݰ� �ٸ� - ���� �Ұ�. �������� ����.
                if stack[-1] != part:
                    ##�ϳ��ۿ� ������ ���� �Ⱥ��̰�,
                    if len(stack)==1:
                        pre_sentence.append(stack.pop())
                    ##2�� �̻��̸� �³� ����.
                    else:
                        pre_sentence.append(str(len(stack)) + stack.pop())
                        #�� ������~
                        stack.clear()
                stack.append(part)
            #���� ���� ���캸��.
            i += size
            
        #stack�� ���� �� ó�� -> �ϳ��� ������ �׳�
        if len(stack) == 1:
            pre_sentence.append(stack.pop())
        elif len(stack) > 1: #�ϳ� �̻��̸� �� ������ ���̹Ƿ� ó�����ֱ�
            pre_sentence.append(str(len(stack)) + stack.pop())
        
        #������ ������� ���� �� �� ó��...->�״�� �̾���̱�
        
        if i < len(s):
            pre_sentence.append(s[i:])
        
        
        #pre_sentence �ϼ��� 
        #������ ����Ʈ�ϱ� �̰� �ϳ��� ��������
        listToStr = ''.join(pre_sentence)
        #���� ��
        if len(listToStr) < minLength:
            minLength = len(listToStr)
        
    
    #size���� �� �غ���
    answer = minLength
    
    
    return answer
