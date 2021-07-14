package pg42579;

import java.util.*;

class Solution {
    static Map<String, Integer> genreMap = new HashMap<>();

    public int[] solution(String[] genres, int[] plays) {
        List<Music> musics = new ArrayList<>();
        for (int i = 0; i < genres.length; i++) {
            Integer genrePlayedCnt = genreMap.get(genres[i]);
            genreMap.put(genres[i], genrePlayedCnt == null ? plays[i] : genrePlayedCnt + plays[i]);

            musics.add(new Music(genres[i], i, plays[i]));
        }

        Collections.sort(musics);

        List<Integer> answer = new ArrayList<>();
        genreMap.replaceAll((key, value) -> 0);

        for (Music music : musics) {
            Integer curGenreCnt = genreMap.get(music.genre);
            if (curGenreCnt < 2) {
                genreMap.put(music.genre, curGenreCnt + 1);
                answer.add(music.idx);
            }
        }

        return answer.stream().mapToInt(x -> x).toArray();
    }

    static class Music implements Comparable<Music> {
        String genre;
        int idx;
        int playedCnt;

        public Music(String genre, int idx, int playedCnt) {
            this.genre = genre;
            this.idx = idx;
            this.playedCnt = playedCnt;
        }

        @Override
        public int compareTo(Music o) {
            if (!genreMap.get(this.genre).equals(genreMap.get(o.genre))) {
                return genreMap.get(o.genre) - genreMap.get(this.genre);
            }
            if (this.playedCnt == o.playedCnt) return this.idx - o.idx;
            return o.playedCnt - this.playedCnt;
        }
    }
}