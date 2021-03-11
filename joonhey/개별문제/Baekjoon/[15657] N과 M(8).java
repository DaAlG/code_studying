import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	static int N, M;
	static int[] selected;
	static int[] input;
	static StringBuilder output;
	//중복조합
	public static void comb(int cnt, int target) {
		//기저조건
		if(cnt == M) {
			for(int num : selected) {
				output.append(num).append(" ");
			}
			output.append("\n");
			return;
		}
		//반복
		for(int i=target; i<N; i++) {
			selected[cnt] = input[i];
			comb(cnt+1, i);
		}
	}
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		input = new int[N];
		selected = new int[M];
		output = new StringBuilder("");
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			input[i] = Integer.parseInt(st.nextToken());
		}
		//오름차순 정렬
		//사전순 증가??
		Arrays.sort(input);
		//중복순열
		comb(0, 0);
		//출력
		System.out.print(output);
	}