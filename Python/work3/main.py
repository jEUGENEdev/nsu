def expand_element_list(_list, depth, res, not_all=True):
    if (depth <= 0) and not_all:
        res += _list
        return res
    for el in _list:
        if isinstance(el, list):
            expand_element_list(el, depth - 1, res, not_all)
        else:
            res.append(el)
    return res


def flatten(_list):
    return expand_element_list(_list, 0, [], False)


def flatten1(_list, depth):
    return expand_element_list(_list, depth, [])


print(flatten([1, 2, [4, 5], [6, [7]], 8]))
print(flatten1([1, 2, [[[[[[[[4]]]]]]], 5], [6, [7]], 8], 5))
print(flatten([1, 2, [[[[[[[[4]]]]]]], 5], [6, [7]], 8]))
