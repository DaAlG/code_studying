package webex;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

/*
  1. 한번 뽑은 원소는 다시 뽑을 수 없다.
  2. 순서 구별(조합X 순열O)
  3. 겹치는 수열 처리 필요
 */ 

class Main{
	static boolean[] selected;
	static boolean[] permDone; // 그 원소로 순열을 돌렸었나 체크
	static int[] input;
	static int[] numbers; //순서 구분이 필요하므로
	static int N, M;
	static StringBuilder sb;
	static HashSet<String> stringShowed;
	
	public static void perm(int cnt) {
		//기저
		if(cnt == M) {
			StringBuilder curSb = new StringBuilder("");
			//현재까지 선택된 원소 삽입
			for(int num : numbers) {
					curSb.append(num).append(" ");
			}
			//겹치는 수열 처리
			if(!stringShowed.contains(curSb.toString())) {
				stringShowed.add(curSb.toString());
				sb.append(curSb).append("\n");
			}
			return;
		}
		
		//반복
		for(int i=0; i<N; i++) {
			if(!selected[i]) {
//				가지 치기 - 같은 원소가 여러개 있을 경우, 나와 같은 원소로 이미 순열을 돌렸다면 실행하지 않는다(그 원소가 들어간 모든 수열은 앞에서 이미 해봤으니까)
				if((cnt == 0 && !permDone[input[i]]) || cnt != 0) {
					if(cnt == 0)
						permDone[input[i]] = true;
					//선택
					selected[i] = true;
					numbers[cnt] = input[i];
					perm(cnt+1);
					//복구
					selected[i] = false;
				}
			}
		}
	}
	public static void main(String[] args) throws IOException{
		sb = new StringBuilder("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		input = new int[N];
		selected = new boolean[N];
		permDone = new boolean[10001];//입력 값은 1000보다 작거나 같은 자연수
		M = Integer.parseInt(st.nextToken());
		numbers = new int[M];
		stringShowed = new HashSet<>();
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			input[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(input);
		perm(0);
		//출력
		System.out.println(sb);
	}
}