# Algorithm
## before running program
- include libraries
- define files 
- define structures
- protype the function
## Main
- say welcome 
- display main menu

## main menu 
- show options
{
1. display books
2. add books 
3. remove books
4. clear
5. quit
}
-if 1,2,3,4,5 then  display books, add books, remove books, clear, quit
-else say error

## display books
- checkDB
- if there is DB then display books by skipping the first line
- else if there is no DB then createDB
	### createDB
	- make a file named books.txt namely books
	- ask for the capacity of library and add it to the first line
- show the books by skipping the first line that contains capacity

## add books
- open books in append mode
- if checkDB return 1 then append books 
- else createDB then append books
	### append books
	- open books in append mode
	- get the last id from the books.txt
		#### get last id 
		- skip first line that has capacity 
		- iterate upto last line while putting the value for last id( 
		  the last  iteration will give the last id )
		 - return lastid 
	- ask for book name, book author 
	- this books id = lastid + 1 
	- put these information in the file 

## remove book
-open books in read mode 
- open temp file in write mode 
- ask if user want to remove by id or name
- if by name them remove book by name 
- if by id then remove book by id

## remove book by id 
- open books in read mode 
- open temp file in write mode 
- copy capacity of book to temp file
- iterate{
	- check if the id of the book mathches the id specified by the user
	- if not matches, write the book to the temp file 
	- if matches, dont write the book to the temp file
- remove the books.txt 
- rename the temp.txt to books.txt
}
-close books 

## remove by name 
- open books in read mode 
- open temp file in write mode 
- copy capacity of book to temp file
- iterate{
	- check if the name of the book mathches the name specified by the user
	- if not matches, write the book to the temp file 
	- if matches, dont write the book to the temp file
- remove the books.txt 
- rename the temp.txt to books.txt
}
-close books 

## clear
- tell system terminal (bash) to clear the screen 

## quit 
- quit the program
