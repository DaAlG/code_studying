import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution {
	private static char tree[] = new char[100];
	private static int n;
	
	private static void inorder(int v) {
		if (v <= n) {
			inorder(2 * v);
			System.out.printf("%c", tree[v]);
			inorder(2 * v + 1);
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = 10;
		for (int test_case = 1; test_case <= T; test_case++) {
			n = Integer.parseInt(br.readLine());

			for (int i = 1; i <= n; i++) {
				String info[] = br.readLine().split(" ");
				tree[i] = info[1].charAt(0);
			}

			System.out.print("#" + test_case + " ");
			inorder(1);
			System.out.println();
		}
	}
}