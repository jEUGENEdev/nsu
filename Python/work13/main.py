def cycle(__iterable, a):
    it = iter(__iterable)
    while (a := a - 1) >= 0:
        try:
            yield next(it)
        except StopIteration:
            it = iter(__iterable)
            yield next(it)


print(list(cycle([1, 2, 3], 10)))
