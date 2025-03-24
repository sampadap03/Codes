#print stars in sequential shape
n=int(input("Enter a number="))
for i in range(n+1):
    for j in range(i):
       # print(" ",end=" ")
        print("*",end=" ")
    print()

#print stars in pyramid shape

#n=int(input("Enter a number="))
for i in range(n+1):
    for j in range(n):
        print(" ",end="")
    n=n-1
    for j in range(i):
        print("*",end=" ")

    print()

#printing stars descending order
#n=int(input("Enter a number="))
for i in range(n+1):
    for j in range(n-i):
       # print(" ",end=" ")
        print("*",end=" ")
    print()




