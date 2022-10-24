def expand_element_list(_list, cur_depth, depth, save: list):
    if cur_depth >= depth:
        return _list
    cur_list = []
    for el in _list:
        if isinstance(el, list):
            cur_list += [a for a in el]
            save += cur_list
        else:
            cur_list += [el]
    expand_element_list(cur_list, cur_depth + 1, depth, save)


def expand_list(_list, depth):
    epn_list = []
    a = []
    for el in _list:
        if isinstance(el, list):
            epn_list += [expand_element_list(el, 1, depth, a)]
        else:
            epn_list += [el]
    return a


print(expand_list([1, 2, [4, 5], [6, [7]], 8], 10))
