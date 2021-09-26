
// 1786 찾기
import java.io.*;
import java.util.*;

public class Main_1786_kmp {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		char[] T = br.readLine().toCharArray();
		char[] P = br.readLine().toCharArray();
		int tlen = T.length, plen = P.length;
		
		int[] pi = new int[plen];
		for (int i = 1, j = 0; i < plen; i++) {
			 while(j>0 && P[i] != P[j]) j = pi[j-1];
			 if(P[i] == P[j]) pi[i] = ++j;
		}
		
		int cnt = 0; // 몇 번 나타나는지
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0, j = 0; i < tlen; i++) {
			 while(j>0 && T[i] != P[j]) j = pi[j-1];
			 if(T[i] == P[j]) {
				 if(j == plen-1) { // 패턴 글자 모두 일치
					++cnt; // 카운트 증가
					list.add((i+1)-plen); 
					j = pi[j]; 
				}else { // 패턴 일치 중간 과정
					++j;
				}
			 }
		}
		System.out.println(cnt);
		StringBuilder sb = new StringBuilder();
		if(cnt>0) {
			for(int i : list) {
				sb.append(i+1).append(" ");
			}
			System.out.println(sb.toString());
		}
	}
}
