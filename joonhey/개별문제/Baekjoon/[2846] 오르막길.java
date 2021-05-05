import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int N;
	static int[] road;
	static int maxLength;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		road = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			road[i] = Integer.parseInt(st.nextToken());
		}

		int i = 0;
		int startLength;
		while (i < N)
		{
			if (i < N - 1 && road[i + 1] > road[i]) {
				startLength = road[i];
				while(i < N - 1 && road[i + 1] > road[i]) {
					i++;
				}
				if(road[i] - startLength > maxLength)
					maxLength = road[i] - startLength;
			}
			i++;
		}
		System.out.println(maxLength);
	}
}
