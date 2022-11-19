from time import time


class LRUCache:
    def __init__(self, capacity=16):
        self.timestamps = dict()
        self.data = dict()
        self.capacity = capacity

    def __put(self, key, value):
        self.data[key] = value
        self.timestamps[key] = time()

    def __get_key_by_min_value(self):
        mn = ('key', 0)
        for key, value in self.timestamps.items():
            if value < mn[1] or mn[1] == 0:
                mn = key, value
        return mn[0]

    def put(self, key, value):
        if len(self.data) + 1 <= self.capacity:
            self.__put(key, value)
        else:
            min_key = self.__get_key_by_min_value()
            del self.data[min_key]
            del self.timestamps[min_key]
            self.__put(key, value)

    def get(self, key):
        return self.data[key]
