import java.util.Scanner;

class Solution {
	public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
		int T = 10;

		for(int test_case = 1; test_case <= T; test_case++) {
            test_case = sc.nextInt();
            
            int arr[][] = new int[101][101];
            
            int answer = 0;
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = sc.nextInt();
                    if (i == j) arr[100][100] += arr[i][j];
                    if (i + j == 99) answer += arr[i][j];
                    arr[i][100] += arr[i][j];
                    arr[100][j] += arr[i][j];
                }
            }
            
            answer = Math.max(answer, arr[100][100]);
            for (int i = 0; i < 100; i++) {
                answer = Math.max(answer, Math.max(arr[i][100], arr[100][i]));
            }
            System.out.println("#" + test_case + " " + answer);
		}
	}
}