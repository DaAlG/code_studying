import java.util.Scanner;

public class Main_3052 {

	static boolean[] check;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		check = new boolean[42]; // 0~41 나머지 체크
		int cnt = 0;
		
		for (int i = 0; i < 10; i++) {
			int now = sc.nextInt();
			if(check[now%42]) continue;
			check[now%42] = true;
			cnt++;
		}
		
		System.out.println(cnt);
	}

}
