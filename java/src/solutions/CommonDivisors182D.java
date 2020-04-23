import java.util.*;
public class CommonDivisors182D {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String str1 = scanner.next();
		String str2 = scanner.next();

		int s1Len = str1.length();
		int s2Len = str2.length();

		int commonDivs = -1;
		if(s1Len < s2Len) {
			commonDivs = findCommonDivisors(str1, str2);
		}
		else {
			commonDivs = findCommonDivisors(str2, str1);
		}
		System.out.println(commonDivs);
	}

	public static int findCommonDivisors(String s1, String s2) {
		int s1L = s1.length();
		int s2L = s2.length();

		if(s1L == 0 || s2L == 0) {
			return 0;
		}

		boolean equals = true;

		int count = 0;

		int divLen = 1;
		while(divLen <= s1L) {
			if(s1L % divLen != 0 || s2L % divLen != 0) {
				divLen += 1;
				continue;
			}
			equals = true;
			int i = divLen;
			while(i < s1L) {
				int k = 0;
				while(k < divLen) {
					if((i+k) >= s1L || s1.charAt(i+k) != s1.charAt(k)) {
						equals = false;
						break;
					} 
					k++;
				}
				i += divLen;
			}
			//System.out.println("DivLen: " + divLen + " Equals: " + equals);
			if(equals == false) {
				divLen += 1;
				continue;
			}
			int j = 0;
			while(j < s2L) {
				int k = 0;
				while(k < divLen) {
					if((j+k) >= s2L || s2.charAt(j+k) != s1.charAt(k)) {
						equals = false;
						break;
					} 
					k++;
				}
				j += divLen; 
			}

			if(equals == true) {
				count++;
			}

			divLen += 1;
		}

		return count;
	}


}