package wk10;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    static final long MAX_VALUE = Long.MAX_VALUE;
    static final long MIN_VALUE = Long.MIN_VALUE;

    static List<Point> intersections = new ArrayList<>();

    Point getIntersection(int[] point1, int[] point2) {
        long denominator = (long) point1[0] * point2[1] - (long) point1[1] * point2[0];
        if (denominator == 0) {
            return null;
        }

        long numerator1 = (long) point1[1] * point2[2] - (long) point1[2] * point2[1];
        long numerator2 = (long) point1[2] * point2[0] - (long) point1[0] * point2[2];
        if (numerator1 % denominator != 0 || numerator2 % denominator != 0) {
            return null;
        }

        int x = (int) (numerator1 / denominator);
        int y = (int) (numerator2 / denominator);
        return new Point(y, x);
    }

    public String[] solution(int[][] line) {
        for (int[] point1 : line) {
            for (int[] point2 : line) {
                Point intersectingPoint = getIntersection(point1, point2);
                if (intersectingPoint != null) {
                    intersections.add(intersectingPoint);
                }
            }
        }

        long maxY = MIN_VALUE;
        long minY = MAX_VALUE;
        long maxX = MIN_VALUE;
        long minX = MAX_VALUE;
        for (Point intersection : intersections) {
            int y = intersection.y;
            int x = intersection.x;
            maxX = Math.max(x, maxX);
            minX = Math.min(x, minX);
            maxY = Math.max(y, maxY);
            minY = Math.min(y, minY);
        }

        int height = (int) (maxY - minY + 1);
        int width = (int) (maxX - minX + 1);
        char[][] matrix = new char[height][width];
        for (char[] chars : matrix) {
            Arrays.fill(chars, '.');
        }

        for (Point intersection : intersections) {
            int y = (int) (intersection.y - minY);
            int x = (int) (intersection.x - minX);
            matrix[y][x] = '*';
        }

        String[] result = new String[height];
        for (int i = 0; i < height; i++) {
            result[i] = String.valueOf(matrix[height - i - 1]);
        }
        return result;
    }

    static class Point {
        int y, x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}