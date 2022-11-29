# This code won't work on Windows, use online compiler to execute
# b) same program, different code.

import os
pid = os.fork()
# p > 0 ---> Parent process
if pid > 0:
    print(f"I am parent process. Actual process id : {os.getpid()}  ")
    print("Exiting the parent process")

# p == 0 ---> Child process
elif pid == 0:
    print(f"I am child process. Actual process id : {os.getpid()}")
    newCode = 'a = 10\nb=20\nprint("Sum =", a+b)'
    exec(newCode)

else:
    print("Forking Error")
    quit()