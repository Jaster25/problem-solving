from collections import deque

answer = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

# BFS
def calculatePath(board, startY, startX, goalY, goalX):
    isVisited = [[-1] * 4 for _ in range(4)]
    isVisited[startY][startX] = 0
    queue = deque([[startY, startX]])
    while queue:
        y, x = queue.popleft()
        if y == goalY and x == goalX:
            return isVisited[y][x]

        for i in range(4):
            # 한 칸 이동
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < 4 and 0 <= nx < 4:
                if isVisited[ny][nx] == -1:
                    queue.append([ny, nx])
                    isVisited[ny][nx] = isVisited[y][x] + 1
            # Ctrl 이동
            ny = y
            nx = x
            while True:
                ny += dy[i]
                nx += dx[i]
                if not (0 <= ny < 4 and 0 <= nx < 4):
                    ny -= dy[i]
                    nx -= dx[i]
                    break
                if board[ny][nx] != 0:
                    break
            if isVisited[ny][nx] == -1:
                queue.append([ny, nx])
                isVisited[ny][nx] = isVisited[y][x] + 1
    return -1


def dfs(board, y, x, count, cards):
    if len(list(filter(lambda x: not x.isDeleted, cards))) == 0:
        answer.append(count)
        return

    for card in cards:
        if card.isDeleted:
            continue

        pairCard = card.pair
        path1 = calculatePath(board, y, x, card.y, card.x)
        path2 = calculatePath(board, card.y, card.x, pairCard.y, pairCard.x)
        if path1 == -1 or path2 == -1:
            continue

        cardNumber = board[card.y][card.x]
        board[card.y][card.x] = 0
        board[pairCard.y][pairCard.x] = 0
        card.delete()
        pairCard.delete()

        newCount = count + path1 + path2 + 2  # +2: enter
        dfs(board, pairCard.y, pairCard.x, newCount, cards)

        board[card.y][card.x] = cardNumber
        board[pairCard.y][pairCard.x] = cardNumber
        card.restore()
        pairCard.restore()


def solution(board, r, c):
    cards = []
    for i in range(4):
        for j in range(4):
            if board[i][j] != 0:
                newCard = Card(i, j, board[i][j])
                for card in cards:
                    if card.number == newCard.number:
                        newCard.setPair(card)
                        card.setPair(newCard)
                cards.append(newCard)

    dfs(board, r, c, 0, cards)

    return min(answer)


class Card:
    def __init__(self, y, x, number):
        self.y = y
        self.x = x
        self.number = number
        self.isDeleted = False

    def setPair(self, card):
        self.pair = card

    def delete(self):
        self.isDeleted = True

    def restore(self):
        self.isDeleted = False
