import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int V, E, K;
	static int INF; // 도달할 수 없음을 표시
	static int[] minDist;
	static boolean[] visited;
	static LinkedList<Node>[] adjList; // 인접 리스트 ([from][to])
	static PriorityQueue<Node> pq;
	static class Node implements Comparable<Node>{
		int vertex;
		int weight;

		public Node(int vertex, int weight) {
			this.vertex = vertex;
			this.weight = weight;
		}

		@Override
		public int compareTo(Node o) {
			return this.weight - o.weight;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		adjList = new LinkedList[V + 1]; // 1 ~ V
		minDist = new int[V + 1];
		visited = new boolean[V + 1];
		pq = new PriorityQueue<>();
		INF = 10 * E + 1;
		// 링크드 리스트 객체 생성
		for (int i = 1; i <= V; i++) {
			adjList[i] = new LinkedList<>();
		}

		K = Integer.parseInt(br.readLine());
		int from, to, weight;
		/////////////////// 간선 입력///////////////////
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			weight = Integer.parseInt(st.nextToken());
			// 이미 같은 출발, 목적지의 간선 존재하나 확인
			adjList[from].addFirst(new Node(to, weight));
		}
		///////// 출발지로부터의 최소 거리 초기화////////////
		for (int i = 1; i <= V; i++) {
			minDist[i] = INF;
		}
		minDist[K] = 0;
		pq.offer(new Node(K, 0));
		// K부터 출발 -> 모든 정점을 방문할 때까지
		while(!pq.isEmpty()) {
			// 1. 현재 방문 지점 (갸장 가까운 곳)
			Node curNode = pq.poll();
			int curDist = curNode.weight;
			int curVertex = curNode.vertex;
			////이미 좀 전에 더 빠른 길로 나왔음 뒷북 ㄴㄴ visited를 큐 넣을 때 말고 빼고 하는 이유? -> 이 다음에 더 작은 경로 나올수도 있으므로
			if(visited[curVertex])
				continue; 
			//20 -> 3 vs 21 ->2 는 20 -> 23넣기 -> 21 ->22넣기 로 진행. 그런데 23넣기에서 visiteㅇ 해버리면 이 담에 못담음.
			visited[curVertex] = true;
			//종료지점 있는 경우 curVertex가 목적지면 끝
			for (Node adjNode : adjList[curNode.vertex]) {
				// 2. 현재 방문 지점 기준으로 업데이트 하기.
				if (minDist[adjNode.vertex] > adjNode.weight + curDist) {
					minDist[adjNode.vertex] = adjNode.weight + curDist;
					//업뎃한거 다시 넣긔
					pq.add(new Node(adjNode.vertex, adjNode.weight + curDist));
				}
			}
		}
		StringBuilder sb = new StringBuilder("");
		for (int i = 1; i <= V; i++) {
			if (visited[i] == false)
				sb.append("INF");
			else
				sb.append(minDist[i]);
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
