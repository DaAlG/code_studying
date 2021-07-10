import java.util.*;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int lottoIdx = 0;
        int winIdx = 0;
        int cnt = 0;
        int lessIdx;
        //인덱스: 일치하는 숫자 개수, 값: 순위
        int[] rank = new int[]{6,6,5,4,3,2,1};
        
        Arrays.sort(lottos);
        Arrays.sort(win_nums);
        int zeroCount = 0;
        
        while(lottoIdx != 6 && winIdx != 6){
            if(lottos[lottoIdx] == 0)
                zeroCount++;
            
            if(lottos[lottoIdx] == win_nums[winIdx]){
                cnt++;
                lottoIdx++; winIdx++;
            }
            else if(lottos[lottoIdx] < win_nums[winIdx])
                lottoIdx++;
            else
                winIdx++;
        }
        answer[1] = rank[cnt];
        answer[0] = rank[zeroCount + cnt];
        
        
        return answer;
    }
}