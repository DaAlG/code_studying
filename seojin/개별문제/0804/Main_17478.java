package baekjoon;

import java.util.*;

// 처음엔 q += under, a[i]+= under, fa += under 이렇게 했는데 이러니까 반환될때 줄어들지 않는문제!
// line을 설정해서 under를 잠시 저장하는 역할 주기! 그러면 반환될때 under 기준이 아니라 line 기준으로 출력돼

public class Main_17478 {

	static String q = "\"재귀함수가 뭔가요?\"";
	static String[] a  = {"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
		"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
		"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""};
	static String fa = "라고 답변하였지.";
	static String ra = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
	static int cnt = 0;
	static String under = "";
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		cnt = sc.nextInt();
		
		System.out.println("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
		quest(cnt);
		
		sc.close();
	}
	
	static void quest(int n) {
		String line = under;
		if(n==0) {
			System.out.println(line+q);
			System.out.println(line+ra);
			System.out.println(line+fa);
			return;
		}

		System.out.println(line + q);
		for(int i=0;i<3;i++) {
			System.out.println(line + a[i]);
		}
		under += "____";
		quest(n-1);
		System.out.println(line + fa);
		
	}

}
