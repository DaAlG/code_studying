
import java.util.*;
// 프로그래머스_프린터
class Solution_프린터 {
	class Task{
		int loc;
		int prior;
		
		public Task(int loc, int prior) {
			this.loc = loc;
			this.prior = prior;
		}
	}
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        Queue<Task> queue = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
			queue.add(new Task(i, priorities[i]));
		}
        
        int now = 0;
        
        while(!queue.isEmpty()) {
        	Task cur = queue.poll();
        	boolean flag = false;
        	
        	for(Task t : queue) {
        		if(cur.prior < t.prior) { // 나보다 큰 우선순위 있으면
        			flag = true;
        		}
        	}
        	// 뒤로 보내기
        	if(flag) {
        		queue.add(cur);
        	}else { // 나보다 큰 우선순위 없다면
        		now++;
        		if(cur.loc == location) { // 그때 찾고 싶은 위치로 왔다면
        			answer = now;
        			break; // 종료
        		}
        	}
        }
        
        return answer;
    }
}