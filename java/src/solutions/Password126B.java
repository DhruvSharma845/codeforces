import java.util.*;
import java.io.*;

public class Password126B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String res = findRequiredSubstring(S);
		System.out.println(res);
	}

	public static String findRequiredSubstring(String str) {
		int[] automaton = buildFailureAutomaton(str);

		int maxSuffixPrefix = automaton[str.length()];
		if(maxSuffixPrefix == -1) {
			return "Just a legend";
		}

		boolean found = false;
		for(int i = 1; i < str.length() - 1; i++) {
			if(automaton[i] == maxSuffixPrefix) {
				found = true;
			}
		}
		if(found == true) {
			return str.substring(0, maxSuffixPrefix + 1);
		}
			
		while(automaton[maxSuffixPrefix + 1] != -1) {
			maxSuffixPrefix = automaton[maxSuffixPrefix + 1];
			found = false;
			for(int i = 2; i <= str.length() - 1; i++) {
				if(automaton[i] == maxSuffixPrefix) {
					found = true;
				}
			}
			if(found == true) {
				return str.substring(0, maxSuffixPrefix + 1);
			}
		}	

		
		return "Just a legend";
	}

	public static int[] buildFailureAutomaton(String str) {
		int[] automaton = new int[str.length() + 1];

		automaton[0] = -1;
		if(str.length() >= 1) {
			automaton[1] = -1;
		}
		int currentState = -1;

		int currentPos = 2;
		while(currentPos <= str.length()) {
			while(currentState != -1 && str.charAt(currentPos - 1) != str.charAt(currentState + 1)) {
				currentState = automaton[currentState + 1];
			}

			if(str.charAt(currentPos - 1) == str.charAt(currentState + 1)) {
				automaton[currentPos] = (++currentState);
			}
			else {
				automaton[currentPos] = -1;
			}
			//System.out.println(currentPos + " " + currentState);
			currentPos++;
		}
		return automaton;
	}
}