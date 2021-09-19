import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.StringTokenizer;

// 백준 15649 N과 M(12)

public class Main_15666{

	static int N, M;
	static int[] tgt;
	static int[] src;
	static StringBuilder sb = new StringBuilder();
	static StringBuilder ch = new StringBuilder();
	static Set<Integer> check;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		src = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=N; i++) {
			src[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(src);
		tgt = new int[M];
		
		check = new HashSet<>();
		
		perm(1, 0);
		System.out.println(sb.toString());
	}
	

	static void perm(int srcIdx, int tgtIdx) {
		// 기저 조건
		if(tgtIdx == tgt.length) {
			for(int t : tgt) {
				sb.append(t).append(" ");
			}
			sb.setLength(sb.length()-1);
			sb.append("\n");
			return;
		}
		// src로부터 모든 수를 고려 - 단, 이미 선택된 숫자는 제외
		for (int i = srcIdx; i <= N; i++) {
			if(src[i-1] == src[i]) continue;
			tgt[tgtIdx] = src[i];
			perm(i,tgtIdx + 1);
			
		}
	}
}
