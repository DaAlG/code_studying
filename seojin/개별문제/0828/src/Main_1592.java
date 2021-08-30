import java.io.*;
import java.util.*;

// 1592 영식이와 친구들
public class Main_1592 {

	static int N, M, L;
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());

		int ballCount = 0;
		int[] arr = new int[N+1];
		int index = 1;
		arr[1] = 1;	// 현재 공 포함하므로 첫 번째 사람 +1
		
		while(true) {
			// 현재 받은 사람이 홀수번 받았을 경우 -> 시계방향(index + L)
			// 현재 받은 사람이 짝수번 받았을 경우 -> 반시계(index - L)
			index = (arr[index] % 2 == 1) ? (index + L) : index - L; 
			
			// 다음 받을 사람이 배열의 범위 벗어났을 때(시계 방향일 때)
			if(index > N) 
				// 인원만큼 나눈 나머지가 다음에 받는 사람임
				// index = 7, N = 5 이면 다음엔 2번째 사람이 받음.
				index %= N;	
			
			// 다음 받을 사람이 배열의 범위 벗어났을 때(반시계 방향일 때)
			else if(index < 1) 
				// 1번이 반시계방향으로 4번에게 줘야할때 -> (-1) + 5 = 4
				index += N;
			
			arr[index] ++;	// 공 받는 사람 ++
			ballCount ++;	// 공 던진 횟수 ++
			
			// 한 사람이 공을 M번 받으면 종료
			if(arr[index] == M)
				break;
		}
		System.out.println(ballCount);
	}
}

/*
	if(N%L == 0) {
		System.out.println(N/L*(M-1));
	}else {
		System.out.println(N*(M-1));
	}
*/