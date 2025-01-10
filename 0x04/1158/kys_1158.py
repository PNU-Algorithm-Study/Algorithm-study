class Empty(Exception):
    pass

class LinkedQueue:
    class _Node:
        __slots__ = '_element', '_next'

        def __init__(self, element, next):
            self._element = element
            self._next = next

    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def first(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        return self._head._element

    def enqueue(self, e):
        newest = self._Node(e, None)
        if self.is_empty():
            self._head = newest
        else:
            self._tail._next = newest
        self._tail = newest
        self._size += 1
        
    def remove_nth(self, n):
        prev = None
        current = self._head
        for _ in range(n):
            prev = current
            current = current._next

        prev._next = current._next
        if current == self._tail:
            self._tail = prev

        self._size -= 1
        return current._element
    
    def __str__(self):
        elements = []
        current = self._head
        while current is not None:
            elements.append(str(current._element))
            current = current._next
        return " ".join(elements)

n,k=map(int,input().split())
queue=LinkedQueue()
for i in range(1,n+1):
    queue.enqueue(i)
queue.remove_nth(2)
print(queue.__str__())