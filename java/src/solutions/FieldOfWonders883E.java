import java.util.*;
import java.io.*;

public class FieldOfWonders883E {
	
	public static void main(String[] args) {
		FastReader fr = new FastReader();
		int numOfChars = fr.nextInt();

		//int[] charsRevealed = new int[26];
		String str = fr.next();

		Set<Character> charsReveal = new HashSet<>();
		List<Integer> starIndices = new ArrayList<>();
		List<Integer> charIndices = new ArrayList<>();
		for(int i = 0; i < numOfChars; ++i) {
			if(str.charAt(i) != '*') {
				//int index = ((int)str.charAt(i)) - 97;
				//charsRevealed[index]++;
				charsReveal.add(str.charAt(i));
				charIndices.add(i);
			}
			else {
				starIndices.add(i);
			}
		}

		int m = fr.nextInt();
		Set<Character> intersection = new HashSet<>();
		String[] options = new String[m];

		boolean filled = false;

		for(int i = 0; i < m; ++i) {
			options[i] = fr.next();

			if(filled == false && intersection.size() == 0) {
				Set<Character> temp = new HashSet<>();
				boolean valid = true;
				for(Integer index: starIndices) {
					char c = options[i].charAt(index);
					if(!charsReveal.contains(c)) {
						temp.add(c);
					}
					else {
						valid = false;
						break;
					}
				}
				for(Integer index: charIndices) {
					if(options[i].charAt(index) != str.charAt(index)) {
						valid = false;
					}
				}
				if(valid == true) {
					intersection = temp;
					if(intersection.size() > 0) {
						filled = true;
					}
				}
			}
			else {
				Set<Character> temp = new HashSet<>();
				boolean valid = true;
				for(Integer index: starIndices) {
					char c = options[i].charAt(index);
					if(!charsReveal.contains(c)) {
						if(intersection.contains(c)) {
							temp.add(c);
						}
					}
					else {
						valid = false;
						break;
					}
				}
				for(Integer index: charIndices) {
					if(options[i].charAt(index) != str.charAt(index)) {
						valid = false;
					}
				}
				if(valid == true) {
					intersection = temp;
				}
			}
		}

		/*Set<Character> intersection = new HashSet<>();
		boolean first = false;
		for(int i = 0; i < numOfChars; ++i) {
			if(str.charAt(i) == '*') {
				Set<Character> temp = new HashSet<>();
				for(int j = 0; j < m; j++) {
					char c = options[j].charAt(i);
					if(!charsReveal.contains(c)) {
						if(first == false) {
							intersection.add(c);
						}
						else if(intersection.contains(c)) {
							temp.add(c);
						}
					}
				}
				if(first != false) {
					intersection = temp;
				}
				else {
					first = true;
				}
			}
		}*/

		System.out.println(intersection.size());
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