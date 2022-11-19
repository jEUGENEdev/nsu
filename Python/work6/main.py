from time import time


class LRUCache:
    def __init__(self, capacity=16):
                            # timestamp    , key
        self.best_timestamp = (float('inf'), float('inf'))
        self.data = dict()
        self.capacity = capacity

    def __put(self, key, value):
        self.data[key] = (value, self.best_timestamp)

    def put(self, key, value):
        if len(self.data) + 1 <= self.capacity:
            pass
        else:
            pass

    def get(self, key):
        return self.data[key]
