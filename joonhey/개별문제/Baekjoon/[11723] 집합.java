import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		int param;
		StringBuilder sb = new StringBuilder("");
		int set = 0;
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			switch (st.nextToken()) {
			case "add":
				param = Integer.parseInt(st.nextToken());
				set |= 1<<(param-1);
				break;
			case "remove":
				param = Integer.parseInt(st.nextToken());
				set &= ~ (1 << (param - 1));
				break;
			case "check":
				param = Integer.parseInt(st.nextToken());
				sb.append((set & 1<<(param-1))>>(param-1)).append("\n");
				break;
			case "toggle":
				param = Integer.parseInt(st.nextToken());
				set ^= 1 << (param - 1);
				break;
			case "all":
				set = 0xFFFFF;
				break;
			case "empty":
				set = 0;
				break;
			}
		}
		System.out.println(sb);

	}
}
