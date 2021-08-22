import java.util.*;

public class Main_1065 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int res = 0;
		
		if(n<=99) {
			res = n;
			System.out.println(res);
		}else {
			res += 99;
			for(int i=100; i<=n; i++) {
				res += checkHanNum(i);
			}
			if(n==1000) res--;
			
			System.out.println(res);
		}

	}
	
	static int checkHanNum(int number) {
		int num1 = number/100%10;
		int num2 = number/10%10;
		int num3 = number%10;
		
		if(num2*2 == num1+num3) return 1;
		return 0;
	}

}
