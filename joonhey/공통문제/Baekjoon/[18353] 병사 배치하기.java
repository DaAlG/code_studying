import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] army; //input ����
	static int[] length; //���� ���� ���
	static int N; //���� ��
	static int maxLength;
	static int[] outArmy;
	static int res;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		maxLength = 0; //�ִ� ���� ���.
		N = Integer.parseInt(br.readLine());
		army = new int[N];
		length = new int[N];
		outArmy = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			army[i] = Integer.parseInt(st.nextToken()); 
			length[i] = 1;
//			i��°���� ������ ���� ������ ���̴� ?
			for(int k=0;k<i; k++) {
//				�տ� ���ҵ�ڿ� ���� �ִ���.
				if(army[k] > army[i] && length[k]+1 > length[i])
				{
					length[i] = length[k] + 1;
					outArmy[i] = outArmy[k] + i-k-1;
//					�ջ�� ����.
				}
			}
//			�ջ�� ����.
			if(length[i] == 1)
				outArmy[i] = i;
//			�޻���� ����.
			if(length[i] > maxLength) {
				maxLength = length[i];
				res = outArmy[i] + N - i - 1;
			}
		}
//		System.out.println(maxLength);
		System.out.println(res);
	}
}
