# 원래 풀이 : 순열 찾기, base[4] 만들고 for문 돌려가면서 1/2/3/4 나올때마다 더하기-> 시간 넘넘 오래걸림!!
# 다른 풀이 : 0,1,2,3 각각 if문을 주고, 1일때는 b3만 고려, 2일때는 b2,b3 고려, 3일 때는 b2,b3,b1 고려, 4일땐 모두 고려+1 복잡하게 풀지 않고 변수 4개 이용.
from itertools import permutations
import sys
input = sys.stdin.readline

def game(line_ups):
  global inning
  hitter_idx = 0
  score = 0
  for each_inning in inning:
    outcount = 0
    b1,b2,b3 = 0,0,0
    while outcount<3:
      if each_inning[line_ups[hitter_idx]] == 0:
        outcount += 1
      elif each_inning[line_ups[hitter_idx]] == 1:
        score += b3 # 3루수만 점수 획득 가능
        b1, b2, b3 = 1, b1, b2 # 1루씩 진출
      elif each_inning[line_ups[hitter_idx]] == 2:
        score += (b2 + b3) # 2루수, 3루수가 점수 획득 가능
        b1, b2, b3 = 0, 1, b1 # 2루씩 진출
      elif each_inning[line_ups[hitter_idx]] == 3:
        score += (b2 + b3 + b1)
        b1, b2, b3 = 0, 0, 1
      elif each_inning[line_ups[hitter_idx]] == 4:
        score += (1 + b1+ b2+ b3)
        b1, b2, b3 = 0, 0, 0

      hitter_idx = (hitter_idx+1)%9
  return score


end = int(input())
inning = [list(map(int, input().split())) for _ in range(end)]

max_score = 0

for line_ups in permutations(range(1,9),8): # [1~8] 순서 정하기
  line_ups = list(line_ups[:3]) + [0] + list(line_ups[3:]) # 라인업 순서
  max_score = max(max_score, game(line_ups))

print(max_score)