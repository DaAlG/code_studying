
import java.util.*;
class Solution {
    static int[] position; //숫자가 겹칠 때 바로바로 점프하기 위해.
    static int pLen;
    static int N;

    //바뀌는 숫자의 시작점 기록.
    public void initialPosition(int[] arr){
        position[pLen++] = 0;

        for(int i=1; i<N; i++){
            if(arr[i] != arr[i-1]){
                position[pLen++] = i;
            }
        }
    }


    public int solution(int[] citations) {
        int answer = 0;
        N = citations.length;
        position = new int[N]; //최대 크기 N
        Arrays.sort(citations);
        initialPosition(citations);

        //h인덱스의 최댓값 구하기.
        int idx = 0;
        while(idx != pLen){
            int cur = position[idx];
            int h = citations[cur]; //현재 인용 수 
            //논문의 수 vs 인용된 수 해서 더 작은 것이 h인덱스
            h = N - cur <= h ? N - cur : h;
            if(answer > h)
                break;
            answer = answer <= h ? h : answer;

            idx++;

        }
        return answer;
    }


}