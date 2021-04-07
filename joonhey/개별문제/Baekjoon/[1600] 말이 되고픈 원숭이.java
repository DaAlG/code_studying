package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	static int K; //말처럼 이동 가능한 횟수 제한.
	static int W, H;
	static int minMove; //정답
	static int[][] map;
	static int[] horse_di = {1,2,-2,-1,2,1,-1,-2};
	static int[] horse_dj = {2,1,1,2,-1,-2,-2,-1};
	//우,하,좌,상
	static int[] di = {0,1,0,-1};
	static int[] dj = {1,0,-1,0};
	static boolean[][][] visited;
	
	//큐 저장 용
	static class Node{
		int x;
		int y;
		int k;
		int cnt;
		public Node(int x, int y, int k, int cnt) {
			this.x = x;
			this.y = y;
			this.k = k;
			this.cnt = cnt;
		}
	}
	static Queue<Node> queue;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		map = new int[H][W];
		visited = new boolean[H][W][K + 1];
		
		minMove = Integer.MAX_VALUE;
		
		for(int i=0; i<H; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<W; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		queue = new LinkedList<>();
		//출발점
		queue.offer(new Node(0,0,0,0));
		
		//BFS
		while(!queue.isEmpty()) {
			Node curPos = queue.poll();
			int curCnt = curPos.cnt;
			
			//업데이트
			if(curPos.x == H - 1 && curPos.y == W - 1) {
				if(curCnt < minMove)
					minMove = curCnt;
				continue; // 더 움직일 필요 x
			}
			//말처럼 이동
			int ni, nj;
			int curK = curPos.k;
			if(curK< K) {
				for(int d=0; d<8; d++) {
					ni = curPos.x + horse_di[d];
					nj = curPos.y + horse_dj[d];
					//범위 내 && 방문 X && 장애물x
					if(ni >= 0 && ni <H && nj >= 0 && nj < W && !visited[ni][nj][curK + 1] && map[ni][nj] == 0) {
						visited[ni][nj][curK + 1] = true;
						queue.offer(new Node(ni, nj, curK+ 1,curCnt + 1));
					}
				}
			}
			//그냥 이동
			for(int d=0; d<4; d++) {
				ni = curPos.x + di[d];
				nj = curPos.y + dj[d];
				//범위내, 방문X, 장애물X
				if(ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj][curK] && map[ni][nj] == 0) {
					visited[ni][nj][curK] = true;
					queue.offer(new Node(ni, nj, curK, curCnt + 1));
				}
			}
		}
		if(minMove == Integer.MAX_VALUE) 
			System.out.println("-1");
		else
			System.out.println(minMove);
	}
}