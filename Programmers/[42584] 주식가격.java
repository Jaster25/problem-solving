package com.ps.java.pg42584;

import java.util.Stack;

class Solution {
    static Stack<Stock> stack = new Stack<>();

    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        for (int i = 0; i < prices.length; i++) {
            while (!stack.isEmpty() && stack.peek().price > prices[i]) {
                Stock poppedStock = stack.pop();
                answer[poppedStock.time] = i - poppedStock.time;
            }
            stack.push(new Stock(i, prices[i]));
        }

        while (!stack.isEmpty()) {
            Stock poppedStock = stack.pop();
            answer[poppedStock.time] = prices.length - 1 - poppedStock.time;
        }

        return answer;
    }

    static class Stock {
        int time;
        int price;

        public Stock(int time, int price) {
            this.time = time;
            this.price = price;
        }
    }
}