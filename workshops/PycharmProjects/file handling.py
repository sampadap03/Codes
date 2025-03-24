'''file=open("file1","w")
file.write("Hello\nTHis is new line\ngood afternoon")
file.close()
f=open("file1","r")
print(f.read())
print(f.readlines())

for l in f:
    print(l)
'''
#copy contents from two files

'''f2=open("file2","w")
f2.write("This is new file\n")
f2.close()
f3=open("file2","r")
f1=open("file1","a")
f1.write(f3.read())
f1.close()
f3.close()'''

#count words, characters,lines in file
f1=open("file1","r")
cn=0
cw=0
cc=0
for l in f1:
    while
    if (l=='\n'):
        cn=cn+1
        cw=cw+1
    elif():
        cc=cc+1
print(cn, cw, cc)

f1.close()