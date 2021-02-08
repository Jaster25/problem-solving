from collections import deque


def solution(genres, plays):
    answer = []
    playlist = dict()
    genres_total = dict()

    for i, (genre, play) in enumerate(zip(genres, plays)):
        if genre in playlist:
            playlist[genre].append((play, i))
            genres_total[genre] += play
        else:
            playlist[genre] = [(play, i)]
            genres_total[genre] = play

    for pl in playlist:
        playlist[pl] = sorted(list(playlist[pl]), key=lambda x: (-x[0], x[1]))[:2]
    sorted_genres_total = sorted(genres_total.items(), key=lambda x: x[1], reverse=True)

    for genre in sorted_genres_total:
        for i in playlist[genre[0]]:
            answer.append(i[1])

    return answer


if __name__ == "__main__":
    # genresm, plays = ["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]
    genresm, plays = ["classic", "SS", "SS", "SS", "SS", "pop"], [6000, 1, 4, 4, 4, 2500]
    print(solution(genresm, plays))
