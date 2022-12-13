def cycle(__iterable):
    while True:
        yield from __iterable


def take(__iterable, a):
    it = iter(__iterable)
    while (a := a - 1) >= 0:
        try:
            yield next(it)
        except StopIteration:
            it = iter(__iterable)


print(list(take(cycle([1, 2, 3]), 10)))
