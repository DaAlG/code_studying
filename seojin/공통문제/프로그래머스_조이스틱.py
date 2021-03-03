import heapq
import copy
INF = int(1e9)

# 다익스트라 써서 그리디할라했는데 안풀림,, 제일 작은 거리값을 가진 애한테 먼저 가게끔 했지만 안됨. 오히려 거꾸로 돌았을때(더 멀리있음) 얘가 더 좋은 값이 나와ㅏ
def goto(start, graph, namelen, mindist):
  q = []
  heapq.heappush(q,(0,start))
  mindist[start]=0
  ans = 0
  nowindex = 0
  while q:
    dist, now = heapq.heappop(q)

    if mindist[now] < dist:
      continue

    minindex = 0
    temp = INF
    for i in range(namelen):
      if graph[now][i]!=0 and graph[now][i]<=temp:
        if mindist[i] < dist:
          continue
        temp = graph[now][i]
        minindex = i
    print(minindex)
    cost = dist+graph[now][minindex]
    if cost < mindist[minindex]:
      ans += graph[nowindex][minindex]
      nowindex = minindex
      mindist[minindex] = cost
      heapq.heappush(q,(cost,minindex))
      # break

        # cost = dist+graph[now][i]
        # if cost < mindist[i]:
        #   ans += graph[nowindex][i]
        #   nowindex = i
        #   mindist[i] = cost
        #   heapq.heappush(q,(cost,i))
        #   break

    print(q)
  return ans

def goto2(start, graph, namelen, mindist):
  q = []
  heapq.heappush(q,(0,start))
  mindist[start]=0
  ans = 0
  nowindex = 0
  while q:
    dist, now = heapq.heappop(q)

    if mindist[now] < dist:
      continue

    minindex = 0
    temp = INF
    for i in range(namelen-1,-1,-1):
      if graph[now][i]!=0 and graph[now][i]<=temp:
        if mindist[i] < dist:
          continue
        temp = graph[now][i]
        minindex = i
    print(minindex)
    cost = dist+graph[now][minindex]
    if cost < mindist[minindex]:
      ans += graph[nowindex][minindex]
      nowindex = minindex
      mindist[minindex] = cost
      heapq.heappush(q,(cost,minindex))

    # for i in range(namelen-1,-1,-1):
    #   if graph[now][i]!=0:
    #     cost = dist+graph[now][i]
    #     if cost < mindist[i]:
    #       ans += graph[nowindex][i]
    #       nowindex = i
    #       mindist[i] = cost
    #       heapq.heappush(q,(cost,i))
    #       break
    # print(q)
  return ans


def solution(name):
  answer = 0
  data = {'A':0,'B':1,'C':2,'D':3,'E':4,'F':5,'G':6,'H':7,'I':8,'J':9,'K':10,'L':11,'M':12,'N':13,'O':12,'P':11,'Q':10,'R':9,'S':8,'T':7,'U':6,'V':5,'W':4,'X':3,'Y':2,
          'Z':1}

  namelen = len(name)
  distance = [[0]*namelen for _ in range(namelen)]

  for i in range(namelen):
    for j in range(1,namelen//2+1):
      if j == namelen//2:
        mid = i+namelen//2
        if mid >= namelen:
          mid = mid-namelen
        distance[i][mid] = namelen//2
      a = i+j
      b = i+namelen-j
      if a >= namelen:
        a = a-namelen
        # distance[i][a] = i-a
      # else:
      distance[i][a] = j
      if b >= namelen:
        b = b-namelen
        # distance[i][b] = b+namelen//2
      # else:
      distance[i][b] = j

      # distance[i][a] = j
      # distance[i][b] = j
      # print(a, end=' ')
      # print(b)
    # print(distance)
  for i in range(namelen):  
    if name[i] == 'A': # 이름에 A가 있으면 거기 안가게 처리
      atemp = i
      for k in range(namelen):
        distance[k][atemp] = INF
  for i in range(namelen):  
    print(distance[i])

  mindist = [INF]*namelen
  distance2 = copy.deepcopy(distance)
  mindist2 =  copy.deepcopy(mindist)

  answer1 = goto(0, distance, namelen, mindist)
  print('answer1 is '+str(answer1))
  answer2 = goto2(0,distance2,namelen,mindist2)
  print('answer2 is '+str(answer2))
  answer = min(answer1,answer2)
  # print(mindist)
  # return answer

  makenamecnt = 0
  for i in name:
    makenamecnt += data[i]
  print(makenamecnt)

  answer+= makenamecnt

  return answer

name = 'ABABAAAAAAABA'
anss = solution(name)
print(anss)

#4,7,8,11