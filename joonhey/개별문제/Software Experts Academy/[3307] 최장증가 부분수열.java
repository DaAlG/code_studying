package dp;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	//둘 다 테케마다 초기화.
	static int[] input;
	static int maxLength;
	static int[] len;
	static int N;
	
	public static void findMaxLength() {
		//각 원소 돌면서
		for(int i=0; i<N; i++) {
			//디폴트 : 내가 젤 작은놈이라 어디에도 설 수 없다 가정.
			len[i] = 1;
			//자신 이전 확인
			for(int j=0; j<i; j++) {
				//나보다 작은 놈이 있고 걔 뒤에 섰을 때 지금보다 사정이 나아짐.
				if(input[j] <= input[i] && len[j] + 1 > len[i])
					len[i] = len[j] + 1;
 			}
			//내 길이가 최대인가 ? 
			if(maxLength < len[i])
				maxLength = len[i];
		}
	}
	
	public static void main(String[] args) throws Exception{
//		String str = Double.MAX_VALUE > 1000000000 ? "YES" : "NO";
//		System.out.println(str);
		StringBuilder sb = new StringBuilder("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		for(int t=1; t<=T ; t++) {
			N = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			input = new int[N];
			len = new int[N];
			maxLength = 0;
			
			for(int i=0; i<N; i++) {
				input[i] = Integer.parseInt(st.nextToken());
			}
			findMaxLength();
			//출력
			sb.append("#").append(t).append(" ").append(maxLength).append("\n");
		}
		//최종
		System.out.println(sb);
	}
}
