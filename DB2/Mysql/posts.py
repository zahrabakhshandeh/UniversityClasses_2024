import mysql.connector
class Posts:
    def __init__(self, id_, content1, title=None, category=None):
        self.id_ = id_
        self.content = content1
        self.title = title
        self.category = category

    def __str__(self):
        data = f"name:{self.title}, content:{self.content}"
        return data

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
            self.connect = self.connection()
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


if __name__ == "__main__":
    obj1 = DB("root","pass","localhost","DBblog")
    post = Posts(1000, "content of new post", "title", "python")
    obj1.add_data(post)
    #obj1.remove_data(1000)
    print(obj1.list_posts())
    obj1.update_data(1000, "title1000", "content")




