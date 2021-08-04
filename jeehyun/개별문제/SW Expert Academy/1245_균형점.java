import java.util.Scanner;

class Solution {
	private static int pos[] = new int[10];
	private static int mass[] = new int[10];
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			
			for (int i = 0; i < n; i++) pos[i] = sc.nextInt();
			for (int i = 0; i < n; i++) mass[i] = sc.nextInt();
			
			System.out.print("#" + test_case + " ");
			for (int i = 0; i < n - 1; i++) {
				double left = pos[i];
				double right = pos[i + 1];
				double answer = 0;
				
				for (int j = 0; j < 50; j++) {
					double mid = (left + right) / 2;
					double sum = 0;
					
					for (int k = 0; k <= i; k++)
						sum += mass[k] / ((mid - pos[k]) * (mid - pos[k]));
					for (int k = i + 1; k < n; k++)
						sum -= mass[k] / ((mid - pos[k]) * (mid - pos[k]));
					
					if (sum > 0)
						left = mid;
					else {
						answer = mid;
						right = mid;
					}
				}
				System.out.printf("%.10f ", answer);
			}
			System.out.println();
		}
	}
}
