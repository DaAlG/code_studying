import java.io.*;
import java.util.*;
// 3985 롤 케이크
public class Main_3985 {

	static int L,N,P,K;
	static boolean[] cake;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		L = Integer.parseInt(br.readLine());
		cake = new boolean[L+1];
		N = Integer.parseInt(br.readLine());
		
		int maxWant = 0;
		int maxWantPerson = 0;
		int cnt = 0;
		int maxGet = 0;
		int maxGetPerson = 0;
		
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			P = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			
			if(maxWant < K-P+1) {
				maxWant = K-P+1;
				maxWantPerson = i;
			}
			cnt = 0;
			for(int j=P; j<=K; j++) {
				if(cake[j]) continue;
				cnt++;
				cake[j] = true;
			}
			
			if(maxGet < cnt) {
				maxGet = cnt;
				maxGetPerson = i;
			}
		}
		
		System.out.println(maxWantPerson);
		System.out.println(maxGetPerson);
	}

}
