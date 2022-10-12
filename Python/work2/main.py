import doctest


def sub_dict(_dict: dict, value):
    """Returns all keys where value = 'value'"""
    res = []
    for entry in _dict.items():
        if entry[1] == value:
            res += [entry[0]]
    return res


def dict_reverse(_dict: dict):
    new_dict = dict()
    for value in _dict.values():
        sub = sub_dict(_dict, value)
        if len(sub) == 1:
            new_dict[value] = sub[0]
        elif len(sub) > 0:
            new_dict[value] = tuple(a for a in sub)
    return new_dict


def _sum(x, y):
    return x + y


def number_system(x, y):
    n = ''
    while x > 0:
        n += str(x % y)
        x //= y
    return n[::-1]


def specialize(func, *args, **kwargs):
    def f(*_args, **_kwargs):
        return func(*args, *_args, **{**kwargs, **_kwargs})
    return f


just_two = specialize(_sum, 1, 1)
plus_one = specialize(_sum, y=1)
system_two = specialize(number_system, y=2)
system_five = specialize(number_system, y=5)
system_nine = specialize(number_system, y=9)


def tests():
    """
    >>> dict_reverse({'Ivanov': 97832, 'Petrov': 55521, 'Kuznecov': 97832})
    {97832: ('Ivanov', 'Kuznecov'), 55521: 'Petrov'}

    >>> dict_reverse({'objectA': 'A', 'objectB': 'B', 'objecta': 'A'})
    {'A': ('objectA', 'objecta'), 'B': 'objectB'}


    >>> just_two()
    2

    >>> plus_one(10)
    11

    >>> system_two(50)
    '110010'

    >>> system_five(112)
    '422'

    >>> system_nine(911)
    '1222'
    """
    pass


doctest.testmod()
