def chain(*__iterable):
    for el in __iterable:
        yield from el


print(list(chain([1, 2, 3], ['Блин', 'сессия', 'скоро'], [42, 13, 7])))
