package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Solution {
	static short flag;
	static int N;
	static String[] tree;
	static HashSet<String> operands = new HashSet<>();
	
	//LRV로 탐색. V됐을 때 나와 자식들의 연산자, 피연산자 여부 확인 후 수정
	public static void dfs(int cur) {
		if(cur > N)
			return;
		dfs(cur * 2);
		dfs(cur * 2 + 1);
		//VISIT-> 여기서 확인
		if(cur * 2 > N && operands.contains(tree[cur]) ==true )//리프이고 연산자임
			flag = 0;
		else if(cur *2 <=N)//리프가 아님 ->자식이 잘 되있다면 수정.
		{
			//자식 상태 확인
			if(operands.contains(tree[cur *2]) == false && operands.contains(tree[cur *2 + 1]) == false && operands.contains(tree[cur])) {
				tree[cur] = "1";
			}
			else
				flag = 0;
		}
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		operands.add("+");
		operands.add("-");
		operands.add("*");
		operands.add("/");
		
		for (int t = 0; t < 10; t++) {
			flag = 1; // 초기화
			N = Integer.parseInt(br.readLine());
			tree = new String[N+1]; 
			//트리입력
			for(int i=1; i<=N; i++) {
				st = new StringTokenizer(br.readLine());
				st.nextToken(); //정점번호
				tree[i] = st.nextToken();
			}
			if ( N % 2 == 0)
				flag = 0; //탐색할 필요 x
			else
				dfs(1);
			// 출력
			System.out.println("#"+(t+1)+" "+flag);
		}
	}
}
