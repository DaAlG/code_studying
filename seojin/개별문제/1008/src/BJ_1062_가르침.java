import java.io.*;
import java.util.*;

public class BJ_1062_가르침 {

	static int N, K;
	static String[] words;
	static boolean[] visited;
	static int max = 0;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		// 영어 소문자 26개
		// src = "anta" "tica" => 없애기 ! 대신 알파벳 방문 처리는 해주기
		// tgt = src에서 k-5개 문자 조합 찾기 
		// 조합 -> 모두 있다면 cnt++ 아니라면 return
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		words = new String[N];
		
		for (int i = 0; i < N; i++) {
			String word = br.readLine();
			word = word.replace("anta", "");
			word = word.replace("tica", "");
			words[i] = word;
		}
		
        if(K < 5) { //a c i n t의 개수가 5개이므로
            System.out.println("0"); // 그보다 작으면 anta, tica를 읽을 수가 없음
            return;
        } else if(K == 26) { //모든 알파벳을 다 읽을 수 있다.
            System.out.println(N);
            return;
        }
        
        visited = new boolean[26]; //각 알파벳을 배웠는지 체크
        visited['a' - 'a'] = true;
        visited['c' - 'a'] = true;
        visited['i' - 'a'] = true;
        visited['n' - 'a'] = true;
        visited['t' - 'a'] = true;
        
		comb(0,0);

		System.out.println(max);
	}

	static void comb(int srcIdx, int tgtIdx) {
		if(tgtIdx == K-5) { // a c i n t 제외하고 나머지를 읽을 수 있어야함.
			int cnt = 0;
			
			for(String word : words) {
				boolean read = true;
				
				for(int i=0; i< word.length(); i++) {
					if(!visited[word.charAt(i) - 'a']) { // 조합으로 찾은 문자에 해당되지 않는다면
						read = false;
					}
				}
				if(read) cnt++; // 단어를 읽을 수 있다면
			}
			
			max = Math.max(max, cnt);
			return;
		}
		
		for(int i = srcIdx; i < 26; i++) { 
			if(visited[i]) continue;
			visited[i]  = true;
			comb(i, tgtIdx+1);
			visited[i] = false;
		}
	}
}
