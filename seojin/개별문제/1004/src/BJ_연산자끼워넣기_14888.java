import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_연산자끼워넣기_14888 {

	static int N;
	static int[] num, op, src, tgt;
	static boolean[] select;
	static long maxNum = Long.MIN_VALUE;
	static long minNum = Long.MAX_VALUE;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// 입력 처리
		N = Integer.parseInt(br.readLine());
		
		num = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		
		op = new int[4];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 4; i++) {
			op[i] = Integer.parseInt(st.nextToken());
		}
		src = new int[N-1];
		int index = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < op[i]; j++) {
				src[index++] = i;
			}
		}
		tgt = new int[N-1];
		select = new boolean[N-1];
		perm(0);
		
		System.out.println(maxNum);
		System.out.println(minNum);
	}
	
	static void perm(int tgtIdx) {
		if(tgtIdx == tgt.length) {
			long res = eval();
			maxNum = Math.max(res, maxNum);
			minNum = Math.min(res, minNum);
			return;
		}

		
		for (int i = 0; i < src.length; i++) {
			if(select[i]) continue;
			
			tgt[tgtIdx] = src[i];
			select[i] = true;
			perm(tgtIdx+1);
			select[i] = false;
		}
	}
	
	static long eval() {
		long res = num[0];
		for (int i = 1; i < num.length; i++) {
			switch(tgt[i-1]) {
				case 0:
					res += num[i];
					break;
				case 1:
					res -=  num[i];
					break;
				case 2:
					res *=  num[i];
					break;
				case 3:
					if(res<0) {
						res = ((-1)*res)/num[i]*(-1);
						break;
					}
					res /= num[i];
					break;
			}
		}
		return res;
	}

}
