"""
12. Write a program to calculate sum of n numbers using thread library. 
"""

from threading import Thread

# function to create threads
def callThread(arg):
    sumVal = 0
    for i in range(1, arg+1):
        print("Running")
        sumVal += i
    print(f"Sum is : {sumVal}")


if __name__ == "__main__":
    thread = Thread(target=callThread, args=(10, ))
    thread.start()
    thread.join()
    print("Parent thread")
    print("Thread finished... Exiting")