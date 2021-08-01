// 핵심 : 가장 많이 나온 숫자라고 해서 스타수열로 만들었을 때 그것이 가장 긴 스타수열이 아닐수도 있다는 것이다. 예를 들어 B A A A A A B C B C A B 가 배열 a 라고 할 때 A가 가장많이 나온 숫자이지만 A를 기준으로 스타수열을 만들었을 때는 길이가 6이고 B를 통해 스타수열을 만들었을 때는 길이가 8이 된다. 따라서 가장 많이 나온 숫자를 시작으로 가장 적게 나온 숫자까지 모든 경우를 검색해야 한다. 단 다음번 검사하는 숫자의 갯수가 현재까지 뽑은 스타수열길이의 반보다 적다면 탐색을 종료하게 된다. https://eno1993.tistory.com/73
// -> 가장 많이 나온 수 기준으로했더니 안되는 경우가 있음.
class Solution {
    public int solution(int[] a) {
                int answer = 0;
        int[] count = new int[a.length];//a 원소의 등장횟수
        for (int i = 0; i < a.length; i++) count[a[i]]++;

        for (int i = 0; i < count.length; i++) {//공통된 원소로 선택할 값
			if(count[i]==0) continue;//배열에 없으면 공통된 원소가 아님
			if(count[i]<=answer) continue;//가장 많이 사용된 횟수보다 작으면 긴 스타수열 만들수 x
			int tmp = 0;//해당 숫자가 사용된 횟수
			
			for (int j = 0; j < a.length-1; j++) {//배열 탐색 반복
                //인접한 2개의 값을 봤을 때 ,어느 하나라도 공통된 원소를 가지고 있어야한다.
				if(a[j] != i && a[j+1] !=i)continue;
                //인접한 2개의 값이 동일하지는 않은지 - 스타수열의 조건 3
				if(a[j] == a[j+1])continue;
				tmp++; j++;
			}
			answer = Math.max(answer, tmp);//현재까지 스타수열을 만드는데 가장 많이 사용된 횟수
		}
        
        return answer*2;//공통된 원소가 사용될 때마다, 인접한 값 하나씩을 더 가지고 있으므로
    }
}