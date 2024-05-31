import mysql.connector

class Student:
    def __init__(self, student_id, name, email, major):
        self.student_id = student_id
        self.name = name
        self.email = email
        self.major = major

    def __str__(self):
        return f"ID: {self.student_id}, Name: {self.name}, Email: {self.email}, Major: {self.major}"

class Score:
    def __init__(self, score_id, student_id, course, score):
        self.score_id = score_id
        self.student_id = student_id
        self.course = course
        self.score = score

    def __str__(self):
        return f"Score ID: {self.score_id}, Student ID: {self.student_id}, Course: {self.course}, Score: {self.score}"

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

    def add_student(self, student):
        sql = "INSERT INTO students (student_id, name, email, major) VALUES (%s, %s, %s, %s)"
        data = (student.student_id, student.name, student.email, student.major)
        self.execute_query(sql, data)

    def remove_student(self, student_id):
        sql = "DELETE FROM students WHERE student_id=%s"
        data = (student_id,)
        self.execute_query(sql, data)

    def list_students(self):
        sql = "SELECT * FROM students"
        data = self.execute_query(sql, fetch=True)
        return data

    def update_student(self, student_id, value, column):
        sql = f"UPDATE students SET {column}=%s WHERE student_id=%s"
        data = (value, student_id)
        self.execute_query(sql, data)

    def add_score(self, score):
        sql = "INSERT INTO scores (score_id, student_id, course, score) VALUES (%s, %s, %s, %s)"
        data = (score.score_id, score.student_id, score.course, score.score)
        self.execute_query(sql, data)

    def list_scores(self):
        sql = "SELECT * FROM scores"
        data = self.execute_query(sql, fetch=True)
        return data

if __name__ == "__main__":
    db = DB("root", "pass", "localhost", "school")

    # Adding a student
    student = Student(1, "Sara", "sara@example.com", "Computer Science")
    db.add_student(student)

    # Listing all students
    students = db.list_students()
    for student in students:
        print(student)

    # Updating a student
    db.update_student(1, "sara.doe@example.com", "email")

    # Adding a score
    score = Score(1, 1, "Math", 95)
    db.add_score(score)

    # Listing all scores
    scores = db.list_scores()
    for score in scores:
        print(score)
