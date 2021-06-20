import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
	static int N, M;
	static int[] money;
	static int tmp;
	
//	현재 상한 액 기준으로 예산 책정이 가능한 지 리턴
	public static boolean moneyAvailable(int upLimit) {
		int sum = 0;
		tmp = 0;
		int cur;
		for(int i=0; i<N; i++) {
			cur = money[i] < upLimit ? money[i] : upLimit;
			sum += cur;
			if(tmp < cur)
				tmp = cur;
		}
//		총 예산 합은 M보다 같거나 작아야 함
		return sum <= M;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		money = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++)
			money[i] = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(br.readLine());
		
		int start = 1;
		int end = M;
		int mid;
		int res = 0;
		while(start <= end) {
//			현재 상한액
			mid = (start + end) / 2;
			if(moneyAvailable(mid)) {
				res = tmp;
				start = mid + 1;
			}
			else
				end = mid - 1;
		}
		System.out.println(res);
	}
}