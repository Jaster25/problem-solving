def solution(files):
    splited_files = []
    for file in files:
        idx_num, idx_tail = len(file), len(file)
        for i, ch in enumerate(file):
            if ch.isdigit() and i < idx_num:
                idx_num = i
            if i > idx_num and not ch.isdigit():
                idx_tail = i
                break
        splited_files.append(
            [file[:idx_num], file[idx_num:idx_tail], file[idx_tail:]])

    splited_files.sort(key=lambda x: (x[0].upper(), int(x[1])))

    return list(map(lambda x: x[0]+x[1]+x[2], splited_files))


if __name__ == "__main__":
    # files = ["img12.png", "img10.png", "img02.png",
    #          "img1.png", "IMG01.GIF", "img2.JPG"]
    files = ["F-5 Freedom Fighter", "B-50 Superfortress",
             "A-10 Thunderbolt II", "F-14 Tomcat"]
    # files = ["foo9.txt", "foo010bar020.zip", "F-15"]
    print(solution(files))
