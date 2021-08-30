import java.util.Scanner;

// SWEA 2005 파스칼의 삼각형
class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
        for (int test_case = 1; test_case <= T; test_case++) {
        	int n = sc.nextInt();
        	
        	int[][] pascal = new int[n + 1][n + 1];
        	
        	for (int i = 1; i <= n; i++) {
        		for (int j = 1; j <= i; j++) {
        			if (i == 1 || i == j) pascal[i][j] = 1;
        			else pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        		}
        	}
        	
        	System.out.println("#" + test_case);
        	for (int i = 1; i <= n; i++) {
        		for (int j = 1; j <= i; j++) {
        			System.out.print(pascal[i][j] + " ");
        		}
        		System.out.println();
        	}
		}
	}
}
