import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N, M;
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		HashSet<String> unheared = new HashSet<>();
		//듣지 못한 사람 수
		for(int i=0; i<N; i++) {
			unheared.add(br.readLine());
		}
		ArrayList<String> deutbo = new ArrayList<>();
		//보지 못한 사람 수
		String name;
		for(int i=0; i<M; i++) {
			name = br.readLine();
			if(unheared.contains(name)) {
				deutbo.add(name);
			}
		}
		Collections.sort(deutbo);
		int size = deutbo.size();
		StringBuilder sb = new StringBuilder();
		sb.append(size).append("\n");
		for(String iter : deutbo)
			sb.append(iter).append("\n");
		System.out.println(sb);
			
		
	}
}