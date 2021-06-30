#https://softworking.tistory.com/379 참고
#https://highrisk-highreturn.tistory.com/13 코드
import datetime

def solution(lines):
    answer = 0
    table = []
    
    for item in lines:
        splits = item.split(' ')
        
        # y,m,d,h,m,s,ms,takes_time 분리
        y, m, d = map(int,splits[0].split('-'))
        h = int(splits[1].split(':')[0])
        mm = int(splits[1].split(':')[1])
        s = int(splits[1].split(':')[2][:2])
        ms = int(splits[1].split(':')[2][3:])*1000
        
        # 걸린 시간 정수부
        takes_s = int(splits[2][:1])
        # print(splits[2])
        # 걸린 시간 소수부
        takes_ms = 0
        if len(splits[2])>2:
            takes_ms = splits[2][2:-1]
            # s-> ms로 변경하기 위해서
            while len(takes_ms)<6:
                takes_ms += '0'
                # print(take_ms)
            takes_ms = int(takes_ms)
        
        # timedelta ; 지금으로부터 얼마 뒤를 나타내기 위해 필요함.그니까 시간에서의 덧셈 규칙?인듯
        # datetime 객체에서 맨 마지막은 milli 아니라 micro
        start_time = datetime.datetime(y,m,d,h,mm,s,ms)
        temp = datetime.timedelta(seconds = takes_s, microseconds = takes_ms)
        add = datetime.timedelta(microseconds = 1)
        start_time -= temp
        start_time += add
        # 최대처리량 확인하는 구간이 1초(1000ms)이기 때문에 999ms를 애초에 작업 끝에 붙여서 찾자! 
        end_time = datetime.datetime(y,m,d,h,mm,s,ms)+datetime.timedelta(microseconds = 999000)
        table.append([start_time, end_time])
        
    stable = sorted(table, key=lambda x:x[1])
    for s in stable:
        print(s, end='\n')
    for i in range(len(stable)):
        num = 1
        for j in range(i+1, len(stable)):
            if stable[j][0] <= stable[i][1]:
                num+=1
        if num > answer:
            answer = num

        
    return answer