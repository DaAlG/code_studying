import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

import com.sun.org.apache.bcel.internal.generic.CHECKCAST;

public class BJ_14226_이모티콘 {
	
	static int S;
	static int res;

	public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        S = Integer.parseInt(br.readLine());
               
        boolean[][] check = new boolean[2*S+1][2*S+1];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] {1, 0}); // {화면, 클립보드};
        
        while(!queue.isEmpty()) {
        	int cnt = queue.size();
        	
        	while(cnt-- > 0) { // 매번 1,2,3 의 조건을 모두 확인해보기
        		int[] cur = queue.poll();
        		
        		int display = cur[0];
        		int clip = cur[1];
        		
        		if(check[display][clip]) continue; // 이미 확인한 내용이라면 넘어가기
        		check[display][clip] = true; 
        		
        		if(display == S) { // 찾았다면
        			System.out.println(res);
        			return;
        		}
        		
//        		1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        		queue.add(new int[] {display, display}); // 화면, 클립보드
//        		2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        		if(display + clip < check.length) queue.add(new int[] {display+clip, clip});
//        		3. 화면에 있는 이모티콘 중 하나를 삭제한다.
        		if(display-1 >= 0) queue.add(new int[] { display-1, clip} );
        		
        	}
        	res++; // 연산횟수++
        }
	}

}
