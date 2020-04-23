import java.util.*;
import java.io.*;

public class Replacement570C {

	public static void main(String[] args) {
		FastReader fr = new FastReader();

		int N = fr.nextInt();
		int M = fr.nextInt();

		String s = fr.next();
		StringBuilder sb = new StringBuilder();

		boolean found = false;
		int dotCount = 0, groupCount = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) == '.') {
				dotCount++;
				if(found == false) {
					groupCount++;
					found = true;
				}
			}
			else {
				found = false;
			}
			sb.append(s.charAt(i));
		}

		//System.out.println(dotCount + " " + groupCount);

		for(int i = 0; i < M; i++) {
			int index = fr.nextInt();
			char c = fr.next().charAt(0);
			index--;

			if(c == '.') {
				if(sb.charAt(index) != '.') {
					int count = 0;
					if((index-1) >= 0 && sb.charAt(index-1) == '.') {
						count++;
					}
					if((index+1) < sb.length() && sb.charAt(index+1) == '.') {
						count++;
					}
					if(count == 0) {
						groupCount++;
					}
					else if(count == 2) {
						groupCount--;
					}
					dotCount++;
					sb.setCharAt(index, c);
				}
			}
			else {
				if(sb.charAt(index) == '.') {
					int count = 0;
					if((index-1) >= 0 && sb.charAt(index-1) == '.') {
						count++;
					}
					if((index+1) < sb.length() && sb.charAt(index+1) == '.') {
						count++;
					}
					if(count == 0) {
						groupCount--;
					}
					else if(count == 2) {
						groupCount++;
					}
					dotCount--;
					sb.setCharAt(index, c);
				}
			}
			
			System.out.println(dotCount - groupCount);
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