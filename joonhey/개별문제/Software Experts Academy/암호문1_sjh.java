import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;
 
public class Solution {
    static LinkedList<String> list = new LinkedList<>();
 
    public static void initializeList(StringTokenizer st) {
        // N개의 토막들로 이루어진걸 파싱할 토크나이저로 list에 열 개 이하만 담자!
        int i = 0;
        while (st.hasMoreTokens() && i < 10) {
            list.addLast(st.nextToken());
            i++;
        }
    }
 
    // 한 문장 속 N개의 명령을 토크나이징하여 삽입 수행.
    public static void handleCommand(StringTokenizer st, int N) {
        int startIdx; // 이후에 삽입
        int insertNum; // 이만큼 삽입
 
        for (int i = 0; i < N; i++) {
            st.nextToken(); // I
            startIdx = Integer.parseInt(st.nextToken());
            insertNum = Integer.parseInt(st.nextToken());
            for (int j = 0; j < insertNum; j++) {
                if (startIdx < 10)
                    list.add(startIdx++, st.nextToken());
                else// 10번째 칸 이후론 관심 밖
                    st.nextToken();
            }
 
        }
    }
 
    public static String addStrings(StringBuilder sb) {
        for (String s : list.subList(0, 10)) {
            sb.append(s).append(" ");
        }
        return sb.toString();
    }
 
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N; // 원소 갯수 혹은 명령문 갯수 저장.
        for (int t = 0; t < 10; t++) {
            StringBuilder sb = new StringBuilder("#").append(Integer.toString(t + 1)).append(" ");
            list.clear(); // 테케마다 초기화.
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            initializeList(st);
            // 명령문.
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            handleCommand(st, N);
            System.out.println(addStrings(sb));
        }
    }
}