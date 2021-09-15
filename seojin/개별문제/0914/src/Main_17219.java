import java.util.*;
import java.io.*;

public class Main_17219 {

	static Map<String, String> webSiteInfo = new HashMap<>();
	static int N, M;
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			webSiteInfo.put(st.nextToken(), st.nextToken());
		}
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < M; i++) {
			sb.append(webSiteInfo.get(br.readLine())).append("\n");
		}
		
		System.out.print(sb.toString());
	}
}
