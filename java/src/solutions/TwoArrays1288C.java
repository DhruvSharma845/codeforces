import java.util.*;
import java.io.*;

public class TwoArrays1288C {

	public static void main(String[] args) {
		FastReader fr = new FastReader();
		int n = fr.nextInt();
		int m = fr.nextInt();

		int[][] a = new int[n+2][2*(m+1)];
		for(int i=1; i <= 2*m; i++)	{
			a[1][i] = 1;
		}

		for(int i=1; i <= n; i++) {
			a[i][1] = i;
		}	
		for(int i=2; i <= n+1; i++) {
			for(int j=2; j <= 2*m+1; j++) {
				a[i][j]=(a[i][j-1] + a[i-1][j]) % 1000000007;
			}	
		}
		
		System.out.println(a[n][2*m]);
	}

	static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
}