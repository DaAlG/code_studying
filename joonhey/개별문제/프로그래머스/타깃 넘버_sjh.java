class Solution {

	static int cnt;
	static int[] sign;

	public static void calculate(int[] numbers, int len, int target) {

		int sum = 0;

		for (int i = 0; i < len; i++) {
			sum += numbers[i] * sign[i];
		}

		if (sum == target)
			cnt++;
	}

	public static void changeSign(int cnt, int[] numbers, int len, int target) {
		if (cnt == len) {
			calculate(numbers, len, target);
			return;
		}
		sign[cnt] = 1;
		changeSign(cnt + 1, numbers, len, target);
		sign[cnt] = -1;
		changeSign(cnt + 1, numbers, len, target);
	}

	public int solution(int[] numbers, int target) {
		int answer = 0;
		sign = new int[numbers.length];
		changeSign(0, numbers, numbers.length, target);
		answer = cnt;
		return answer;
	}
}ㄴ