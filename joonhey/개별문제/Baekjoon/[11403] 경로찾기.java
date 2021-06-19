import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
	static int N;
	static int[][] dist;
	
	public static void floyd() {
		int startToMid, midToEnd;
		for(int mid = 0; mid < N; mid++) {
			for(int start = 0; start < N; start++) {
				for(int end = 0; end < N; end++) {
					startToMid = dist[start][mid];
					midToEnd = dist[mid][end];
					if(startToMid != 0 && midToEnd != 0) {
//						아예 경로가 없거나, 오래걸리거나 -> 업데이트 필요
//						경로의 유무만 중요하므로 오래걸리는거 굳이 업데이트 안해도 될듯
						if(dist[start][end] == 0) {
							dist[start][end] = startToMid + midToEnd;
						}
					}
				}
			}
		}
	}
	public static void printArray() {
		StringBuilder sb = new StringBuilder("");
//		출력
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(dist[i][j] != 0)
					sb.append(1);
				else
					sb.append(0);
				sb.append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
//	그냥 플로이드로 모든 경로간 거리 구하고, 0이면 (이동불가)면 0 출력, 그 외는 1 출력 시키면 됨
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		dist = new int[N][N];
		StringTokenizer st;
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++)
				dist[i][j] = Integer.parseInt(st.nextToken());
		}
		floyd();
		printArray();
	}
}