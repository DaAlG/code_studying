import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 백준 15649 N과 M(3)
// 출력을 System.out.print로 했더니 시간초과 생겼다
// -> Stringbuilder사용해서 모아놨다가 한번에 출력했더니 통과.

public class Main_15651 {

	static int N, M;
	static int[] tgt;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		tgt = new int[M];
		perm(0);
		System.out.println(sb.toString());
	}
	

	static void perm(int tgtIdx) {
		// 기저 조건
		if(tgtIdx == tgt.length) {
			for(int t : tgt) {
				sb.append(t).append(" ");
			}
			sb.append("\n");
			return;
		}
		// src로부터 모든 수를 고려 - 단, 이미 선택된 숫자는 제외
		for (int i = 1; i <= N; i++) {
			tgt[tgtIdx] = i;
			perm(tgtIdx + 1);
			
		}
	}
}
