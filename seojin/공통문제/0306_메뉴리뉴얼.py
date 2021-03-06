from itertools import combinations
def choose_best(dictionary):
                
    data = []
    s = 0
    for i in dictionary:
        if dictionary[i] >= s and dictionary[i]>=2:
            if s < dictionary[i]:
                data = []
            s = dictionary[i]
            data.append(i)
    return data
    # pass
def solution(orders, course):
    answer = []
    cnt = 0
    for num in course:
        a = dict()
        for j in orders:
            temp = list(combinations(j,num))
            # print(temp)
            
            for k in temp:
                k = list(k)
                k.sort()
                t = ''.join(k)
                
                if t in a:
                    a[t] += 1
                else:
                    a[t] = 1
            # print(a)
        b = choose_best(a)
        for i in b:
            answer.append(i)
    answer.sort()
    return answer