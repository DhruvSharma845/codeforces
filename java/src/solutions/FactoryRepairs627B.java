import java.util.*;
import java.io.*;

public class FactoryRepairs627B {
	public static void main(String[] args) {
		FastReader sc = new FastReader();
		int n = sc.nextInt();
		int k = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int q = sc.nextInt();

		int[] reducedOrders = new int[n+1];		
		int[] normalOrders = new int[n+1];
		

		Map<Integer, Integer> sortedMap = new TreeMap<>();
		StringBuilder maxOrders = new StringBuilder(""); 
		
		for (int i = 0; i < q; ++i) {
			int type = sc.nextInt();
			if(type == 1) {
				int day = sc.nextInt();
				int updateV = sc.nextInt();
				
				if(!sortedMap.containsKey(day)) {
					sortedMap.put(day, 0);
				}
				int curVal = sortedMap.get(day);
				if(curVal + updateV <= b) {
					update(day, updateV, reducedOrders, n);
					update(day, updateV, normalOrders, n);
				}
				else if(curVal + updateV > b && curVal + updateV <= a) {
					if(curVal < b) {
						update(day, b - curVal, reducedOrders, n);
					}
					update(day, updateV, normalOrders, n);	
				}
				else if(curVal + updateV > a) {
					if(curVal < b) {
						update(day, b - curVal, reducedOrders, n);
					}
					if(curVal < a) {
						update(day, a - curVal, normalOrders, n);	
					}
				}
				sortedMap.put(day, sortedMap.get(day) + updateV);

			}
			else if(type == 2) {
				int repairDay = sc.nextInt();
				int orders = 0;
				orders += query(repairDay - 1, reducedOrders) - query(0, reducedOrders);
				orders += query(n, normalOrders) - query(repairDay + k - 1, normalOrders);
				maxOrders.append(orders + "\n");
			}
		}

		System.out.println(maxOrders.toString());
	}

	public static void update(int x, int delta, int[] BIT, int n) {
		for(; x <= n; x += x&-x) {
			BIT[x] += delta;
		}
	}

	public static int query(int x, int[] BIT) {
		int sum = 0;
		for(; x > 0; x -= x&-x) {
        	sum += BIT[x];
		}
     	return sum;
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