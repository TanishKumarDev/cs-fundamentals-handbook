## Lecture 15: NoSQL Databases - Key Concepts

### 1. Introduction to NoSQL
- **Definition**: NoSQL (Not Only SQL) databases are non-relational systems designed to store and manage unstructured, semi-structured, or structured data without a fixed schema.
- **Purpose**: Handles large volumes of flexible data (e.g., social media posts, emails) that don't fit rigid relational schemas, enabling horizontal scaling and faster operations.
- **Key Characteristics**:
  - Flexible schema: Attributes can vary per record (e.g., one student has "branch," another doesn't).
  - Supports unstructured/semi-structured data: Text, JSON, images, etc., unlike relational's structured tables.
- **Example**: Storing student data with varying fields (e.g., some with "branch," others without) in a document format.
- **Connection to Previous Lectures**:
  - **Lecture 9**: NoSQL complements SQL for flexible queries, avoiding rigid `SELECT` on fixed schemas.
  - **Lecture 11**: Addresses limitations of normalization (rigid schemas) for unstructured data.

### 2. Structured vs. Unstructured/Semi-Structured Data
- **Structured Data**: Fixed schema with predefined attributes (e.g., relational table: StudentID, Name, RollNumber).
- **Unstructured Data**: No fixed format (e.g., emails, videos, text files).
- **Semi-Structured Data**: Partial schema (e.g., JSON with optional fields like "branch" or "address").
- **Why NoSQL?**: Relational databases struggle with unstructured/semi-structured data due to schema rigidity; NoSQL allows dynamic fields.
- **Example**: Student data: Structured (fixed columns in SQL table); Semi-structured (JSON: `{ "Name": "Rohit", "Branch": "IT" }` – optional "Branch").
- **Connection to Lecture 11**: Normalization enforces structure; NoSQL avoids it for flexibility.

### 3. Advantages of NoSQL
- **Flexible Schema**: Add/remove fields dynamically without altering the entire database (e.g., add "branch" to some records only).
- **Horizontal Scalability**: Easily distribute data across multiple servers (e.g., add nodes for growing data).
- **High Performance for Large Data**: Handles massive volumes (e.g., social media posts) with fast reads/writes.
- **Example**: In a student app, add "profile picture" to one record without affecting others.
- **Connection to Lecture 13**: NoSQL benefits from indexing for fast access in large, flexible datasets.

### 4. Disadvantages of NoSQL
- **Lack of ACID Properties**: Limited support for full atomicity, consistency, isolation, durability (e.g., no strong transactions like in SQL).
- **No Joins**: Data is denormalized (duplicated across documents), requiring application-level joins (e.g., fetch related data in code).
- **Complexity in Queries**: Lacks SQL's powerful querying; uses custom languages.
- **Example**: Updating a student's branch requires updating multiple documents; no built-in join for related data.
- **Connection to Lecture 12**: Contrasts with ACID in relational transactions; NoSQL uses eventual consistency.

### 5. Types of NoSQL Databases
- **Document Stores** (e.g., MongoDB):
  - Stores data as documents (e.g., JSON/BSON) with flexible fields.
  - **Example**: Student record: `{ "ID": 1, "Name": "Rohit", "Branch": "IT" }` – query by any field.
- **Key-Value Stores** (e.g., Redis):
  - Simple pairs (key: value) for fast lookups.
  - **Example**: `UserID: { "Name": "Rohit", "Email": "rohit@email.com" }`.
- **Column-Family Stores** (e.g., Cassandra):
  - Stores data in columns, efficient for wide tables.
  - **Example**: Student table with dynamic columns (e.g., add "Grades" per student).
- **Graph Databases** (e.g., Neo4j):
  - Stores nodes (entities) and edges (relationships) for connected data.
  - **Example**: Student → Studies → Subject → Taught by → Professor.
- **Connection to Lecture 11**: Document stores avoid normalization for flexibility; graph stores handle relationships without joins.

### 6. NoSQL vs. Relational Databases (SQL)
- **Schema**: NoSQL (flexible, schema-less); SQL (fixed schema).
- **Data Types**: NoSQL (unstructured/semi-structured); SQL (structured).
- **Scalability**: NoSQL (horizontal, easy scaling); SQL (vertical, harder for massive data).
- **Joins/Queries**: NoSQL (no joins, denormalized); SQL (joins via `JOIN`, normalized).
- **ACID Support**: NoSQL (limited, eventual consistency); SQL (full ACID).
- **Use Cases**: NoSQL (social media, big data); SQL (banking, transactions).
- **Example**: SQL table requires fixed columns for students; NoSQL document allows varying fields.
- **Connection to Lecture 9**: SQL uses `JOIN` for relations; NoSQL embeds data to avoid it.
- **Connection to Lecture 12**: NoSQL lacks full ACID, unlike SQL transactions.

### 7. Using NoSQL (Implementation)
- **Schema Design**: Define flexible models (e.g., JSON documents) in code (e.g., JavaScript class for Student).
- **Operations**: Insert/update data dynamically (e.g., add "branch" to one document).
- **Example**: In MongoDB, insert: `db.students.insert({ "Name": "Rohit", "Branch": "IT" })` – query: `db.students.find({ "Branch": "IT" })`.
- **Connection to Lecture 9**: NoSQL uses query languages (e.g., MongoDB queries) similar to SQL but schema-flexible.

### 8. Practical Examples
- **Student Data in NoSQL**:
  - Document: `{ "ID": 1, "Name": "Rohit", "Branch": "IT", "Address": "Noida" }` – add "Grades" later without schema change.
  - Query: Fetch by "Branch" without joins.
- **Social Media (e.g., Facebook)**:
  - Documents for users/posts with embedded relations (e.g., post with user ID, comments).
  - Scalable for millions of posts.
- **Big Data (e.g., Logs/Emails)**: Store unstructured text in key-value pairs for fast retrieval.
- **Connection to Lecture 13**: Indexing in NoSQL (e.g., on document fields) optimizes queries.

### 9. Misconceptions and Realities
- **Misconception**: NoSQL lacks ACID support.
  - **Reality**: Early NoSQL had limited ACID, but modern systems (e.g., MongoDB) support transactions.
- **Misconception**: NoSQL doesn't support joins.
  - **Reality**: Denormalized design embeds data; application-level joins or graph models handle relations.
- **Connection to Lecture 12**: Modern NoSQL provides partial ACID for consistency.

### 10. Interview Relevance
- **Key Points**: NoSQL is an emerging interview topic due to big data and scalability needs.
  - Common Questions: When to use NoSQL vs. SQL? Advantages/disadvantages? Types with examples?
- **Example**: "Design a NoSQL schema for a student app with flexible fields."
- **Connection to Previous Lectures**: Compare to SQL (Lecture 9), normalization (Lecture 11), and transactions (Lecture 12).

---

## Questions from Lecture 15: NoSQL Databases

### 1. Introduction to NoSQL
- **What is NoSQL, and how does it differ from relational databases?**
  - **Answer**: NoSQL is a non-relational database for unstructured/semi-structured data with flexible schemas. Unlike relational databases (fixed schemas, normalized tables), NoSQL allows dynamic fields and horizontal scaling.
  - **Context**: Explained as an alternative for data without rigid structure.

- **What types of data does NoSQL handle best?**
  - **Answer**: Unstructured (e.g., text, videos) and semi-structured (e.g., JSON with optional fields) data, unlike relational's structured data.
  - **Context**: Example: Student records with varying attributes like "branch."

### 2. Advantages of NoSQL
- **What is the benefit of flexible schemas in NoSQL?**
  - **Answer**: Allows adding/removing fields dynamically without schema changes (e.g., add "branch" to some student records only).
  - **Context**: Contrasted with rigid SQL schemas.

- **How does NoSQL support horizontal scalability?**
  - **Answer**: Easily adds servers (nodes) to distribute data, handling large volumes (e.g., social media posts) better than vertical SQL scaling.
  - **Context**: Example: Scaling for thousands of users without downtime.

### 3. Disadvantages of NoSQL
- **Why does NoSQL lack full ACID support?**
  - **Answer**: Early NoSQL prioritized speed over strict consistency; modern systems offer partial support, but not like SQL's full ACID.
  - **Context**: Misconception clarified; suitable for non-critical apps.

- **What is the challenge with joins in NoSQL?**
  - **Answer**: No built-in joins; data is denormalized (duplicated), requiring application-level handling (e.g., embed user ID in posts).
  - **Context**: Example: Fetching related data in code, not SQL `JOIN`.

### 4. Types of NoSQL Databases
- **What is a document store, and give an example?**
  - **Answer**: Stores data as flexible documents (e.g., JSON). Example: MongoDB – `{ "Name": "Rohit", "Branch": "IT" }`.
  - **Context**: Ideal for semi-structured data like student profiles.

- **What is a key-value store, and when is it used?**
  - **Answer**: Simple pairs (key: value) for fast lookups. Example: Redis – `UserID: { "Name": "Rohit" }` for caching sessions.
  - **Context**: For quick access to simple data.

- **Describe column-family stores and graph databases.**
  - **Answer**: Column-family: Stores in wide columns (e.g., Cassandra for dynamic fields like grades). Graph: Nodes/edges for relationships (e.g., Neo4j for Student → Subject).
  - **Context**: Column for big data; graph for connected data like social networks.

### 5. NoSQL vs. Relational Databases
- **How does NoSQL handle schema changes compared to SQL?**
  - **Answer**: NoSQL allows dynamic changes (e.g., add fields without altering schema); SQL requires schema modifications.
  - **Context**: Example: Adding "address" to some records in NoSQL.

- **Why might NoSQL be preferred for social media apps?**
  - **Answer**: Handles unstructured data (e.g., posts with varying fields) and scales horizontally for millions of users.
  - **Context**: Example: Facebook storing user profiles/posts as documents.

### 6. Using NoSQL
- **How do you implement a NoSQL schema for student data?**
  - **Answer**: Use documents like `{ "ID": 1, "Name": "Rohit", "Branch": "IT" }` in MongoDB; query by fields (e.g., `find({ "Branch": "IT" })`).
  - **Context**: Flexible for optional attributes.

- **What is denormalization in NoSQL?**
  - **Answer**: Duplicating data (e.g., embed user details in posts) to avoid joins, trading storage for speed.
  - **Context**: Example: Posts with embedded user ID/comment.

### 7. Practical Examples
- **How would NoSQL store social media data?**
  - **Answer**: As documents (e.g., post with user ID, comments embedded); scalable for relations without joins.
  - **Context**: Facebook example with flexible fields.

- **Give an example of NoSQL for big data like logs.**
  - **Answer**: Key-value store for unstructured logs (e.g., Redis: `LogID: { "Timestamp": "2025-09-24", "Message": "Error" }`).
  - **Context**: Fast insertion/retrieval for high-volume data.

### 8. Misconceptions and Realities
- **Is it true that NoSQL doesn't support transactions?**
  - **Answer**: Misconception; early NoSQL had limited ACID, but modern systems (e.g., MongoDB) support transactions.
  - **Context**: Clarified for banking-like apps.

- **Does NoSQL completely replace SQL?**
  - **Answer**: No; NoSQL complements SQL for unstructured data, while SQL is better for structured, relational data.
  - **Context**: Hybrid use in apps (e.g., SQL for transactions, NoSQL for logs).

### 9. Interview Relevance
- **What are common interview questions on NoSQL?**
  - **Answer**: When to use NoSQL vs. SQL? Advantages/disadvantages? Types (document, graph)? Schema design examples?
  - **Context**: Emerging topic for big data roles.

- **How does NoSQL handle relationships?**
  - **Answer**: Via embedding (denormalization) or graph models; no native joins like SQL.
  - **Context**: Example: Embed user in posts.

---

## Notes on Connections to Previous Lectures
- **Lecture 9 (SQL)**: NoSQL uses query languages (e.g., MongoDB `find()`) similar to SQL but for flexible data; lacks `JOIN`.
- **Lecture 11 (Normalization)**: NoSQL avoids normalization for flexibility, using denormalization.
- **Lecture 12 (Transactions)**: Limited ACID support; eventual consistency vs. SQL's strong ACID.
- **Lecture 13 (Indexing)**: NoSQL supports indexing on fields for optimization.

These notes and questions are self-contained for revision. If you need expansions or more questions, let me know!## Lecture 14: NoSQL Databases - Key Concepts

Below are concise notes covering all key concepts discussed in the transcript of Lecture 14 on **NoSQL Databases**. The notes are organized by topic, based solely on the transcript, with transcription errors corrected (e.g., "Bigg Boss" as contextual example or filler, "ghr ghr" as emphasis, "penis" as irrelevant). The content is structured to be study-friendly, focusing on definitions, explanations, examples, and their relevance to database management, with connections to previous lectures where applicable. At the end, I've included a section with questions derived from the concepts for review or interview preparation.

### 1. Introduction to NoSQL Databases
- **Definition**: NoSQL (Not Only SQL) databases are non-relational systems designed to store and manage unstructured or semi-structured data without a fixed schema, offering flexibility for modern applications.
- **Purpose**: Handles large volumes of diverse data (e.g., documents, graphs) that don't fit relational models, enabling scalable storage and retrieval.
- **Key Characteristics**:
  - **Unstructured/Semi-Structured Data**: Stores data in formats like JSON (e.g., documents with varying fields) without rigid tables/rows.
  - **Flexible Schema**: Allows dynamic changes (e.g., add fields like "profile picture" to one user without affecting others).
- **Example**: Storing student data as JSON: `{ "name": "Rohit", "branch": "IT", "branchInfo": { "code": "IT", "name": "Information Technology" } }`.
- **Connection to Previous Lectures**:
  - **Lecture 9**: NoSQL contrasts with SQL's structured queries; uses languages like MongoDB Query Language (MQL) instead of SQL.
  - **Lecture 11**: NoSQL avoids normalization issues by allowing denormalized, flexible structures.

### 2. Comparison: NoSQL vs. Relational (SQL) Databases
- **Relational (SQL) Databases**:
  - Structured data with fixed schema (tables, rows, columns).
  - Uses SQL for queries; supports joins for relationships.
  - ACID compliant (Atomicity, Consistency, Isolation, Durability) for strong consistency.
  - Example: MySQL or PostgreSQL for student-branch relationships via foreign keys.
- **NoSQL Databases**:
  - Flexible schema for unstructured/semi-structured data (e.g., JSON documents).
  - No joins; data is denormalized (e.g., embed branch info in student document).
  - Follows BASE model (Basically Available, Soft State, Eventual Consistency) for high availability and scalability.
  - Example: MongoDB stores student with embedded branch: `{ "studentID": 1, "name": "Rohit", "branch": { "code": "IT", "name": "Information Technology" } }`.
- **Key Differences**:
  - **Schema**: SQL (fixed/rigid) vs. NoSQL (dynamic/flexible).
  - **Data Types**: SQL (structured tables) vs. NoSQL (documents, key-value, graphs).
  - **Scalability**: SQL (vertical scaling) vs. NoSQL (horizontal scaling across nodes).
  - **Consistency**: SQL (ACID for transactions) vs. NoSQL (BASE for eventual consistency).
  - **Joins**: SQL (required for relationships) vs. NoSQL (avoided; use embedding or referencing).
- **Example**: In SQL, querying student-branch requires a JOIN; in NoSQL, it's embedded, reducing query complexity.
- **Connection to Previous Lectures**:
  - **Lecture 12**: NoSQL's BASE contrasts with ACID in transactions; suitable for high-availability apps but less for strict consistency (e.g., banking).
  - **Lecture 11**: NoSQL denormalizes data, avoiding normalization anomalies but potentially increasing redundancy.

### 3. Advantages of NoSQL
- **Flexibility**: Dynamic schema allows adding fields without schema changes (e.g., add "profile picture" to one document).
- **Scalability**: Horizontal scaling (add servers) for big data; handles high read/write loads.
- **Performance**: Fast queries on unstructured data; no joins reduce latency (e.g., retrieve full document in one operation).
- **Handling Diverse Data**: Stores semi-structured data (e.g., social media posts with varying fields like images, text).
- **Example**: Facebook uses NoSQL to store user profiles with varying attributes (e.g., some users have "hobbies," others don't).
- **Connection to Previous Lectures**:
  - **Lecture 9**: Faster than SQL joins for read-heavy apps.
  - **Lecture 12**: BASE enables high availability in distributed systems.

### 4. Disadvantages of NoSQL
- **No ACID Support (Misconception Clarified)**: Early NoSQL lacked full ACID; modern ones (e.g., MongoDB) support it for single documents but not always across collections.
- **Joins Not Supported**: Relationships require embedding (denormalization) or referencing, which can lead to data duplication.
- **Eventual Consistency**: BASE model may cause temporary inconsistencies (e.g., updates propagate later).
- **Learning Curve**: Requires understanding BASE vs. ACID; not ideal for complex relational queries.
- **Example**: In banking, NoSQL's eventual consistency might delay balance updates, risking errors (better for social media feeds).
- **Connection to Previous Lectures**:
  - **Lecture 12**: Lacks full ACID for multi-document transactions.
  - **Lecture 11**: Denormalization can introduce redundancy, opposite of normalization.

### 5. Use Cases for NoSQL
- **Big Data & Real-Time Apps**: Social media (e.g., Facebook profiles), IoT (sensor data), content management (e.g., blogs with varying fields).
- **Unstructured Data**: Documents (JSON), graphs (social networks), key-value stores (caching).
- **High Scalability Needs**: E-commerce catalogs, analytics (e.g., user logs).
- **When to Use NoSQL Over SQL**:
  - Flexible schema required (e.g., evolving apps).
  - High write/read volumes (e.g., logging).
  - Horizontal scaling needed.
- **Example**: MongoDB for storing user posts with embedded comments/images (no joins needed).
- **Connection to Previous Lectures**:
  - **Lecture 9**: Ideal for non-SQL queries in apps like social media.
  - **Lecture 12**: Suited for BASE-tolerant apps (e.g., non-financial).

### 6. MongoDB as a NoSQL Example
- **Definition**: Document-oriented NoSQL database storing data as BSON (Binary JSON) documents.
- **Key Features**:
  - Collections (like tables) of flexible documents.
  - Embedding for relationships (e.g., student document with branch sub-document).
  - Supports some ACID for single documents.
- **Example**: `{ "userID": 1, "name": "Rohit", "posts": [{ "title": "Hello", "content": "World" }] }` – embeds posts in user document.
- **Comparison to RDBMS**: MongoDB avoids joins by embedding; faster for reads but may duplicate data.
- **Connection to Previous Lectures**:
  - **Lecture 9**: Uses MQL instead of SQL; supports aggregation pipelines like `GROUP BY`.
  - **Lecture 11**: Denormalized structure suits semi-structured data.

### 7. BASE Properties (vs. ACID)
- **Definition**: BASE (Basically Available, Soft State, Eventual Consistency) is the NoSQL alternative to ACID, prioritizing availability and scalability over strict consistency.
- **Key Points**:
  - **Basically Available**: System remains operational even during failures.
  - **Soft State**: Data may change without immediate consistency.
  - **Eventual Consistency**: Updates propagate eventually (not instantly).
- **Example**: In social media, a like may not appear immediately but eventually syncs across nodes.
- **Misconception**: Early NoSQL lacked ACID; modern ones (e.g., MongoDB) support it partially.
- **Connection to Lecture 12**: BASE trades ACID's strong consistency for high availability in distributed systems.

### 8. Object Mapping (ORM-like in NoSQL)
- **Definition**: Mapping application objects (e.g., Java classes) to NoSQL documents, allowing seamless data handling.
- **Process**: Define a class (e.g., Student) and map it to a collection; the ORM handles serialization/deserialization.
- **Example**: In Spring Boot with MongoDB, `@Document` annotates a Student class, mapping fields to document properties.
- **Purpose**: Simplifies integration between apps and NoSQL (e.g., retrieve student as an object).
- **Connection to Lecture 9**: Similar to SQL ORM (e.g., JPA) but for documents.

### 9. Interview Relevance
- **Key Points**: NoSQL is an emerging interview topic; focus on when to use it (unstructured data, scalability) vs. SQL (structured, ACID needs).
- **Common Questions**: Differences between SQL/NoSQL, BASE vs. ACID, MongoDB use cases, schema flexibility.
- **Example**: "Why use MongoDB for social media profiles?" (Flexible schema for varying fields).
- **Connection to Previous Lectures**:
  - **Lecture 9**: SQL vs. MQL queries.
  - **Lecture 11**: NoSQL for denormalized data.
  - **Lecture 12**: BASE for eventual consistency in transactions.

---

## Questions from Lecture 14: NoSQL Databases

### 1. Introduction and Comparison
- **What is a NoSQL database, and how does it differ from relational (SQL) databases?**
  - **Answer**: NoSQL stores unstructured/semi-structured data with flexible schemas (e.g., JSON documents), unlike SQL's fixed tables/rows. NoSQL avoids joins via embedding; SQL uses them for relationships.
  - **Context**: Highlighted as an alternative for scalable, schema-less data.

- **What types of data are best suited for NoSQL databases?**
  - **Answer**: Unstructured (e.g., social media posts) or semi-structured (e.g., JSON with varying fields) data, where schema flexibility is needed.
  - **Context**: Example: Student data with optional fields like "branchInfo."

### 2. Advantages and Disadvantages
- **What are the main advantages of NoSQL over SQL?**
  - **Answer**: Flexible schema (dynamic changes), horizontal scalability, fast queries on unstructured data, and handling big data (e.g., no joins needed).
  - **Context**: Example: Embedding branch in student document reduces query complexity.

- **What is a key disadvantage of NoSQL databases?**
  - **Answer**: Lacks full ACID support (uses BASE for eventual consistency); joins are not native, leading to denormalization and potential redundancy.
  - **Context**: Misconception clarified: Modern NoSQL supports partial ACID.

### 3. Use Cases
- **When should you use NoSQL instead of SQL?**
  - **Answer**: For unstructured data, high scalability (e.g., social media, IoT), or flexible schemas (e.g., evolving apps like Facebook profiles).
  - **Context**: Example: MongoDB for user posts with embedded comments.

- **Give an example of a NoSQL use case in social media.**
  - **Answer**: Storing user profiles as documents with varying fields (e.g., posts, likes) without rigid schemas.
  - **Context**: Facebook uses NoSQL for scalable, denormalized data.

### 4. MongoDB and BASE Properties
- **What is MongoDB, and how does it exemplify NoSQL?**
  - **Answer**: A document-oriented NoSQL database using BSON for flexible collections; embeds relationships to avoid joins.
  - **Context**: Example: `{ "userID": 1, "name": "Rohit", "posts": [...] }`.

- **What does the BASE model mean, and how does it differ from ACID?**
  - **Answer**: BASE (Basically Available, Soft State, Eventual Consistency) prioritizes availability/scalability over strict consistency, unlike ACID's strong guarantees.
  - **Context**: NoSQL's eventual consistency suits high-traffic apps.

### 5. Object Mapping and Implementation
- **What is object mapping in NoSQL, and how does it work?**
  - **Answer**: Maps application classes (e.g., Student in Java) to documents/collections, handling serialization (e.g., Spring Boot with `@Document`).
  - **Context**: Simplifies app-database integration.

- **How do you implement NoSQL in an application like Spring Boot?**
  - **Answer**: Use MongoDB with Spring Data; define classes with `@Document` and repositories for CRUD operations.
  - **Context**: Example: Map Student class to a MongoDB collection.

### 6. Interview Relevance
- **Why is NoSQL a common interview topic?**
  - **Answer**: Emerging for big data/scalability; questions test understanding of SQL vs. NoSQL, use cases, and BASE vs. ACID.
  - **Context**: Focus on when to choose NoSQL (flexible data) over SQL (structured).
