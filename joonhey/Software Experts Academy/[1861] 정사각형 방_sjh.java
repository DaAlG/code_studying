import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
    static int maxCnt, maxNum; //이거 클래스로 묶어서 한 번 해보기.
    static int N;
    static int[][] room;
    static int curNum;
    static int[] di = {-1, 1, 0, 0};
    static int[] dj = {0, 0, -1, 1};
     
    public static int travelRoom(int posX, int posY) {
        int cnt = 1; 
        int k = 0;
        int ni, nj;
         
        while(k < 4) { //더 이상 이동할 수 없을 때까지!
            ni = posX + di[k];
            nj = posY + dj[k];
             
            //이동 가능.
            if( ni>=0 && nj>=0 && ni<N && nj<N && room[ni][nj] == room[posX][posY] + 1) {
                cnt++;
                posX = ni; posY = nj;
                k = 0;
            }
            else
                k++;
        }
        return cnt;
    }
     
    public static void findingMax() {
        int cnt;
         
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cnt = travelRoom(i, j);
                curNum = room[i][j]; //도착시가 아니라 출발시의 번호임에유의
                //중복이면 숫자가 작은 방 승리.
                if(maxCnt == cnt) {
                    if(maxNum > curNum) {
                        maxNum = curNum;
                        maxCnt = cnt;
                    }
                }
                else if(maxCnt < cnt) {
                    maxNum = curNum;
                    maxCnt = cnt;
                }
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        String inputLine;
        StringTokenizer st;
         
        for(int t=0; t<T; t++) {
            sb.setLength(0); //출력 초기화
            maxCnt = -1; //최대 이동 횟수 초기화
             
            N = Integer.parseInt(br.readLine());
            room = new int[N][N];
            for(int i=0; i<N; i++) {
                inputLine = br.readLine();
                st = new StringTokenizer(inputLine);
                for(int j=0; j<N; j++) {
                    room[i][j] =  Integer.parseInt(st.nextToken());
                }
            }
            findingMax(); //최대 이동 횟수 리셋.
            //출력
            sb.append("#").append(Integer.toString(t+1)+" ").append(maxNum+" ").append(maxCnt);
            System.out.println(sb.toString());
        }
    }