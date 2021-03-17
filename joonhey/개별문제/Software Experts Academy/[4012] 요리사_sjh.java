import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
class Solution{
    static int minAbs;
    static int[][] sinergy;
    static int N;
    static boolean[] selectedA;
     
    public static int getSinergy(boolean Adish) {
        int sum = 0;
        for(int first=0; first<N; first++) {
            if(selectedA[first] == Adish) {
                for(int second=0; second<N; second++) {
                    if(selectedA[second] == Adish)
                        sum += sinergy[first][second];
                }
            }
        }
        return sum;
    }
     
    //특정 요리의 시너지 차 리턴.
    public static int getSinergyAbs() {
        int sinergyA = getSinergy(true);
        int sinergyB = getSinergy(false);
        return Math.abs(sinergyA - sinergyB);
    }
     
    //target은 항상 증가, cnt는 N/2까지만.
    public static void comb(int cnt, int target) {
        //기저조건
        if(target == N)
            return;
         
        if(cnt == N/2) { //각자 다 고름 -> 맛의 차이 최솟값 업데이트
            int sinergyAbs = getSinergyAbs(); // 두 음식의 시너지 합을 구하고, 이 차이를 리턴
            if( sinergyAbs < minAbs) {
                minAbs = sinergyAbs;
            }
            return;
        }
        //선택
        selectedA[target] = true;
        comb(cnt+1, target+1);
        //비선택
        selectedA[target] = false;
        comb(cnt, target+1);
    }
     
    public static void main(String[] args) throws IOException{
     
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t=1; t<=T; t++) {
            minAbs = Integer.MAX_VALUE;
            N = Integer.parseInt(br.readLine());
            sinergy = new int[N][N];
            selectedA = new boolean[N];
             
            for(int i=0; i<N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++) {
                    sinergy[i][j] = Integer.parseInt(st.nextToken());
                }
            }
             
            comb(0, 0);
             
            //출력
            System.out.println("#"+t+" "+minAbs);
             
        }
    }
}