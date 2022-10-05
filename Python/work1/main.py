# TASK1
def my_bin(n):
    sign = 1 if n > -1 else -1
    count = 1 if sign == -1 else 0
    n = n if sign == 1 else abs(n) - 1
    while n > 0:
        count += n % 2 if sign == 1 else n % 2 ^ 1
        n //= 2
    return count


# print("7 -> 3", my_bin(7) == 3)  # True
# print("10 -> 2", my_bin(10) == 2)  # True
# print("-123 -> 3", my_bin(-123) == 3)  # True


# TASK2
def my_zip(list1: list, list2: list):
    res = []
    for i in range(min(len(list1), len(list2))):
        res += [(list1[i], list2[i])]
    return res


# print("[1, 2, 3], ['a', 'b'] -> [(1, 'a'), (2, 'b')]", my_zip([1, 2, 3], ['a', 'b']) == [(1, 'a'), (2, 'b')])
# print("[30, 1, 2, 3], ['a', 'b', 'x', 'c'] -> [(30, 'a'), (1, 'b'), (2, 'x'), (3, 'c')]",
#       my_zip([30, 1, 2, 3], ['a', 'b', 'x', 'c']) == [(30, 'a'), (1, 'b'), (2, 'x'), (3, 'c')])


# TASK3
# massive1 | massive2 | massive3
def my_matrix_builder(s: str):
    return list(map(lambda x: list(y for y in map(lambda l: float(l), x.split())), s.split('|')))


print(my_matrix_builder('1 2 | 3 4')[0][1])
