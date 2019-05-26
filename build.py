#!python
# Crossplatform scons build manager
import os,sys

# Commands
y=" && "
cleanCmd = "scons -c"
mockCmd="scons MOCK=yes"
prjCmd="scons"
testsCmd="scons TEST_ONLY=yes"
logCmd = " > build/log.txt 2>&1"

def rebuildTestsOnly():
    os.system(
        "("+
        cleanCmd+y+
        mockCmd+y+
        testsCmd+")"+
        logCmd
    )

def rebuildProject():
    os.system(
        "("+
        cleanCmd+y+
        mockCmd+y+
        prjCmd+")"+
        logCmd
    )

def updateProject():
    os.system(
        "("+prjCmd+")"+
        logCmd
    )

def updateTests():
    os.system(
        "("+testsCmd+")"+
        logCmd
    )

if __name__ == '__main__':
    globals()[sys.argv[1]]()
