import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	static int C, N;
	static int[] house;
	
//	최소 거리 dist 기준으로 공유기를 설치 함.
	public static int installWifi(int dist) {
		int ans = 1;
//		맨 처음 집부터 공유기 설치
		int point = house[0];
		for(int i=1; i<N; i++) {
			if(house[i] - point >= dist) {
//				그 집에 설치, 기준점바뀜
				ans++;
				point = house[i];
			}
//			간격이 너무 좁으므로 공유기 설치 못함. 기준점 그대로.
		}
		return ans;
	}
		
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		house = new int[N]; 
		for(int i=0; i<N; i++) {
			house[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(house);
//		1. 집 사이의 간격 이분 탐색 시행
		int start = 1; //최소거리
		int end = house[N-1] - house[0]; //최장거리
		int mid, cnt;
		int res = 0; //정답: 최소 거리 중 최대값
		while(start <= end) {
//			mid가 현재 선택된 최단거리
			mid = (start + end)/2;
//			mid 기준으로 공유기를 설치함 -> 최소 이정도 간격은 되어야 이 집에 공유기를 설치할 수 있다는 뜻
			cnt = installWifi(mid);
//			그렇게 설치한 공유기 개수는 C보다 같거나 커야 한다(기준이 최소거리니까 이 기준으로 공유기가 설치된 집이 더 많아도 됨)
			if(cnt >= C) {
//				정답 기록
				res = mid;
//			단 그 중 최대값을 요구하고 있으므로 공유기 사이 간격을 늘려준다(parametric search)
				start = mid + 1;
			}
//			단, c보다 작으면 안된다 -> 최소 기준으로 공유기를 설치했어도 너무 넓으니까 더 줄이는게 필요하다ㄹ
			else
				end = mid - 1;
		}
		System.out.println(res);
	}
}