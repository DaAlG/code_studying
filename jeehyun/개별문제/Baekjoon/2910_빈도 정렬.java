import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// BOJ 2910 빈도 정렬
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int c = Integer.parseInt(input[1]);
		
		Integer[] arr = new Integer[n];
		Map<Integer, Integer> cnt = new HashMap<>();
		Map<Integer, Integer> idx = new HashMap<>();
		
		input = br.readLine().split(" ");
		for (int i = 0; i < input.length; i++) {
			arr[i] = Integer.parseInt(input[i]);
			if (cnt.containsKey(arr[i])) {
				cnt.replace(arr[i], cnt.get(arr[i]) + 1);
			} else {
				cnt.put(arr[i], 1);
				idx.put(arr[i], i);
			}
		}
		
		Arrays.sort(arr, new Comparator<Integer>() {
			@Override
			public int compare(Integer a, Integer b) {
				if (cnt.get(a) == cnt.get(b)) { // 등장하는 횟수가 같으면
					return idx.get(a) - idx.get(b); // 먼저 나온 것이 앞에
				}
				return cnt.get(b) - cnt.get(a); // 많이 등장하는 경우가 앞에
			}
		});
		
		for (int k : arr) {
			System.out.print(k + " ");
		}
	}
}
