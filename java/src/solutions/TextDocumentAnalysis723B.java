package solutions;

import java.util.Scanner;

public class TextDocumentAnalysis723B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        String s = scanner.next();

        findDetails(N, s);
    }

    private static void findDetails(int n, String s) {

        int start_index = -1;
        int end_index = -1;

        int max_length = 0;
        int num_words = 0;
        boolean isInBrackets = false;

        for (int i = 0; i < s.length(); i++) {
            if (Character.isLetter(s.charAt(i))) {
                if(start_index == -1) {
                    start_index = i;
                }
                end_index = i;
            }
            else if (s.charAt(i) == '_' || s.charAt(i) == '(') {
                if(start_index != -1 && end_index != -1) {
                    if(isInBrackets == false) {
                        int word_length = end_index - start_index + 1;
                        if (word_length > max_length) {
                            max_length = word_length;
                        }
                    }
                    else if(s.charAt(i) == '_' && isInBrackets == true) {
                        num_words++;
                    }
                    start_index = -1;
                    end_index = -1;
                }
                if (s.charAt(i) == '(') {
                    isInBrackets = true;
                }
            }
            else if(s.charAt(i) == ')') {
                if(start_index != -1 && end_index != -1) {
                    if (isInBrackets == true) {
                        num_words++;
                    }
                    start_index = -1;
                    end_index = -1;
                }
                isInBrackets = false;
            }
        }
        if(start_index != -1 && end_index != -1 && isInBrackets == false) {
            int word_length = end_index - start_index + 1;
            if (word_length > max_length) {
                max_length = word_length;
            }
        }

        System.out.println(max_length + " " + num_words);
    }
}
