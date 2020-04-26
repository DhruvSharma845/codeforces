import java.util.*;
public class SpellingCheck39J {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String s1 = scanner.next();
		String s2 = scanner.next();

		if(s1.length() == 1 && s2.length() == 0) {
			System.out.println("1");
			System.out.println("1");
		}

		int i = 0;
		int left = 0;
		while(left < s2.length() && s1.charAt(i) == s2.charAt(left)) {
			i++;
			left++;
		}

		int j = s1.length() - 1;
		int right = s2.length() - 1;
		while(right >= 0 && s1.charAt(j) == s2.charAt(right)) {
			j--;
			right--;
		}

		if(right - left < 0) {
			System.out.println("" + (left-right));
			right++;
			StringBuilder sb = new StringBuilder();
			while(right <= left) {
				sb.append((right+1) + " ");
				//System.out.print((right+1) + " ");
				right++;
			}
			System.out.println(sb.toString());
		}
		else {
			System.out.println("0");
		}
	}
}