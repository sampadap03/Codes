id<- 101: 105
name<- c("sampada", "sudeshna", "aditi", "smruti", "riya")
age<- c(18, 17, 18, 19, 19)

#========================Data Frame====================================================
x = data.frame(id, age, name)
x

nrow(x)
ncol(x)
dim(x)
names(x)[2]
head(x) #shows 1st 6 pieses of info
tail(x) #shows last 6 pieses of info

#access individual columns
x$age
x[2]

x[1,3]  #x[row, column]
x[3, 1:3]

class(x["age"]) #returns data type of data frame
#as data.frame
class(x[,"age"]) #returns a particular vector for class identification

#===============================LIST================================================
sampadasList <- list(23, "sms", c(1:6), "home", x)
sampadasList

#assign names to headings
names(sampadasList) <- c("number", "shortcut", "Vector", "word", "data frame")
sampadasList[["word"]]  #access a particular part

#access dataframe
sampadasList[["data frame"]]$name
length(sampadasList)
sampadasList[["newItem"]] <- c(1.00:10.00)
sampadasList
length(sampadasList)