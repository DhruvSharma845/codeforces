import java.util.*;
import java.io.*;

public class AntonAndLetters443A {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String x = scanner.nextLine();
		
		String trimmedString = x.substring(1, x.length()-1);
		String[] arr = trimmedString.split(", ");
	
		if(!trimmedString.trim().equals("")){
			Set<String> unique = new HashSet<>();
			for(int i=0;i< arr.length;i++){
				unique.add(arr[i]);
			}
			
			System.out.println(unique.size());
		}
		else {
			System.out.println("0");
		}
	}
}
