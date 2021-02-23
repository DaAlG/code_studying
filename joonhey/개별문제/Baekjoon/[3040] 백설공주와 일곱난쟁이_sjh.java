import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{
	static int[] numbers;
	static boolean[] selected;
	
	public static void printRes() {
		for(int i=0; i<9; i++)
			if(selected[i])
				System.out.println(numbers[i]);
	}
	
	public static void comb(int target, int sum, int cnt) {
		if(cnt == 2) {
			if(sum == 100)
				printRes();
			return;
		}
		if(sum < 100)
			return;
		if(target == 9)
			return;
		selected[target] = false;
		comb(target+1, sum - numbers[target], cnt+1);
		selected[target] = true;
		comb(target+1, sum , cnt);
		
	}
	
	public static void main(String[] args) throws IOException{
		numbers = new int[9];
		selected = new boolean[9];
		int sum = 0;
		int input;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0; i<9; i++) {
			input = Integer.parseInt(br.readLine());
			numbers[i] = input;
			sum += input;
			selected[i] = true;
		}
		comb(0, sum, 0);
	}
}