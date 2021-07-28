import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
	static int N;
	static ArrayList<Integer>[] tree;
	static Queue<Integer> queue;
	
//	bfs로 삭제
	public static void bfs() {
		
		while(!queue.isEmpty()) {
			int cur = queue.poll();
			ArrayList<Integer> curList = tree[cur];
			for(int num : curList) {
				if(tree[num] != null)
					queue.offer(num);
			}
			tree[cur] = null;
			//부모도 자식 없어짐
		}
	}
	
	public static int getLeafNode() {
		int res = 0;
		
		for(int i=0; i<N; i++)
//			자식이 사라졌거나 본래 자식이 없음.
			if(tree[i] != null) {
				if(tree[i].size() == 0) {
					res++;
				}
				else{
//					모든 자식이 사라짐
					ArrayList<Integer> list = tree[i];
					boolean flag = false;
					for(int n : list) {
						if(tree[n] != null) {
							flag = true;
							break;
						}
					}
					if(!flag) {
						res++;
					}
				}
			}
		return res;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		N = Integer.parseInt(br.readLine());
		tree = new ArrayList[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
//		트리 생성
		for(int i=0; i<N; i++) {
			tree[i] = new ArrayList<Integer>();
		}
		for(int i=0; i<N; i++) {
			int parent = Integer.parseInt(st.nextToken());
			if(parent != -1) {
				tree[parent].add(i);
			}
		}
		int deleteNode = Integer.parseInt(br.readLine());
		queue = new LinkedList<Integer>();
		queue.offer(deleteNode);
		bfs();
//		리프노드 세기
		System.out.println(getLeafNode());
		
	}
}