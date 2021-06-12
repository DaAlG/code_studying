import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static int N, M;
	static long[][] dist;
	// 한 점-> 다른 점 최댓값이 100만, 최대 파티장 개수 500개이므로
	// 최장거리 : 499 * 100만 -> int로 거리 계산 시 오버플로우 발생가능.

	public static void floyd() {
		for (int middle = 1; middle <= N; middle++) {
			for (int start = 1; start <= N; start++) {
				for (int end = 1; end <= N; end++) {
					dist[start][end] = Math.min(dist[start][middle] + dist[middle][end], dist[start][end]);
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
//		파티장 수, 요청 수
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

//		거리 배열 초기화 
		// 1번 파티장부터 시작함.
		dist = new long[N + 1][N + 1];
//	      연결되지 않은 건 -1 -> 이 문제의 경우 모두 연결되어 있음.
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= N; j++) {
//				dist[i][j] = -1;
//			}
//		}
//		파티장 사이 거리 입력 (자기 자신까지 거리는 0)
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				dist[i][j] = Long.parseLong(st.nextToken());
			}
		}
//		플로이드-워샬로 최단경로 계산.
		floyd();
//		요청 입력받고, 값 저장하기
		StringBuilder sb = new StringBuilder("");
		for (int t = 0; t < M; t++) {
			st = new StringTokenizer(br.readLine());
			int start, end;
			long time;
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			time = Long.parseLong(st.nextToken());
			long runtime = dist[start][end];
			if ( runtime > time)
				sb.append("Stay here");
			else
				sb.append("Enjoy other party");
			sb.append("\n");
		}
		sb.setLength(sb.length()-1);
		System.out.println(sb);
	}
}