import java.io.*;
import java.util.*;

public class BJ_게리멘더링_17471 {

	static int N;
	static int[] people;
	static boolean[] select;
	static boolean[][] adjMatrix;
	static int min = Integer.MAX_VALUE;
	static boolean isPossible = false;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 입력 처리
		N = Integer.parseInt(br.readLine());
		people = new int[N];
		st = new StringTokenizer(br.readLine());
		// 인구 정보
		for (int i = 0; i < N; i++) {
			people[i] = Integer.parseInt(st.nextToken());
		}
		// 인접한 구역 정보
		adjMatrix = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()); // 인접한 구역의 개수
			for (int j = 0; j < n; j++) {
				int k = Integer.parseInt(st.nextToken()); // 인접한 구역 번호
				adjMatrix[i][k-1] = true;
				adjMatrix[k-1][i] = true;
			}
		}

		// 부분집합 구하기
		select = new boolean[N];
		subset(0);
		
		System.out.println(isPossible ? min : -1);

	}

	static void subset(int cnt) {

		if(cnt == N) { 
			
			// A 선거구, B 선거구에 속하는 구역 찾기
			List<Integer> A = new ArrayList<>();
			List<Integer> B = new ArrayList<>();
			for (int i = 0; i < N; i++) {
				if(select[i]) A.add(i);
				else B.add(i);
			}
			
			// 아예 선택하지 않거나, 모두 선택된 경우는 제외
			if(A.size() == N || A.size() == 0) return;
			
			// 각 선거구가 연결되어있는지 확인!
			if(isConnect(A) && isConnect(B)) {
				// 인구 수 차이 계산
				int peopleA = calcul(A);
				int peopleB = calcul(B);
				
				min = Math.min(min, Math.abs(peopleA-peopleB));
				isPossible = true;
			}
			
			return;
		}
		
		select[cnt] = true; // 현재 인덱스 선택
		subset(cnt+1);
		
		select[cnt] = false; // 현재 인덱스 선택 x
		subset(cnt+1);
	}

	static int calcul(List<Integer> list) {
		int sum = 0;
		for(int i : list) {
			sum += people[i];
		}
		
		return sum;
	}

	static boolean isConnect(List<Integer> list) {
		
		Queue<Integer> queue = new LinkedList<>();
		boolean[] visit = new boolean[N];
		
		int start = list.get(0);
		queue.offer(start);
		visit[start] = true; // 시작 위치 방문 처리
		
		while(!queue.isEmpty()) {
			int cur = queue.poll();
			
			for (int i : list) { // 선거구 구역만 돌아보기
				if(!visit[i] && adjMatrix[cur][i]) { // 현재 구역과 연결되어있다면
					queue.offer(i);
					visit[i] = true; // 방문 처리
				}
			}
		}
		
		// visit 안했다면 연결되어 있지 않은 곳이 있다는 의미
		for (int i : list) {
			if(!visit[i]) return false;
 		}
		
		// 다 방문했다면 연결되어있음
		return true;
	}

}
