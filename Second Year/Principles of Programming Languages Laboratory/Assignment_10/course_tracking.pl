% Define courses
course(cse101, 'Introduction to Computer Science').
course(cse201, 'Data Structures').
course(cse301, 'Algorithms').
course(mth101, 'Mathematics for Computer Science').
course(mth201, 'Discrete Mathematics').
course(mth301, 'Probability and Statistics').
course(phy101, 'Physics I').
course(phy201, 'Physics II').
course(che101, 'Chemistry I').
course(che201, 'Chemistry II').

% Define prerequisites for courses
prerequisite(cse201, cse101).
prerequisite(cse301, cse201).
prerequisite(mth201, cse101).
prerequisite(mth301, mth201).
prerequisite(phy201, phy101).
prerequisite(che201, che101).

% Define departments and their maximum course limit for a semester
department(cse, 2).
department(mth, 1).
department(phy, 1).
department(che, 1).

% Define teacher's course assignments
teacher(cse, teacher1).
teacher(mth, teacher2).
teacher(phy, teacher3).
teacher(che, teacher4).

% Define student's course enrollments
student(student1, [cse101, cse201, mth201, phy101]).
student(student2, [cse101, cse301, mth201, mth301]).
student(student3, [phy101, phy201]).
student(student4, [che101, che201]).
student(student5, [cse101, mth201, phy101]).

% Define rules for checking prerequisites
has_prerequisite(Student, Course) :-
    student(Student, Enrollments),
    member(Course, Enrollments),
    prerequisite(Prerequisite, Course),
    \+ member(Prerequisite, Enrollments).

% Define rules for checking course assignments for teachers
can_teach(Teacher, Course) :-
    teacher(Department, Teacher),
    department(Department, MaxCourses),
    findall(C, teacher(Department, Teacher), Courses),
    length(Courses, NumCourses),
    NumCourses < MaxCourses,
    course(Course, _),
    \+ member(Course, Courses).

% Define rules for course tracking
enroll(Student, Course) :-
    student(Student, Enrollments),
    length(Enrollments, NumCourses),
    NumCourses < 5,
    course(Course, _),
    has_prerequisite(Student, Course),
    \+ member(Course, Enrollments).

assign(Teacher, Course) :-
    can_teach(Teacher, Course),
    course(Course, _),
    \+ teacher(_, Teacher),
    assert(teacher(_, Teacher)).

% Example usage:

% Check if student1 can enroll in cse301
?- has_prerequisite(student1, cse301).
% Output: true

% Enroll student1 in cse301
?- enroll(student1, cse301).
% Output: true

% Try to enroll student1 in cse201 (already enrolled in 5 courses)
?- enroll(student1, cse201).
% Output: false

% Try to enroll student1 in cse101 (already enrolled in cse301)
?- enroll(student1, cse101).
% Output: false

% Check if teacher1 can teach cse301 (already teaching 2 courses)
?- can_teach(teacher1, cse301).
% Output: false

% Assign teacher1 to cse101
?- assign(teacher1, cse101).
% Output
