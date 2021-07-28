import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = 10;
		for (int test_case = 1; test_case <= T; test_case++) {
			int n = Integer.parseInt(br.readLine());
			
			int b[] = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) {
				b[i] = Integer.parseInt(st.nextToken());
			}
			
			int answer = 0;
			for (int i = 2; i < n - 2; i++) {
				boolean check = true;
				int view = 255;
				
				for (int j = -2; j <= 2; j++) {
					if (j == 0) continue;
					if (b[i + j] > b[i]) {
						check = false;
						break;
					}
					view = Math.min(view, b[i] - b[i + j]);
				}
				
				if (check) {
					answer += view;
				}
			}
			System.out.println("#" + test_case + " " + answer);
		}
	}
}
