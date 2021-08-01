import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Integer[][] position = new Integer[N][2];


        for(int i=0; i<N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            position[i][0] = Integer.parseInt(st.nextToken());
            position[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(position, new Comparator<Integer[]>() {
            @Override
            public int compare(Integer[] o1, Integer[] o2) {
                if(o1[0].equals(o2[0])) {
                    return o1[1] - o2[1];
                }else {
                    return o1[0] - o2[0];
                }
            }
        });

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (Integer[] pos : position) {
            bw.write(pos[0] + " " + pos[1] + "\n");
        }

        bw.flush();

        bw.close();
        br.close();
    }
}