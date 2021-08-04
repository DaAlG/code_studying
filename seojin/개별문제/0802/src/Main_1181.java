import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main_1181 {

	public static void main(String[] args) throws Exception {
		//System.setIn(new FileInputStream("input2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	    int N = Integer.parseInt(br.readLine());
	    String[] arr = new String[N];
	    for(int i=0;i<N;i++){
	      arr[i] = br.readLine();
	    }
	    
	    Arrays.sort(arr, new Comparator<String>() {

			@Override
			public int compare(String o1, String o2) {
				if(o1.length() == o2.length()) return o1.compareTo(o2); // 길이 같으면 사전순!
				return o1.length()-o2.length(); // 아니면 길이순!
			}
		});
	    
	    // 중복도 제거해줘야해.. 
	    System.out.println(arr[0]);
	    for(int i=1;i<N;i++) {
	    	if(arr[i].equals(arr[i-1])) continue;
	    	System.out.println(arr[i]);
	    }

	}

}
