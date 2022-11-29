"""
3. Write a program to report behaviour of Linux kernel including information on configured memory, amount of free and used memory. (memory information)

"""

import psutil
print(f"Total memory : {psutil.virtual_memory()}")
print(f"Total memory (in GB) : {psutil.virtual_memory().total / (1024.0 ** 3):.3f}")
print(f"Used memory (in GB) : {psutil.virtual_memory().used / (1024.0 ** 3):.3f}")
print(f"Available memory (in GB) : {psutil.virtual_memory().available / (1024.0 ** 3):.3f}")
print(f"Percentage : {psutil.virtual_memory().percent}")