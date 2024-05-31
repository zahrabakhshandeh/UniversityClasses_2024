-- Create the database
CREATE DATABASE library;

-- Use the database
USE library;

-- Create the books table
CREATE TABLE books (
    book_id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255),
    author VARCHAR(255),
    genre VARCHAR(50)
);

-- Create the borrowers table
CREATE TABLE borrowers (
    borrower_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    book_id INT,
    FOREIGN KEY (book_id) REFERENCES books(book_id)
);
