import java.util.*;
import java.io.*;

public class HarryPotterAndHistoryOfMagic65B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String[] dates = new String[N];
		for (int i = 0; i < N; ++i) {
			dates[i] = sc.next();
		}

		String correctedDates = correctDates(dates);
		System.out.println(correctedDates);
	}

	public static String correctDates(String[] dates) {
		if(dates.length == 0) {
			return "";
		}
		StringBuilder sb = new StringBuilder("");
		String res = makeDateCorrect(dates[dates.length - 1], "2011");
		if(res == null) {
			return "No solution";
		}
		sb.append(res);
		dates[dates.length - 1] = res;
		//System.out.println((dates.length - 1) +  " " + dates[dates.length - 1]);

		for(int i = dates.length - 2; i >= 0; --i) {
			String num = dates[i];
			res = makeDateCorrect(dates[i], dates[i+1]);
			if(res == null) {
				return "No solution";
			}
			sb.insert(0, res + "\n");
			dates[i] = res;
			//System.out.println(i + " " + dates[i]);
		}
		return sb.toString();
	}
	public static String makeDateCorrect(String date, String maxPossibleDate) {
		StringBuilder sb = determineDigitByBacktracking(new StringBuilder(date), maxPossibleDate, 0);
		if(sb == null) {
			return null;
		}
		return sb.toString();
	}
	public static StringBuilder determineDigitByBacktracking(StringBuilder date, String maxPossibleDate, int index) {
		if(index == 4) {
			if(Integer.parseInt(date.toString()) <= Integer.parseInt(maxPossibleDate)) {
				return date;
			}
			return null;
		}
		int maxRange = 9;
		int minRange = 1;
		if(index == 0) {
			maxRange = 2;
		}
		else {
			minRange = 0;
		}
		for(int i = maxRange; i >= minRange; --i) {
			if(i != Integer.parseInt(String.valueOf(date.charAt(index)))) {
				char prevChar = date.charAt(index);
				date.setCharAt(index, (char)(i+48));
				if(Integer.parseInt(date.toString()) <= Integer.parseInt(maxPossibleDate)) {
					return date;
				}
				date.setCharAt(index, prevChar);
			}
			else if(i == Integer.parseInt(String.valueOf(date.charAt(index)))) {
				StringBuilder updatedDate = determineDigitByBacktracking(date, maxPossibleDate, index + 1);
				if(updatedDate != null) {
					return updatedDate;
				}
			}
		}
		return null;
	}
}