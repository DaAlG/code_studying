import java.io.*;
import java.util.*;

// 시간 초과 -> 10억개..라서..
public class Main_1256 {	
	
	static int N, M, K;
	static int[] arr; // 순열 찾기 위한 배열
	static int COUNT; // 몇번째 순열인지 체크
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// 입력
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		arr = new int[N+M];
		for (int i = 0; i < N; i++) {
			arr[i] = 1;
		}
		for (int i = N; i < N+M; i++) {
			arr[i] = 2;
		}

		do {
			COUNT ++;
			if(COUNT == K) {
				for (int i = 0; i < arr.length; i++) {
					if(arr[i] == 1) System.out.print('a');
					else if(arr[i]==2) System.out.print('z');
				}
				System.out.println();
				return;
			}
		}while(np(arr));
		System.out.println(-1);
	}
	
	static boolean np(int[] number) {
		
		int n = number.length;
		// 1. 교환할 위치 찾기
		int i = n-1;
		while(i>0 && number[i-1] >= number[i]) --i;
		if(i==0) return false; // 다음 수가 없음. 얘가 끝!
		
		// 2. 교환할 애보다 큰 가장 작은 수 찾기
		int j= n-1;
		while(number[i-1] >= number[j]) --j;
		
		// 3. 교환
		swap(number, i-1, j);
		
		// 4. 오름차순으로 바꾸기!
		int k = n-1;
		while( i < k ) {
			swap(number, i, k);
			i++;
			k--;
		}
		return true;
	}
	
	static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	} 
}
