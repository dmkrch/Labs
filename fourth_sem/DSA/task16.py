import itertools
 
def solveTask(num):
    arr = list(map(int, str(num)))
    arr_list = list(itertools.permutations(arr))
    arr_list.sort()
    
    for lst in arr_list:
        test = int("".join(map(str, lst)))
        if test > num:
            return test
    return -1

x = int(input())

if x < 10:
    print(-1)
else:
    print(solveTask(x))