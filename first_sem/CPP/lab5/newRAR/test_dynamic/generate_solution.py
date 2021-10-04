import time, os, sys, re
import subprocess

if not os.path.exists('build'):
    os.mkdir('build')
os.chdir('build')

visual_studio_proccess = subprocess.Popen('cmake -G "Visual Studio 16 2019" -a Win64 ..')
visual_studio_proccess.wait()
