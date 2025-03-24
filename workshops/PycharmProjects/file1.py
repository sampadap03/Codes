file=open("file1","r")
cn=0
cc=0
cw=0
cs=0
for line in file:
    cn=cn+1
    cc=cc+len(line)
    cw=cw+len(line.split())
    print(line.split())
print("number of lines:")
print(cn)
print("number of characters:")
print(cc)
print("number of characters excluding new lines and spaces:")
print(cc-cw+1)
print("number of words")
print(cw)
print("number of spaces")
print(cw-cn)
print()