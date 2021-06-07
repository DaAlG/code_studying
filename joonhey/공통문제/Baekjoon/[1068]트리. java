import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main{
    public static Node tree[];
    public static int n, delList[];
	
	static class Node{
    int num, parent, child[] = new int[50], childCnt;
    public void setChild(int childNum){
    	child[childNum] = 1;
    	childCnt++;
    	}
	}
	
    public static void main(String args[]) throws Exception {
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    	int i, pa;
        n = Integer.parseInt(in.readLine());
    	tree = new Node[n]; 
        delList = new int[n];
    	String line[] = in.readLine().split(" ");
    	for(i=0;i<n;i++) tree[i] = new Node();
    	for(i=0;i<n;i++){
    	    pa = Integer.parseInt(line[i]);
    	    tree[i].num = i;
            tree[i].parent = pa;
    	    if(pa!=-1) tree[pa].setChild(i);
    	}
    	delete(Integer.parseInt(in.readLine()));
    	out.write(String.valueOf(getLeaf()));
        out.close();
    	in.close();
    }

    private static int getLeaf(){
	    int i, cnt = 0;
        for(i=0;i<n;i++)
            if(tree[i]!=null && tree[i].childCnt==0)
        	    cnt++;
   	    return cnt;
    }

    public static void delete(int num){
    	makeDelList(num);
    	int i, k, pa;
	    for(i=0;i<n;i++){
    	    k = tree[i].num;
    	    if(delList[k]==1){
        		pa = tree[k].parent;
        		tree[k] = null;
	        	if(pa!=-1&&tree[pa]!=null){
	        	    tree[pa].childCnt--;
		            tree[pa].child[k] = 0;
	        	}
	        }
	    }
    }

    private static void makeDelList(int num){
	    delList[num] = 1;
       	for(int i=0;i<n;i++)
	        if(tree[num].child[i]==1)
        		makeDelList(i);
    }
}
