package day0326;

import java.util.Scanner;

class Main{
	
	public static int getMin(int cur, int dest) {
		int cnt = -1;
		int prev = cur + 1;
		//만약 3이면 1이 되지 못함. -> prev와 cur이 같다.막힘.
		while(prev != cur) {
			prev = cur;
			if(cur == dest) {
				return cnt;
			}
			if(cur == 1)
				return -1;
			if(cur % 2 == 0) {
				cur /= 2;
				cnt++;
			}
			else if(cur % 10 == 1) {
				StringBuilder sb = new StringBuilder(Integer.toString(cur));
				sb.setLength(sb.length() - 1);
				cur = Integer.parseInt(sb.toString());
				cnt++;
			}
		}
		return -1;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int res = getMin(B, A);
		res = res == -1 ? -1 : res + 2;
		System.out.println(res);
	}
}