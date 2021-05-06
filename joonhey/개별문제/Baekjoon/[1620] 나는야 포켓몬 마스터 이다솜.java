import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

class Main{
	static int N, M;
	static String[] arr; //번호 - 이름
	static HashMap<String,Integer> map; // 이름 - 번호.
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new String[N + 1];
		map = new HashMap<>();
		for(int i=1; i<=N; i++) { //포켓몬 입력
			arr[i] = br.readLine();
			map.put(arr[i], i);
		}
		StringBuilder sb = new StringBuilder("");
		String inputLine;
		for(int i=0; i<M; i++) { //퀴즈
			inputLine = br.readLine();
			if(map.get(inputLine) == null)  //번호인 경우
				sb.append(arr[Integer.parseInt(inputLine)]).append("\n");
			else
				sb.append(map.get(inputLine)).append("\n");
		}
		//출력
		System.out.println(sb);
	}
}