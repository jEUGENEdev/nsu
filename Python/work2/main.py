import doctest


def tests():
    """
    >>> dict_reverse({'Ivanov': 97832, 'Petrov': 55521, 'Kuznecov': 97832})
    {97832: ('Ivanov', 'Kuznecov'), 55521: 'Petrov'}

    >>> dict_reverse({'objectA': 'A', 'objectB': 'B', 'objecta': 'A'})
    {'A': ('objectA', 'objecta'), 'B': 'objectB'}
    """
    pass


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


doctest.testmod()
