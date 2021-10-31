import java.io.*;

public class BJ_신기한소수_2023 {

    static int N; // 자릿수
    static int maxNum;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        maxNum = (int) Math.pow(10, N);

        // 조건
        for (int i = 2; i <= 9; i++) {
            if (findPrime(i)) findSurprisingNum(1, String.valueOf(i));
        }
        System.out.println(sb.toString());
    }

    private static void findSurprisingNum(int idx, String num) {
        // 2,3,5,7로 시작

        if (idx == N) {
            sb.append(num).append("\n");
            return;
        }

        for (int i = 1; i <= 9; i++) {
            String now = num + String.valueOf(i); // ex 21~29
            int nowNum = Integer.parseInt(now);
            if (findPrime(nowNum)) findSurprisingNum(idx + 1, now);

        }
    }

    private static boolean findPrime(int num) {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}