from posts import *
import mysql.connector
import json
class DB:
    def __init__(self, user, password, host, datbase):
        self.user = user
        self.password = password
        self.host = host
        self.database = datbase
        self.connect = None

    def connection(self):
        self.connect = mysql.connector.connect(
            user=self.user,
            password=self.password,
            host = self.host,
            database = self.database,
        )

    def execute_query(self, query, data=None, fetch=False):
        try:
            self.connection()
            print(self.connect)
            mycursor = self.connect.cursor()
            mycursor.execute(query, data)
        except Exception as e:
            print(e)
        else:
            if fetch:
                data = mycursor.fetchall()
                return data
            self.connect.commit()
            print("DONE!")
        finally:
            mycursor.close()
            self.connect.close()

    def add_data(self, post):
        #self.connect = self.connection()
        sql = "INSERT INTO posts VALUES (%s, %s, %s, %s)"
        data = (post.id_, post.title, post.content, post.category)
        self.execute_query(sql, data)

    def remove_data(self, p_id):
        sql = "DELETE FROM posts WHERE p_id=%s"
        data = (p_id,)
        self.execute_query(sql, data)

    def list_posts(self):
        sql = "SELECT * FROM posts"
        data = self.execute_query(sql, fetch=True)
        return data

    def update_data(self, id_p, data_column, column):
        sql = f"UPDATE posts SET {column}=%s WHERE p_id=%s"
        data = (data_column, id_p)
        self.execute_query(sql, data)

    def load_data_from_json(self, filename="posts.json"):
        try:
            with open(filename, "r", encoding='UTF-8') as file:
                data = json.load(file)
        except Exception as e:
            print(e)
            return
        for post in data:
            post = Posts(post.get('id'),post.get('content'),
                post.get('title'),  post.get('category'))
            self.add_data(post)

    def save_data_to_json(self, filename="result.json"):
        data = self.list_posts()
        all_posts = []
        for post in data:
            post = Posts(*post)
            all_posts.append(post.to_dict())  
        with open(filename, "w") as file:
            json.dump(all_posts, file, indent=4)

if __name__ == "__main__":
    obj1 = DB("root","pass","localhost","DBblog")
    post = Posts(1000, "content of new post", "title", "python")
    #obj1.add_data(post)
    obj1.remove_data(1000)
    #print(obj1.list_posts())
    #obj1.update_data(1000, "title1000", "content")
    obj1.load_data_from_json()
    obj1.save_data_to_json()
