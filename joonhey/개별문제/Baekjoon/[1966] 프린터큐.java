import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	static int cnt;
	static class Node{
		int num;
		boolean important;
		public Node(int num, boolean important) {
			this.num = num;
			this.important = important;
		}
	}
	static int[] biggerCnt;
	static Queue<Node> queue;
	static int N, M;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		//정답 출력용
		StringBuilder sb = new StringBuilder("");
		for(int t=1; t<=T; t++) {
			//테케마다 초기화
			cnt = 0;
			biggerCnt = new int[10]; //현재 중요도보다 높은 중요도를 가진 문서가 몇개나 있는지. 중요도 1 ~ 9
			queue = new LinkedList<>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			//큐에 문서 삽입 -> 관심있는 문서는 따로 (M 범위 별로 for문 분류해서 if문 없애기)
			st = new StringTokenizer(br.readLine());
			int num;
			for(int i=0; i<M; i++) {
				num = Integer.parseInt(st.nextToken());
				queue.offer(new Node(num, false));
				//나보다 작은 숫자들은 본인보다 큰 원소가 들어왔으므로 값을 증가시킴.
				for(int n=1; n<num; n++)
					biggerCnt[n]++;
			}
			//관심있는 문서(M번째)
			num = Integer.parseInt(st.nextToken());
			queue.offer(new Node(num, true));
			for(int n=1; n<num; n++)
				biggerCnt[n]++;
			
			//관심있는 문서 이후 삽입
			for(int i=M+1; i<N; i++) {
				num = Integer.parseInt(st.nextToken());
				queue.offer(new Node(num, false));
				for(int n=1; n<num; n++)
					biggerCnt[n]++;
			}
			//프린트
			while(!queue.isEmpty()) {
				Node front = queue.poll();
				int curNum = front.num;
				//만약 나보다 큰게 뒤에 있다면
				if(biggerCnt[curNum] != 0) {
					//맨 뒤에 넣어준다.
					queue.offer(front);
				}else {
					//나보다 큰 게 없으면 빼내되,몇번째로 빼냈는지 기록
					cnt++;
					if(front.important) // 관심있는 원소의 순번 알아냈으니 break
						break;
					//내가 빠짐 -> 나보다 작은 원소들은 자신보다 큰 원소 개수가 줄어듦
					for(int n=1; n<curNum; n++)
						biggerCnt[n]--;
				}
			}
			sb.append(cnt).append("\n");
		}
		System.out.println(sb);
		
	}
}