import java.util.*;
import java.io.*;
public class Shifts229A {
	public static void main(String[] args) {
		FastReader fr = new FastReader();

		int n = fr.nextInt();
		int m = fr.nextInt();

		List<List<Integer>> ones = new ArrayList<>();
		String[] strs = new String[n];
		for(int i = 0; i < n; i++) {
			String s = fr.next();
			strs[i] = s;
			ones.add(new ArrayList<>());
			for(int j = 0; j < m; ++j) {
				if(s.charAt(j) == '1') {
					ones.get(i).add(j);
				}
			}
		}

		int minSum = Integer.MAX_VALUE;
		for(int j = 0; j < m; ++j) {
			int colSum = 0;
			for(int i = 0; i < n; i++) {	
				if(strs[i].charAt(j) == '0') {
					if(ones.get(i).size() == 0) {
						System.out.println(-1);
						return;
					}
					int minValue = Integer.MAX_VALUE;
					/*for(Integer index : ones.get(i)) {
						int minV = -1;
						if(index < j) {
							minV = Math.min(j - index, index + m - j);
						}
						else {
							minV = Math.min(index - j, j + m - index);
						}
						minValue = Math.min(minValue, minV);
					}*/
					int fIndex = findFloor(ones.get(i), 0, ones.get(i).size()-1, j);
					if(fIndex == -1) {
						fIndex = ones.get(i).size() - 1;
					}
					int cIndex = (fIndex + 1) % ones.get(i).size(); 

					int floorIndex = ones.get(i).get(fIndex);
					int ceilIndex = ones.get(i).get(cIndex);
					int minV1 = -1;
					if(floorIndex < j) {
						minV1 = Math.min(j - floorIndex, floorIndex + m - j);
					}
					else {
						minV1 = Math.min(floorIndex - j, j + m - floorIndex);
					}

					int minV2 = -1;
					if(ceilIndex < j) {
						minV2 = Math.min(j - ceilIndex, ceilIndex + m - j);
					}
					else {
						minV2 = Math.min(ceilIndex - j, j + m - ceilIndex);
					}
					minValue = Math.min(minV1, minV2);					
					//System.out.println("   " + i + " " + minValue);
					colSum += minValue;
				}
			}
			//System.out.println(j + " " + colSum);
			minSum = Math.min(minSum, colSum);
		}
		System.out.println(minSum);
	}

	public static int findFloor(List<Integer> arr, int lo, int hi, int key) {
		if(lo > hi) {
			return -1;
		}
		int mid = lo + (hi - lo) / 2;

		if(arr.get(mid) == key) {
			return mid;
		}

		if(arr.get(mid) < key && (mid+1 > hi || arr.get(mid + 1) > key)) {
			return mid;
		}

		if(arr.get(mid) < key) {
			return findFloor(arr, mid + 1, hi, key);
		}
		else {
			return findFloor(arr, lo, mid - 1, key);
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