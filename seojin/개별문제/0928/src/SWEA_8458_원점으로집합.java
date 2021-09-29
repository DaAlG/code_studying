import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_8458_원점으로집합 {

	static int T, N;
	static int maxDist;
	static int even, odd;
	static int day;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			
			N = Integer.parseInt(br.readLine());
			boolean isEnd = false;
			even = 0;
			odd = 0;
			day = 0;
			maxDist = 0;
			
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				int dist = Math.abs(y-0) + Math.abs(x-0);
				
				// 원점으로부터의 거리가 전부 짝수이거나 홀수인지 확인
				if(dist % 2 == 0) even++;
				else odd++;
				
				maxDist = Math.max(maxDist, dist);
			}
				
			if(even > 0 && odd > 0) {
				System.out.println("#"+t+" "+-1);
				continue;
			}
			
			// 가장 멀리 있는 애가 몇 번 만에 0으로 오는지
			// 마지막이 원점에서 짝수 거리여야 원점에 도달가능하다
			int res = 0;
			while(true) {
				maxDist -= day; // 상하좌우를 마음대로 움직이는데.. 최소거리니깐 제일 많이 갔다고 생각하고 빼는듯
				// 마지막 판별을 어떻게 하징 뺐는데 거리가 0보다 작아지면 마지막이네! 하고 다시 붙여주기?
				if(maxDist <= 0) {
					break;
				}
				day++;
			}
			res = Math.abs(maxDist);
			if(res % 2 != 0) {
				if(res % 2  == (day+1) % 2) day+=1;
				else day += 2;
			}
				
			System.out.println("#"+t+" "+day);
		}
	}
}
