// 시간초과

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class BJ_나무재테크_16235 {
	
	static int N,M,K;
	static Ground[][] ground;
	static int[][] A;
	static int[][] d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		// 입력 처리
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		ground = new Ground[N+1][N+1];
		// 땅의 정보 -> 5로 초기화
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ground[i][j] = new Ground(5);
			}
		}
		
		// 추가되는 영양 정보
		A = new int[N+1][N+1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		// 심은 나무의 정보
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			
			// (y,x)에 z나이를 가진 나무 추가
			ground[y][x].tree.add(z); 
		}
		
		for(int i=0; i<K; i++) {
			// 봄
			spring();
			// 여름
			summer();
			// 가을
			fall();
			// 겨울
			winter();
		}

		
		// 살아있는 나무의 개수
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if(ground[i][j].tree != null) {
					cnt += ground[i][j].tree.size();
				}
			}
		}
		System.out.println(cnt);
	}
	
	
	static void winter() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ground[i][j].nu += A[i][j];
			}
		}
	}


	static void fall() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				
				if(ground[i][j].tree != null) {
					// 나무의 나이가 5의 배수라면
					for(int year: ground[i][j].tree) {
						if(year % 5 == 0) {
							// 8방으로 나이가 1인 나무 심기
							plantTree(i,j);
						}
					}
				}
			}
		}
	}


	private static void plantTree(int i, int j) {
		int y = i;
		int x = j;
		
		for (int k = 0; k < 8; k++) {
			int ny = y + d[k][0];
			int nx = x + d[k][1];
			
			if(ny<1 || nx<1 || ny>N || nx>N) continue;
			ground[ny][nx].tree.add(1);
		}
	}


	static void summer() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 죽은 나무가 있던 곳이라면
				if(ground[i][j].deadtree != null) {
					for(int year: ground[i][j].deadtree) {
						ground[i][j].nu += year/2;
					}
				}
			}
		}
	}


	static void spring() {
		
		// 가장 어린 나무부터 양분을 먹고 자람
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if(ground[i][j].tree != null) {
					
					// 나이가 어린 나무부터 뽑기 위해서 정렬
					Collections.sort(ground[i][j].tree);
					
					List<Integer> ntree = new ArrayList<>();
					
					for (int year: ground[i][j].tree) {
						// 현재 양분보다 나무의 나이가 적으면
						if(year <= ground[i][j].nu) {
							ground[i][j].nu -= year;
							year+=1;
							ntree.add(year);
						}
						else {
							// 양분을 받지 못한 나무는 죽음
							ground[i][j].deadtree.add(year);
						}
					}
					
					// 새로 양분을 받고 나이가 든 나무 정보를 업데이트
					ground[i][j].tree = ntree;
				}
			}
		}
	}


	static class Ground{
		int nu; // 양분 정보
		List<Integer> tree = new ArrayList<>();
		List<Integer> deadtree = new ArrayList<>();
		
		public Ground(int nu) {
			this.nu = nu;
		}
	}
}
