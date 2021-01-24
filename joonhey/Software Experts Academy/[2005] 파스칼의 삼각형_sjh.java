import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * [2005]. 파스칼의 삼각형
 * */

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			int N = Integer.parseInt(br.readLine());

			int[][] triangle = new int[N][];

			// 크기 달라도 ok
			for (int i = 0; i < N; i++) {
				triangle[i] = new int[i + 1];
			}

			// N은 1이상 -> [0][0] 초기화하고 시작.
			triangle[0][0] = 1;

			for (int i = 1; i < N; i++) {
				for (int j = 0; j < i + 1; j++) {

					int leftUp, rightUp;
					// 왼쪽 위
					if (j - 1 < 0) {
						leftUp = 0;
					} else {
						leftUp = triangle[i - 1][j - 1];
					}
					// 오른쪽 위
					if (j >= i) {
						rightUp = 0;
					} else {
						rightUp = triangle[i - 1][j];
					}

					// 합산.
					triangle[i][j] = leftUp + rightUp;
				}
			}
			System.out.println("#" + (t + 1));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < i + 1; j++) {
					System.out.print(triangle[i][j] + " ");
				}
				System.out.println("");
			}

		}

	}
}
