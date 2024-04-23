import mysql.connector
import json
# blog ===> post ===> id, title, content, category
# add, edit, list
# connection, add, edit, list
def connection(user, password, host, database):
    mydb = mysql.connector.connect(
        user = user,
        password = password,
        host = host,
        database = database
    )
    return mydb

def execute_query(sql, data=None, fetch=False):
    try:
        mydb = connection("root", "pass", "localhost", "DBblog2")
        mycursor = mydb.cursor()
        mycursor.execute(sql, data)
    except Exception as e:
        print(e)
        return None
    else:
        if fetch:
            data = mycursor.fetchall()
            return data
        mydb.commit()
        print("Done!")
    finally:
        mydb.close()
        mycursor.close()

def add(id_, content, title=None, category=None):
    sql = "INSERT INTO posts VALUES(%s, %s, %s, %s)"
    data = (id_, title, content, category)
    execute_query(sql, data)

def list(table_name):
    sql = f"SELECT * FROM {table_name}"
    data = execute_query(sql=sql, fetch=True)
    return data

def edit(id_, new_title):
    sql = "UPDATE posts SET title=%s WHERE id=%s"
    data = (new_title, id_)
    execute_query(sql, data)

def remove(id_):
    sql = "DELETE FROM posts WHERE id=%s"
    data = (id_,)
    execute_query(sql, data)

def show_data(data):
    for id_, title, content, category in data:
        print(f"{id_}: {title} - {content} - {category}")

def load_json(filename="posts.json"):
    with open(filename, "r") as file:
        data = json.load(file)
    for post in data:
        add(id_=post.get("id"), title=post.get("title"),
            content=post.get("content"), category=post.get("category"))

def to_dict(post):
    data = {
        "id":post[0],
        "content":post[2],
        "title":post[1],
        "category":post[3]
    }
    return data

def save_to_json(filename="result.json"):
    data = list("posts")
    all_posts = []
    for post in data:
        post = to_dict(post)
        all_posts.append(post)
    with open(filename, "w") as file:
        json.dump(all_posts, file, indent=4)

save_to_json()
"""while True:
    cmd = input("add, edit, remove, list, exit: ")
    if cmd == "add":
        id_ = int(input("id: "))
        content = input("content: ")
        title = input("title: ") 
        category = input("category: ")
        title = title or None
        category = category or None
        add(id_, content, title, category)"""