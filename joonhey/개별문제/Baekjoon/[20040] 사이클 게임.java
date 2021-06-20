import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static int N, M;
	static int[] parents;

	public static int find(int num) {
		if (parents[num] == num)
			return num;
		else
			return parents[num] = find(parents[num]);
	}

	public static void union(int rootA, int rootB) {
		parents[rootA] = rootB;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int res = 0;

		parents = new int[N];
		for (int i = 0; i < N; i++)
			parents[i] = i;

		int a, b;
		int rootA, rootB;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
//			root가 같은 것끼리 이어주면 사이클이 생김 -> 사이클 ~ a, a~ b, b~사이클 이렇게 순환하기 때문
			if (parents[a] == parents[b]) {
//				이미 부모가 같으면 find 연산 x -> 시간 줄이기
				res = i + 1;
				break;
			} else {
				rootA = find(a);
				rootB = find(b);
				if (rootA == rootB) {
					res = i + 1;
					break;
				} else
					union(rootA, rootB);
			}
		}
		System.out.println(res);
	}
}