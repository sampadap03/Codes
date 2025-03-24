mstr <- 'Sampada'
print (mstr)

#ways to assign value to variable
#1) a = 5
#2) a <- 5
#3) assign("a", 5)

#remove a variable: rm(a)

#class/ data type of variable: class(a)
#is.numeric(a): gives TRUE/ FALSE for whether data is numeric or not

nchar("sampada petkar") #returns character's number

dates = as.Date("2019-01-10")
class(dates) #date as data type

arr = 4:10
arr
arr[1:3]  #returns a set of array in given range
all(arr < 6)  #are all members of array are less than 6
any(arr < 6)  # Is any of number of array is less than 6

