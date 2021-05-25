from itertools import permutations
numb = input()
if int(numb) < 0:
    print(-1)
    quit()

#sorted list of numbers by permutations
lst = sorted(map(int, map(''.join, list(permutations(numb)))))
 
numb = int(numb)
flag = True

for item in lst:
    if item > numb:
        print(item)
        flag = False
        break

if flag: 
    print(-1)