import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA_키순서_5643 {
	
	static int T, N, M;
	static int answer;
	static ArrayList<ArrayList<Integer>> in; // 진입차수
	static ArrayList<ArrayList<Integer>> out;// 진출자수
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for (int t = 1; t <= T; t++) {
			
			// 입력 처리
			N = Integer.parseInt(br.readLine());
			M = Integer.parseInt(br.readLine());
			
			in = new ArrayList<>();
			out = new ArrayList<>();
			
			answer = 0;
			
			// 1~N 볼꺼라서 N+1까지 만들기
			for (int i = 0; i < N+1; i++) {
				in.add(new ArrayList<>());
				out.add(new ArrayList<>());
			}
			
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				
				int front = Integer.parseInt(st.nextToken());
				int back = Integer.parseInt(st.nextToken());
				
				in.get(back).add(front); // back 정점의 진입차수로 front 정점 저장
				out.get(front).add(back); // front 정점의 진출차수로 back 정점 저장
			}
			
			for (int i = 1; i <= N; i++) {
				// 각 정점마다 진입차수, 진출차수를 타고 완탐해서 나머지 정점을 모두 접근가능한지 확인
				// 각 정점 번호의 학생의 위치를 알 수 있는지 확인
				check(i);
			}
			System.out.println("#"+t+" "+ answer);
		}
	}
	
	// bfs
	static void check(int index) {
		
			Queue<Integer> q = new LinkedList<>();
			boolean[] visited = new boolean[N+1];
			
			int cnt = 0; // 정점을 발견할 때마다 갯수 증가 => 모든 점을 확인하면 정점의 갯수가 됨
			int dNow = 0;
			
			q.add(index); // 해당 정점 큐에 삽입
			visited[index] = true;
			cnt++;
			
			while(!q.isEmpty()) { // 진입차수로 아래로 끝까지 내려가기
				
				dNow = q.poll();
				
				for (int i = 0; i < in.get(dNow).size(); i++) {
					
					int t = in.get(dNow).get(i);
					
					if(!visited[t]) {
						q.add(t);	
						visited[t] = true;
						cnt++;
					}
				}
			}

			q.add(index);
			while(!q.isEmpty()) { // 진출차수로 위로 끝까지 올라가기
				
				dNow = q.poll();
				
				for (int i = 0; i < out.get(dNow).size(); i++) {
					
					int t = out.get(dNow).get(i);
					
					if(!visited[t]) {
						q.add(t);	
						visited[t] = true;
						cnt++;
					}
				}
			}
			
			if(cnt==N) answer++; // 모든 점을 확인했다면 정확한 위치를 알 수 있으므로 answer 증가
	}
}