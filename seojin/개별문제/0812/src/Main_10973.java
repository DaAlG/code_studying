import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;

public class Main_10973 {

	static int N;
	static int[] input;
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		st = new StringTokenizer(br.readLine());
		input = new int[N];
		for(int i=0;i<N;i++) {
			input[i] = Integer.parseInt(st.nextToken());
		}
		
//		np(input);
		boolean res = pp(input);
		
		if(!res) System.out.println(-1);
		else {
			for(int i : input) {
				System.out.print(i+" ");
			}
//			System.out.println(Arrays.toString(input));
		}
		
		// 순열 찾기
//		do {
//			// 순열 사용
//			System.out.println(Arrays.toString(input));
//		}while(np(input));
	}
	
	// 다음 순열 찾는.. next permutation
	static boolean np(int[] input) {
		
		// 일단 먼저 뒤에서부터 보면서 top을 찾는다. 꼭대기를 통해 교환할 애 찾기(i-1)
		int i = N-1;
		while(i>0 && input[i] <= input[i-1]) --i;
		if(i==0) return false;
		
		// 교환할 i-1를 찾았고, 나보다 큰 가장 작은 수를 찾기. 
		int j = N-1;
		while(input[i-1] >= input[j]) --j;
		
		// 교환하기!
		swap(input, i-1, j);
		
		// 꼭대기부터 내림차순인 애들을 오름차순으로 바꾸기
		int k = N-1;
		while(i < k) {
			swap(input, i++, k--);
		}
		
		return true;
	}
	
	static boolean pp(int[] input) {
		
		// 일단 먼저 뒤에서부터 보면서 top을 찾는다. 꼭대기를 통해 교환할 애 찾기(i-1)
		int i = N-1;
		while(i>0 && input[i] >= input[i-1]) --i;
		if(i==0) return false;
		
		// 교환할 i-1를 찾았고, 나보다 큰 가장 작은 수를 찾기. 
		int j = N-1;
		while(input[i-1] <= input[j]) --j;
		
		// 교환하기!
		swap(input, i-1, j);
		
		// 꼭대기부터 내림차순인 애들을 오름차순으로 바꾸기
		int k = N-1;
		while(i < k) {
			swap(input, i++, k--);
		}
		
		return true;
		
		
		
	}
	
	static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

}
