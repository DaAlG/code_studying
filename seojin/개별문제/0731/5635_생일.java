import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        people[] peoples = new people[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String a = st.nextToken();
            String b = st.nextToken();
            String c = st.nextToken();
            if(a.length() == 1) a = "0" + a;
            if(b.length() == 1) b = "0" + b;
            peoples[i] = new people(name, Integer.parseInt(c + b + a));
        }
        Arrays.sort(peoples, (a, b) -> b.birthday - a.birthday);
        bw.write(peoples[0].name + "\n");
        bw.write(peoples[n - 1].name + "\n");

        bw.flush();
        br.close();
        bw.close();
    }

    static class people {
        String name;
        int birthday;

        public people(String name, int birthday) {
            this.name = name;
            this.birthday = birthday;
        }
    }
}