// 배열 => 해시맵 사용(통과)

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class BJ_나무재테크_16235_2 {
	
	static int N,M,K;
	static HashMap<Integer, List<Integer>> map = new HashMap<>();
	static int[][] nu, A;
	static int[][] d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	static int cnt = 0; // 나무의 수
	static int deadnu = 0; // 죽은 나무의 영양분
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		// 입력 처리
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		//  영양 정보
		nu = new int[N+1][N+1];
		A = new int[N+1][N+1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				nu[i][j] = 5;
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
			List<Integer> tree = new ArrayList<>();
			tree.add(z);
			map.put(N*y+x,tree); 
			cnt ++;
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 나이가 어린 나무부터 뽑기 위해서 정렬
				if(map.get(N*i+j) != null) {
					Collections.sort(map.get(N*i+j));
				}
			}
		}
		
		for(int k=0; k<K; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					// 봄
					if(map.get(N*i+j) != null) {
						spring(i,j);
					}
					// 여름
					if(map.get(N*i+j) != null) {
						nu[i][j] += deadnu;
					}
				}
			}
			// 가을
			fall();
			
			// 겨울
			winter();
		}
		
		// 살아있는 나무의 개수
		System.out.println(cnt);
	}
	
	static void winter() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				nu[i][j] += A[i][j];
			}
		}
	}


	static void fall() {
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				
				if( map.get(N*i+j) != null) {
					// 나무의 나이가 5의 배수라면
					List<Integer> now = map.get(N*i+j);
					for(int year: now) {
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
			if( map.get(N*ny+nx) == null) {
				List<Integer> tree = new ArrayList<>();
				tree.add(1);
				map.put(N*ny+nx, tree);
			}else {
				map.get(N*ny+nx).add(0,1);
			}
			cnt++;
		}
	}


	static void spring(int i, int j) {
		List<Integer> ntree = new ArrayList<>();
		List<Integer> now = map.get(N*i+j);
		deadnu = 0; // 봄마다 나무가 죽으니깐 초기화
		
		for (int k=0; k<now.size(); k++) {
			int year = now.get(k);
			// 현재 양분보다 나무의 나이가 적으면
			if(year <= nu[i][j]) {
				nu[i][j] -= year;
				year+=1;
				ntree.add(year);
			}
			else {
				// 양분을 받지 못한 나무는 죽고, 땅에 양분을 뿌림
				deadnu += year/2;
				cnt--;
			}
		}
		
		// 새로 양분을 받고 나이가 든 나무 정보를 업데이트
		map.put(N*i+j, ntree);
	}

	static class Ground{
		int nu; // 양분 정보
		List<Integer> tree = new ArrayList<>();
		
		public Ground(int nu) {
			this.nu = nu;
		}
	}
}
