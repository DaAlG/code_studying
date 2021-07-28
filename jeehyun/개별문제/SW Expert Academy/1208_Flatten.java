import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		for (int test_case = 1; test_case <= 10; test_case++) {
			int dump = Integer.parseInt(bf.readLine());
			StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
			
			int box[] = new int[100];
			for (int i = 0; i < box.length; i++) {
				box[i] = Integer.parseInt(st.nextToken());
			}
			
			for (int i = 0; i < dump; i++) {
				Arrays.sort(box);
				if (box[99] - box[0] <= 1)
					break;
				box[99]--; box[0]++;
			}
			Arrays.sort(box);
			System.out.println("#" + test_case + " " + (box[99] - box[0]));
		}
	}
}
