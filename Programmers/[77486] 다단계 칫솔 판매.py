class Node:
    def __init__(self):
        self.profit = 0
        self.parent = None

    def connect_parent(self, parent_name):
        self.parent = parent_name

    def gain_profit(self, node, money):
        if money * 0.1 < 1:
            self.profit += money
        else:
            send_money = int(money * 0.1)
            remain_money = money - send_money

            self.profit += remain_money
            if self.parent:
                node[self.parent].gain_profit(node, send_money)
            # else -> center


node = dict()


def solution(enroll, referral, seller, amount):
    answer = []
    global node

    for enroll_name, referral_name in zip(enroll, referral):
        node[enroll_name] = Node()
        if referral_name != "-":
            node[enroll_name].connect_parent(referral_name)

    for name, cnt in zip(seller, amount):
        node[name].gain_profit(node, 100 * cnt)

    for name in enroll:
        answer.append(node[name].profit)

    return answer


if __name__ == "__main__":
    enroll = ["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"]
    referral = ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"]
    seller = ["young", "john", "tod", "emily", "mary"]
    amount = [12, 4, 2, 5, 10]

    print(solution(enroll, referral, seller, amount))
