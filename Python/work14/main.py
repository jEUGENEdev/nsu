def chain(*__iterable):
    it = iter(__iterable)
    try:
        while 1:
            _it = iter(next(it))
            try:
                while 1: yield next(_it)
            except StopIteration:
                pass
    except StopIteration:
        pass


print(list(chain([1, 2, 3], ['Блин', 'сессия', 'скоро'], [42, 13, 7])))
