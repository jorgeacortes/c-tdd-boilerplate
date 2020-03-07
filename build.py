#!python
# Crossplatform scons build manager
import os,sys

# Commands
cleanCmd = "scons -c"
mockCmd="scons MOCK=yes"
prjCmd="scons"
testsCmd="scons TEST_ONLY=yes"
appCmd='scons APP_ONLY=yes'
logCmd = " > build/log.txt 2>&1"

def clean():
    os.system(cleanCmd)

def buildProject():
    os.system(prjCmd)

def buildApp():
    os.system(appCmd)

def buildMocksAndTests():
    os.system(
        mockCmd
        +testsCmd
    )

def buildMocks():
    os.system(mockCmd)

def buildTests():
    os.system(testsCmd)

if __name__ == '__main__':
    globals()[sys.argv[1]]()
