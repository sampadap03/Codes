#error occured in reading website of HTML

getwd()  #gives path of working directory

xyz <- read.csv("goldData.csv", TRUE, ",")
#(name of file, true :if 1st row includes headings of each columns, how the data is seperated from each other)
class(xyz) #data.frame
head(xyz)

#can read any csv file on internet just provide the path in the place of name i.e provide link

#==============read HTML =================================
require(XML)
items <- readHTMLTable("https://www.w3schools.com/html/html_tables.asp", which=1)
#("name/link", which table on website 1st 2nd etc,)
head(items)