class Posts:
    def __init__(self, id_, content1, title=None, category=None):
        self.id_ = id_
        self.content = content1
        self.title = title
        self.category = category

    def __str__(self):
        data = f"name:{self.title}, content:{self.content}"
        return data

    def to_dict(self):
        data = {
            "id": self.id_,
            "content": self.content,
            "title": self.title,
            "category": self.category
        }
        return data

if __name__ == "__main__":
    post1 = Posts(1, "content1", "title1", "python")
    print(post1)