# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes/No

  Yes.

Q: All public functions have been implemented: 7/7

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: ENTER_NUMBER

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: ENTER_NUMBER

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: ENTER_NUMBER

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: ENTER_NUMBER

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: ENTER_NUMBER

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): ENTER_NUMBER

 Each function is commented. 

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: Store.cpp (executeCommand)

invalid movie type: Movie.cpp (createMovie)

invalid customer ID: Store.cpp (executeCommand), HashTable (build)
 
invalid movie: Movie.cpp (createMovie), Store.cpp (executeCommand)

factory classes: Movie.cpp (createMovie), HashTable.cpp (build)

hashtable: HashTable.cpp, Store.customers. HashTable was used for storing customers.

container used for comedy movies: Movies* vector

function for sorting comedy movies: Movies* vector

function where comedy movies are sorted: Movie.cpp (build), Store.cpp (returnEquivelent) Movies* vector

functions called when retrieving a comedy movie based on title and year: Store.cpp (executeCommand, returnEquivelent)

functions called for retrieving and printing customer history: Store.cpp (displayCustomerHistory), Customer.cpp (displayBorrowingHistory)

container used for customer history: Customer.cpp (vector<borrowedMovie*>)

functions called when borrowing a movie: Store.cpp (borrowMovie), Customer.cpp (borrowMovie), Movie.cpp (borrow)

explain borrowing a movie that does not exist: Store.cpp first check it's inventory to see if the file exists. At the point, it will abort before attempting to borrow. 

explain borrowing a movie that has 0 stock: The Store checks inventory, returns true. Then it call's Movie's borrow function, which will return false because there not enough stock. At that pint Store will abort before calling the Customer's borrow function. 

explain returning a movie that customer has not checked out: Store retrieves the Customer, then goes through their borrowing history. If the history does not contain the movie, it prints an error message. 

any static_cast or dynamic_cast used: Yes, for the Movies build and equal method. 


Q: Total points: ADD_ALL_POINTS (max 25)
; 100 / 25