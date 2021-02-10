def dfs(list,now,listindex,target):
    if listindex+1 < len(list):
        nextindex = listindex+1
        next = list[nextindex]
        return dfs(list, now-next, nextindex, target) + dfs(list, now+next, nextindex, target)
    else:
        if now == target:
            return 1
        else:
            return 0


def solution(numbers, target):
    answer = 0
    # 첫번째 들어오는 애도 -가 될 수 있게 해줘야해서
    numbers.insert(0,0)
    answer = dfs(numbers, numbers[0],0, target) 

    return answer
