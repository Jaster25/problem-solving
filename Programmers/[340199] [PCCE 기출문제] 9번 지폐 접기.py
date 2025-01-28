def solution(wallet, bill):
    cnt = 0
    
    while not is_bill_fittable(wallet, bill):
        cnt += 1
        if bill[0] >= bill[1]:
            bill[0] = bill[0] // 2
        else:
            bill[1] = bill[1] // 2

    return cnt


def is_bill_fittable(wallet, bill):
    if wallet[0] >= bill[0] and wallet[1] >= bill[1]:
        return True
    if wallet[1] >= bill[0] and wallet[0] >= bill[1]:
        return True
    return False