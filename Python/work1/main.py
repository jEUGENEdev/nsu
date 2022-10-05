# TASK1
def my_bin(n):
    sign = 1 if n > -1 else -1
    count = 1 if sign == -1 else 0
    n = n if sign == 1 else abs(n) - 1
    while n > 0:
        count += n % 2 if sign == 1 else n % 2 ^ 1
        n //= 2
    return count


print("7 -> 3", my_bin(7) == 3)  # True
print("10 -> 2", my_bin(10) == 2)  # True
print("-123 -> 3", my_bin(-123) == 3)  # True
