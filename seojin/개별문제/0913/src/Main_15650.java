import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 백준 15649 N과 M(2)

public class Main_15650 {

	static int N, M;
	static int[] src;
	static int[] tgt;
	static int COUNT = 0;
	static boolean[] select;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		src = new int[N];
		for (int i = 0; i < N; i++) {
			src[i] = i+1;
		}
		tgt = new int[M];
		select = new boolean[src.length];
		perm(0, 0);
	}
	

	static void perm(int tgtIdx, int selectIdx) {
		// 기저 조건
		if(tgtIdx == tgt.length) {
			// complete code!!
			// 순열 하나 완성 !! = 문제에 맞는 추가 작업!
			for(int t : tgt) {
				System.out.print(t+" ");
			}
			System.out.println();
			COUNT++;
			return;
		}
		// src로부터 모든 수를 고려 - 단, 이미 선택된 숫자는 제외
		for (int i = selectIdx; i < src.length; i++) {
			// 이미 선택되어있는지 체크
			if(select[i]) {
				continue;
			}
			tgt[tgtIdx] = src[i];
			select[i] = true;
			perm(tgtIdx + 1, i);
			select[i] = false;
			
		}
	}
}
