import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 백준 15649 N과 M(8)

public class Main_15657 {

	static int N, M;
	static int[] tgt;
	static int[] src;
	static StringBuilder sb = new StringBuilder();
	static boolean[] select;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		src = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			src[i] = Integer.parseInt(st.nextToken());
		}
		tgt = new int[M];
		
		Arrays.sort(src);
		select = new boolean[src.length];
		perm(0, 0);
		System.out.println(sb.toString());
	}
	

	static void perm(int tgtIdx, int srcIdx) {
		// 기저 조건
		if(tgtIdx == tgt.length) {
			for(int t : tgt) {
				sb.append(t).append(" ");
			}
			sb.append("\n");
			return;
		}
		// src로부터 모든 수를 고려 - 단, 이미 선택된 숫자는 제외
		for (int i = srcIdx; i < src.length; i++) {
			tgt[tgtIdx] = src[i];
			perm(tgtIdx + 1, i);
			
		}
	}
}
