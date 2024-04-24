# DataBase system Documentation

## Overview
Small class project using C++ for a student record managment system.

## System Requirements
- C++ compiler (e.g., g++, clang)
- Standard Template Library (STL)

## Compilation
Compile the source code using a C++ compiler. For example:
```bash
g++ database.cpp -o manager.
```

## Running the Program
Execute the compiled program:
```bash
./manager
```
## Code Structure

1. **Header Inclusion**
    - Standard input/output and string libraries.
    - fstream for file manupilation.

2. **Struct Initialization**
    - A struct datatype having members name, age, gender and batch .

3. **Read Function**
    - Takes alias value n for the length of the array.
    - Asks for the amount of records.  
    - Initializes a dynamic structure array.
    - Opens the file and continue if the file is open
    - Prompts a menu of list of records to enter
    - Then writes the record array in the binary file.
    - Then closes the file

4. **Display Function**
    - Has a const parameter of n to control the for loop inside.
    - Opens the file and continue if the file is open
    - Iterates through the structure array stored in the binary file.
    - Outputs the records in a table form.
    - Then closes the file

5. **Main Function**
    - Initializes an integer value n for size to pass it.
    - Call the functions read and display
    - Pass n as an argument for call and display functions


## Limitations and Possible Improvements
    1. No random record insertion, only sequential 
    2. No way to find out how many records that are stored 
    3. No search function
    4. Has small structure members to explain a record
    5. Less user experience  

## FAQs
**Q**: Can I search a record?
**A**: No, search function in this version.

**Q**: How can we enter a record without overwriting it?
**A**: Current version doesn't have a random entry.

## Future Enhancements
    - There are some features that are not in but inconsideration for the next version
    1. Start inputing records from the position it last stopped 
    2. Store the number of records
    3. An overloaded search function for searching the entery points 
    4. Other structure memebers that fulfill the database 
    5. More best UX implimentation  

