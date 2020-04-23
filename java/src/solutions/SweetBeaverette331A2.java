import java.io.*;
import java.util.*;
import java.util.stream.*;

public class SweetBeaverette331A2 {
    static class IntervalInfo {
    	public int s;
    	public int e;
        public Long totalAppeal;
    }

    public static void main(String[] args) {
    	FastReader fr = new FastReader();
    	int numOfTrees = fr.nextInt();
    	int[] eap = new int[numOfTrees];
    	for(int i = 0; i < numOfTrees; i++) {
    		eap[i] = fr.nextInt();
    	}

        IntervalInfo finalP = new IntervalInfo();
    	long countOfCutTrees = findTreesToBeCut(numOfTrees, eap, finalP);
    	System.out.print(finalP.totalAppeal + " " + countOfCutTrees + "\n");
        StringBuilder sb = new StringBuilder();
    	for(int i = 0; i < numOfTrees; i++) {
            if(i < finalP.s || i > finalP.e) {
                sb.append((i+1) + " ");
            }
            else if(i > finalP.s && i < finalP.e && eap[i] < 0){
                sb.append((i+1) + " ");
            }
        }
        System.out.print(sb.toString());
    }

    public static long findTreesToBeCut(int n, int[] app, IntervalInfo finalP) {
    	
    	long[] sum = new long[n];
        int[] negCount = new int[n];
    	Map<Integer, Integer> indexMap = new HashMap<>();
    	
        long maxSum = Long.MIN_VALUE;
        long countOfCutTrees = 0L;
        
        if(app[0] >= 0) {
            negCount[0] = 0;
            sum[0] = app[0];
        }
        else {
            negCount[0] = 1;
            sum[0] = 0;
        }
        indexMap.put(app[0], 0);
        for(int i = 1; i < n; i++) {

    		if(app[i] >= 0) {
    			sum[i] = sum[i-1] + app[i];
                negCount[i] = negCount[i-1];
    		}
    		else {
    			sum[i] = sum[i-1];
                negCount[i] = negCount[i-1] + 1; 
    		}


    		if(!indexMap.containsKey(app[i])) {
    			indexMap.put(app[i], i);
    		}
    		else {
    			Integer s = indexMap.get(app[i]);
                
                long curSum = sum[i] - ((s > 0) ? sum[s - 1] : 0);
                if(app[s] < 0) {
                    curSum += (app[s] + app[i]);
                }
                if(curSum > maxSum) {
                    maxSum = curSum;
                    finalP.s = s;
                    finalP.e = i;
                    finalP.totalAppeal = maxSum;

                    countOfCutTrees = s;
                    countOfCutTrees += (n - i - 1);
                    countOfCutTrees += (negCount[i] - negCount[s]);
                    if(app[s] < 0) {
                        countOfCutTrees--;
                    }
                }
    		}
    	}
    	return countOfCutTrees;
    }

    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next() { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException  e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() { 
            String str = ""; 
            try { 
                str = br.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
}