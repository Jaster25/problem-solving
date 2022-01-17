from collections import defaultdict


class Node:
    def __init__(self):
        self.data = None
        self.children = {}
        self.count = 0


def insert_node(trie, word):
    current_node = trie

    for ch in word:
        current_node.count += 1

        if ch in current_node.children:
            current_node = current_node.children[ch]
        else:
            new_node = Node()
            new_node.data = ch
            current_node.children[ch] = new_node
            current_node = current_node.children[ch]


def count_word(trie, query):
    current_node = trie

    for ch in query:
        if ch == "?":
            break

        if ch in current_node.children:
            current_node = current_node.children[ch]
        else:
            return 0
    return current_node.count


def solution(words, queries):
    trie = defaultdict(Node)
    reversed_trie = defaultdict(Node)

    for word in words:
        word_length = len(word)
        insert_node(trie[word_length], word)
        insert_node(reversed_trie[word_length], word[::-1])

    answer = []
    for query in queries:
        query_length = len(query)
        if query[0] == query[-1] == "?":
            answer.append(trie[query_length].count)
        elif query[-1] == "?":
            answer.append(count_word(trie[query_length], query))
        else:  # query[0] == "?"
            answer.append(count_word(reversed_trie[query_length], query[::-1]))
    return answer


# 시간 초과 풀이------------------------------------
# def check(word, query):
#     if len(word) != len(query):
#         return False

#     counter = Counter(query)
#     wildcard_count = counter["?"]
#     word_length = len(word)

#     if query[0] == "?":
#         for index in range(wildcard_count, word_length):
#             if word[index] != query[index]:
#                 return False
#     else:
#         for index in range(0, word_length - wildcard_count):
#             if word[index] != query[index]:
#                 return False
#     return True


# def solution(words, queries):
#     answer = []
#     for query in queries:
#         count = 0
#         for word in words:
#             if check(word, query):
#                 count += 1
#         answer.append(count)
#     return answer
# ------------------------------------시간 초과 풀이
