import java.io.*;
import java.math.BigInteger;
import java.util.*;

// 조합의 개수를 구하는 경우

public class Main_2407 {
	
	static int n,m;
	static BigInteger dpComb[][];
	
	static void setDPComb(int n, int m) {
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=i; j++) {
				if(j==0 || j==i)
					dpComb[i][j] = new BigInteger("1");
				else
					dpComb[i][j] = dpComb[i-1][j-1].add(dpComb[i-1][j]);
			}
		}
	}
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		m = sc.nextInt();
		
		
		dpComb = new BigInteger[1001][1001];
		
		setDPComb(n, m);
		System.out.println(dpComb[n][m]);
	}

}
