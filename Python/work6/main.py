class LRUCache:
    def __init__(self, capacity=16):
        self.timestamps_queue = []
        self.data = dict()
        self.capacity = capacity

    def __put(self, key, value):
        self.data[key] = value
        self.timestamps_queue.append((key, value))

    def put(self, key, value):
        if len(self.data) + 1 <= self.capacity:
            self.__put(key, value)
        else:
            min_key = self.timestamps_queue.pop(0)[0]
            del self.data[min_key]
            self.__put(key, value)

    def get(self, key):
        self.timestamps_queue.append(self.timestamps_queue.pop(0))
        return self.data[key]
