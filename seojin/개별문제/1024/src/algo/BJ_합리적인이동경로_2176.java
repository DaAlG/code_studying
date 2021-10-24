package algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ_합리적인이동경로_2176 {

	static int N, M;
	static int[][] map;
	static LinkedList<Node>[] adj;
	
	static int[] result;
	
	static int res; // 결과값
	static int[] dp = new int[1001]; 
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		result = new int[N+1];
		
		Arrays.fill(result, Integer.MAX_VALUE);
		adj = new LinkedList[N+1];
		for (int i = 0; i <= N; i++) {
			adj[i] = new LinkedList<>();
		}
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			adj[a].add(new Node(b,c));
			adj[b].add(new Node(a,c));
		}
		
		dijkstra();
		System.out.println(dp[1]);
	}
	
	// 다익스트라 알고리즘
	static void dijkstra() {
		
		PriorityQueue<Node> pq =  new PriorityQueue<>();
		result[2] = 0;
		dp[2] = 1;
		pq.offer(new Node(2, 0));
		
		while(!pq.isEmpty()) {
			Node node = pq.poll();
			int idx = node.idx;
			int cost = node.cost;
			
			if(cost > result[idx]) {
				continue;
			}
			
			for (Node i : adj[idx]) {
				if(cost + i.cost < result[i.idx]) {
					result[i.idx] = cost + i.cost;
					pq.offer(new Node(i.idx, result[i.idx]));
				}
				
				if(cost > result[i.idx]) {
					dp[idx] += dp[i.idx];
				}
			}
		}
	}
	
	// 우선순위 큐에서 정렬기준을 잡기위해 Comparable를 구현합니다.
	static class Node implements Comparable<Node>{
		int idx;			// 노드 번호
		int cost;		// 이동 할 노드까지의 거리
 
		Node(int index, int distacne) {
			this.idx = index;
			this.cost = distacne;
		}
		
		// 최단거리를 기준으로 오름차순 정렬합니다.
		@Override
		public int compareTo(Node o) {
			return Integer.compare(this.cost, o.cost);
		}
	}
	
}
