import java.util.Scanner;

// 구냥 조합 말고 DP로 하는게 모지?
// nCr = n-1Cr-1 + n-1Cr

public class BJ_이항계수1_11050 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		int res = pascal(N,K);
		System.out.println(res);
	}

	static int pascal(int n, int r) {
		if(n==r || r == 0) return 1;
		return pascal(n-1, r-1) + pascal(n-1,r);
	}
}
