-- Creating the StudentScores table
CREATE TABLE StudentScores2 (
    StudentID INT,
    StudentName VARCHAR(100),
    Subject VARCHAR(50),
    Score INT, 
    Age INT
);

-- Inserting data into StudentScores
INSERT INTO StudentScores2 (StudentID, StudentName, Subject, Score, Age) VALUES (1, 'n1', 'Math', 88, 19);
INSERT INTO StudentScores2 (StudentID, StudentName, Subject, Score, Age) VALUES (1, 'n1', 'Science', 92, 20);
INSERT INTO StudentScores2 (StudentID, StudentName, Subject, Score, Age) VALUES (2, 'n2', 'Math', 75, 30);
INSERT INTO StudentScores2 (StudentID, StudentName, Subject, Score, Age) VALUES (2, 'n2', 'Science', 55, 23);
INSERT INTO StudentScores2 (StudentID, StudentName, Subject, Score, Age) VALUES (3, 'n3', 'Math', 95, 18);
INSERT INTO StudentScores2 (StudentID, StudentName, Subject, Score, Age) VALUES (3, 'n3', 'Science', 82, 43);

-- Average score per student
SELECT StudentName, AVG(Score) AS AverageScore
FROM StudentScores2
GROUP BY StudentName
ORDER BY AverageScore DESC;

SELECT Subject,AVG(Score) AS AverageScore
FROM StudentScores2
GROUP BY Subject
ORDER BY AverageScore DESC;

-- Number of scores per subject
SELECT Subject, COUNT(*) AS NumberOfScores
FROM StudentScores2
GROUP BY Subject
ORDER BY NumberOfScores DESC;

-- Average score per subject
SELECT Subject, AVG(Score) AS AverageSubjectScore
FROM StudentScores2
GROUP BY Subject
ORDER BY AverageSubjectScore DESC;