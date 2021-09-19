import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

// 백준 15649 N과 M(10)

public class Main_15664 {

	static int N, M;
	static int[] tgt;
	static int[] src;
	static StringBuilder sb = new StringBuilder();
	static StringBuilder ch = new StringBuilder();
	static boolean[] select;
	static Set<String> check;
	
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
		Arrays.sort(src);
		select = new boolean[src.length];
		tgt = new int[M];
		
		check = new HashSet<>();
		
		perm(0, 0);
		System.out.println(sb.toString());
	}
	

	static void perm(int srcIdx, int tgtIdx) {
		// 기저 조건
		if(tgtIdx == tgt.length) {
			ch.setLength(0);
			for(int t : tgt) {
				ch.append(t);
			}
			if(check.contains(ch.toString())) return; // 이미 있으면 돌아간다!
			
			// 없다면
			check.add(ch.toString());
			for(int t : tgt) {
				sb.append(t).append(" ");
			}
			sb.append("\n");
			return;
		}
		// src로부터 모든 수를 고려 - 단, 이미 선택된 숫자는 제외
		for (int i = srcIdx; i < src.length; i++) {
			
			if(select[i]) continue;
			
			tgt[tgtIdx] = src[i];
			select[i] = true;
			perm(i, tgtIdx + 1);
			select[i] = false;
			
		}
	}
}
