import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] army; //input 저장
	static int[] length; //최장 수열 기록
	static int N; //병사 수
	static int maxLength;
	static int[] outArmy;
	static int res;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		maxLength = 0; //최대 길이 기록.
		N = Integer.parseInt(br.readLine());
		army = new int[N];
		length = new int[N];
		outArmy = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			army[i] = Integer.parseInt(st.nextToken()); 
			length[i] = 1;
//			i번째에서 끝나는 최장 수열의 길이는 ?
			for(int k=0;k<i; k++) {
//				앞에 원소들뒤에 슬수 있는지.
				if(army[k] > army[i] && length[k]+1 > length[i])
				{
					length[i] = length[k] + 1;
					outArmy[i] = outArmy[k] + i-k-1;
//					앞사람 열외.
				}
			}
//			앞사람 열외.
			if(length[i] == 1)
				outArmy[i] = i;
//			뒷사람두 열외.
			if(length[i] > maxLength) {
				maxLength = length[i];
				res = outArmy[i] + N - i - 1;
			}
		}
//		System.out.println(maxLength);
		System.out.println(res);
	}
}
