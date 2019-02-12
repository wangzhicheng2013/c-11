import sys
import os
print os.path.isfile("./check.sh")
print os.path.isdir("/root")
filepath = "./opppp/fool.file"
try:
    file = open(filepath)
    file.close()
except IOError, e:
    print "no such file %s %s" %(filepath, e.strerror)
