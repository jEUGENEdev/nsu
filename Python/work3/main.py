def expand_element_list(_list, cur_depth, depth, res, not_all=True):
    if (cur_depth >= depth) and not_all:
        res += _list
        return res
    for el in _list:
        if isinstance(el, list):
            expand_element_list(el, cur_depth + 1, depth, res, not_all)
        else:
            res.append(el)
    return res


def flatten(_list):
    return expand_element_list(_list, 0, 0, [], False)

# And where is polymorphism?


def flatten1(_list, depth):
    return expand_element_list(_list, 1, depth, [])


print(flatten([1, 2, [4, 5], [6, [7]], 8]))
print(flatten1([1, 2, [[[[[[[[4]]]]]]], 5], [6, [7]], 8], 5))
print(flatten([1, 2, [[[[[[[[4]]]]]]], 5], [6, [7]], 8]))
