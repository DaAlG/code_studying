import java.io.*;
import java.util.*;

public class BJ_좋다_1253 {

    static int N, tgtIdx, res;
    static int[] A;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            int val = arr[i]; // A
            boolean flag= false;

            for (int j = n-1; j >= 0; j--) {
                // 이분탐색

                int l = 0; // left
                int r = j - 1; // right

                if(j == i) continue;

                while (l <= r) {
                    int mid = (l + r) / 2;
                    int val2 = val - arr[j];

                    if (arr[mid] > val2) {
                        r = mid - 1;
                    } else if (arr[mid] == val2 && mid != i && mid != j) {
                        flag = true;
                        break;
                    } else {
                        l = mid + 1;
                    }
                }

            }

            if (flag) cnt++;
        }
        bw.write(Integer.toString(cnt));
        bw.flush();
    }
}

/*
N개 <= 2000의 수 중 어떤 수 = 다른 수 두 개의 합 => GOOD
수의 위치가 다르면 값이 같아도 다른 수이다.

-1,000,000,000 <= A_i <= 1,000,000,000

A : [1,2,3,4,5,6,7,8,9,10]
3,4,5,6,7,8,9,10은 좋다.

정렬 => 이분탐색으로 찾기?
정렬 => N개 수 탐색 (a) => 한번 더 N개 수 돌기(b) => 차이인 값이 있는지 이분탐색으로 찾기!(a-b = c)

 */

//처음 짠거 -> i,j 인덱스 모두 고려해줬어야했나봄
//https://velog.io/@pjh612/%EB%B0%B1%EC%A4%80-1253%EB%B2%88-%EC%A2%8B%EB%8B%A4 코드 참조