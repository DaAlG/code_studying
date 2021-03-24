package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static boolean[] visited;
	static int[][] matrix; //간선 개수 저장.
	static StringBuilder sb;
	static Queue<Integer> queue;
	//current번째 정점 방문.
	public static void dfs(int current){
		sb.append(current).append(" ");
		//가지 뻗기
		for(int i=1; i<=N; i++) {
			//인접해 있고 방문 하지 않았으면
			if(matrix[current][i] != 0 && !visited[i]) {
				visited[i] = true;
				dfs(i);
			}
		}
	}
	
	public static void bfs() {
		while(!queue.isEmpty()) {
			int current = queue.poll();
			sb.append(current).append(" ");
			for(int i=1; i<=N; i++) {
				if(matrix[current][i] != 0 && !visited[i]) {
					visited[i] = true;
					queue.offer(i);
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		int M, startIdx;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		//정점 수 및 간선 수 입력받음
		N = Integer.parseInt(st.nextToken());
		matrix = new int[N+1][N+1]; //각 행에 대해서도 공간 할당 해야 함.
		for(int i=0; i<N; i++)
			matrix[i] = new int[N+1];
		M = Integer.parseInt(st.nextToken());
		startIdx = Integer.parseInt(st.nextToken());
		//인접 행렬 입력하긔
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			//양방향(무방향)
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			matrix[from][to]++;
			matrix[to][from]++;
		}
		
		/****** DFS ******/
		visited = new boolean[N+1]; // BFS 돌릴 때 또 리셋 해줘야 함.
		sb = new StringBuilder("");
		//처음 방문.
		visited[startIdx] = true;
		dfs(startIdx);
		System.out.println(sb);
		
		/****** BFS ******/
		queue = new LinkedList<Integer>();
		visited = new boolean[N+1]; 
		sb = new StringBuilder("");
		//처음 방문.
		queue.offer(startIdx);
		visited[startIdx] = true;
		bfs();
		System.out.println(sb);
	}
}
