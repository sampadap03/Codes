def a(b):
    b.append([1,2,3])
    print"Value in function: ",b
    return

b=[10,20,30]
a(b)
print"value outside function: ",b

def c(b):
    b.append((1,2,3))
    print"Value in function: ",b
    return

b=[10,20,30]
c(b)
print"value outside function: ",b

def a(b):
    b.append({1,2,3})
    print"Value in function: ",b
    return

b=[10,20,30]
a(b)
print"value outside function: ",br  0217