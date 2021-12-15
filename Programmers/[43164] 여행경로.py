from collections import defaultdict


def solution(tickets):
    graph = defaultdict(list)
    for ticket in tickets:
        graph[ticket[0]].append(ticket[1])

    for city in graph.keys():
        graph[city].sort(reverse=True)

    path = []
    stack = ["ICN"]
    while stack:
        current = stack[-1]
        if not graph[current]:
            path.append(stack.pop())
        else:
            stack.append(graph[current].pop())

    return path[::-1]
