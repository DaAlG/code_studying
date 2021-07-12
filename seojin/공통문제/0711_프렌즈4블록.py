# 집합 이용
# 아이디어는 찾았는데 해결방법 찾는데 시간 걸렸음.. 집합.. ㅇㅋ... 

def pop_num(b,m,n):
  pop_set = set()

  # search
  for i in range(1,n):
    for j in range(1,m):
      if b[i][j] == b[i-1][j-1] == b[i-1][j] == b[i][j-1] != '_':
        # union 연산자 : |
        # 터지는 애들 다 집어넣기 
        pop_set |= set([(i,j),(i-1,j-1),(i-1,j),(i,j-1)])
  
  # set_board 터진 애들은 다 0으로 ~
  for i,j in pop_set:
    b[i][j] = 0

  # 모으기
  for i, row in enumerate(b):
    empty=  ['_'] * row.count(0) # 없어진 수만큼 empty 
    b[i] = empty + [block for block in row if block!=0] # empty 블록을 한쪽으로 밀고 0이 아닌 블록만 모으기   
  
  return len(pop_set)


def solution(m,n,board):
  count = 0
  # *: list/tuple에 있는 원소들을 차례대로 꺼내어 함수 인자에 대응.
  # board를 행/열을 바꾸어 조작하기 쉽게한다.
  # 리스트 뒤집는 방법
  b = list(map(list, zip(*board)))
  
  while True:
    pop = pop_num(b,m,n)
    if pop == 0:
      return count
    count += pop
  
  return count


# m = 4
# n = 5
# board = ["CCBDE", "AAADE", "AAABF", "CCBBF"]
# solution(m,n,board)