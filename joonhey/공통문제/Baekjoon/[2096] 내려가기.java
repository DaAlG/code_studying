package hu;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[][] maxArr; //최댓값 누적
	static int[][] minArr; //최솟값 누적
	static int N;
	
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		maxArr = new int[N][3]; //최댓값 누적해서 저장. 
		minArr = new int[N][3]; //최댓값 누적해서 저장. 
		
//		배열 값 저장
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++) {
				maxArr[i][j] = Integer.parseInt(st.nextToken());
				minArr[i][j] = maxArr[i][j];
			}
		}
//		i=1 ~ i=N-1까지 이전 것에 합해서 저장
		int leftVal, rightVal;
		int i;
		for(i=1; i < N ; i++) {
//			최댓값 저장(누적)
			leftVal = maxArr[i-1][0] > maxArr[i-1][1] ? maxArr[i-1][0] : maxArr[i-1][1];
			rightVal = maxArr[i-1][1] > maxArr[i-1][2] ? maxArr[i-1][1] : maxArr[i-1][2];
			maxArr[i][0] += leftVal;
			maxArr[i][2] += rightVal;
			maxArr[i][1] += leftVal > rightVal ? leftVal : rightVal;
//			최솟값 저장(누적)
			leftVal = minArr[i-1][0] < minArr[i-1][1] ? minArr[i-1][0] : minArr[i-1][1];
			rightVal = minArr[i-1][1] < minArr[i-1][2] ? minArr[i-1][1] : minArr[i-1][2];
			minArr[i][0] += leftVal;
			minArr[i][2] += rightVal;
			minArr[i][1] += leftVal < rightVal ? leftVal : rightVal;
		}
//		정답 출력
		StringBuilder sb = new StringBuilder("");
//		최댓값
		int res = maxArr[--i][0] > maxArr[i][1] ? maxArr[i][0] : maxArr[i][1];
		res = res > maxArr[i][2] ? res : maxArr[i][2];
		sb.append(res).append(" ");
//		최솟값
		res = minArr[i][0] < minArr[i][1] ? minArr[i][0] : minArr[i][1];
		res = res < minArr[i][2] ? res : minArr[i][2];
		sb.append(res);
		System.out.println(sb);
	}
}
