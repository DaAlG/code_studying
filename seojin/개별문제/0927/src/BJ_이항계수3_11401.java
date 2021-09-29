// 페르마의 소정리 

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 이항계수 - 파스칼의 삼각형 - 조합
//        n            n-r r
// (a + b)  을 전개 했을 때  a   b 의 계수
//  =>   n!
//    ㅡㅡㅡㅡㅡㅡ   하지만, factorial 단순 계산은 시간복잡도 높다.
//    r!(n-r)!
// 
//  파스칼의 법칙 = 이항계수 (n/r) 은 이항계수 (n-1/r-1) + (n-1/r) <= 점화식 => DP!!

// 페르마의 소정리 - 
// ( a + b ) % c == ( a%c + b%c ) % c

// a (mod p) 에 대한 역원은 ap-2 (mod p) ???

// 분자 N!
// 분모 K! x (N-K)! % MOD

// N 이 매우 크다 
// 1 <= N <= 4000000 => 이항계수2 처럼 풀면 메모리 초과 발생 => DP X
// long !!

public class BJ_이항계수3_11401 {

	static long N, K;
	final static long MOD = 1_000_000_007; // , 처럼 자릿수 표시 가능!

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		//System.out.println(pow(2,3));
		
		// 분자 N!
		long top = fac(N);

		// 분모 (K! * (N-K)!) mod p
		long bottom = fac(K) * fac(N - K) % MOD;

		// N! * 분모의 역원((K! * (N-K)!)
		System.out.println(top * pow(bottom, MOD - 2) % MOD);
	}

	// factorial
	// 재귀 X -> 반복문	
	public static long fac(long N) {
		long num = 1L;

		while (N > 1) {
			num = (num * N) % MOD;
			N--;
		}
		return num;
	}

	// pow 자체만 이해할 경우 MOD 로 나누는 부분 제외하고 생각
	// 2^16 계산 방법 pow(2, 16)
	// 16 이 1이 될 때까지 계속 나눈다. 중간에 홀수가 되면 base 를 한번 더 곱해주어서  지수/2 가 계속 유효하도록 처리
	// 마지막에 1이 되면 1*2/2 = 0 이 되어 while 문 종료
	// 각 단계마다 base 는 *= 연산을 통해서 ^만큼 증가
	// base = 2
	// base = 4 
	// base = 8
	// base = 16
	public static long pow(long base, long expo) {
		long num = 1;

		while (expo > 0) {

			// 지수가 홀수일 경우, 지수를 줄이는 expo /= 2 처리가 안되므로 미리 결과 값에 base를 한번 곱해 
			if (expo % 2 == 1) {
				num *= base;
				num %= MOD;
			}
			base = (base * base) % MOD;
			expo /= 2;
		}
		return num;
	}

}
