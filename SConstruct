#!python
# Scons build system
# Launching a script to be able to build in a variant dir.
import sys
import os
cwd = os.getcwd() # Exporting SCons launch directory

# Default options
#SetOption('silent','yes')

SConscript('project.scons', variant_dir='build', duplicate=0, exports='cwd')
