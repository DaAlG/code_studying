import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
    static int N;
    static int[] parent;
     
    public static void makeSet() {
        for(int i=1; i<=N; i++)
            parent[i] = i;
    }
    public static int findSet(int num) {
        if(parent[num] == num)
            return num;
        else
            return parent[num] = findSet(parent[num]);
    }
    public static boolean unionSet(int a, int b) {
        int smaller = a <= b ? a : b;
        int bigger = a == smaller ? b : a;
        //root 구하고
        int rootA = findSet(smaller);
        int rootB = findSet(bigger);
        if(rootA == rootB)
            return false;
        //큰거 root 작은거 root로
        parent[rootB] = rootA;
        return true;
    }
    public static int getGroupCnt() {
        int cnt = 0;
        for(int i=1; i<=N; i++) {
            if(parent[i] == i)
                cnt++;
        }
        return cnt;
    }
    public static void main(String[] args) throws Exception{
        StringBuilder sb = new StringBuilder("");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int m;
        for(int t=1; t<=T; t++) {
            sb.append("#").append(t).append(" ");
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            parent = new int[N+1];
            makeSet(); //관계형성
            for(int i=0; i<m; i++) {
                st = new StringTokenizer(br.readLine());
                //둘 이 아는 42
                unionSet(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            }
             
            //정답 append
            sb.append(getGroupCnt()).append("\n");
        }
        //출력
        System.out.println(sb.toString());
     
    }
}