import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_어항정리_23291 {

	static int N, K;
	static FishBowl[][] fishbowls;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// 입력 처리
		// 어항 수가 변하지는 않으므로 N을 받아서 최대 크기를 만들기
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		fishbowls = new FishBowl[N][N];
		for (int i = 0; i < N; i++) {
			fishbowls[i] = new FishBowl[N];
			
			if(i == N-1) {
				// 처음엔 가장 아래 부분에 넣기
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					fishbowls[i][j] = new FishBowl(i, j, Integer.parseInt(st.nextToken()));
				}
			}
		}
		// 물고기 가장 많은 곳 - 가장 적은 곳 <= K 일때까지
		
		// 1. 물고기 수가 가장 작은 어항에 물고기 1마리 넣기
		
		// 2. 어항 쌓기
			// 2-1. 가장 왼쪽 어항을 그 다음 어항 위에 올리기
			// 2-2. 2개 이상 쌓여 있는 어항 떼기 => 시계방향 90'회전 => 바닥에 올리기
			// 		열 -> 행 돌리기로 해서 하고 싶은데 좀 많이 헷갈리는구만,, 오른쪽에 잇는게 젤 아래로 가야함ㅇ으음..
			// 2-3. 공중부양 하는애 중 맨 오른쪽 바닥에 있는 애 밑에 아무것도 없다면 이전 상황으로 돌리고 끝내기
	
		// 3. 물고기 수 조절
			// 3-1. 새로운 배열 하나 만들어서 인접한 두 어항 사이의 물고기 수 차이 구하기
					// 왼-> 오 순서로 이동한다면, 아래와 오른쪽만 비교하면 됨
			// 3-2. 원래 배열 + 차이 배열 더해주기
		
		// 4. 어항 놓기
			// 왼쪽 열부터 => 오른쪽 열로 이동하는데 아래에서 위쪽으로 
		
		// 5. 공중 부양 => 절반씩 나눠서 시계방향 180도 해서 위에 올리기 = > 두번 반복
		
		// 6. 3번 다시 하기
		
		// 7. 일렬로 놓기
		
	}
	
	static class FishBowl{
		int y,x,fishcnt;
		
		public FishBowl(int y, int x, int fishcnt) {
			this.y = y;
			this.x = x;
		}
	}
}

