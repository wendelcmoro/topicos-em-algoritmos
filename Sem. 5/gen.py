from random import randrange
import random
import string
string.ascii_letters
'AB'

num = 100000
print (num, end=' ')
print(randrange(10))

nums = random.sample(range(1, 100000 + 1), 100000)

for x in range(len(nums)):
    print(nums[x], end=' ')