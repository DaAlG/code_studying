import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
	public static List<Node> nodeList = new ArrayList<>();
	public static int index = 0;
    public static int[][] solution(int[][] nodeinfo) {
    	int[][] answer = {};
    	
    	// 노드 생성
    	for (int i = 0; i < nodeinfo.length; i++) {
			nodeList.add(new Node(i+1, nodeinfo[i][0], nodeinfo[i][1]));
		}
    	
    	// y 기준 내림차순 정렬
    	Collections.sort(nodeList, (i,j)->-(i.y-j.y));
    	
    	// 루트 노드
    	Node root = nodeList.get(0);
    	
    	// 노드 연결
    	for (int i = 1; i < nodeList.size(); i++) {
			Node child = nodeList.get(i);
			connectNode(root, child);
		}
    	
    	answer = new int[2][nodeList.size()];
    	// 전위 순회
    	preorder(answer, root);
    	// 후위 순회
    	index = 0;
    	postorder(answer, root);
    	
        return answer;
    }
    
    public static void preorder(int[][] ans, Node node) {
    	if(node!=null) {
    		ans[0][index] = node.n;
    		index++;
    		if(node.leftChild!=null) preorder(ans, node.leftChild);
    		if(node.rightChild!=null) preorder(ans, node.rightChild);
     	}
    }
    public static void postorder(int[][] ans, Node node) {
    	if(node!=null) {
    		if(node.leftChild!=null) postorder(ans, node.leftChild);
    		if(node.rightChild!=null) postorder(ans, node.rightChild);
    		ans[1][index] = node.n;
    		index++;
    	}
    }
    
    public static void connectNode(Node parent, Node child) {
    	if(child.x < parent.x) {
    		if(parent.leftChild == null) {
    			parent.leftChild = child;
    		}else {
    			connectNode(parent.leftChild, child);
    		}
    	}else {
    		if(parent.rightChild == null) {
    			parent.rightChild = child;
    		}else {
    			connectNode(parent.rightChild, child);
    		}
    	}
    }
        
	static class Node{
		Node leftChild;
		int n;
		int x;
		int y;
		Node rightChild;
		
		public Node(int n, int x, int y) {
			this.n = n;
			this.x = x;
			this.y = y;
		}
	}
}

