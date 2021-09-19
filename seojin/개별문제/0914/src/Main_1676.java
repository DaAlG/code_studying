import java.util.*;

public class Main_1676 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		// N이 5의 배수일 때마다 0이 하나씩 증가
		// 25의 배수일때는 0이 두번 늘어남 (25*24)..00
		// 125의 배수일때는 0이 세번 늘어남.. (125*124) ...000
		System.out.println(N/5+N/25+N/125);
	}

}
