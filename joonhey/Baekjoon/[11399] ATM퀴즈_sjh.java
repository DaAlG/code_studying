package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static int N;
	public static int[] P;
	public static int[] wait;

	public static int totalWait() {
		wait[0] = P[0];//대기시간 없는 0번.
		int total = wait[0];
		for(int i=1; i<N; i++) {
			wait[i] = wait[i-1] + P[i];
			total += wait[i];
		}
		return total;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		wait = new int[N];
		P = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			P[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(P); //오름차순 정렬.
		System.out.println(totalWait()); //총 대기시간 합 출력.
	}
}
