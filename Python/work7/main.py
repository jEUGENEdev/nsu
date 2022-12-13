import functools

data = {}


def singleton(clazz):
    init_called = False
    old_init = clazz.__init__
    @functools.wraps(clazz.__new__)
    def new(cls, *args, **kwargs):
        if clazz.__name__ not in data:
            data[clazz.__name__] = object.__new__(clazz)
        return data[clazz.__name__]

    @functools.wraps(clazz.__init__)
    def init(self, *args, **kwargs):
        nonlocal init_called
        if not init_called:
            old_init(self, *args, **kwargs)
            init_called = True

    clazz.__new__ = new
    clazz.__init__ = init

    return clazz


@singleton
class UnrealEngine:
    test = 10

    def __init__(self, fps):
        self.fps = fps


print(UnrealEngine.test)
a = UnrealEngine(0)
b = UnrealEngine(-1)
c = UnrealEngine(-10)

print(a.fps)

print(id(b) == id(a) == id(c))
