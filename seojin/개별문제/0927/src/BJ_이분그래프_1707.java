// 알고리즘 월말평가 2번

import java.io.*;
import java.util.*;

public class BJ_이분그래프_1707 {

	static int T, V, E;
	static ArrayList<ArrayList<Integer>> graph;
	static int[] team;
	static String ans = "YES";
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		
		T = Integer.parseInt(br.readLine()); // 테스트 케이스의 수
		for (int i = 0; i < T; i++) {
			
			// 입력 처리
			ans = "YES";
			st = new StringTokenizer(br.readLine());
			V = Integer.parseInt(st.nextToken()); // 정점 개수
			E = Integer.parseInt(st.nextToken()); // 간선 개수
			
			graph = new ArrayList<>(); // 간선 정보 저장
			for (int j = 0; j < V; j++) {
				graph.add(new ArrayList<>());
			}
			
			for (int j = 0; j < E; j++) {
				st = new StringTokenizer(br.readLine());
				int s = Integer.parseInt(st.nextToken())-1;
				int e = Integer.parseInt(st.nextToken())-1;
				
				graph.get(s).add(e);
				graph.get(e).add(s);
			}
			
			team = new int[V];
			for (int j = 0; j < V; j++) {
				if(team[j] == 0) {
					if(!bfs(j)) break;
				}
			}
			
			System.out.println(ans);
		}
	}
	
	// 두 개의 팀을 만듦 -> 1,-1
	// 그래프의 인접요소를 방문하면서 색칠되어있지 않다면 자신과 다른 색깔로 색칠한다.
	// 이미 색칠이 되어 있는 노드라면 자신과 비교한다.
	// 같으면 빠져나오고 NO를 출력한다.
	// 끝까지 NO가 출력되지 않으면 YES를 출력한다.
	static boolean bfs(int n) {
		Queue<Integer> q = new LinkedList<>();
		q.add(n);
		team[n] = 1;
		
		while(!q.isEmpty()) {
			int node = q.poll(); // 현재 기준 노드
			
			for(Integer i: graph.get(node)) { // 기준 노드의 인접 노드 보기
				if(team[node] == team[i]) {
					// 인접한 곳이 나와 같은 팀인지 체크
					ans = "NO"; // 같다면 이분 그래프 아님!
					return false;
				}
				if(team[i] == 0) {
					// 방문하지 않았으면 자신과 반대되는 팀으로 지정
					team[i] = team[node] * -1;
					q.add(i);
				}
			}
		}
		
		return true;
	}

}
