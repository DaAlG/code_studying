package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
class Solution{
	
	static int N;
	static int[][] map;
	static int S,X,Y; //-1주의.
	static int[] di = {-1,1,0,0};
	static int[] dj = {0,0,-1,1};
	static class Virus implements Comparable<Virus>{
		int x;
		int y;
		int num;
		public Virus(int x, int y, int num) {
			this.x = x;
			this.y = y;
			this.num = num;
		}
		@Override
		public int compareTo(Virus o) {
			return Integer.compare(this.num, o.num);
		}
		
	}
	static Queue<Virus> queue;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		queue = new LinkedList<>();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] != 0) {
					//바이러스 큐에 넣기
					queue.offer(new Virus(i,j,map[i][j]));
				}
			}
		}
		//번호가 작은 것부터 확산.
		Collections.sort((List<Virus>) queue);
		
		st = new StringTokenizer(br.readLine());
		S = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());
		Y = Integer.parseInt(st.nextToken());
		X--;Y--;
		int cur = 0;
		int ni, nj;
		
		//큐가 비어있지 않고, 시간이 S미만일 때, 아직 x,y 위치 바이러스퍼지기 전.
		while(map[X][Y] == 0 && !queue.isEmpty() && cur != S) {
			int qSize = queue.size();
			int q = 0;
			//특정 시간에 퍼질 바이러스들만 -> qsize만큼만 순회.
			while(q<qSize && map[X][Y] == 0) {
				Virus curVirus = queue.poll();
				//현재 바이러스 기준으로 사방탐색
				for(int d=0; d<4; d++) {
					ni = curVirus.x + di[d];
					nj = curVirus.y + dj[d];
					//만약 찾고자 하는 범위면 기록하고 끝낸다.
					//범위확인, 방문확인
					if(ni >= 0 && ni < N && nj >= 0 && nj < N && map[ni][nj] == 0) {
						map[ni][nj] = curVirus.num;
						if(ni == X && nj == Y)
							break;
						queue.offer(new Virus(ni, nj, map[ni][nj]));
					}
				}
				q++;
			}
			cur++;
		}
		//정답출력
		System.out.println(map[X][Y]);
		
	}
}