import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Main {
	static boolean[] visited;
	static int N;
	static HashSet<Integer>[] up;
	static HashSet<Integer>[] down;
	static LinkedList<Integer>[] list;

//	root는 시작 인덱스, cur은 현재 인덱스.
	public static void dfs(int root, int cur) {
//		일단 방문표시.
		if(root != cur) {
			up[root].add(cur);
			down[cur].add(root);
		}
		visited[cur] = true;
		for(int num : list[cur]) {
			if(!visited[num])
				dfs(root, num);
		}
	}
	
	public static void main(String[] args) throws Exception {
		int TC;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M;
		TC = Integer.parseInt(br.readLine());
		StringTokenizer st;
		list = new LinkedList[501]; //N이 최대 500개.
		up =new HashSet[501];
		down =new HashSet[501];
		StringBuilder sb = new StringBuilder("");
		for(int t=1; t<=TC; t++) {
			N = Integer.parseInt(br.readLine());
//			각 인덱스보다 작은 앧르 몇개나 있는지.
			M = Integer.parseInt(br.readLine());
//			리스트 입력.
			for(int i=1; i<=N; i++) {
				list[i] = new LinkedList<>();
				up[i] = new HashSet<>();
				down[i] = new HashSet<>();
			}
			
			for(int i=0; i<M; i++) {
				st = new StringTokenizer(br.readLine());
				list[Integer.parseInt(st.nextToken())].add(Integer.parseInt(st.nextToken()));
			}
			
//			각 인덱스별로 탐색.
			for(int i=1; i<=N; i++) {
				if(up[i].size() + down[i].size() != N-1) {
					visited = new boolean[N+1];
					dfs(i,i);
				}
			}
//			각 인덱스별로 확인.
			int sum = 0;
			for(int i=1; i<=N; i++) {
				if(up[i].size() + down[i].size() == N-1)
					sum++;
			}
			sb.append("#").append(t).append(" ").append(sum).append("\n");
			
		}
		System.out.println(sb);
		
	}

}