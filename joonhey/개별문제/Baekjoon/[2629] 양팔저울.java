import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Main {
	static HashSet<Integer> set;
	static HashSet<Integer> temp;
	
	//temp의 내용 set에 모조리 옮겨닮기
	public static void deepCopy() {
		Iterator<Integer> iter = temp.iterator();
		while(iter.hasNext())
			set.add(iter.next());
	}
	public static void main(String[] args) throws IOException{
		//여기에 측정 가능한 무게 담아두기.
		set = new HashSet<>();
		//입력받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		//추 무게 입력
		for(int i=0; i<N; i++) {
			int weight = Integer.parseInt(st.nextToken());
			Iterator<Integer> iter = set.iterator();
			temp = new HashSet<>();
			//기존 추들과 더한것, 뺀것(반대편에 올려놓는경우) 다 고려하기.
			//처음엔 아무것도 없다가 점점 늘어남. 시간 복잡도 N^2 -> 추의 개수 30이하.
			while(iter.hasNext()) {
				//set에 실시간으로 담으면 iter가 예상하지 못한 원소가 추가되어 에러가 남 -> temp에다 저장해두고 deepCopy로 set에 다시 담기.
				int cur = iter.next();
				temp.add(cur + weight);
				temp.add(Math.abs(cur - weight));
			}
			//자신도 추가.
			set.add(weight);
			//옮겨 담았던 애들 다시 넣기
			deepCopy();
		}
		//판단
		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		//판단하면서 정답 StringBuilder에 담기
		StringBuilder sb = new StringBuilder("");
		for(int i=0; i<N; i++) {
			int cur = Integer.parseInt(st.nextToken());
			if(set.contains(cur))
				sb.append("Y");
			else
				sb.append("N");
			sb.append(" ");
		}
		System.out.println(sb);
	}
}
