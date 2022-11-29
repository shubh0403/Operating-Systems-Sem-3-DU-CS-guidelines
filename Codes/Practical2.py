"""
2. Write a program to report behaviour of Linux kernel including kernel version, CPU type and model. (CPU information) 
"""

import platform

print(f"Operating System name : {platform.system()}")
print(f"Operating System version : {platform.version()}")
print(f"Operating System release : {platform.release()}")
print(f"Machine type: {platform.machine()}")
print(f"Processor type: {platform.processor()}")