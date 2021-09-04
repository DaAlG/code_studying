import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

  public static List<Integer> solution(int[] progresses, int[] speeds) {
        int[] answer = new int[progresses.length];
        // 시간 측정
        for (int i = 0; i < progresses.length; i++) {
            int prog = progresses[i];
            int workingTime = 0;
            while (true) {
                if (prog >= 100)
                    break;
                prog += speeds[i];
                workingTime++;  //일한 시간 입니다.
            }
            answer[i] = workingTime;
        }
        
        //값 확인
        List<Integer> ans = new ArrayList<>();
        int i = 0;
        while(i<answer.length) {
    	   int cnt = 1;
           
           for(int j=i+1 ; j < answer.length ; j++){  
           	if(answer[i] >= answer[j]){
           		answer[j] = -1;  // 확인한 것 처리
           		i = j;
           		cnt++;
           	} else {
           		break;
           	}
           }
           i++;
           ans.add(cnt);
        }
        
        System.out.println(ans);
        return ans;
    }
    
	public static void main(String[] args) {
		solution(new int[]{93, 30, 55},new int[]{1, 30, 5});
	}

}
