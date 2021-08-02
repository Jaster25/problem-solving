package weekly1;

class Solution {

    public long solution(int price, int money, int count) {

        long totalN = (long) count * (count + 1) / 2;
        long totalPrice = price * totalN;
        long curMoney = money - totalPrice;

        return curMoney < 0 ? -curMoney : 0;
    }
}