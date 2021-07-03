package com.ps.java.pg1836;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

class Solution {
    static int M;
    static int N;
    static List<String> answer;
    static List<Position>[] tiles = new ArrayList[26];

    // TODO ff -> stream
    void dfs(char[][] board, int remainTileCnt, String removedSequence) {
        if (remainTileCnt == 0) {
            answer.add(removedSequence);
            return;
        }

        for (int i = 0; i < 26; i++) {
            tiles[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if ('A' <= board[i][j] && board[i][j] <= 'Z') {
                    tiles[board[i][j] - 'A'].add(new Position(i, j));
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (tiles[i].size() == 2) {
                int y1 = tiles[i].get(0).y;
                int x1 = tiles[i].get(0).x;
                int y2 = tiles[i].get(1).y;
                int x2 = tiles[i].get(1).x;
                if (isPossibleToRemove(y1, x1, y2, x2, board)) {
                    char originalTile = board[y1][x1];
                    board[y1][x1] = '.';
                    board[y2][x2] = '.';

                    dfs(board, remainTileCnt - 2, removedSequence + originalTile);

                    board[y1][x1] = originalTile;
                    board[y2][x2] = originalTile;
                }
            }
        }

        for (List<Position> tile : tiles) {
            tile.clear();
        }
    }

    boolean isPossibleToRemove(int y1, int x1, int y2, int x2, char[][] board) {
        // 수직 먼저
        if (y1 < y2) {
            boolean isPossible = true;
            for (int y = y1 + 1; y < y2; y++) {
                if (board[y][x1] != '.') {
                    isPossible = false;
                    break;
                }
            }
            // 수평
            if (isPossible) {
                for (int x = x1; x < x2; x++) {
                    if (board[y2][x] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                for (int x = x1; x > x2; x--) {
                    if (board[y2][x] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) {
                    return true;
                }
            }
        } else if (y1 > y2) {
            boolean isPossible = true;
            for (int y = y1 - 1; y > y2; y--) {
                if (board[y][x1] != '.') {
                    isPossible = false;
                    break;
                }
            }
            // 수평
            if (isPossible) {
                for (int x = x1; x < x2; x++) {
                    if (board[y2][x] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                for (int x = x1; x > x2; x--) {
                    if (board[y2][x] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) {
                    return true;
                }
            }
        }
        // 수평 먼저
        if (x1 < x2) {
            boolean isPossible = true;
            for (int x = x1 + 1; x < x2; x++) {
                if (board[y1][x] != '.') {
                    isPossible = false;
                    break;
                }
            }
            // 수직
            if (isPossible) {
                for (int y = y1; y < y2; y++) {
                    if (board[y][x2] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                for (int y = y1; y > y2; y--) {
                    if (board[y][x2] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) {
                    return true;
                }
            }
        } else if (x1 > x2) {
            boolean isPossible = true;
            for (int x = x1 - 1; x > x2; x--) {
                if (board[y1][x] != '.') {
                    isPossible = false;
                    break;
                }
            }
            // 수직
            if (isPossible) {
                for (int y = y1; y < y2; y++) {
                    if (board[y][x2] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                for (int y = y1; y > y2; y--) {
                    if (board[y][x2] != '.') {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) {
                    return true;
                }
            }
        }
        return false;
    }

    public String solution(int m, int n, String[] board) {
        answer = new ArrayList<>();
        M = m;
        N = n;

        int tileCnt = 0;
        char[][] newBoard = new char[M][N];

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                newBoard[i][j] = board[i].charAt(j);
            }
            tileCnt += board[i].chars().filter(x -> 'A' <= x && x <= 'Z').count();
        }

        dfs(newBoard, tileCnt, "");

        if (answer.size() == 0) {
            return "IMPOSSIBLE";
        } else {
            Collections.sort(answer);
            return answer.get(0);
        }
    }

    static class Position {
        int y, x;

        public Position(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    @Test
    public void test() {
        assertEquals("ZCB", solution(3, 3, new String[]{"B#Z", "C.Z", "B#C"}));
        assertEquals("AB", solution(1, 4, new String[]{"BAAB"}));
        assertEquals("C", solution(6, 1, new String[]{"C", ".", ".", ".", ".", "C"}));
        assertEquals("ABCDFHGIE", solution(5, 5, new String[]{"FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE"}));
        assertEquals("RYAN", solution(2, 4, new String[]{"NRYN", "ARYA"}));
        assertEquals("MUZI", solution(4, 4, new String[]{".ZI.", "M.**", "MZU.", ".IU."}));
    }
}

