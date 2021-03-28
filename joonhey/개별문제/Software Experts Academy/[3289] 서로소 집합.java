package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static int n;
	static StringBuilder sb;
	static int[] parent;
	
	//1인 대표 만들기
	public static void makeSet() {
		for(int i=1; i<=n; i++) {
			parent[i] = i;
		}
	}
	
	public static int findSet(int element) {
		if(parent[element] == element)
			return element;
		else
			//내 대장은 내 부모의 대장과 같아!!!!!
			//첫 시도는 효율성이 또ㄱ같지만 다음에 해당 원소에 접근할 때부터 위로 올라갈 필요가 없으니까 확연히 달라짐.
			return parent[element] = findSet(parent[element]);
	}
	
	//param1의 집합과 param2의 집합을 합친다.
	public static boolean unionSet(int param1, int param2) {
		int smaller = param1 <= param2 ? param1 : param2;
		int bigger = smaller == param1 ? param2 : param1;
		//각자 대장을 찾고 같으면 합칠 필요  x
		int aRoot = findSet(smaller);
		int bRoot = findSet(bigger);
		//이 때, 각자 parent를 root로 초기화 하는 과정이 일어남(path compression)

		if(aRoot == bRoot) {
			return false;
		}
		//다르면 합친다.
		parent[bRoot] = aRoot;
		return true;
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int m;
		sb = new StringBuilder("");
		StringTokenizer st;
		
		for(int t=1; t<=T; t++) {
			//테케 시작
			sb.append("#").append(t).append(" ");
			//n, m 입력
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			parent = new int[n+1]; //1~n
			//1 ~ n 까지의 각자 집합 make
			makeSet();
			//m번 연산 -> 0이면 union, 1이면 find -> 결과값 틈틈이 저장.
			for(int i=0; i<m; i++) {
				st = new StringTokenizer(br.readLine());
				String cmd = st.nextToken(); //명령어
				int param1 = Integer.parseInt(st.nextToken());
				int param2 = Integer.parseInt(st.nextToken());
				//0이면 union
				if(cmd.equals("0")) {
					unionSet(param1, param2);
				}
				//1이면 확인 ( sb에 추가)
				else {
					String curSb = findSet(param1) == findSet(param2)? "1" : "0";
					sb.append(curSb);
				}
			}
			//테케 끝
			sb.append("\n");
		}
		//최종 출력
		System.out.println(sb);
	}
	
}
