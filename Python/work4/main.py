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


def deprecated(since=None, will_be_removed=None):
    def inner(f):
        @functools.wraps(f)
        def inner_in_inner(*args, **kwargs):
            if since is not None and will_be_removed is not None:
                print(f"Warning: function {inner_in_inner.__name__} is deprecated since version "
                      f"{since}. It will be removed in version {will_be_removed}")
            elif will_be_removed is not None:
                print(f"Warning: function {inner_in_inner.__name__} is deprecated. It will be "
                      f"removed in version {will_be_removed}")
            elif since is not None:
                print(f"Warning: function {inner_in_inner.__name__} is deprecated since version {since} "
                      f".It will be removed in future versions")
            else:
                print('Warning: function foo is deprecated. It will be removed in future versions.')
            return f(*args, **kwargs)
        return inner_in_inner
    return inner


@deprecated()
def foo():
    print("Hello from foo")


@deprecated(since='1.1.5')
def bar():
    print("Hello from bar")


@deprecated(since='2.8.4', will_be_removed='3.0.0')
def baz():
    print("Hello from baz")


foo()
bar()
baz()
