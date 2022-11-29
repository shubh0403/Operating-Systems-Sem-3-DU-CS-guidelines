#  5. Write a program to copy files using system calls.

file1 = "file1.txt"
file2 = "file2.txt"
print()
lines=" "
with open(file1,'r',encoding='utf8') as src:
    lines = src.readlines()

with open(file2,'a',encoding='utf8') as dest :
    dest.writelines(lines)

print(f"Content copied from {file1} to {file2}")
print()