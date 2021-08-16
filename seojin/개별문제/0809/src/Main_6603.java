import java.io.*;
import java.util.*;

public class Main_6603 {
	
	static int k;
	static int[] s;
	static int[] tgt;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		while(true) {
			st = new StringTokenizer(br.readLine());
			
			k = Integer.parseInt(st.nextToken());
			if(k == 0) break;
			
			s = new int[k];
			tgt = new int[6];
			
			for (int i = 0; i < k; i++) {
				s[i] = Integer.parseInt(st.nextToken());
			}
			
			comb(0,0);
			System.out.println();
		}
	}
	
	private static void comb(int srcIdx, int tgtIdx) {
		if(tgtIdx == 6) {
			
			for(int i=0;i<6;i++) {
				System.out.print(tgt[i]+" ");
			}
			System.out.println();
			
			return;
		}
		if(srcIdx == k) return;
		
		tgt[tgtIdx] = s[srcIdx];
		comb(srcIdx+1, tgtIdx+1);
		comb(srcIdx+1, tgtIdx);

	}

}
