import java.util.HashMap;

//카카오 블로그 참고해서 풂 ㅈㅅ,,ㅜㅜ
class Solution {
	static HashMap<String, Integer> map;
	static int kind;

	public int[] solution(String[] gems) {
		int[] answer = new int[] {0, Integer.MAX_VALUE};
		map = new HashMap<>();

//		1. 전체 종류 수 파악
		for (String g : gems) {
			if (map.get(g) == null)
				map.put(g, 1);
		}
		kind = map.size();

//		2. 전체 순회
		int l = 0;
		int r = 0;
		int gSize = gems.length;
		int curKind = 0;
		map = new HashMap<>();

		while (r != gSize) {
//			1. 모자랄 경우 -> 다 채울 때 까지 증가
			if (curKind != kind) {
				while (r != gSize && curKind != kind) {
					if (map.get(gems[r]) == null) {
						map.put(gems[r], 1);
					} else {
						map.put(gems[r], map.get(gems[r]) + 1);
					}
					r++;
					curKind = map.size();
				}
			}
//			2. 모자라지 않은데 아직 끝까지 안가봄 -> 하나씩 간보면서 증가
			else {
				if (map.get(gems[r]) == null) {
					map.put(gems[r], 1);
				} else {
					map.put(gems[r], map.get(gems[r]) + 1);
				}
				r++;
			}
//			3. 갱신, 기록
			if (curKind == kind) {
//				갱신 -> 겹치는 게 있을 경우 나가도 무방
				while (l < r && map.get(gems[l]) != 1) {
					if (map.get(gems[l]) != 1) {
						map.put(gems[l], map.get(gems[l]) - 1);
						l++; 
					} else
						break; // 나가면 안되는 거임.
				}

				if (r -1- l < answer[1] - answer[0]) {
					answer[1] = r;
					answer[0] = l + 1;
				}
			}
		}
		return answer;
	}


}