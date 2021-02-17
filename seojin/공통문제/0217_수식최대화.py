from collections import deque
import itertools # 순열

def solution(expression):
  answer = 0
  num = [str(i) for i in range(0,10)]
  operand = []
  data = []
  temp = ''

  # 식 분리
  for i in expression:  
    if i in num:
      temp += i
    else:
      data.append(temp) # 숫자 넣기
      operand.append(i) # 피연산자 넣기
      temp = ''
  data.append(temp) # 마지막 숫자 넣기

  print(data)
  print(operand)
 # python - eval 문자열 수식 계산 가능

  # pri = {'*':1,'-':2,'':-1}
  # res = 0
  
  
  # #priority 경우의 수
  dic = []
  for i in operand:
    if i not in dic:
      dic.append(i)
  print(dic)
  # priority 만들기
  y = [i for i in range(1,len(dic)+1)]
  y_permu = itertools.permutations(y,len(dic))

  pri = dict()

  answer = 0
  for yp in y_permu:
    print(yp)

    for cnt in range(len(yp)):
      pri[dic[cnt]] = yp[cnt] # 이런식으로 해야 동시에 집어넣기 가능
    pri[''] = -1
    # print('dic is')
    # print(pri)
    res = calcul(data,operand,pri)
    if res > answer:
      answer = res
  return answer    

def calcul(data, operand, priority):
  
  prev = '' # 이전 operator
  now = '' # 초기, 현재 operator

  result = '' #결과 저장할 문자열
  # nowpr = 0
  stack = deque()
  # print('--------------')
  # print(data)
  # print(operand)
  # print(priority)
  for i in range(len(data)):
    if i != len(data)-1:
      now = operand[i]
      if priority[now] > priority[prev]: #prev]: # 현재 operand가 우선순위가 더 높다면,
        stack.append(now)
        result += '('
        
      result += data[i]
      # print('중간점검')
      # print(result)
      if priority[now] < priority[prev]:
        # prev = stack.pop()
        # print('now is '+now+'prev is '+prev)
        while stack:
          prev = stack[-1]
          if priority[now] == priority[prev]:
            break
          # print('여기 1')
          result += ')'
          prev = stack.pop()
      result += now
      prev = now
      now = ''
    else:
      result += data[i]
      while stack:
        result+=')'
        stack.pop()
    print(stack)
    print(result)
  print(result)
  return abs(eval(result))


expression = "50*6-3*2"
print(expression)
print(solution(expression))
