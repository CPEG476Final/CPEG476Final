#CPEG476Final

#This Repository Contains 3 C++ Projects

#1) Markovian Tweets (Ceaser Salad):
The Markovian Tweets project takes a text file and generates a statement in the style of a tweet (< 140 characters) in the style of the written text file provided.  Some text files are provided in the repository but you can easily substitue them for any other text file of your choice.

This is accomplished by using a Markov model to decide sentence order.  It builds a simple first order Markov model, by tracking with what probability certain words follow others in the inputted text.

This project additionally focused largely on correctly dynamically allocating and freeing memory to make sure that memory is not wasted since due to the possibility of a large text file it may be working with a lot of memory.  To accomplish this we used C++'s built in map data structure to build the Markov model.

#2) Minesweeper


#3) Gee-Mail
