import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{
	static int L;
 
	public static long getHashValue(String inputLine) {
		long sum = 0;
		long r = 1;
		
		for(int i = 0; i<L; i++) {
			sum += (inputLine.charAt(i) - 'a' + 1) * r % 1234567891;
			r *= 31;
            r %= 1234567891;
		}
		return sum % 1234567891;
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		L = Integer.parseInt(br.readLine());
		System.out.println(getHashValue(br.readLine()));
	}
}