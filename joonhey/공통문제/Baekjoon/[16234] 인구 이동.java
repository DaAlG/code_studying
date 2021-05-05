import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int arr[][],check[][];		
	static int num,l,r;
	final static int dx[]= {0,1,0,-1};
	final static int dy[]= {-1,0,1,0};
	static class Info{
		int x,y;
		public Info(int y, int x) {
			this.x=x;
			this.y=y;
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		num = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		arr = new int[num][num];
		
		for(int i=0;i<num;i++) {
			String str = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str);
			for(int j=0;j<num;j++) 
				arr[i][j]=Integer.parseInt(st2.nextToken());
		}
		int result=0;
		Info ii;
		while(true) {
			int cnt=0;
			check = new int[num][num];
			int tot[] = new int[2501];		 //한 국가의 인구 합	
			int number[] = new int[2501];	// 한 국가 칸의 수	
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					if(check[i][j]==0) {
						cnt++;
						check[i][j]=cnt;						
						Queue<Info> q = new LinkedList<>();
						q.offer(new Info(i,j));
						while(!q.isEmpty()) {
							ii = q.poll();
							int cx = ii.x;
							int cy = ii.y;
							tot[cnt]+=arr[cy][cx];
							number[cnt]++;
							for(int k=0;k<4;k++) {
								int nx = cx + dx[k];
								int ny = cy + dy[k];
								if(nx>=0 && ny>=0 && nx<num && ny<num && check[ny][nx]==0 && l<=Math.abs(arr[ny][nx]-arr[cy][cx]) && Math.abs(arr[ny][nx]-arr[cy][cx])<=r ) {
									check[ny][nx]=cnt;
									q.offer(new Info(ny,nx));
								}
							}
						}
					}
				}
			}
			boolean change = false;
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					int country = check[i][j];
					int vv = tot[country]/number[country];
					if(arr[i][j]!=vv) {
						change=true;
						arr[i][j]=vv;
					}
				}
			}
			if(!change) break;
			result++;
		}
		System.out.println(result);
	}
}