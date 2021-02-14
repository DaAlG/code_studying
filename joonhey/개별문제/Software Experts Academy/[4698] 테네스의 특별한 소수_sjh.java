package practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	static String D;
	static int A, B;
	static boolean primeNum[] = new boolean[1000000 + 1];

	public static boolean containsD(int num) {
		String numStr = Integer.toString(num);
		if (numStr.indexOf(D) == -1)
			return false;
		else
			return true;
	}

	public static void initialPrimeTable() {
		primeNum[1] = true;

		int k;
		for (int i = 2; i < B; i++) {
			if (!primeNum[i]) { // 소수 곱하기.
				k = 2;
				while (i * k <= B) {
					primeNum[i * (k++)] = true;
				}
			}
		}

	}

	public static boolean isitPrime(int num) {

		return primeNum[num] ? false : true;

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		int cnt;

		for (int t = 0; t < T; t++) {
			cnt = 0; // 테케마다 초기화
			st = new StringTokenizer(br.readLine());
			D = st.nextToken();
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			initialPrimeTable();
			for (int i = A; i <= B; i++) {
				if (isitPrime(i) && containsD(i))
					cnt++;
			}

			System.out.println("#" + (t + 1) + " " + cnt);

		}
	}
}