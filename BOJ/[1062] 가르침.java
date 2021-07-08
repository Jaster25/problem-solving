package boj1062;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N, K;
    static List<Set<Character>> words = new ArrayList<>();
    static boolean[] isLearned = new boolean[26];
    static int maxReadableWordCnt = 0;

    static boolean isReadable(Set<Character> set) {
        for (Character ch : set) {
            if (!isLearned[ch - 'a']) {
                return false;
            }
        }
        return true;
    }

    static void dfs(int selectedCnt, int idx) {
        if (selectedCnt == K) {
            int readableWordCnt = 0;
            for (Set<Character> word : words) {
                if (isReadable(word)) {
                    readableWordCnt++;
                }
            }
            maxReadableWordCnt = Math.max(readableWordCnt, maxReadableWordCnt);
            return;
        }

        for (int i = idx; i < 26; i++) {
            if (!isLearned[i]) {
                isLearned[i] = true;
                dfs(selectedCnt + 1, i + 1);
                isLearned[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        List<Character> defaultChar = Arrays.asList('a', 'n', 't', 'i', 'c');
        for (Character ch : defaultChar) {
            isLearned[ch - 'a'] = true;
        }

        for (int i = 0; i < N; i++) {
            s = br.readLine();
            for (Character ch : defaultChar) {
                s.replaceAll(String.valueOf(ch), "");
            }

            Set<Character> set = s.chars()
                    .mapToObj(ch -> (char) ch)
                    .collect(Collectors.toSet());
            words.add(set);
        }
        br.close();

        if (K < 5) {
            bw.write(String.valueOf(0));
        } else {
            dfs(5, 0);
            bw.write(String.valueOf(maxReadableWordCnt));
        }

        bw.flush();
        bw.close();
    }
}