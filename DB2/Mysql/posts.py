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
        self.connection()

    def connection(self):
        self.connect = mysql.connector.connect(
            user=self.user,
            password=self.password,
            host = self.host,
            database = self.database,
        )

    def add_data(self, post):
        #self.connect = self.connection()
        sql = "INSERT INTO posts VALUES (%s, %s, %s, %s)"
        data = (post.id_, post.title, post.content, post.category)
        try:
            mycursor = self.connect.cursor()
            mycursor.execute(sql, data)
        except Exception as e:
            print(e)
        else:
            self.connect.commit()
        finally:
            mycursor.close()
#/home/zahra/Desktop/a.jpg
if __name__ == "__main__":
    obj1 = DB("root","pass","localhost","DBblog")
    post = Posts(1000, "content of new post", "title", "python")
    obj1.add_data(post)