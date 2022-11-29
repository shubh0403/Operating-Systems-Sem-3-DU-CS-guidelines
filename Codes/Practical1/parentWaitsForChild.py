# This code won't work on Windows, use online compiler to execute
# c) before terminating, the parent waits for the child to finish its task.

import os
pid = os.fork()
# p > 0 ---> Parent process
if pid > 0:
    print(f"I am parent process. Actual process id : {os.getpid()}  ")
    os.waitpid(-1, 0)
    print("Exiting the parent process")

# p == 0 ---> Child process
elif pid == 0:
    print(f"I am child process. Actual process id : {os.getpid()}")
    print("Exiting the child process")

else:
    print("Forking Error")
    quit()