package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int maxCnt, expectedMax;
	static int maxCntIdx, expectedMaxIdx;
	static boolean[] isSelected;
	static int totalCnt;
	static int L;
	
	//p~k번, idx 번째 방청객.
	public static void shareCake(int p, int k, int idx) {
		int cnt = 0;
		
		//예상 최대 케잌 방청객은 totalCnt 관련X 진행.
		int expectedCur = k - p + 1;
		if(expectedMax < expectedCur) {
			expectedMax = expectedCur;
			expectedMaxIdx = idx;
		}
		
		if(totalCnt == L) // 케익 못줌.
			return;
		
		for(int i=p-1; i<=k-1; i++) {
			//범위 체크 필요 x 이유: p,k는 L보다 같거나 작다.
			if(!isSelected[i]) {
				isSelected[i] = true;
				cnt++;
			}
		}
		//L개 초과할 수 없는 이유: 한케익은 한명에게만
		totalCnt += cnt;
		
		if(cnt > maxCnt) {
			maxCnt = cnt;
			maxCntIdx = idx;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N;
		int p,k;
		
		L = Integer.parseInt(br.readLine());
		isSelected = new boolean[L];
		N = Integer.parseInt(br.readLine());
		
		for(int i=0; i<N; i++) {
			st=  new StringTokenizer(br.readLine());
			p = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			shareCake(p, k, i);
			//예상은 해야되니까 끝까지 돌려야 되는 건맞음.
		}
		//출력
		System.out.println(Integer.toString(expectedMaxIdx + 1));
		System.out.println(Integer.toString(maxCntIdx + 1));
		
	}
}
