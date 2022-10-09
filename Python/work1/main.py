# TASK1
def my_bin(n):
    count = n & 1
    n >>= 1
    while n not in [0, -1]:
        count += n & 1
        n >>= 1
    return count + (n & 1)


print("7 -> 3", my_bin(7) == 3)  # True
print("10 -> 2", my_bin(10) == 2)  # True
print("-123 -> 3", my_bin(-123) == 3, my_bin(-123))  # True
print(my_bin(-1))


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
    return list(map(lambda x: [y for y in map(float, x.split())], s.split('|')))

# print(my_matrix_builder('1 2 | 3 4')[0][1])
