import java.util.*;
import java.io.*;

// 음의 가중치 -> 다익스트라로는 못함
// 벨만-포드 써야해~!

public class Main_11657 {

	static int N, M;
	static int INF = 500 * 10000; // 문제 정보
	static long[] dist;
	static Bus[] busArr;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); // 도시 수
		M = Integer.parseInt(st.nextToken()); // 노선 수
		dist = new long[N+1]; // 최단거리 배열
		busArr = new Bus[M+1]; 
		
		// 최단 거리 배열 초기화
		for (int i = 1; i <= N; i++) dist[i] = INF;
		// 입력 초기화
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			
			busArr[i] = new Bus(A,B,C);
		}
		
		if(bellmanFord()) {
			for (int i = 2; i <= N; i++) {
				sb.append(dist[i]==INF ? "-1\n" : dist[i]+"\n");
			}
		}else {
			sb.append("-1\n");
		}
		
		System.out.println(sb.toString());
	}
	
	static boolean bellmanFord() {
		dist[1] = 0;
		
		// (정점-1 번) 동안 수행!
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Bus bus = busArr[j];
				
				if(dist[bus.start] != INF) {
					dist[bus.end] = Math.min(dist[bus.end], dist[bus.start]+bus.weight);
				}
			}
		}
		
		// 음수 사이클 있는지 확인! -> 한번 더 돈다.
		for (int i = 0; i < M; i++) {
			Bus bus = busArr[i];
			
			// 정점 탐색이 끝났는데도 다시 도니깐 값이 작아지는 곳이 있다면
			// 음수 사이클 있네! -> false 반환
			if(dist[bus.start] != INF && dist[bus.end] > dist[bus.start] + bus.weight) {
				return false;
			}
		}
		
		return true;
	}
	
	static class Bus{
		int start, end, weight;

		public Bus(int start, int end, int weight) {
			this.start = start;
			this.end = end;
			this.weight = weight;
		}
		
	}
}
