import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
	
	static int V, E;
	static int[][] adj;
	static int minDist;
	
	public static void floyd() {
		for(int mid = 0; mid<V; mid++) {
			for(int start =0; start<V; start++) {
				for(int end=0; end<V; end++) {
					int startToMid = adj[start][mid];
					int midToEnd = adj[mid][end];
//					중간지점과 시작, 끝지점이 겹치지 않으며 이어져 있음
					if(startToMid != 0 && midToEnd != 0) {
//						원래 이어져있지 않거나 기존 값보다 더 가까운 값 업데이트.
						if(adj[start][end] == 0 || adj[start][end] > startToMid + midToEnd) {
							adj[start][end] = startToMid + midToEnd;
							if(adj[end][start] != 0 && minDist > adj[start][end] + adj[end][start])
								minDist = adj[start][end] + adj[end][start];
						}
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		adj = new int[V][V];
		minDist = Integer.MAX_VALUE;
		
		int start, end, dist;
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			dist = Integer.parseInt(st.nextToken());
			adj[start-1][end-1] = dist;
//			둘다 이어져 있으면 큐에 push
			if(adj[end-1][start-1] != 0 && minDist > dist + adj[end-1][start-1])
				minDist = dist + adj[end-1][start-1];
		}
//		플로이드-워셜로 거리 업데이트
		floyd();
		
//		최소 거리 리턴
		minDist = minDist == Integer.MAX_VALUE ? -1 : minDist;
		System.out.println(minDist);
		
	}
}