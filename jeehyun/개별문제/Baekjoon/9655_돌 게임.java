import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// BOJ 9655 돌 게임
public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if (n % 2 == 0) System.out.println("CY");
		else System.out.println("SK");
	}
}
