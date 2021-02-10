package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	static int maxWeight;
	static int[] weight;
	static int N, M;

	public static void findMaxWeight() {
		
		for(int i=0; i<N-1; i++) { // 한 봉지
			if(weight[i]>= M)
				break;
			for(int j=i+1; j<N; j++) { //두 봉지
				if(weight[i] + weight[j] > M)
					break;
				else if(weight[i] + weight[j] > maxWeight)
					maxWeight = weight[i] + weight[j];
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;

		for (int t = 0; t < T; t++) {
			maxWeight = -1;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			weight = new int[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
				weight[i] = Integer.parseInt(st.nextToken());
			Arrays.sort(weight);

			findMaxWeight();

			// 출력
			System.out.println("#" + (t + 1) + " " + maxWeight);
		}
	}
}
