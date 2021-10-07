// 프림 -> 연결된 정점 기준으로 비용 작은 쪽부터 선택해나감
// 우선순위큐

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ_1197_최소스패닝트리_P {

	static int V, E;
	static long sum;
	static ArrayList<ArrayList<Edge>> vertex; // 정점 리스트
	static boolean[] visit;
	static PriorityQueue<Edge> queue = new PriorityQueue<Edge>((e1, e2)->(e1.c - e2.c));
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		vertex = new ArrayList<ArrayList<Edge>>();
		
		for (int i = 0; i <= V; i++) { // 0 dummy
			vertex.add(new ArrayList<Edge>());
		}
		visit = new boolean[V+1]; // 0 dummy
		
		
		// 간선
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			vertex.get(v1).add(new Edge(v2,c));
			vertex.get(v2).add(new Edge(v1,c));
		}
		
		queue.clear();
		
		int cnt = 1; // 정점
		visit[1] = true;
		
		queue.addAll(vertex.get(1)); // 1번을 제일 먼저 넣을게~
		while(!queue.isEmpty()) {
			
			Edge edge = queue.poll(); // 현재 큐에 담긴 Edge 중 비용이 최소인 것
			if(visit[edge.v]) continue; // 이미 방문한 정점이라면 continue
			
			queue.addAll(vertex.get(edge.v));
			visit[edge.v] = true; // edge.v 방문 처리
			sum += edge.c; // 비용 더하기
			
			cnt++;
			
			if(cnt == V) break; // 정점을 V개 다 봤다면 break;
		}
		
		System.out.println(sum);
	
	}

	static class Edge{
		int v;
		int c;
		
		public Edge(int v, int c) {
			this.v = v;
			this.c = c;
		}
	}
}
