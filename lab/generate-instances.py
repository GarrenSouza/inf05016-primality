import random

k = [10, 20, 40, 80, 160, 320, 640, 1000]
n = 1
numbers = []

random.seed(0xf00d)

for i in range(n):
    for l in range(1, 3001, 1):
        num = ""
        for j in range(l):
            t = random.randint(0,9)
            if j == 0:
                while t == 0:
                    t = random.randint(0,9)
            elif j == (l - 1):
                while t % 2 == 0:
                    t = random.randint(0,9)
            num += str(t)
        print(num)