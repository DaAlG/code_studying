// 아이디어 전혀 생각 못했다..
// 이분탐색이라는데 뭘..? 했는데 구글링으로 알게 됨!
//https://swycha.tistory.com/122 감사합니다.. 이해가 쏙쏙..
import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
		long answer = 0;
        
        Arrays.sort(times); // 크기 순으로 정렬
        
        long left = 1;
        long right = n * (long)times[times.length-1]; // 가장 오래 걸리는 심사관이 n명 보는거- 최대
        //타입
        long sum = 0;
        answer = right;
        while(left <= right){
            long mid = (left + right) / 2;
            sum = 0;
            // 전체 걸리는 시간을 추정했을 때, 심사위원들이 몇 명이나 볼 수 있는지 확인해본다.
            for(int i = 0; i < times.length; i++){
                sum += mid / times[i];
            }
            // 만약 N명보다 적게 볼 수 있다면 불가능한 시간이니까 시간의 길이를 늘려준다.
            if(sum < n){
                left = mid + 1;
                // 불가능-> 시간을 더 많이
            }
            // 만약 N명보다 많이 볼 수 있다면 가능한건데, 일단 최대한 시간을 줄여보기 위해 노력해준다!
            else{  
                right = mid -1;
                answer = mid;
                //가능 -> 시간을 최대한 줄여보기
            }
        }
        
        return answer;
    }
}