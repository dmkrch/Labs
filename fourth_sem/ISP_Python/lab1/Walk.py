#!/usr/bin/python
import os
import sys

for dirpath, dirnames, filenames in os.walk(sys.argv[1]):
    print("Current Path: ", dirpath)
    print("Directories: ", dirnames)
    print("Files: ", filenames)
    print()