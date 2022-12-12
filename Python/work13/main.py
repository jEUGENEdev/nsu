def cycle(__iterable, a):
    res = [obj for obj in __iterable]
    it = iter(__iterable)
    while (a := a - 1) >= 0:
        try:
            res.append(next(it))
        except StopIteration:
            it = iter(__iterable)
            res.append(next(it))
    return res


print(cycle([1, 2, 3], 10))
