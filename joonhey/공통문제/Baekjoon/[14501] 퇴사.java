import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[] T;
	static int[] P;
	static int[] arr; 
	//start가 끝난 이후의 상담 중 최대값
	public static int getAfterMax(int cur) {
		int start = cur + T[cur];
		int max = 0;
		//이후의 상담이 퇴사 이후라면 0 리턴.
		for(int i=start; i<=N; i++) {
			if(arr[i] > max)
				max = arr[i];
		}
		return max;
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		T = new int[N+1];
		P = new int[N+1];
		StringTokenizer st;
		//입력
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			T[i] = Integer.parseInt(st.nextToken());
			P[i] = Integer.parseInt(st.nextToken());
		}
		int maxPrice = -1;
		//끝에서 부터 역순회 하면서, 각자 자신부터 시작했을 때의 최대값을 기록한다.
		//내 값 + 내 일이 끝난 이후의 값들 중 최대값 이렇게 누적.
		//이번 상담 끝난 후 최대값 하나만 뽑아도 가능한 이유 - 
		// 만약 해당 값이후에도 상담을 할 수 있으면 그 값이 누적되어 기록되었을 것이고, 그 값 혹은 그 이후의 값 중 
		//날짜가 겹쳐서 하나만 가능하다면 그 중 최대값을 뽑는 것이므로..
		arr = new int [N+1];
		for(int i = N; i>=1; i--) {
			int priceSum = 0;
			//이번 상담은 가능 한가? 불가능하면 0
			if(T[i] + i <= N+1) {
				//이번 상담 가격 + 이후 중 최대값
				priceSum  = P[i] + getAfterMax(i);
			}
			arr[i] = priceSum;
			if(maxPrice < priceSum)
				maxPrice = priceSum;
		}
		System.out.println(maxPrice);
	}
}
