# Student-Record-Management-System
It is a Student Management System written in C++. By help of fstream class header file in C++.
Created a ID.txt file for handling ID values(Primary key). Help in getting to know about last student Id entered.

It is having functionalities:
# AddStudent() details
Used encapsulation concepts from oops and storing the value by user into object's member variable. (Data member variables + member functions)

# PrintallStudents() details
Navigating through a file.
Reading Student details from file using output file stream object(ofstream object).
printing those details one by one on the screen using cout. until we reach End Of File(eof()).

# Search a particular student detail by help of id(Primary key)
Id acts as a primary key here.
Based on given id we can navigate and read particular Student details from file using input file stream(ifstream object).

# Delete a particular student details by his/her id
I used a temporary file to maintain a file detail.

# Update a particular student details on basis of Id(Primary Key)
This uses functionality of both Delete() and then Add() data for a particular student based on that student id.
