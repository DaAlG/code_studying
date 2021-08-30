import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main_1260 {
	
	static int N, M, V;
	static boolean[][] graph;
	
	static Queue<Integer> queue = new LinkedList<Integer>();
	// static boolean[] visit;
	static StringBuilder ans = new StringBuilder();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());

		graph = new boolean[N+1][N+1]; // 0번째 dummy가 되는데.. 이걸 visit 배열로 이용한다!
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			
			graph[n1][n2] = true;
			graph[n2][n1] = true;
		}
		
		// 탐색 - dfs
		graph[V][0] = true;
		dfs(V);
		
		System.out.println(ans.toString());
		
		// 탐색 - bfs
		
		// 방문 초기화
		for(int i=1; i<=N; i++) {
			graph[i][0] = false;
		}
		ans.setLength(0);
		bfs();
		System.out.println(ans.toString());
		
	}
	
	// num 정점을 방문한다.
	static void dfs(int num) {
		ans.append(num).append(" ");
		
		for (int i = 1; i <= N; i++) {
			// num 정점이 방문할 수 있는 정점
			if(graph[num][i] && !graph[i][0]) {
				// num의 정점 --> i로 갈 수 있다면 && i를 아직 방문하지 않았다면
				graph[i][0] = true;
				dfs(i);
			}
		}
	}
	
	static void bfs() {
		
		// 시작 코드
		graph[V][0] = true;
		queue.offer(V);
		
		while(!queue.isEmpty()) {
			
			int num = queue.poll();
			ans.append(num).append(" ");
			
			for (int i = 1; i <= N; i++) {
				// num 정점이 방문할 수 있는 정점
				if(graph[num][i] && !graph[i][0]) {
					// num의 정점 --> i로 갈 수 있다면 && i를 아직 방문하지 않았다면
					graph[i][0] = true;
					queue.offer(i);
				}
			}
		}
	}
}
