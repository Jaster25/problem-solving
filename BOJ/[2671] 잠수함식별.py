import re


s = input()
if re.fullmatch("((100+1+)|(01))+", s):
    print("SUBMARINE")
else:
    print("NOISE")
