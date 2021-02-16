import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int weight = Integer.parseInt(br.readLine());
		int cnt = 0;
		
		while (weight > 0) {
			if(weight % 5 == 0)
				weight -= 5;
			else if(weight % 3 == 0)
				weight -= 3;
			else
				weight -= 5;
			cnt++;
		}
		if(weight < 0)
			cnt = -1;
		System.out.println(cnt);
	}
}