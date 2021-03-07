package webex;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Main{
	static LinkedList<Integer> children;
	
	public static int sortChildren() {
		int cnt = 0;
		//마지막 남은 애(젤 작은 애)는 이미 정렬되있음.
		for(int i=0; i<20; i++) {
			boolean flag = false;
			//맨 앞에 뽑힘
			int maxHeight = children.get(0);
			//그 뒤에 섬
			for(int j=1; j<20; j++) {
				int curHeight = children.get(j);
			
				if(maxHeight < curHeight) {
					maxHeight = curHeight;
				}
				
				else {
					for(int k=0; k<j; k++) {//나보다 큰 애들 중 제일 앞
						if(children.get(k) > curHeight) {
							children.remove(j);
							cnt += j-k;//뒤로 물러선 사람 수
							if(k == 0)
								children.addFirst(curHeight);
							else
								children.add(k, curHeight);
							break;
						}
					}
					flag = true;
				}
			}
			
			if(flag == false) //정렬 완료: 앞으로 간 애x
				return cnt;
		}
		
		return cnt;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int P = Integer.parseInt(br.readLine());
		for(int p=1; p<=P; p++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			st.nextToken(); //번호씹기.
			children = new LinkedList<>();
			for(int i=0; i<20; i++) {
				children.add(Integer.parseInt(st.nextToken()));
			}
			//출력
			System.out.println(p+" "+sortChildren());
		}
	}
}