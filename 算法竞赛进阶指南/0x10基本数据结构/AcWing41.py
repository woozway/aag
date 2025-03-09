class MinStack(object):

    def __init__(self):
        self.a, self.b = [], []

    def push(self, x):
        self.a.append(x)
        self.b.append(x) if not self.b else self.b.append(min(self.b[-1], x))

    def pop(self):
        self.a.pop()
        self.b.pop()

    def top(self):
        return self.a[-1]

    def getMin(self):
        return self.b[-1]