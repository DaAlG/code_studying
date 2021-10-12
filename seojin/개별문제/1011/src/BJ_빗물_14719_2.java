
import java.io.*;
import java.util.*;
// 그냥 전체 boolean 배열 만들고 탐색!!
public class BJ_빗물_14719_2 {

  static int H, W;
  static boolean[][] wall;
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    
    // 입력 처리
    st = new StringTokenizer(br.readLine());
    H = Integer.parseInt(st.nextToken());
    W = Integer.parseInt(st.nextToken());

    wall = new boolean[H][W];
    st = new StringTokenizer(br.readLine());
    for(int i=0; i<W; i++){
      int cnt = Integer.parseInt(st.nextToken());
      for (int j = H-1; j > H-1-cnt; j--) {
		wall[j][i] = true;
      }
    }
    
    // 계산
    // 위에서 부터 내려왔을 때 같은 행에 양 옆 기둥이 있다면 그 사이는 반드시 물이 고임
    int amount = 0; // 빗물의 총량
    for (int i = 0; i < H; i++) {
        int lidx = -1, ridx = -1; // 각 행마다 빗물이 고일 수 있는 양 체크하기 위한 index
        
    	for (int j = 0; j < W; j++) {
			if(wall[i][j]) { // 벽이 세워져있다면
				if(lidx == -1) { // 왼쪽 벽이 아직 없다면
					lidx = j; // 왼쪽 벽 세우기
				}
				else {
					// 오른쪽 벽 세우기
					ridx = j;
					amount += ridx - lidx - 1; 
					lidx = ridx;
				}
			}
		}
	}
    
    System.out.println(amount);

  }
}