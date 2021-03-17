def possible(answer):
    for x,y,stuff in answer:
        if stuff == 0 : # 설치된 게 지금 기둥인 경우,
            if y==0 or [x-1,y,1] in answer or [x,y,1] in answer or [x,y-1,0] in answer:
                continue #잘 했으면 넘어가
            return False # 아니라면 거짓 반환
        elif stuff == 1: #설치된게 보라면
            if [x,y-1,0] in answer or [x+1,y-1,0] in answer ([x-1,y,1] in answer and [x+1,y,1] in answer):
                continue # 잘 했으면 넘어가
            return False
    return True


def solution(n, build_frame):
    answer = []

    for frame in build_frame:
        x,y,stuff,operate = frame

        if operate == 0: # 삭제하는경우
            answer.remove([x,y,stuff]) # 일단 삭제한 후에
            if not possible(answer): # 가능한지 확인했는데 아니라면
                answer.append([x,y,stuff])
        if operate == 1: # 설치하는경우
            answer.append([x,y,stuff]) # 일단 설치해본뒤에
            if not possible(answer):# 가능한 경우인지 확인했는데 아니라면
                answer.remove([x,y,stuff])

    return sorted(answer)
