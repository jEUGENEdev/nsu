data = {}
def singleton(clazz):
    def inner(*args, **kwargs):
        if clazz.__name__ not in data:
            data[clazz.__name__] = clazz(*args, **kwargs)
        return data[clazz.__name__]

    return inner


@singleton
class UnrealEngine:
    def __init__(self, fps):
        self.fps = fps


a = UnrealEngine(0)
b = UnrealEngine(-1)
c = UnrealEngine(-10)

print(id(b) == id(a) == id(c))