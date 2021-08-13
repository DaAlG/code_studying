import java.io.*;
import java.util.*;

public class Main_2961 {

	static int N;
	static ArrayList<Material> m = new ArrayList<>();
	static int res = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws Exception{
		
		// 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			m.add(new Material(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		for(int r=1; r<=N; r++) {
			int[] p = new int[N]; 
			// 뒤쪽부터 R개만큼 채우기
			int cnt = 0;
			while(++cnt<=r) p[N-cnt] = 1;
			
			do {
				int rs = 1, rb = 0;
				// 조합 사용
				for(int i=0;i<N;i++){
					if(p[i]==0) continue;
					rs *= m.get(i).s;
					rb += m.get(i).b;
				}
				
				res = Math.min(res, Math.abs(rs-rb));
			}while(np(p));
		}
		
		System.out.println(res);
	}
	
	// 다음 큰 순열이 있으면 true, 없으면 false
		private static boolean np(int[] numbers) {
			// TODO Auto-generated method stub
			
			int N = numbers.length;
			
			int i = N-1;
			// step1. 꼭대기 i를 찾는다. 꼭대기를 통해 교환할 위치(i-1) 찾기
			while(i>0 && numbers[i-1] >= numbers[i]) --i;
			if(i==0) { // 맨 앞까지 왔음. 내림차순이라 다음 순열이 없다!
				return false;
			}
			
			int j = N-1;
			// step2. i-1과 교환할 큰 값 찾기.(항상 있음)
			while(numbers[i-1] >= numbers[j]) --j;
			
			// step3. i-1 위치 값과 j 위치값 교환
			swap(numbers, i-1, j);
			
			// step4. 꼭대기부터 맨 뒤까지 내림차순 형태의 순열을 오름차순으로 처리
			int k = N-1;
			while(i < k) {
				swap(numbers, i++, k--);
			}
			
			return true;
		}
		
		
		private static void swap(int[] numbers, int i, int j) {
			
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}

}

class Material{
	int s;
	int b;
	
	public Material(int s, int b) {
		this.s = s;
		this.b = b;
	}
	
}