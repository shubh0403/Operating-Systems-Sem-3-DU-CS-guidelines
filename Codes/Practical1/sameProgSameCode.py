"""
os.fork() is used to create child process Returns 0 in child process and child's process id in parent process

"""
# This code won't work on Windows, use online compiler to execute
# a) same program, same code. 

import os
pid = os.fork()

if pid < 0:
    print("Fork failed")
    quit()

print(f"p(Returned value of os.fork()) : {pid}")
print(f"Process id : {os.getpid()}")
# If returned value of os.fork() is 0, child process has been executed
# Returned value of os.fork() in parent process will match os.getpid() of child process