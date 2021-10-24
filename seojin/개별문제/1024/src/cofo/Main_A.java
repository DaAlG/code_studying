package cofo;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_A {

	static int T,N;
	static NumberIdx arr[];
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			
			// 입력 처리
			N = Integer.parseInt(br.readLine());
			arr = new NumberIdx[N];
			
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				int num = Integer.parseInt(st.nextToken());
				arr[i] = new NumberIdx(num, i+1);
			}
			
			// 하나 빼곤 같은 수이므로 정렬을 하면
			// 맨 앞이나 맨 뒤에 spy가 있게 됨
			// 2번째 원소와 첫번째 원소 비교/마지막 원소 비교
			Arrays.sort(arr); // 오름차순 정렬
			
			if(arr[0].num != arr[1].num) {
				System.out.println(arr[0].idx);
			}else if(arr[N-1].num != arr[1].num){
				System.out.println(arr[N-1].idx);
			}
		}
	}

	
	static class NumberIdx implements Comparable<NumberIdx>{
		int num;
		int idx;
		
		public NumberIdx(int num, int idx) {
			this.num = num;
			this.idx = idx;
		}

		@Override
		public int compareTo(NumberIdx o) {
			return this.num - o.num;
		}

	}

}
