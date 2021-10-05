
// 정올 2577 회전초밥
import java.io.*;
import java.util.*;

public class Main_회전초밥_2577 {
	
	static int N, d, k, c; // 접시 수, 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
	static int arr[]; // 초밥의 정보 저장
	static int count[]; // 각 종류의 초밥이 몇개씩 있는지
	static int kind = 0; // 먹은 종류의 수
	static int result = 0;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		arr = new int[N+k];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		count = new int[d+1];
		// 최대의 종류 -> 쿠폰을 사용해야만 함
		kind++;
		count[c]++;
		
		// 슬라이딩 윈도우
		// 처음 k개를 미리 계산해준다.
		for (int i = 0; i < k; i++) {
			
			if(count[arr[i]] == 0) kind++;
			count[arr[i]]++;
			
			arr[N+i] = arr[i]; // 마지막 인덱스와 첫번쨰 인덱스가 이어져있으므로 맨 뒤에 배열을 추가해서 연결되어있는것처럼 해결
			
		}
		for (int i = k; i < N+k; i++) {
			
			if(result < kind) {
				result = kind;
			}
			
			// 연속된 접시의 마지막 인덱스 뒤에 추가
			if(count[arr[i]] == 0) kind++; // 이전에 먹어보지 않은 종류라면
			count[arr[i]]++;
			
			// 연속된 접시의 첫번째 인덱스 제거
			if(count[arr[i-k]] == 1) kind--; // 하나밖에 안남은 종류라면
			count[arr[i-k]]--;
		}
		
		System.out.println(result);
	}

}
