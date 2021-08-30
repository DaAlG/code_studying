import java.util.Arrays;
import java.util.Scanner;

// SWEA 1966 숫자를 정렬하자
class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
        		for (int test_case = 1; test_case <= T; test_case++) {
        			int n = sc.nextInt();
        	
        			int[] arr = new int[n];
        			for (int i = 0; i < n; i++) {
        				arr[i] = sc.nextInt();
        			}
        			Arrays.sort(arr);
        	
        			System.out.print("#" + test_case + " ");
        			for (int k : arr) {
				System.out.print(k + " ");
			}
        			System.out.println();
		}
	}
}
