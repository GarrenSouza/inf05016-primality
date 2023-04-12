import random

k = [10, 20, 40, 80, 160, 320, 640, 1280, 2560]
n = 20
numbers = []

random.seed(0xf00d)

for i in range(n):
    for l in k:
        num = ""
        for j in range(l):
            t = random.randint(0,9)
            if j == 0:
                while t == 0:
                    t = random.randint(0,9)
            num += str(t)
        print(num)