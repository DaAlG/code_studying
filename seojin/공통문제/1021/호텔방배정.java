import java.util.*;

class Solution {
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];
        
        TreeSet<Long> nextRoom = new TreeSet<Long>(); // 다음 빈 방이 될 수 있는 번호들. 정렬됨
        LinkedHashSet<Long> ret = new LinkedHashSet<Long>(); // 고객이 들어갈 수 있는 방 번호들 들어온 순서대로 저장됨
        int idx = 0;
        
        for(int i=0; i<room_number.length; i++){
            long cur = room_number[i];
            
            if(ret.contains(cur)){
                // 현재 방이 찼다면 -> 다른 방 찾아야함(제일 가까운 번호의)
                
                long nRoom = nextRoom.ceiling(cur); // nextRoom에 들어있는 cur의 바로 다음 빈방 찾아오기
                
                ret.add(nRoom); // 방 배정
                nextRoom.remove(nRoom); // 이 방번호는 썼으므로 제거
                
                // 다음 빈 방 넣기(nRoom을 방 배정 했으므로 의 다음 빈 방 넣어줘야함)
                if(!ret.contains(nRoom+1)) nextRoom.add(nRoom+1); 
                
            }else{
                // 현재 방이 비어있다면
                
                ret.add(cur); // 방 배정
                nextRoom.remove(cur); // 방 번호는 썼으므로 제거
                
                // 다음 빈 방 넣기
                if(!ret.contains(cur+1)) nextRoom.add(cur+1);
            }
        }
        
        Iterator<Long> iter = ret.iterator();
        while(iter.hasNext()){
            Long num = iter.next();
            // System.out.println(num);
            answer[idx++] = num;
        }
        
        return answer;
    }
}

/* 한 번에 한 명씩 신청한 순서대로 방배정
 * 고객은 투숙하기 원하는 방 번호 신청
 * 고객이 원하는 방이 비었다면 즉시 배정
 * 고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방 배정
 */

// https://velog.io/@jms8732/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%98%B8%ED%85%94-%EB%B0%A9-%EB%B0%B0%EC%A0%95
// treeset을 이용하면 정렬+set이니깐 좋을 것 같아서 검색했는데
// 그걸 이용하는 문제가 아니구 ceiling 메서드 이용하면 뚝딱임
// 해당 객체가 존재하면 그 객체를 리턴, 없으면 그 바로 뒤의 객체를 리턴