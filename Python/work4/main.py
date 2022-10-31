import functools
import time

# WORKOUT


def speed(f):
    def inner(*args, **kwargs):
        start = time.time_ns()
        ret = f(*args, **kwargs)
        print(f'The function was completed in some {time.time_ns() - start} ns')
        return ret
    return inner


@speed
def _sum(*args):
    time.sleep(1)
    return sum(args)


# print(_sum(5, 5, 5, 5))


# TUOKROW


def deprecated(f=None, since=None, will_be_removed=None):
    if f is None:
        return functools.partial(deprecated, since=since, will_be_removed=will_be_removed)

    def inner(*args, **kwargs):
        war = f'Warning: function {f.__name__} is deprecated' + (f' since version {since}' if since else '') + '. '
        war += f'It will be removed in ' + (f'version {will_be_removed}' if will_be_removed else 'future versions') + \
               '.'
        print(war)
        return f(*args, **kwargs)
    return inner


@deprecated
def foo():
    print("Hello from foo")


foo()


@deprecated(since='1.1.5')
def bar():
    print("Hello from bar")


bar()


@deprecated(since='2.8.4', will_be_removed='3.0.0')
def baz():
    print("Hello from baz")


baz()
