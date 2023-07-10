from random import randrange
import random

num = 100000
print (num, end=' ')
print (num)


for x in range(num):
    print(random.randint(-10000, 10000), end=' ')

print ("")


for x in range(num):
    op = random.randint(1, 2)
    if (op == 1):
        print (1, end=' ')
        val1 = random.randint(0, 99999)
        print (val1, end=' ')
        val2 = random.randint(val1 + 1, 99999)
        print (val2, end=' ')
        val3 = random.randint(-10000, 10000)
        print (val3)
    else:
        print (2, end=' ')
        val1 = random.randint(0, 99999)
        print (val1, end=' ')
        val2 = random.randint(val1 + 1, 99999)
        print (val2)
