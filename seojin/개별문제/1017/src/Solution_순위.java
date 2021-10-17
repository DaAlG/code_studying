import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution_순위 {
	
	static int[] front;
	static int[] back;
	public static int solution(int n, int[][] results) {
        int answer = 0;
        
        // 초기화
        front = new int[n+1]; // 0 dummy
        back = new int[n+1]; // 0 dummy
        
        List<Integer>[] list = new ArrayList[n+1];
        for(int i=0; i<=n; i++) {
        	list[i] = new ArrayList<>();
        }
        // result -> linkedlist로 바꾸기
        for(int i=0; i<results.length; i++) {
        	list[results[i][0]].add(results[i][1]);
        }
        
        // list 순회 -> front, back에 몇개씩 있는지 확인!
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= n; i++) { // 1번부터 ~ n번까지 확인
        	queue.add(i); 
        	boolean[] check = new boolean[n+1];
        	
            while(!queue.isEmpty()) {
            	int curIdx = queue.poll();
            	check[curIdx] = true;
            	
            	if(list[curIdx]==null) continue;
            	
            	for(int j=0; j<list[curIdx].size(); j++) {
            		int next = list[curIdx].get(j);

            		if(check[next]) continue;
            		check[next] = true;
            		queue.add(next); // curIdx 뒤에 오는 애들
            		
            		back[i]++; // 내 뒤의 cnt 증가
            		front[next]++; // next(패배) 선수보다 한 명 앞서니깐 front++
            	}
            }
		}
        
        for(int i=1; i<=n; i++) {
        	if(front[i] + back[i] == n-1) answer++;
        }
        
        // System.out.println(answer);
        
        return answer;
    }
	public static void main(String[] args) {
		solution(3, new int[][]{{3, 2}, {3, 1}});
	}
}
