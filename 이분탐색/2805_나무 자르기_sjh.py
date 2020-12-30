# -*- coding:utf-8 -*-
#절단기의 높이를 설정하고, 나무의 길이 - 절단기 높이 만큼 상근이가 가져갈 수 있음
#나무의 수 N, 상근이가 집으로 가져가려고 하는 나무의 길이 최소 M
#M(이상) 만큼 가져가기 위해 상근이가 설정해야 하는 절단기의 최대 높이 구하기

#이진 탐색 사용 - 절단기의 높이가 0일때(가져갈 수 있는 높이: 나무의 총 길이 합, 이 때 최대로 가져감)
#                        ~ 절단기 높이가 가장큰 나무와 같을 때 (가져갈 수 있는 높이 : 0, 이 때 최소로 가져감)
#이 사이에서 M만큼 가져가도록 하는 절단기 높이의 최댓값을 구해야 함. -> 범위가 주어졌을 때 정답 찾기, 이분탐색.
import sys



N,M =map(int, sys.stdin.readline().split())
tree = list(map(int, sys.stdin.readline().split()))
tree.sort(reverse = True) #역순으로 - 절단기의 높이보다 작은 나무는 그 이후부터 pass하기 위함.


#0부터 시작해서 가져갈 수 있는 나무의 높이가 M보다 크면 절단기의 높이를 키우고,
#M보다 작으면 절단기의 높이를 줄인다.

start = 0
end = max(tree) 

while (start <= end):
    #절단기 길이 설정
    mid = (start + end)//2
    sum = 0

    #절단기로 자르기
    for t in tree:
        if t - mid >= 0:
            sum += t - mid
        else:
            break

    #잘린 나무의 길이 확인
    if sum >= M:
         #절단기 높이 늘리기
        ans = mid
        start = mid + 1
    else:
        #절단기 높이 줄이기
        end = mid - 1
        

print(ans)