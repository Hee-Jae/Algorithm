import random
# print(random.randrange(1,100))
w = open("sample.txt","w")
for _ in range(0,5000000):
    a = str(random.randrange(1,100)) + " "
    w.write(a)

w.close()