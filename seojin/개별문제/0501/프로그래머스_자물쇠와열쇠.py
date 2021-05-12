def rotate_a_matrix_by_90_degree(a):
    n = len(a) # 열 길이
    m = len(a[0]) # 행 길이

    result = [[0]*n for _ in range(m)] # 결과 리스트

    for i in range(n):
        for j in range(m):
            result[j][n-i-1] = a[i][j]
    return result

def check(new_lock):
    lock_length = len(new_lock)//3
    for i in range(lock_length, lock_length*2):
        for j in range(lock_length, lock_length*2):
            if new_lock[i][j] != 1:
                return False
    return True

def solution(key,lock):
    n = len(lock)
    m  = len(key)

    # 자물쇠의 크기를 3배로 변환 그러면 내 몸만큼 벽이 만들어짐
    new_lock = [[0]*(n*3) for _ in range(n*3)]
    for i in range(n):
        for j in range(n):
            # 중앙 부분에만 자물쇠 넣기
            new_lock[i+n][j+n] = lock[i][j]

    # 4가지 방향에 대해서 확인
    for rotation in range(4):
        key = rotate_a_matrix_by_90_degree(key) # 열쇠를 회전해보기
        # 그리고 방향 다 가보기
        for x in range(n*2):
            for y in range(n*2):
                # 자물쇠에 열쇠 넣기
                for i in range(m):
                    for j in range(m):
                        new_lock[x+i][y+j] += key[i][j]

                # 새로운 자물쇠에 열쇠가 정확히 들어있는지 검사하기
                if check(new_lock) == True:
                    return True
                # 자물쇠에서 열쇠를 다시 빼기
                for i in range(m):
                    for j in range(m):
                        new_lock[x+i][y+j] -= key[i][j]
    return False