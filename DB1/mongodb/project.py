from pymongo import MongoClient
from datetime import datetime
import json
# pip install pymongo
# limit ====> username
# ------------Setup------------------
def read_data():
    with open("config.json", "r") as config_file:
        config = json.load(config_file)
    return config

config = read_data()
client = MongoClient(config["connection"])
db = client[config["db_name"]]
users = db[config["users_collection"]]
posts = db[config["posts_collection"]]
print("connected")
# ------------User operations---------
def register_user():
    username = input("Enter Username: ")
    email = input("Enter Email: ")
    user = users.find_one({"username": username})
    if user:
        print("Username already exists! choose another")
        return
    user = {
        "username" : username,
        "email": email
    }
    users.insert_one(user)
    print("added!")


def view_users():
    print("_"*10 + "Users" + "_"*10)
    reg_users = users.find({}, {"_id":0})
    #print(reg_users)
    for user in reg_users:
        for k, v in user.items():
            print(f"{k} ----> {v}")
        print()

# ----------Post operations-----------
def create_post():
    username = input("username: ")
    user = users.find_one({"username":username})
    if not user:
        print("user not found!")
        return
    title = input("title: ")
    content = input("content: ")
    post = {
        "author": username,
        "title": title,
        "content": content,
        "date": datetime.now()
    }
    posts.insert_one(post)
    print("added!")

def view_posts():
    print("_"*10 + "POSTS" + "_"*10)
    site_posts = posts.find()
    for post in site_posts:
        for k, v in post.items():
            print(f"{k} ----> {v}")
        print()

def update_post():
    title = input("title: ")
    new_title = input("new title: ")
    new_content = input("new content: ")
    posts.update_one({"title": title}, {"$set": {"title": new_title, "content": new_content}})
    print("updated!")

def delete_post():
    title = input("title: ")
    posts.delete_one({"title": title})
    print("removed!")

def remove_user():
    username = input("username: ")
    post_count = posts.delete_many(
        {"author": username}).deleted_count
    print(f"deleted {post_count} posts")
    users.delete_one({"username": username})
    print("removed!")

# ------------Main----------------
def main_menu():
    while True:
        print("\nBlog Management System")
        print("1. Register user")
        print("2. View users")
        print("3. Create a new post")
        print("4. View all posts")
        print("5. Update a post")
        print("6. Delete a post")
        print("7. Remove User")
        print("8. Exit")
        choice = input("Enter choice: ")

        if choice == '1':
            register_user()
        elif choice == '2':
            view_users()
        elif choice == '3':
            create_post()
        elif choice == '4':
            view_posts()
        elif choice == '5':
            update_post()
        elif choice == '6':
            delete_post()
        elif choice == '7':
            remove_user()
        elif choice == '8':
            break
        else:
            print("Invalid! Please try again.")

if __name__ == "__main__":
    main_menu()