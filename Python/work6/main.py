class LRUCache:
    def __init__(self, capacity=16):
        self.timestamps_queue = []
        self.data = {}
        self.capacity = capacity

    def __put(self, key, value):
        if key not in self.data:
            self.timestamps_queue.append(key)
        self.data[key] = value

    def put(self, key, value):
        if len(self.data) + 1 <= self.capacity:
            self.__put(key, value)
        else:
            min_key = self.timestamps_queue.pop(0)
            del self.data[min_key]
            self.__put(key, value)

    def get(self, key):
        index = self.timestamps_queue.index(key)
        if index != -1:
            del self.timestamps_queue[index]
        self.timestamps_queue.append(key)
        # self.timestamps_queue.append(self.timestamps_queue.pop(0))
        return self.data[key]


lru = LRUCache(20)


def f(n):
    lru.put(n, n)
    if n < 2:
        return n
    return f(n - 2) + f(n - 1)


f(10)
