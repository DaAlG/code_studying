import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

// 11279 최대 힙
public class Main_1927 {

	static long N;
	static PriorityQueue<Integer> maxheap = new PriorityQueue<>((i,j)->-(i-j));
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < N; i++) {
			int now = Integer.parseInt(br.readLine());
			if(now == 0) {
				if(maxheap.isEmpty()) System.out.println(0);
				else System.out.println(maxheap.poll());
			}else {
				maxheap.offer(now);
			}
		}
	}
}
