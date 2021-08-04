import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static Queue<Integer> q = new LinkedList<>();

	public static void main(String args[]) throws Exception {
		int T = 10;
		
        for (int test_case = 1; test_case <= T; test_case++) {
        	test_case = Integer.parseInt(br.readLine());
        	st = new StringTokenizer(br.readLine(), " ");
        	
        	while (st.hasMoreTokens()) {
        		q.add(Integer.parseInt(st.nextToken()));
        	}
        	
        	int cycle = 1;
        	while (true) {
        		int now = q.poll() - cycle;
        		
        		if (now <= 0) break;
        		q.add(now);
        		
        		cycle++;
        		if (cycle > 5) cycle = 1;
        	}
        	q.add(0);
        	
        	System.out.print("#" + test_case + " ");
        	while (!q.isEmpty()) {
        		System.out.printf("%d ", q.poll());
        	}
        	System.out.println();
		}
	}
}