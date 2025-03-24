getwd()
goldData <- read.csv("goldData.csv", TRUE, ",")
head(goldData)
goldData
#hist(goldData$vol., main-"volume traded og GOLD", ylab="users", xlab="volumes")
class(goldData$Open)

#=====================Histogram==================================
#Histogram: a diagram consisting of rectangles whose area is proportional to the frequency
#of a variable and whose width is equal to the class interval.

goldData$Open = as.numeric(goldData$Open)
is.numeric(goldData$Open)
goldData$Open

hist(goldData$Open, main="volume traded of GOLD", ylab="users", xlab="volumes")




