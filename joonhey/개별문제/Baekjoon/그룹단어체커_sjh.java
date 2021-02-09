package baekjoon;

import java.util.Scanner;

/*
 * [1316]그룹단어체커
 * 
 */
public class 그룹단어체커_sjh {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		for(int i = 0; i<n; i++) {
			String word = sc.next();
			
			//이 알파벳이 다른 문자를 만났는지 체크함.
			boolean[] alphabet = new boolean[26];
 			boolean groupWord= true;
			
			for(int idx = 0; idx<word.length(); idx++) {
				//문자를 숫자로 ->a는 97부터 시작
				int number = (int)word.charAt(idx) - 97;
				
				//이미 나온 알파벳의 경우 그룹단어가 아님
				if(alphabet[number] == true) {
					groupWord = false;
					break;
				}
				else if(idx +1 <word.length() && word.charAt(idx+1) != word.charAt(idx)) {
					alphabet[number] = true;
				}
			}
			
			if (groupWord == true)
				ans++;
		}
		System.out.println(ans);
}
}
