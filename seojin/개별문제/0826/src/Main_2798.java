import java.io.*;
import java.util.*;

public class Main_2798 {

	static int N, M;
	static int[] cards;
	static int[] tgt;
	static int maxNum;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		cards = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			cards[i] = Integer.parseInt(st.nextToken());
		}
		
		tgt = new int[3];
		comb(0,0);
		
		System.out.println(maxNum);
	}
	
	
	static void comb(int srcIdx, int tgtIdx) {
		if(tgtIdx == 3) {
			
			int sum = 0;
			for(int i=0; i<3; i++) {
				sum += tgt[i];
			}
			
			if(maxNum<sum && sum<=M) maxNum = sum;
			return;
		}
		if(srcIdx == N) return;
		
		tgt[tgtIdx] = cards[srcIdx];
		comb(srcIdx+1, tgtIdx+1);
		comb(srcIdx+1, tgtIdx);
	}

}
