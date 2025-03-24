str="Hello world"
print(len(str))
print(str.index("o"))
#print(str[11:0])
#print(str[2:7:2])

#for i in range(11,0,-1):    #to reverse a string
   # print(str[i])
#print(str[12:0:-1])
print(str[::-1])
print(str[11:9:-1])
count =0
for letter in 'Hello World':
    if(letter=='l'):
        count=count+1
print(count,'letter l found')

print(str.count("l"))

a="HEllo"
b="World"
c=a+b
print(c)

d=a*3
print(d)
c=a
print(c==a)

