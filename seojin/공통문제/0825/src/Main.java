
// 백준 1039
import java.io.*;
import java.util.*;

public class Main {
	
	
	static String N;
	static int K;
	
	static int len, sol;
	static int[][] visit;
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = st.nextToken();
		K = Integer.parseInt(st.nextToken());
		len = N.length();
		visit = new int[K+1][1000001];
		
		sol = -1; // 연산이 불가능하다고 가정하고 시작
		sol = dfs(N, 0);
		
		System.out.println(sol);
	}
	
	static int dfs(String strN, int depth) {
		int num = Integer.parseInt(strN); // 현재 수(String)를 정수형으로 바꾸기
		
		if(depth == K) { // K번 연산 했다면 
			return num; // 끝!!
		}
		
		int ret = visit[depth][num];
		if(ret != 0) { // 같은 depth에서 방문한 이력이 있다면 
			return ret;
		}
		ret = -1; // 처음 방문한 경우, 안된다고 가정하고 -1 시작
		
		for (int i = 0; i < len-1; i++) {
			for (int j = i+1; j < len; j++) {
				
				if( i == 0 && strN.charAt(j) == '0') continue; // 0이 맨 앞으로 올 경우
				
				String tmpStr = swap(strN, i, j);
				int tRet = dfs(tmpStr, depth+1);
				ret = tRet > ret ? tRet : ret;
			}
		}
		
		visit[depth][num] = ret;
		return ret;
	}
	
	static String swap(String str, int i, int j) {
		char[] chars = str.toCharArray();
		char tmp = chars[i];
		chars[i] = chars[j];
		chars[j] = tmp;
		
		return String.valueOf(chars);
		
	}
}
