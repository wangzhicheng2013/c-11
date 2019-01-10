import sys
file = open("./example0.txt", "w")
for i in range(1000):
    str = "del key" + bytes(i) + "\n"
    file.write(str)
file.close()
