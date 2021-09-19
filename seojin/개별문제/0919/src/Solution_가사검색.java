import java.util.*;

class Solution_가사검색 {
	
    public int[] solution(String[] words, String[] queries) {
    	
        Trie[] trie = new Trie[100001];                
        
        for(int i = 0; i < words.length; i++) {
            int wordLen = words[i].length();
            if(trie[wordLen] == null) {
                trie[wordLen] = new Trie();
            }
            trie[wordLen].insert(words[i]);
        }
        
        int[] answer = new int[queries.length];
        
        for(int i = 0; i < queries.length; i++) {
            int queryLen  = queries[i].length();
            if(trie[queryLen] == null) {
                answer[i] =0;
                continue;
            }
            answer[i] = trie[queryLen].getCount(queries[i]);
        }
        
        return answer;
    }
    
    class Trie{
        TrieNode forward;
        TrieNode back;
        
        Trie(){
            forward = new TrieNode();
            back = new TrieNode();
        }
        
        public void insert(String words) {
            insertBack(words);
            insertForward(words);
        }
        
        private void insertBack(String words) {
            TrieNode node = back;
            for(int i = words.length() - 1; i >= 0; i--) {
                node.count++;
                if(!node.childNodes.containsKey(words.charAt(i))){
                    node.childNodes.put(words.charAt(i), new TrieNode());
                }
                node = node.childNodes.get(words.charAt(i));
            }
        }
        private void insertForward(String words) {
            TrieNode node = forward;
            for(int i = 0 ; i <  words.length(); i++) {
                node.count++;
                if(!node.childNodes.containsKey(words.charAt(i))){
                    node.childNodes.put(words.charAt(i), new TrieNode());
                }
                node = node.childNodes.get(words.charAt(i));
            }
        }
        
        public int getCount(String query) {
            if(query.charAt(0) == '?') {       
                return getCountBack(query);
            }
            return getCountForward(query);
        }
        
        private int getCountBack(String query) {
            TrieNode node = back;
            for(int i = query.length() - 1; i >= 0 ; i--) {
                if(query.charAt(i) =='?') {
                    return node.count;
                }
                if(!node.childNodes.containsKey(query.charAt(i))) {
                    return 0;
                }
                node = node.childNodes.get(query.charAt(i));
            }
            return node.count;
        }
        
        private int getCountForward(String query) {
            TrieNode node = forward;
            for(int i = 0; i < query.length(); i++ ){
                if(query.charAt(i) =='?') {
                    return node.count;
                }
                if(!node.childNodes.containsKey(query.charAt(i))) {
                    return 0;
                }
                node = node.childNodes.get(query.charAt(i));
            }
            return node.count;
        }
    }
    
    class TrieNode{
        int count;
        Map<Character, TrieNode> childNodes;
        
        public TrieNode() {
            count = 0;
            childNodes = new HashMap<Character, TrieNode>();
        }
    }

}