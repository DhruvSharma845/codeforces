import java.util.*;
import java.io.*;

public class ProducingSnow923B {

	public static void main(String[] args) {
		FastReader fr = new FastReader();

		int N = fr.nextInt();
		long[] cTemp = new long[N];

		int[] snow = new int[N];
		for(int i = 0; i < N; ++i) {
			snow[i] = fr.nextInt();
		}

		int[] temp = new int[N];
		for(int i = 0; i < N; ++i) {
			temp[i] = fr.nextInt();
			cTemp[i] = ((i > 0) ? (long)cTemp[i-1] : 0L) + temp[i];
		}		
		
		int[] end = new int[N];
		long[] diff = new long[N];
		for(int i = 0; i < N; ++i) {
			long val = (long)snow[i] + ((i > 0) ? cTemp[i-1] : 0L);
			int index = ceilSearch(cTemp, val, i, N-1);
			//System.out.println(index);
			if(index >= 0 && index < N) {
				end[index]++;
				diff[index] += (long)(cTemp[index] - val);
				//System.out.println("Index: " + index + " Diff:" + diff[index]);
			}

		}

		int count = 0;
		for(int i = 0; i < N; ++i) {
			count = count + 1 - ((i > 0) ? end[i-1] : 0);
			//System.out.println(count);
			long val = (long)(temp[i] * count) - (long)diff[i]; 
			System.out.print(val + " ");
		}

	}

	public static int ceilSearch(long[] arr, long x, int low, int high) {
		int mid;      
      
    	if(x <= arr[low])  
        	return low;  
      
    	if(x > arr[high])  
        	return -1;  
      
    	mid = low + (high - low) / 2;
      
    	if(arr[mid] == x)  
        	return mid;  
          
    	else if(arr[mid] < x)  
    	{  
        	if(mid + 1 <= high && x <= arr[mid + 1])  
            	return mid + 1;  
        	else
            	return ceilSearch(arr,x , mid + 1, high);  
    	}  
    	else
    	{  
        	if(mid - 1 >= low && x > arr[mid - 1])  
            	return mid;  
        	else
            	return ceilSearch(arr, x, low, mid - 1);  
    	}  
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