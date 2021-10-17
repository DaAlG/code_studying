import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BJ_숨바꼭질2_12851 {

    static int N,K;
    static int minTime = Integer.MAX_VALUE, minCnt;
    static boolean[] isCheck = new boolean[100001]; 
    static Queue<Find> queue = new LinkedList<>();
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        K = Integer.parseInt(str[1]);

        queue.add(new Find(K,0)); // 동생이 언니 찾기!
        
        while(!queue.isEmpty()) {
        	
        	Find x = queue.poll();
        	isCheck[x.val] = true;
        	
            if(x.val == N) { // 
            	// 언니를 찾았다면
            	if(minTime >= x.time) {
            		if(minTime == x.time) minCnt++;
            		else {
            			minCnt = 1;
            			minTime = x.time;
            		}
            	}
            }
            if(x.time > minTime) continue; // 최소시간보다 많이 걸리면 볼 필요 없음
            
            // 이미 방문한 곳이 아니라면 -> 넣기
        	if(x.val-1 >= 0 && !isCheck[x.val-1]) { 
            	queue.add(new Find(x.val-1, x.time+1));
            }
            if(x.val+1<=100000 && !isCheck[x.val+1]) {
            	queue.add(new Find(x.val+1, x.time+1));
            }
            if(x.val%2 == 0 && !isCheck[x.val/2]) {
            	queue.add(new Find(x.val/2, x.time+1));
            }
        }
        
        System.out.println(minTime);
        System.out.println(minCnt);
    }

    static class Find{
    	int val;
    	int time;
    	
    	public Find(int val, int cnt){
    		this.val = val;
    		this.time = cnt;
    	}
    }
}
