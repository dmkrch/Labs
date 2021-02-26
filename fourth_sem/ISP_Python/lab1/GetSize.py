import os
import sys
import time


def convert_bytes(num):
    for size in ['bytes', 'KB', 'MB', 'GB', 'TB']:
        if num < 1024.0:
            return "%3.1f %s" % (num, size)
        num /= 1024.0


def file_size(file_path):
    if os.path.isfile(file_path):
        print("This is file")
        file_info = os.stat(file_path)
        return convert_bytes(file_info.st_size)
    elif os.path.isdir(file_path):
        print("This is directory")
        file_info = os.stat(file_path)
        return convert_bytes(file_info.st_size)



def main():
    if len(sys.argv) > 1:
        file_path = sys.argv[1]
        print("Size = ", file_size(file_path))
    else:
        print("Specify the path to file!")

main()
