#CPEG476Final: 3 C++ Projects

#1) Markovian Tweets (Ceaser Salad):
The Markovian Tweets project takes a text file and generates a statement in the style of a tweet (< 140 characters) in the style of the written text file provided.  Some text files are provided in the repository but you can easily substitue them for any other text file of your choice.

This is accomplished by using a Markov model to decide sentence order.  It builds a simple first order Markov model, by tracking with what probability certain words follow others in the inputted text.

This project additionally focused largely on correctly dynamically allocating and freeing memory to make sure that memory is not wasted since due to the possibility of a large text file it may be working with a lot of memory.  To accomplish this we used C++'s built in map data structure to build the Markov model.

#2) Minesweeper:
This project creates a command-line minesweeper program that can be run from any linux command line.  

When running the program there are 3 flags that can be sent:

-w or -width: The width of the minesweeper board, this can be any number between 1 and 19.

-h or -height: The height of the minesweeper board, this can be any number between 1 and 19.

-m or -mines: The total number of mines to be randomly placed on the board. This can be any number between 1 and the total number of cells on the board.

This is the traditional minesweeper game with the rules we are all used to.  You keep selecting a square until you have found all cells without mines or you accidentally trip a mine.  The easy to use command line interface allows for easy selection of the square that you wish to select.

Cell Representations:
'-' - Unopened Cell

'1-8' - Opened Cell not containing a mine stating how many of it's neighbors have mines

' ' - Opened Cell not containing a mine with no neighbor mines

'*' - Opened Cell containing a mine

#3) Gee-Mail:
This project creates a local encrypted email platform.

All stored data is stored in gmail.db, no passwords or passphrases are stored in plain text.

The platform comes with the following functionalities:

1) Register a new user

2) Log in as a registered user

3) Send an email to any other registered user

4) Read (assuming you have the proper passphrase) any email sent to your username by another user

This platform uses encryption in the following ways:
1) All passwords are hashed using the SHA-256 hash and stored.  This way even if one were to gain access to that table they would not be able to find passwords.
When a password is entered during login it is also hashed and then the two hashes are compared.

2) All emails are encrypted using a SALSA20 Cypher.  When a user sends an email they enter a passphrase that is 32 characters or less which is to be used in encrypting the email.  When the user to whom the email was sent wants to read it, they must input the same passphrase or else they will not be able to see the message contents.
