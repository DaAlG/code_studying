import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

class Main{
	 static HashMap<String, Integer> map; //key: 옷 종류 - value : 가짓수
	
	 public static int getResult() {
		 int sum = 1;
		 int value;
		 for(String s : map.keySet()) {
			 value = map.get(s);
			 sum *= (value+1); //안입는거 더해주기
		 }
		 return sum;
	 }
	 
	 public static void main(String[] args) throws IOException{
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 int T = Integer.parseInt(br.readLine());
		 StringBuilder sb = new StringBuilder();
		 StringTokenizer st;
		 int res; //테케별 정답
		 
		 for(int t=0; t<T; t++) {
			int N = Integer.parseInt(br.readLine());
			map = new HashMap<>();
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				st.nextToken(); //옷  이름 노관심
				String clothKind = st.nextToken();
				if(map.get(clothKind) == null) {
					map.put(clothKind, 1);
				}
				else {
					int value = map.get(clothKind);
					map.put(clothKind, value+1);
				}
			}
			//가짓수 구하기
			res = getResult();
			sb.append(res-1).append("\n"); //알몸 제외
		 }
		 
		 //출력
		 System.out.println(sb);
	}
}