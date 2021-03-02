from collections import deque

def solution(board, moves):
    answer = 0
    
    bowl = deque()
    bowl.append(0)
    
    for i in moves:
        print('지금 꺼내는 행은'+str(i-1))
        for j in range(len(board)):
            if board[j][i-1] != 0:
                a = bowl.pop()
                print('now is'+str(board[j][i-1]))
                if a != board[j][i-1]:
                    bowl.append(a)
                    bowl.append(board[j][i-1])
                else:
                    answer+=2 # 2개씩 사라지니까
                board[j][i-1] = 0
                break
    
    return answer