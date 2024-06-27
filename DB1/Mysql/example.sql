-- Creating tables
CREATE TABLE Students (
    StudentID INT,
    StudentName VARCHAR(255),
    PRIMARY KEY (StudentID)
);

CREATE TABLE Courses (
    CourseID INT,
    CourseName VARCHAR(255),
    PRIMARY KEY (CourseID)
);

CREATE TABLE Enrollments (
    StudentID INT,
    CourseID INT,
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);

-- Inserting data into Students
INSERT INTO Students (StudentID, StudentName) VALUES (1, 'STUDENT1');
INSERT INTO Students (StudentID, StudentName) VALUES (2, 'STUDENT2');
INSERT INTO Students (StudentID, StudentName) VALUES (3, 'STUDENT3');

-- Inserting data into Courses
INSERT INTO Courses (CourseID, CourseName) VALUES (101, 'COURSE1');
INSERT INTO Courses (CourseID, CourseName) VALUES (102, 'COURSE2');
INSERT INTO Courses (CourseID, CourseName) VALUES (103, 'COURSE3');

-- Inserting data into Enrollments
INSERT INTO Enrollments (StudentID, CourseID) VALUES (1, 101);
INSERT INTO Enrollments (StudentID, CourseID) VALUES (1, 102);
INSERT INTO Enrollments (StudentID, CourseID) VALUES (2, 101);


SELECT *
FROM Students
INNER JOIN Enrollments ON Students.StudentID = Enrollments.StudentID;

SELECT StudentID
FROM Courses
INNER JOIN Enrollments ON Courses.CourseID = Enrollments.CourseID

-- INNER JOIN Query
SELECT 'INNER JOIN' AS JoinType, Students.StudentName, Courses.CourseName
FROM Enrollments
INNER JOIN Students ON Enrollments.StudentID = Students.StudentID
INNER JOIN Courses ON Enrollments.CourseID = Courses.CourseID

UNION ALL

-- LEFT JOIN Query
SELECT 'LEFT JOIN' AS JoinType, Students.StudentName, Courses.CourseName
FROM Students
LEFT JOIN Enrollments ON Students.StudentID = Enrollments.StudentID
LEFT JOIN Courses ON Enrollments.CourseID = Courses.CourseID

UNION ALL

-- RIGHT JOIN Query
SELECT 'RIGHT JOIN' AS JoinType, Students.StudentName, Courses.CourseName
FROM Courses
RIGHT JOIN Enrollments ON Courses.CourseID = Enrollments.CourseID
RIGHT JOIN Students ON Enrollments.StudentID = Students.StudentID

UNION ALL

-- Simulated FULL OUTER JOIN Query
SELECT 'FULL OUTER JOIN' AS JoinType, Students.StudentName, Courses.CourseName
FROM Students
LEFT JOIN Enrollments ON Students.StudentID = Enrollments.StudentID
LEFT JOIN Courses ON Enrollments.CourseID = Courses.CourseID
UNION
SELECT 'FULL OUTER JOIN' AS JoinType, Students.StudentName, Courses.CourseName
FROM Courses
LEFT JOIN Enrollments ON Courses.CourseID = Enrollments.CourseID
LEFT JOIN Students ON Enrollments.StudentID = Students.StudentID;

--Order-By
SELECT StudentID, StudentName
FROM Students
ORDER BY StudentName ASC;

SELECT StudentID, StudentName
FROM Students
ORDER BY StudentName DESC;

SELECT *
FROM Students
ORDER BY StudentName ASC, StudentID DESC;

