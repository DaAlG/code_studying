import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo2_대전_5반_신준희 {
	static long res;
	static int N, M;
	static int[] T;
	static int Tmax; //심사시간 중 최장.
	static long maxTime; //M명이 심사 시 최장시간.
//	mid 시간 내에 입국 심사대를 통과할 수 있는 사람 수 세기
	public static long getAvailPeople(long mid) {
		long cnt = 0;
		int i = 0;
//		i번 입국 심사대부터 세기. cnt 는 사람 수
		while(cnt <(long) M && i != N) { 
			//시간이 너무 적으면 i == N 에 걸려서 나올것이고 
			//시간이 너무 많으면 cnt == N (충분히 수용)에 걸려서 나올 것임.
//			i번 입국 심사대에서 통과할 수 있는 사람수 .
			cnt +=(mid/(long)T[i++]);
		}
//		System.out.println("사람 수 "+cnt);
		return cnt;
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		T = new int[N];
		M = Integer.parseInt(st.nextToken());
		for(int i=0; i<N; i++) {
			T[i] = Integer.parseInt(br.readLine());
			if(T[i] > Tmax)
				Tmax = T[i];
		}
//		int 끼리 계산할 때도 long 해주어야 함.
		maxTime =(long)Tmax *(long) M;
		long start = 1; 
		long end = maxTime;
//		System.out.println("end "+maxTime);
		long mid;
//		parametric search : 모두 통과할 수 있는 시간중 최소.
		while(end >= start) {
//			System.out.println("end "+end);
//			System.out.println("start "+ start);
			mid = (end + start) / 2;
//			System.out.println("mid "+mid);
			long availPeople = getAvailPeople(mid);
//			mid 시간 내에 통과할 수 있는 사람 수가 M보다 크거나 같다 -> 기록하고 작은 범위 탐색
//			mid 시간 내에 통과할 수 있는 사람 수가 M보다 작다 -> 큰 범위 탐색.
			if(availPeople >= (long)M) {
				res = mid;
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}

		}
		System.out.println(res);
		
	}
}
