import java.util.*;

public class Main_2851 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int sum = 0;
		int res = 0;
		for (int i = 0; i < 10; i++) {
			int num = sc.nextInt();
			
			if(sum + num >= 100) {
				res = Math.abs(sum-100)<Math.abs(sum+num-100)?sum:sum+num;
				break;
			}
			sum += num;
		}
		sc.close();
		if(res == 0) res = sum;
		System.out.println(res);
	}
}
