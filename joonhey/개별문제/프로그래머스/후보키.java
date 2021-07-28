import java.util.*;

class Solution {
	static String[][] sRelation;
	static int rSize, cSize;
	static boolean[] uhyoKey;
	static int uLen;

//    유효키가 포함되어 있는가 ?
	public boolean containUhyo(int subset) {
		for (int i = 0; i < uLen; i++) {
			if (uhyoKey[i] && ((subset & i) == i))
				return true;
		}
		return false;
	}

	// 얘가 후보키가 될 수 있는가 ?
	public boolean check(int subset) {
//                    	이미 유효키에 포함됐으면 넘겨
		if (containUhyo(subset)) {
			return false;
		}
		for (int first = 0; first < rSize - 1; first++) {
			for (int second = first + 1; second < rSize; second++) {
				// 비트별로 확인
				StringBuilder firstSet = new StringBuilder("");
				StringBuilder secondSet = new StringBuilder("");
				for (int c = 0; c < cSize; c++) {
					if ((subset & (1 << c)) != 0) {
						firstSet.append(sRelation[first][c]);
						secondSet.append(sRelation[second][c]);
					}
				}
				if (firstSet.toString().equals(secondSet.toString())) {
					return false;
				}
			}
		}
		return true;
	}

	public int solution(String[][] relation) {
		// 전체 속성 4개 -> 비트를 사용해서 2^4의 경우의 수 모두 해아려 보기
		rSize = relation.length;
		cSize = relation[0].length;
		sRelation = new String[rSize][cSize];
		// 전역변수로 옮기기
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < cSize; j++) {
				sRelation[i][j] = relation[i][j];
			}
		}

		// 후보키에 속하는 비트 (1100 -> 학번, 이름)
		List<Integer> candidates = new LinkedList<Integer>();

		uLen = 1 << cSize; // 최대 경우의 수 (2^4)
		uhyoKey = new boolean[uLen];
		for (int i = 1; i < uLen; i++) {
			if (check(i) == true) {
				uhyoKey[i] = true;
				candidates.add(i);
			}
		}

		return candidates.size();
	}

}