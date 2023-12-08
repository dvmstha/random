# Algorithm

## before running the function
- include libraries of string ctypes stdio stdlib
- include qna.txt which contains question,4 options,corresponding_correct_answer_no
- define functions tolower
	### toLowercase *str(call by reference)
	- initialize i = 0
	- iterate over the string 
		- lower the character

## get_no_of_question
- open qna
- init i = 0
- while seeing question, 4 options, and the correct answer increase i
- print no of question
- return no of question

# MAIN FUCTION

- init score = 0, noofq = get_no_of_questions
- open qna 
- loop init i = 0 upto less than no of questions with increment of one question
	- see i th line of qna
	- print questions then options
	- take user input as answer
	- if answer == correct option increase score
	- else go to next question
- float percentage = score/noofq * 100
- if percentage == 100 >> perfect score
- else if >= 80 >> excellent score out of noofq
- else if >= 60 >> good score out of noofq
- else if >= 40 >> satisfactory score out of noofq
- else if < 40 >> failed score out of noofq
- else >> something went wrong
- return 0