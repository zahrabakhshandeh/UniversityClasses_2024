import mysql.connector
import json

class Book:
    def __init__(self, book_id, title, author, genre):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.genre = genre

    def __str__(self):
        return f"ID: {self.book_id}, Title: {self.title}, Author: {self.author}, Genre: {self.genre}"

class Borrower:
    def __init__(self, borrower_id, name, email, book_id):
        self.borrower_id = borrower_id
        self.name = name
        self.email = email
        self.book_id = book_id

    def __str__(self):
        return f"Borrower ID: {self.borrower_id}, Name: {self.name}, Email: {self.email}, Book ID: {self.book_id}"

class DB:
    def __init__(self, user, password, host, database):
        self.user = user
        self.password = password
        self.host = host
        self.database = database
        self.connect = None

    def connection(self):
        self.connect = mysql.connector.connect(
            user=self.user,
            password=self.password,
            host=self.host,
            database=self.database,
        )

    def execute_query(self, query, data=None, fetch=False):
        self.connection()
        try:
            mycursor = self.connect.cursor()
            mycursor.execute(query, data)
            if fetch:
                result = mycursor.fetchall()
                return result
            self.connect.commit()
            print("DONE!")
        except Exception as e:
            print(e)
        finally:
            mycursor.close()
            self.connect.close()

    def add_book(self, book):
        sql = "INSERT INTO books (book_id, title, author, genre) VALUES (%s, %s, %s, %s)"
        data = (book.book_id, book.title, book.author, book.genre)
        self.execute_query(sql, data)

    def remove_book(self, book_id):
        sql = "DELETE FROM books WHERE book_id=%s"
        data = (book_id,)
        self.execute_query(sql, data)

    def list_books(self):
        sql = "SELECT * FROM books"
        data = self.execute_query(sql, fetch=True)
        return data

    def update_book(self, book_id, value, column):
        sql = f"UPDATE books SET {column}=%s WHERE book_id=%s"
        data = (value, book_id)
        self.execute_query(sql, data)

    def add_borrower(self, borrower):
        sql = "INSERT INTO borrowers (borrower_id, name, email, book_id) VALUES (%s, %s, %s, %s)"
        data = (borrower.borrower_id, borrower.name, borrower.email, borrower.book_id)
        self.execute_query(sql, data)

    def list_borrowers(self):
        sql = "SELECT * FROM borrowers"
        data = self.execute_query(sql, fetch=True)
        return data

    def save_to_json(self, data, filename):
        with open(filename, 'w') as json_file:
            json.dump(data, json_file, indent=4)
        print(f"Data saved to {filename}")

if __name__ == "__main__":
    db = DB("root", "pass", "localhost", "library")

    # Adding a book
    book = Book(1, "book1", "A. B", "Fiction")
    db.add_book(book)

    # Listing all books and saving to JSON
    books = db.list_books()
    db.save_to_json(books, "books.json")

    # Updating a book
    db.update_book(1, "book1 Updated", "title")

    # Adding a borrower
    borrower = Borrower(1, "Sara", "sara@example.com", 1)
    db.add_borrower(borrower)

    # Listing all borrowers and saving to JSON
    borrowers = db.list_borrowers()
    db.save_to_json(borrowers, "borrowers.json")
