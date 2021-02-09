'''
그룹 단어의 기준: 한번 등장한 문자가 다시 등장할 때,
그 간격이 떨어져 있다면 그룹 단어가 아니다.
'''
#해싱 - 등장했거나/안했거나.
def isitGroup(w):
    d = {}
    for i in range(len(w)):
        if w[i] in d: #등장o
            if w[i-1]!=w[i]:
                return False
        else:#등장X
            d[w[i]] = 1
    return True

cnt=0
N = int(input())

for i in range(N):
    word = input()
    if isitGroup(word):
        cnt+=1
print(cnt)

