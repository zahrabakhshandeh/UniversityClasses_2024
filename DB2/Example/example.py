from pymongo import MongoClient
import json

# ------------Setup------------------
def read_data():
    with open("config.json", "r") as config_file:
        config = json.load(config_file)
    return config

config = read_data()
client = MongoClient(config["connection"])
db = client[config["db_name"]]
books = db[config["books_collection"]]
borrowers = db[config["borrowers_collection"]]
print("Connected to MongoDB")

# ------------Book operations---------
def add_book():
    title = input("Enter Book Title: ")
    author = input("Enter Author: ")
    genre = input("Enter Genre: ")
    book = {
        "title": title,
        "author": author,
        "genre": genre
    }
    books.insert_one(book)
    print("Book added!")

def view_books():
    print("_" * 10 + " Books " + "_" * 10)
    for book in books.find():
        print(book)

# ----------Borrower operations-----------
def add_borrower():
    name = input("Enter Borrower Name: ")
    email = input("Enter Borrower Email: ")
    book_title = input("Enter Book Title to Borrow: ")
    book = books.find_one({"title": book_title})
    if not book:
        print("Book not found!")
        return
    borrower = {
        "name": name,
        "email": email,
        "book_id": book["_id"]
    }
    borrowers.insert_one(borrower)
    print("Borrower added!")

def view_borrowers():
    print("_" * 10 + " Borrowers " + "_" * 10)
    for borrower in borrowers.find():
        print(borrower)

# ------------Main----------------
def main_menu():
    while True:
        print("\nLibrary Management System")
        print("1. Add book")
        print("2. View books")
        print("3. Add borrower")
        print("4. View borrowers")
        print("5. Exit")
        choice = input("Enter choice: ")

        if choice == '1':
            add_book()
        elif choice == '2':
            view_books()
        elif choice == '3':
            add_borrower()
        elif choice == '4':
            view_borrowers()
        elif choice == '5':
            break
        else:
            print("Invalid! Please try again.")

if __name__ == "__main__":
    main_menu()
