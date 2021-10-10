// 크루스칼 -> 간선 기준으로 비용이 적은 것부터 선택
// 서로소집합

import java.io.*;
import java.util.*;

public class BJ_1197_최소스패닝트리_K {

	static int V, E;
	static int[] parent;
	static Edge[] edges;
	static long sum;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		parent = new int[V+1];
		edges = new Edge[E];
		
		// 간선
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			edges[i] = new Edge(v1, v2, c);
		}
		
		makeSet();
		
		// 간선 정렬
		Arrays.sort(edges, (e1,e2)->e1.c - e2.c);
		
		// 가장 짧은 간선부터 보면서 집합에 포함
		int cnt = 0; // 간선의 개수 (정점 V => 간선 V-1)
		for (int i = 0; i < E; i++) {
			Edge edge = edges[i];
			
			// 이 간선이 연결하는 두 개의 정점이 이미 연결되어 있는지 확인(사이클 발생)
			if(findSet(edge.v1) == findSet(edge.v2)) continue;
			
			// 집합에 포함시키기
			union(edge.v1, edge.v2);
			
			cnt++; // 선택된 간선의 개수
			sum += edge.c; // 선택된 비용의 누적 값
			
			if( cnt == V-1 ) break;
		}
		System.out.println(sum);
	
	}

	static void union(int x, int y) {
		int px = findSet(x); // 부모 찾기
		int py = findSet(y); // 부모 찾기
		
		// 작은 번호가 부모 되게끔 만들어준것
		if(px < py) parent[py] = px;
		else parent[px] = py;
		
	}

	// 경로 압축 기법,, 핻당 노드의 루트 노드가 바로 부모 노드가 됨
	static int findSet(int x) {
		if(parent[x] == x) return x;
		else return parent[x] = findSet(parent[x]);
	}
	
	static void makeSet() {
		// 자기 자신을 가리키도록 초기화
		for (int i = 1; i <= V; i++) {
			parent[i] = i;
		}
	}

	static class Edge{
		int v1;
		int v2;
		int c;
		
		public Edge(int v1, int v2, int c) {
			this.v1 = v1;
			this.v2 = v2;
			this.c = c;
		}
	}
}
