import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

// 1927 최소 힙
public class Main_11279 {

	static long N;
	static PriorityQueue<Integer> minheap = new PriorityQueue<>();
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < N; i++) {
			int now = Integer.parseInt(br.readLine());
			if(now == 0) {
				if(minheap.isEmpty()) System.out.println(0);
				else System.out.println(minheap.poll());
			}else {
				minheap.offer(now);
			}
		}
	}
}
