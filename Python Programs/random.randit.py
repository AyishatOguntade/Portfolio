import random

def randomTest(seedIn,n,add):
    random.seed(seedIn)
    num = random.randint(0,n)
    add = add + num
    return num,add
