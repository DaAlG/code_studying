package cofo;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main_D {
	static int T,N;
	static List<Long> b;
	static Set<Long> set;
	static boolean findA;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			N = Integer.parseInt(br.readLine());
			findA = false;
			
			st = new StringTokenizer(br.readLine());
			
			set = new HashSet<Long>();
			b = new ArrayList<Long>();
			
			for (int i = 0; i < N+2; i++) {
				long num = Long.parseLong(st.nextToken());
				b.add(num);
			}
			
			// b 정렬
			Collections.sort(b);
			
			// 2 2 3  / 7 12
			// 1. 0~n-1 다 더해서 -> n/n+1 값 나온다면 -> 하나는 합, 하나는 x
			long sumN = 0;
			for (int i = 0; i < N; i++) {
				long num = b.get(i);
				sumN += num;
				set.add(num);
			}
			set.add(b.get(N));
			if(sumN == b.get(N) || sumN == b.get(N+1)) {
				findA = true;
				for (int i = 0; i < N; i++) {
					System.out.print(b.get(i)+" ");
				}
				System.out.println();
			}
			
			// 2 2 3 7 / 12
			// 2. 0~n 다 더해서 -> n+1 값과 차이나는 값이 0~n에 있든지 -> 0~n 안에 x가 있음
			if(!findA) {
				long diff = sumN + b.get(N) - b.get(N+1);
				
				if(set.contains(diff)) { // 그 차이값이 b에 있다면..
					findA = true;
					b.remove(N+1);
					b.remove(new Long(diff));
					for (int i = 0; i < N; i++) {
						System.out.print(b.get(i)+" ");
					}
					System.out.println();
				}
			}
			
			// 3. 아직도 못 찾았다면
			if(!findA) System.out.println(-1);
		}
	}
}
