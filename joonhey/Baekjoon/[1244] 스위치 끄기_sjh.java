package workshop;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * [1244] 스위치 켜고 끄기 
 */
public class Solution {
	static int N;
	static short[] switches;

	private static void changeSymmetry(int left, int right) {
		// 범위
		if (left < 1 || right > N)
			return;
		// 같나?
		if (switches[left] != switches[right])
			return;
		switches[left] = (short) ((switches[left] + 1) % 2);
		switches[right] = switches[left];
		changeSymmetry(left - 1, right + 1);
	}

	private static void switchControl(int sex, int num) {
		if (sex == 1) { // 남
			int idx = num;
			while (idx < switches.length) {
				switches[idx] = (short) ((switches[idx] + 1) % 2);
				idx += num;
			}
		} else { // 여
			switches[num] = (short) ((switches[num] + 1) % 2);
			changeSymmetry(num - 1, num + 1);
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		switches = new short[N + 1]; // 1번부터
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 1; i < N + 1; i++) {
			switches[i] = Short.parseShort(st.nextToken());
		}

		int cnt = Integer.parseInt(br.readLine());
		int sex;
		int num;

		for (int i = 0; i < cnt; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			sex = Integer.parseInt(st.nextToken());
			num = Integer.parseInt(st.nextToken());
			switchControl(sex, num);
		}
		
		for(int i=1; i<N+1; i++) {
			System.out.print(switches[i]+" "); //1 0 0 0 1 1 0 1
			if(i % 20 == 0)
				System.out.println();
		}
	}
}
//8
//0 1 0 1 0 0 0 1
//2
//1 3
//2 3
