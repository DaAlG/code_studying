# 문자열은 변경할 수 없음. +연산자로 늘려주기
def solution(n, arr1, arr2):
    answer = ['']*(n)
    
    for i in range(n):
        temp1 = tobin(arr1[i],n)
        temp2 = tobin(arr2[i],n)
        
        for j in range(n):
            if temp1[j] == '1' or temp2[j] == '1':
                answer[i]+='#'
            else:
                answer[i]+=' '
                
    return answer

def tobin(num,n):
    result = [0]*n
    i=0
    while num>0:
        result[i]=num%2
        num//=2
        i+=1
    result = list(map(str,result))
    return ''.join(result)