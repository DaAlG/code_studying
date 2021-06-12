import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main{
	static int N, M;
	static int[] parent;
	static int[] city;
	
	public static int find(int cur) {
		if(parent[cur] == cur)
			return cur;
		else
			return parent[cur] = find(parent[cur]);
	}
	
	public static void union(int root, int element) {
//		조상이 같은지 체크
//		처음에 부모가 달라서
		if(parent[element] != parent[root]) {
//			추적 해봄 -> 그래도 다르면 합치자
			int findA = find(root);
			int findB = find(element);
			if(findA != findB) {
				parent[findB] = parent[findA];
			}
		}
	}
	
//	윾니온 파인드
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
//		parent 초기화
		parent = new int[N+1];
		for(int i=1; i<=N; i++)
			parent[i] = i;
//		연결 정보 받기
		for(int i=1; i<=N; i++) {
		    st = new StringTokenizer(br.readLine());
			for(int j=1; j<=i; j++) {
//				받았던 정보는 필요 없음 - 씹기.
				st.nextToken();
			}
			for(int j=i+1; j<=N; j++) {
//					연결되있다면
				if(st.nextToken().equals("1")) {
//					이어주기
					union(i, j);
				}
			}
		}
		st = new StringTokenizer(br.readLine());
		if(M == 1) 
			System.out.println("YES");
		else if(M == 0)
			System.out.println("NO");
		else {
			city = new int[M];
			for(int i=0; i != M; i++) {
				city[i] = Integer.parseInt(st.nextToken());
			}
//			두개씩 묶긔
			int i = 0; int j = 1;
			boolean flag = false;
			while(j < M ){
//				범위 내에 있고, 부모가 같으면 연결되있으므로 횡단 가능
				if(city[i] < 1 || city[i] > N || find(city[i]) != find(city[j])) {
					flag = true;
					break;
				}
				i++;j++;
			}

			if(flag)
				System.out.println("NO");
			else
				System.out.println("YES");
			
		}
		
	}
}