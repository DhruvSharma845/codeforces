import java.util.*;
import java.io.*;
public class WordCut176B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String start = sc.next();
		String end = sc.next();
		int K = sc.nextInt();

		int res = findWaysOfWordCut(start, end, K);
		System.out.println(res);
	}

	public static int findWaysOfWordCut(String start, String end, int K) {
		int res = 0;
		if(start.length() <= 1 || end.length() <= 1) {
			return res;
		}
		res = findWaysWordCutUtil(start, end, K);
		return res % 1000000007;
	}

	public static int findWaysWordCutUtil(String s, String e, int K) {
		if(K == 0) {
			if (s.equals(e)) {
				return 1;
			}
			return 0;
		}
		/*int res = 0;
		/*for(int i = 1; i < s.length(); ++i) {
			String w = s.substring(i) + s.substring(0, i);
			System.out.println(K + " " + w);
			res = (res + (findWaysWordCutUtil(w, e, K - 1) % 1000000007)) % 1000000007;
		}*/
		int[][] dpTable = new int[K + 1][2];
		if(!s.equals(e)) {
			dpTable[0][0] = 1;
		}
    	else {
    		dpTable[0][1] = 1;
    	}
    	int sameE = 0;
    	for(int i = 0; i < s.length(); i++) {
        	boolean flag = true;
        	for(int j = 0; j < e.length(); j++) {
            	if(s.charAt((i+j) % s.length()) != e.charAt(j)) {
                	flag = false;
                	break;
            	}
        	}
        	if(flag == false) {
        		sameE++;
        	}
    	}
    	for(int i = 0; i < K; i++) {
    		
    		dpTable[i+1][0] = ((sameE - 1 * dpTable[i][1]) % 1000000007 + ((sameE - 1) * dpTable[i][0]) % 1000000007) % 1000000007;
        	dpTable[i+1][1] = (((s.length() - sameE) * dpTable[i][0]) % 1000000007 + ((s.length() - sameE - 1) * dpTable[i][1])  % 1000000007) % 1000000007;
    		/*
        	dpTable[i+1][0] = (sameE * dpTable[i][1] + (sameE - 1) * dpTable[i][0]) % 1000000007;
        	dpTable[i+1][1] = ((s.length() - sameE) * dpTable[i][0] + (s.length() - sameE - 1) * dpTable[i][1]) % 1000000007;
    		*/
    	}
    	return dpTable[K][0] % 1000000007;
	}
}