import java.util.*;
import java.io.*;

public class LuckyTransformation121B {
	public static void main(String[] args) {
		FastReader fr = new FastReader();

        int N = fr.nextInt();
        int K = fr.nextInt();

        String s = fr.next();
        StringBuilder sb = new StringBuilder(s);

        TreeSet<Integer> indices = new TreeSet<>();
        for(int i = 0; i < s.length() - 1; ++i) {
            if(s.charAt(i) == '4' && s.charAt(i+1) == '7') {
                indices.add(i);
            }
        }		

        while(indices.size() > 0 && K > 0) {
            Integer first = indices.first();
            if((first+1) % 2 == 0) {
                sb.setCharAt(first, '7');
                sb.setCharAt(first + 1, '7');
            }
            else {
                sb.setCharAt(first, '4');
                sb.setCharAt(first + 1, '4');
            }
            indices.remove(first);

            if(first > 0) {
                if(sb.charAt(first - 1) == '4' && sb.charAt(first) == '7') {
                    indices.add(first - 1);
                }
            }

            if(first + 1 < (s.length() - 1)) {
                if(sb.charAt(first + 1) == '4' && sb.charAt(first + 2) == '7') {
                    indices.add(first + 1);
                }
            }

            K--;
        }

        System.out.println(sb.toString());

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