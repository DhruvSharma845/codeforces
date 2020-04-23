import java.util.*;
public class CompleteTheWord716B {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String initial = scanner.next();
		int initialLength = initial.length();

		if(initialLength < 26) {
			System.out.println("-1");
			return;	
		}

		char[] finalCharArr = initial.toCharArray();

		int[] countMap = new int[26];
		int noOfDuplicates = 0;
		int noOfQues = 0;
		int i = 0;
		for(; i < 25; i++) {
			char ch = initial.charAt(i);
			if(ch == '?') {
				noOfQues++;
			}
			else {
				int c = (int)ch - 65;
				if(countMap[c] == 1) {
					noOfDuplicates++;
				}
				countMap[c]++;
			}
		}

		boolean found = false;
		while(i < initialLength) {
			char ch = initial.charAt(i);
			if(ch == '?') {
				noOfQues++;
			}
			else {
				int c = (int)ch - 65;
				if(countMap[c] == 1) {
					noOfDuplicates++;
				}
				countMap[c]++;
			}

			if(noOfDuplicates == 0) {
				int nextIndex = 0;
				for(int j = i-25; j <= i; j++) {
					if(finalCharArr[j] == '?') {
						while(countMap[nextIndex] != 0) {
							nextIndex++;
						}
						finalCharArr[j] = (char)(nextIndex + 65);
						nextIndex++;
					}
				}
				found = true;
				break;
			}
			i++;
			char pch = initial.charAt(i-26);
			if(pch == '?') {
				noOfQues--;
			}
			else {
				int c = (int)pch - 65;
				countMap[c]--;
				if(countMap[c] == 1) {
					noOfDuplicates--;
				}
			}
		}

		if(found == true) {
			for(i = 0; i < initialLength; i++) {
				if(finalCharArr[i] == '?') {
					finalCharArr[i] = 'A';
				}
			}
			System.out.println(new String(finalCharArr));
		}
		else {
			System.out.println("-1");
		}
	}
}