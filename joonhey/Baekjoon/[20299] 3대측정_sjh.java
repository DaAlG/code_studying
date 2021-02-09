import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		int N, S, M;
		int a,b,c;
		ArrayList<Integer> approved = new ArrayList<>();
		StringBuilder sb= new StringBuilder("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for(int i=0; i<N; i++) {
			//각 동아리 별 부원들 능력치 파싱
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			if(a>=M && b>=M && c>=M && a+b+c >=S ) {
				//각자 모두 M 을 넘고, 합이 S를 넘어야 가입 가능
				approved.add(a);
				approved.add(b);
				approved.add(c);
			}
		}
		System.out.println(approved.size()/3); //동아리는 3인 1팀이므로 3을 나눠줌.
		for(int i=0; i<approved.size(); i++) { //공백 구분하여 순서대로 출력.
			sb.append(approved.get(i)).append(" ");
		}
		System.out.print(sb.toString());
	}
}