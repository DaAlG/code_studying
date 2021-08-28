import java.io.*;
import java.util.*;

// 직사각형을 만드는 방법: 잘 모르겠서!
public class Main_8320 {

	public static void main(String[] args) throws Exception {
		// 1. 가로와 세로를 1부터 하나씩 늘려가면서 곱했을 때, n보다 작은 경우의 수를 구한다.
		// 2. a*b 와 b*a 는 같은 것으로 취급하므로, 이중 포문을 돌릴 때 j는 i전까지만 반복한다.
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int cnt = 0;
		for(int i=1; i<n+1; i++)
			for(int j=1; j<=i; j++)
				if(i*j <= n)
					cnt++;
		System.out.println(cnt);
	}

}
