import java.lang.StringBuilder;


class Solution {
    
    static String convertToBinary(int length, int number) {
        String binary = Integer.toString(number, 2);
        String extendedBinary = "0".repeat(length - binary.length()) + binary;
        return extendedBinary;
    }
    
    static String overlap(String row1, String row2) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < row1.length(); i++) {
            if (row1.charAt(i) == '0' && row2.charAt(i) == '0') {
                sb.append(" ");
            } else {
                sb.append("#");
            }
        }
        return sb.toString();
    }
    
    static String encode(String row) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < row.length(); i++) {
            if (row.charAt(i) == '1') {
                sb.append("#");
            } else {
                sb.append(" ");
            }   
        }
        return sb.toString();
    }
    
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for (int i = 0; i < n; i++) {
            String binary1 = convertToBinary(n, arr1[i]);
            String binary2 = convertToBinary(n, arr2[i]);
            String overlappedRow = overlap(binary1, binary2);
            String encodedRow = encode(overlappedRow);
            answer[i] = overlappedRow;
        }
        return answer;
    }
}