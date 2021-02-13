import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Main{
	static int[] height = new int [9];
	static int N;
	static final int DEST = 100;
	static boolean done;
	static ArrayList<Integer> arr = new ArrayList<>();
	
	public static void selectDwarf(int target, int cnt, int totalHeight) {
		if( cnt == 7) {
			if(totalHeight == 100 && !done)
			{
				arr.sort(null);
				for(int dwarf : arr)
					System.out.println(dwarf);
				done = true;
			}
			return;
		}
		// 아직 7이 안됨 >> 범위 초과 or 키 초과 가지치기
		if(target == 9 || totalHeight >= 100) {
			return;
		}
		
		//범위 내, 키 아직 초과 안함 >>현재 선택 or 비선택.
		arr.add(height[target]);
		selectDwarf(target+1, cnt+1, totalHeight + height[target]);
		arr.remove(cnt);
		selectDwarf(target+1, cnt, totalHeight);
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0; i<9; i++) {
			height[i] = Integer.parseInt(br.readLine());
		}
		selectDwarf(0,0,0);
		
	}
}