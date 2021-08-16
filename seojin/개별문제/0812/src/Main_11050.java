
import java.util.*;

public class Main_11050 {
	
	static int N, K, CNT;
	static int[] src;
	static int[] tgt;
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		
		src = new int[N]; 
		for(int i=0; i<N; i++) {
			src[i] = i+1; // 자연수..1~N까지 들어간당~~~
		}
		tgt = new int[K]; // k개를 찾을 수 있숴
		
		comb(0, 0);
		
		System.out.println(CNT%10007);
	}
	
	static void comb(int srcIdx, int tgtIdx) {
		if(tgtIdx == tgt.length) {
			CNT++;
			return;
		}
		
		if(srcIdx == src.length) {
			return;
		}
		
		tgt[tgtIdx] = src[srcIdx];
		comb(srcIdx+1, tgtIdx+1); // 지금꺼 골랐고, 다음 차례로 넘어가자!
		comb(srcIdx+1, tgtIdx); // 지금꺼 맘에안드니까 다른애로 바꿔라!
		
	}
	
	// 재귀로 불가능! next permutation을 써야겠다아..!!
	

}
