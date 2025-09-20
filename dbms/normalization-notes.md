# Concepts : Normalization and Functional Dependency

### 1. Normalization
- **Definition**: Normalization is the process of organizing a database to eliminate redundancy and data anomalies (insertion, deletion, update) by decomposing tables into smaller, related tables while preserving data integrity.
- **Purpose**: Ensures efficient database design, reduces data redundancy, and prevents anomalies during data operations.
- **Importance**: Critical for maintaining data consistency and optimizing storage, especially in relational databases. It’s a common interview topic due to its role in designing robust databases.
- **Example**: Decomposing a table with student and branch details (`StudentID, Name, BranchCode, BranchName, HOD`) into two tables: `Student (StudentID, Name, BranchCode)` and `Branch (BranchCode, BranchName, HOD)` to avoid redundancy.
- **Connection to Lecture 9**: Builds on SQL table creation (e.g., `CREATE TABLE`) and constraints (e.g., primary/foreign keys) from Lecture 9, as normalization involves restructuring tables created using these commands.

### 2. Data Anomalies
- **Definition**: Problems in non-normalized databases that occur during data operations, leading to inconsistency or inefficiency.
- **Types**:
  - **Insertion Anomaly**: Inability to add data without unnecessary dependencies. Example: Cannot add a branch without a student in a non-normalized table.
  - **Deletion Anomaly**: Deleting a record removes unrelated data. Example: Deleting a student removes branch information (e.g., Mechanical Engineering details).
  - **Update Anomaly**: Changing one piece of data requires updates in multiple places. Example: Updating the Head of Department (HOD) for a department requires changing multiple student records.
- **Solution**: Normalization eliminates these by separating related data into distinct tables.
- **Example**: Splitting a table with `StudentID, BranchCode, BranchName, HOD` into `Student` and `Branch` tables prevents loss of branch data when a student is deleted.
- **Connection to Lecture 9**: Anomalies relate to SQL operations like `INSERT`, `UPDATE`, and `DELETE` (Lecture 9), as normalization ensures these operations don’t cause data issues.

### 3. Functional Dependency
- **Definition**: A relationship where one attribute (or set of attributes) uniquely determines another attribute in a table. Denoted as `X → Y`, where X determines Y.
- **Key Points**:
  - X is the determinant, and Y is the dependent attribute.
  - Example: `EmployeeID → Name` means each EmployeeID uniquely determines a Name.
- **Types**:
  - **Full Functional Dependency**: An attribute depends on the entire composite key, not a subset. Example: `EmployeeID, ProjectID → ProjectName` (ProjectName depends on both).
  - **Partial Dependency**: An attribute depends on only part of a composite key. Example: If `EmployeeID, ProjectID → ProjectName` but `ProjectID → ProjectName`, it’s partial.
  - **Transitive Dependency**: A non-key attribute depends on another non-key attribute via the primary key. Example: `StudentID → Department → HOD` (HOD depends on Department, not directly on StudentID).
- **Example**: In a table with `EmployeeID, Name, Address`, `EmployeeID → Name, Address` is a full dependency, but `Department → HOD` is transitive if Department is not a key.
- **Connection to Lecture 9**: Functional dependencies rely on primary keys and constraints (Lecture 9) to define relationships, which normalization refines.

### 4. Normal Forms
- **Definition**: A series of rules (normal forms) to structure tables to eliminate anomalies and ensure data integrity.
- **First Normal Form (1NF)**:
  - **Requirements**:
    - All attributes are atomic (no multi-valued or repeating groups).
    - Each row is unique (via a primary key).
  - **Example**: Convert a table with `StudentID, Name, PhoneNumbers (123,456)` into `StudentID, Name, PhoneNumber` with separate rows for each phone number (`123` and `456`).
  - **Purpose**: Ensures data is stored in a simple, non-redundant format.
- **Second Normal Form (2NF)**:
  - **Requirements**:
    - Table is in 1NF.
    - No partial dependencies (non-key attributes must depend on the entire primary key).
  - **Example**: For a table with `StudentID, ProjectID, ProjectName`, where `ProjectID → ProjectName` is a partial dependency, split into `StudentProject (StudentID, ProjectID)` and `Project (ProjectID, ProjectName)`.
  - **Purpose**: Removes partial dependencies to reduce redundancy.
- **Third Normal Form (3NF)**:
  - **Requirements**:
    - Table is in 2NF.
    - No transitive dependencies (non-key attributes don’t depend on other non-key attributes).
  - **Example**: For a table with `StudentID, Department, HOD`, where `Department → HOD` is transitive, split into `Student (StudentID, Department)` and `Department (Department, HOD)`.
  - **Purpose**: Eliminates transitive dependencies to avoid update anomalies.
- **Boyce-Codd Normal Form (BCNF)**:
  - **Requirements**:
    - Table is in 3NF.
    - For every functional dependency `X → Y`, X must be a superkey (a set of attributes that uniquely identifies rows).
  - **Example**: In a table with `StudentID, Subject, Professor` where `Professor → Subject` (a professor teaches one subject), decompose into `StudentProfessor (StudentID, Professor)` and `ProfessorSubject (Professor, Subject)` to ensure only superkeys determine attributes.
  - **Purpose**: Strengthens 3NF by ensuring all determinants are superkeys.
- **Connection to Lecture 9**: Normal forms build on table creation and constraints (e.g., primary keys, foreign keys) from Lecture 9, as normalization restructures tables to meet these rules.

### 5. Table Decomposition
- **Definition**: The process of breaking a table into smaller tables to achieve higher normal forms and eliminate anomalies.
- **Process**:
  - Identify functional dependencies.
  - Check for violations of normal forms (partial or transitive dependencies).
  - Split tables to isolate dependencies while preserving data integrity (lossless decomposition).
- **Example**:
  - Non-normalized: `Student (StudentID, Name, BranchCode, BranchName, HOD)`.
  - 1NF: Ensure atomic values (e.g., no multi-valued attributes).
  - 2NF: Split into `Student (StudentID, Name, BranchCode)` and `Branch (BranchCode, BranchName, HOD)` to remove partial dependency (`BranchCode → BranchName, HOD`).
  - 3NF: Ensure no transitive dependencies (already achieved in this case).
- **Stopping Point**: Decompose until the Single Responsibility Principle (SRP) is achieved, where each table handles one entity or relationship, typically up to 3NF or BCNF.
- **Connection to Lecture 9**: Decomposition uses SQL commands like `CREATE TABLE` and `ALTER TABLE` (Lecture 9) to create and modify the resulting tables.

### 6. Single Responsibility Principle (SRP) in Databases
- **Definition**: Each table should represent one entity or relationship, ensuring it has a single purpose to avoid anomalies.
- **Application**: Guides table decomposition to ensure each table handles one type of data (e.g., `Student` for student details, `Branch` for branch details).
- **Example**: A table with `StudentID, Name, BranchCode, BranchName, HOD` violates SRP because it mixes student and branch data. Splitting into `Student` and `Branch` tables adheres to SRP.
- **Connection to Lecture 9**: SRP aligns with creating well-structured tables with clear primary keys and relationships (Lecture 9).

### 7. Practical Examples
- **Student-Branch Example**:
  - **Problem**: A table with `StudentID, Name, BranchCode, BranchName, HOD` has:
    - Insertion anomaly: Can’t add a branch without a student.
    - Deletion anomaly: Deleting a student removes branch data.
    - Update anomaly: Changing HOD requires updating multiple rows.
  - **Solution**: Decompose into `Student (StudentID, Name, BranchCode)` and `Branch (BranchCode, BranchName, HOD)`.
- **Student-Project Example**:
  - **Problem**: A table with `StudentID, ProjectID, ProjectName` has a partial dependency (`ProjectID → ProjectName`).
  - **Solution**: Split into `StudentProject (StudentID, ProjectID)` and `Project (ProjectID, ProjectName)` for 2NF.
- **Student-Professor-Subject Example**:
  - **Problem**: A table with `StudentID, Subject, Professor` where `Professor → Subject` violates BCNF (Professor is not a superkey).
  - **Solution**: Decompose into `StudentProfessor (StudentID, Professor)` and `ProfessorSubject (Professor, Subject)`.
- **Connection to Lecture 9**: These examples rely on SQL joins (Lecture 9) to retrieve data from decomposed tables and constraints to maintain relationships (e.g., foreign keys).

# Questions : Normalization and Functional Dependency

### 1. Introduction to Normalization
- **What is normalization in the context of databases?**
  - **Answer**: Normalization is the process of organizing data in a database to eliminate redundancy and anomalies (insertion, deletion, update) by decomposing tables into smaller, related tables while maintaining data integrity.
  - **Context**: Introduced as a key topic to ensure efficient database design, with a focus on avoiding "free scan entry" (likely insertion anomalies).

- **Why is normalization important?**
  - **Answer**: Normalization prevents data anomalies (insertion, deletion, update issues) that arise from redundant data, ensuring data consistency and efficient storage.
  - **Context**: Highlighted as critical for database design to avoid problems when data is inserted, updated, or deleted.

- **What problems arise if a database is not normalized?**
  - **Answer**: Non-normalized databases face:
    - **Insertion Anomalies**: Difficulty adding new data without incomplete or inconsistent entries (e.g., unable to add a branch without a student).
    - **Deletion Anomalies**: Losing related data when deleting a record (e.g., deleting a student removes branch information).
    - **Update Anomalies**: Needing to update multiple records for a single change (e.g., updating a department’s HOD across multiple rows).
  - **Context**: Explained with examples of student and department data issues.

### 2. Functional Dependency
- **What is functional dependency?**
  - **Answer**: Functional dependency (FD) is a relationship where the value of one attribute (or set of attributes) determines the value of another attribute in a table. Example: If EmployeeID determines Name, then `EmployeeID → Name`.
  - **Context**: Described as a mathematical concept where attributes like EmployeeID uniquely determine others like Name or Department.

- **What are the types of functional dependencies?**
  - **Answer**: 
    - **Full Functional Dependency**: An attribute is fully dependent on a composite key, not a subset of it. Example: `EmployeeID, Name → Address` (Address depends on both).
    - **Partial Dependency**: An attribute depends on only part of a composite key. Example: If `EmployeeID, ProjectID → ProjectName` but `ProjectID → ProjectName`, it’s partial.
    - **Transitive Dependency**: An attribute depends on another non-key attribute, which depends on the key. Example: `StudentID → Department → HOD` (HOD depends on Department, not directly on StudentID).
  - **Context**: Explained with examples like EmployeeID determining Name and Department, and distinguishing between full, partial, and transitive dependencies.

- **How can you determine if a functional dependency exists?**
  - **Answer**: Check if one attribute (or set of attributes) uniquely determines another. Example: If `EmployeeID` always gives the same `Name`, then `EmployeeID → Name`.
  - **Context**: Illustrated with Employee table where ID and Name determine Address.

- **Can a non-key attribute determine another attribute?**
  - **Answer**: Yes, in transitive dependencies, a non-key attribute can determine another (e.g., `Department → HOD`). However, this is undesirable and addressed in higher normal forms like 3NF.
  - **Context**: Discussed when explaining transitive dependencies in the Student-Department example.

- **Can a combination of attributes determine another attribute?**
  - **Answer**: Yes, a set of attributes can determine another if they together uniquely identify it. Example: `EmployeeID, ProjectID → ProjectName`.
  - **Context**: Shown with composite keys determining other attributes.

### 3. Normal Forms
- **What is the First Normal Form (1NF)?**
  - **Answer**: A table is in 1NF if:
    - All attributes are atomic (no repeating groups or multi-valued attributes).
    - Each row is unique (typically via a primary key).
  - **Answer**: Example: Convert a table with multiple phone numbers in one column (e.g., `Phone: 123,456`) into separate rows (e.g., `Phone: 123`, `Phone: 456`).
  - **Context**: Demonstrated with a table having repeated phone numbers being split.

- **What is the Second Normal Form (2NF)?**
  - **Answer**: A table is in 2NF if:
    - It is in 1NF.
    - All non-key attributes are fully functionally dependent on the entire primary key (no partial dependencies).
  - **Answer**: Example: Split a table with `StudentID, ProjectID → ProjectName` where `ProjectID → ProjectName` into two tables: one for Student-Project and one for Project details.
  - **Context**: Explained with a Student-Project table to remove partial dependencies.

- **What is the Third Normal Form (3NF)?**
  - **Answer**: A table is in 3NF if:
    - It is in 2NF.
    - There are no transitive dependencies (non-key attributes don’t depend on other non-key attributes).
  - **Answer**: Example: Split a table with `StudentID → Department → HOD` into two tables: one for Student-Department and one for Department-HOD.
  - **Context**: Shown with a Student-Department example to eliminate transitive dependencies.

- **What is Boyce-Codd Normal Form (BCNF)?**
  - **Answer**: A table is in BCNF if:
    - It is in 3NF.
    - For every functional dependency `X → Y`, X is a superkey (a set of attributes that uniquely identifies rows).
  - **Answer**: Example: In a table with `StudentID, Subject → Professor` and `Professor → Subject`, decompose into `Student-Professor` and `Professor-Subject` tables to ensure only superkeys determine attributes.
  - **Context**: Discussed with a Student-Professor-Subject example to address non-superkey dependencies.

- **How do you decompose a table to achieve normalization?**
  - **Answer**: Break a table into smaller tables to eliminate anomalies while preserving data integrity:
    - For 1NF: Ensure atomic values and a primary key.
    - For 2NF: Remove partial dependencies by creating separate tables for attributes dependent on part of the key.
    - For 3NF: Remove transitive dependencies by isolating non-key dependencies.
    - For BCNF: Ensure all determinants are superkeys.
  - **Answer**: Example: Decompose `Student (ID, Name, BranchCode, BranchName, HOD)` into `Student (ID, Name, BranchCode)` and `Branch (BranchCode, BranchName, HOD)`.
  - **Context**: Illustrated with Student and Branch tables to reduce redundancy.

- **How far should you decompose tables?**
  - **Answer**: Decompose until the Single Responsibility Principle (SRP) is achieved, meaning each table handles one type of entity or relationship, typically up to 3NF or BCNF for practical purposes.
  - **Context**: Mentioned as a guideline to stop decomposition when anomalies are eliminated.

### 4. Practical Examples and Anomalies
- **What is an insertion anomaly, and how does normalization fix it?**
  - **Answer**: An insertion anomaly occurs when you can’t add data without unnecessary dependencies (e.g., unable to add a branch without a student). Normalization splits tables (e.g., Student and Branch) to allow independent insertions.
  - **Context**: Shown with a Student-Branch example where a branch can’t be added without a student in a non-normalized table.

- **What is a deletion anomaly, and how does normalization address it?**
  - **Answer**: A deletion anomaly occurs when deleting a record removes unrelated data (e.g., deleting a student removes branch information). Normalization separates data into related tables (e.g., Student and Branch) to preserve branch data.
  - **Context**: Illustrated with deleting a mechanical engineering student causing loss of branch data.

- **What is an update anomaly, and how does normalization resolve it?**
  - **Answer**: An update anomaly requires updating multiple rows for a single change (e.g., updating HOD for a department in multiple student records). Normalization stores HOD in a separate Branch table, requiring only one update.
  - **Context**: Explained with updating HOD across multiple rows in a non-normalized table.

- **How do you normalize a Student-Project table?**
  - **Answer**: Decompose into:
    - `Student (StudentID, Name, BranchCode)` (1NF, 2NF).
    - `Branch (BranchCode, BranchName, HOD)` (3NF to remove transitive dependency).
    - `StudentProject (StudentID, ProjectID)` and `Project (ProjectID, ProjectName)` (2NF to remove partial dependency).
  - **Context**: Shown with a Student-Project example to eliminate partial and transitive dependencies.

- **How do you normalize a Student-Professor-Subject table?**
  - **Answer**: Decompose into:
    - `Student (StudentID, Name)` (1NF).
    - `Professor (ProfessorID, Name)` (1NF).
    - `Subject (SubjectID, Name)` (1NF).
    - `StudentProfessor (StudentID, ProfessorID)` (to link students and professors).
    - `ProfessorSubject (ProfessorID, SubjectID)` (to link professors and subjects, addressing BCNF issues where Professor determines Subject).
  - **Context**: Discussed with a professor teaching one subject, removing dependencies like `Professor → Subject`.

### 5. Interview and Practical Considerations
- **What are common interview questions about normalization?**
  - **Answer**: Questions focus on:
    - Defining normalization and its purpose.
    - Explaining functional dependencies (full, partial, transitive).
    - Describing normal forms (1NF, 2NF, 3NF, BCNF).
    - Identifying and resolving data anomalies through decomposition.
  - **Context**: Noted as a critical topic for interviews due to its role in database design.

- **Why do partial and transitive dependencies cause problems?**
  - **Answer**: Partial dependencies cause redundancy and anomalies when attributes depend on part of a composite key. Transitive dependencies cause similar issues when non-key attributes depend on other non-key attributes, leading to inefficiencies and data inconsistencies.
  - **Context**: Explained with examples like Student-Project and Student-Department tables.

- **Can a table have no dependencies?**
  - **Answer**: A table with no dependencies is possible but rare, typically when it contains only a primary key or independent attributes. In practice, tables have functional dependencies to model relationships.
  - **Context**: Implied when discussing non-trivial dependencies and their removal.
