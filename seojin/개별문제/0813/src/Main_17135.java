import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_17135 {

	static int N,M,D;
	
	static ArrayList<Node> archer = new ArrayList<>();
	static ArrayList<Enemy> enemy = new ArrayList<>();
	static ArrayList<Enemy> tempenemy = new ArrayList<>();
	static PriorityQueue<Enemy> q;
	static int[] tgt;
	static int[] src;
	
	// 동시에 공격하니까 위치를 담아서 한번에 제거. Hashset이용해서 중복제거
	static HashSet<Enemy> list = new HashSet<>();
	static int attackCnt, result = Integer.MIN_VALUE;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 입력 처리
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				int temp = Integer.parseInt(st.nextToken());
				
				if(temp == 1) enemy.add(new Enemy(i,j));
			}
		}

		// 궁수의 위치 조합 찾기
		tgt = new int[3];
		src = new int[M];
		for(int i=0; i<M; i++) {
			src[i] = i;
		}
		
		comb(0,0); 
		
		System.out.println(result);
	}
	
	static void comb(int srcIdx, int tgtIdx) {
		
		if(tgtIdx == tgt.length) {
			// 하나의 조합 완성!
			// 궁수 배치
			archer = new ArrayList<>();
			for(int t:tgt) {
				archer.add(new Node(N, t));
			}
			
			// 공격
			tempenemy.clear();
			for(int i=0;i<enemy.size();i++) {
				tempenemy.add(new Enemy(enemy.get(i).y, enemy.get(i).x));
			}
			attackCnt = 0;
			attack();
			
			// 궁수가 제거할 수 있는 적의 최대 수 찾기
			result = Math.max(result, attackCnt);
			
			return;
		}
		if(srcIdx == src.length) return;
		
		tgt[tgtIdx] = src[srcIdx];
		comb(srcIdx+1, tgtIdx+1);
		comb(srcIdx+1, tgtIdx);
	}

	
	static void attack() {
		q = new PriorityQueue<>();

		while(!tempenemy.isEmpty()) { // 적이 있는 동안
			list.clear();
			for (int i = 0; i < archer.size(); i++) {
				int ay = archer.get(i).y;
				int ax = archer.get(i).x;
				for (int j = 0; j < tempenemy.size(); j++) {
					int ey = tempenemy.get(j).y;
					int ex = tempenemy.get(j).x;
					
					// 거리 확인
					int d = Math.abs(ay-ey)+Math.abs(ax-ex);
					if( d <= D) {
						tempenemy.get(j).d = d;
						q.add(tempenemy.get(j)); // 공격받는 위치 저장
					}
					
				}
				
				// 제일 가깝고 왼쪽에 있는 애 꺼내기
				while(!q.isEmpty()) {
					Enemy e = q.poll();
					list.add(e);
					
					q.clear();
					
				}
			}

			for(Enemy e : list) {
				tempenemy.remove(e);
				attackCnt++;
			}
			
			// 성 방향으로 한 칸 이동(적)
			gotoCastle();
		}
	}
	
	static void gotoCastle() {
		for (int i = tempenemy.size()-1; i >=0 ; i--) {
			if(tempenemy.get(i).y+1 == N) { // 성에 도달했으면
				tempenemy.remove(i);
				continue;
			}
			tempenemy.get(i).y++;
		}
	}
}

class Node{
	int y;
	int x;
	
	public Node(int y, int x) {
		this.y = y;
		this.x = x;
	}

	@Override
	public String toString() {
		return "Archer [y=" + y + ", x=" + x + "]";
	}
	
}


class Enemy implements Comparable<Enemy>{
	int y, x, d;
	boolean dead;
	
	public Enemy() {};
	public Enemy(int y, int x) {
		this.y = y;
		this.x = x;
	}
	
	@Override
	public int compareTo(Enemy o) {
		// enemy 열 순서대로 정렬!!
		if(this.d > o.d) return 1; // 거리 가까울수록 굿. 오름차순
		else if(this.d == o.d) {
			// 거리가 같다면 왼쪽 열로 !!
			if(this.x > o.x) return 1;
			else if(this.x == o.x) return 0;
			else return  -1;
		}else return -1;
	}

	@Override
	public String toString() {
		return "Enemy [y=" + y + ", x=" + x + ", d=" + d + "]";
	}
}