
import java.util.Arrays;

class Solution {
    
    	static int size;
	static char[] curString;
	static char[] originName;
	static int minCnt;

	// 그 알파벳을 A로 바꾸는 최소 횟수 -> 위 OR 아래
	public int changeFromA(char alphabet) {

		int atoi = alphabet - 'A'; // 0 <= atoi < 26
		int pressUp = atoi;
		int pressDown = 26 - atoi;

		return pressUp <= pressDown ? pressUp : pressDown;

	}
    
    	public int rightIdx(int cur) {
		int i;
		for (i = cur; i < size; i++) {
			if (curString[i] != originName[i])
				return i;
		}
		return i;

	}
    
    	public int leftIdx(int cur) {
		// 처음에서 왼 쪽으로 갈 수 있음에 유의. 이건 바꿀 거 없을 때에만 음수 리턴한다. 즉 나한테 다시 돌아왔을 때!
		int i = cur - 1;
		while (i != cur) {
			if (i < 0) {
				i += size;
			}
			if (curString[i] != originName[i])
				break;
			i--;
		}
		return i;
	}
    
    	// 현재 cur 위치이며 cnt번 움직였다.
	public void move(int cur, int cnt) {
		cnt += changeFromA(originName[cur]);
		curString[cur] = originName[cur];
		// 다 바뀌면 끝남
		if (Arrays.toString(curString).equals(Arrays.toString(originName))) {
			if (cnt < minCnt)
				minCnt = cnt;
			return;
		}
		// 아직 덜 바깠음 -> 왼쪽으로 갈지 오른쪽으로 갈 지 정해야 함.
		// 갈 데 없으면 더 안나감.
		int rIdx = rightIdx(cur);
		int lIdx = leftIdx(cur);
		
		//오른쪽은 더 이상 이동할 수 없을 때가 있지만,
		if (rIdx < size) {
			// 오른쪽으로 이동 (거리 이동 더해주기)
			move(rIdx, cnt + rIdx - cur);
			curString[rIdx] = 'A';

		}
		
		//왼쪽은 항상 이동할 수 있다.
		int dist;
		dist = cur > lIdx ? cur - lIdx : cur + size - lIdx;
		// 왼쪽으로 이동. (거리 이동 더해주기)
		move(lIdx, cnt + dist);
		curString[lIdx] = 'A';

	}
    
    public int solution(String name) {
       int answer = 0;
		size = name.length();
		curString = new char[size];
		originName = name.toCharArray();
		for (int i = 0; i < size; i++)
			curString[i] = 'A';
		// 오른쪽으로 갈 때, 왼쪽으로 갈 때의 거리를 구하는 데,
		// 만약 갈 수 없는 거리면 가지 않는다(예-끝에서 오른쪽으로가는 거슨 불가.)
		// 만약 갈 수 있다면 둘 다 가본다. 그 때 거리를 더해준다.
		// 현재 상태도 바꿔놓는다. 리턴하면 되돌려놓기!
		minCnt = Integer.MAX_VALUE;
		move(0, 0);
		answer = minCnt;
		return answer;
    }
}