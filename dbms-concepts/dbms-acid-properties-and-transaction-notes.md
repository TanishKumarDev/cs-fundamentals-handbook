# Concepts : Database Transactions

### 1. Database Transaction
- **Definition**: A transaction is a logical unit of work consisting of one or more database operations (e.g., read, write, update) executed in a specific sequence to achieve a consistent outcome.
- **Key Points**:
  - Transactions ensure data integrity by completing all operations or none at all.
  - Operations are treated as a single, indivisible unit (atomic).
- **Example**: Transferring ₹50 from Account A (balance ₹100) to Account B involves:
  - Read Account A’s balance (₹100).
  - Update Account A to ₹50 (deduct ₹50).
  - Read Account B’s balance.
  - Update Account B by adding ₹50.
- **Purpose**: Maintains consistency in the database, ensuring operations like money transfers don’t result in lost or duplicated data.
- **Connection to Lecture 9**: Transactions use SQL commands like `SELECT` (read), `UPDATE` (write), and `INSERT`/`DELETE` (Lecture 9) to perform operations, ensuring they are executed as a unit.

### 2. ACID Properties
- **Definition**: ACID (Atomicity, Consistency, Isolation, Durability) are four properties that guarantee reliable database transactions.
- **Atomicity**:
  - Ensures all operations in a transaction are completed successfully, or none are applied.
  - If any operation fails, the transaction is rolled back to its initial state.
  - **Example**: In a ₹50 transfer, if Account A is debited but Account B fails to credit, the debit is undone (rolled back).
- **Consistency**:
  - Ensures the database remains in a valid state before and after the transaction, adhering to integrity constraints (e.g., primary keys, foreign keys).
  - **Example**: Total balance (Account A + Account B) must remain the same (e.g., ₹2000 before and after a ₹50 transfer).
- **Isolation**:
  - Ensures transactions are executed independently, preventing interference between concurrent transactions.
  - **Example**: If two users transfer money simultaneously (e.g., ₹50 and ₹100 from Account A), the system ensures one transaction completes before the other starts to avoid incorrect balances.
- **Durability**:
  - Guarantees that once a transaction is committed, its changes are permanently saved, even in case of system failure.
  - **Example**: After transferring ₹50, the updated balances (Account A: ₹50, Account B: increased by ₹50) are saved to persistent storage (e.g., hard drive).
- **Purpose**: ACID properties maintain data integrity and reliability in database systems, especially in critical applications like banking.
- **Connection to Lecture 9**: ACID properties rely on constraints (e.g., primary/foreign keys) and SQL operations (e.g., `UPDATE`, `COMMIT`) from Lecture 9 to enforce consistency and durability.

### 3. Transaction Operations
- **Read Operation**:
  - Retrieves data from the database into memory (e.g., buffer) for processing.
  - **Example**: Reading Account A’s balance (₹100) before a transfer.
- **Write Operation**:
  - Updates data in memory (temporary) or database (persistent after commit).
  - **Example**: Updating Account A’s balance to ₹50 after deducting ₹50.
- **Commit Operation**:
  - Permanently saves all changes made in the transaction to the database.
  - **Example**: After debiting Account A and crediting Account B, a `COMMIT` ensures both changes are stored in the database.
- **Rollback Operation**:
  - Reverts all changes made by a transaction if it fails, restoring the database to its previous state.
  - **Example**: If Account B’s update fails, rollback restores Account A’s balance to ₹100.
- **Process**:
  - Transactions involve a sequence of read, write, and update operations, followed by either `COMMIT` or `ROLLBACK`.
  - Operations are initially performed in memory (e.g., RAM buffer) and finalized to persistent storage (e.g., hard drive) upon commit.
- **Connection to Lecture 9**: These operations use SQL commands like `SELECT` (read), `UPDATE` (write), and transaction control commands like `COMMIT` and `ROLLBACK` (implied in Lecture 9’s discussion of SQL operations).

### 4. Transaction States
- **Definition**: A transaction progresses through states during its execution.
- **States**:
  - **Active**: Transaction is executing operations (e.g., reading or updating balances).
  - **Partially Committed**: All operations are completed, but changes are still in memory (not yet saved to persistent storage).
  - **Committed**: Transaction is successfully completed, and changes are permanently saved (`COMMIT`).
  - **Failed**: Transaction encounters an error (e.g., hardware failure) and cannot proceed.
  - **Aborted**: Transaction is rolled back, undoing all changes to restore the original state.
- **Example**:
  - Active: Reading Account A’s balance.
  - Partially Committed: After updating Account A and B in memory.
  - Committed: After `COMMIT` saves changes to the database.
  - Failed/Aborted: If the system crashes before crediting Account B, rollback restores Account A’s balance.
- **Purpose**: States track the transaction’s progress to ensure proper handling of success or failure.
- **Connection to Lecture 9**: Transaction states relate to SQL operations (e.g., `UPDATE` in active state, `COMMIT` for committed state) from Lecture 9.

### 5. Concurrency and Isolation Issues
- **Definition**: Concurrency occurs when multiple transactions run simultaneously, potentially causing interference.
- **Problem**: Without isolation, concurrent transactions can lead to inconsistencies.
  - **Example**: Two transactions (T1 and T2) read Account A’s balance (₹100) simultaneously. T1 deducts ₹50, and T2 deducts ₹100, but both update based on the original ₹100, resulting in an incorrect final balance (e.g., ₹50 instead of ₹-50).
- **Solution**: Isolation ensures transactions are executed in a serial order (one completes before another starts) to avoid interference.
  - **Example**: The system processes T1 (deduct ₹50, balance ₹50), then T2 (deduct ₹100, balance ₹-50 or fails if negative balances are disallowed).
- **Mechanism**: Locking or scheduling mechanisms ensure isolation.
  - **Example**: Lock Account A while T1 processes, preventing T2 from accessing it until T1 commits.
- **Connection to Lecture 9**: Isolation relates to SQL’s ability to handle multiple queries (e.g., `SELECT`, `UPDATE`) concurrently, with constraints ensuring data integrity (Lecture 9).

### 6. Recovery Mechanisms
- **Definition**: Mechanisms to restore the database to a consistent state after a transaction failure.
- **Key Points**:
  - **Logging**: Records operations (e.g., read, write, commit) to track transaction progress.
    - **Example**: Log “deduct ₹50 from Account A” and “add ₹50 to Account B” to enable rollback if needed.
  - **Checkpoints**: Save the database state periodically to reduce recovery time.
    - **Example**: Save the database state before a transaction to revert to it if the system crashes.
  - **Rollback**: Uses logs to undo changes if a transaction fails.
    - **Example**: If Account B’s update fails, logs help restore Account A’s balance to ₹100.
- **Purpose**: Ensures durability and consistency by recovering from failures without data loss.
- **Example**: If a system crash occurs after debiting Account A but before crediting Account B, logs enable rollback to restore Account A’s balance.
- **Connection to Lecture 9**: Recovery mechanisms support SQL operations (e.g., `UPDATE`, `COMMIT`) and constraints (Lecture 9) by ensuring changes are either fully applied or undone.

### 7. Practical Example: Banking System
- **Scenario**: Transfer ₹50 from Account A (balance ₹100) to Account B.
- **Steps**:
  - Read Account A’s balance (₹100).
  - Update Account A to ₹50 (deduct ₹50).
  - Read Account B’s balance.
  - Update Account B by adding ₹50.
  - Commit changes to persistent storage.
- **ACID Application**:
  - **Atomicity**: All steps (deduct, credit) complete, or none are applied.
  - **Consistency**: Total balance (Account A + Account B) remains constant.
  - **Isolation**: Prevents another transaction (e.g., another transfer) from interfering.
  - **Durability**: Ensures the new balances are saved even if the system fails post-commit.
- **Failure Case**:
  - If the system crashes after debiting Account A but before crediting Account B, rollback restores Account A to ₹100.
- **Connection to Lecture 9**: This example uses SQL operations like `SELECT` (read), `UPDATE` (write), and `COMMIT`/`ROLLBACK` (Lecture 9) to implement the transaction.

### 8. Interview Relevance
- **Key Points**:
  - Transactions and ACID properties are critical interview topics due to their importance in ensuring reliable database operations.
  - Common questions include:
    - Defining transactions and their purpose.
    - Explaining ACID properties with examples.
    - Describing transaction states and recovery mechanisms.
    - Handling concurrency issues (e.g., isolation through locking).
- **Examples**: Be prepared to explain a banking transaction, including how ACID properties prevent errors and how rollback recovers from failures.
- **Connection to Lecture 9 & 11**:
  - Lecture 9: Transactions build on SQL commands (`SELECT`, `UPDATE`, `COMMIT`) and constraints (e.g., ensuring balance integrity).
  - Lecture 11: Transactions complement normalization by ensuring operations on normalized tables (e.g., Student, Branch) maintain consistency.

# Questions: Database Transactions

### 1. Database Transaction
- **What is a database transaction, and why is it considered a logical unit of work?**
  - **Answer**: A transaction is a sequence of database operations (e.g., read, write, update) executed as a single logical unit to achieve a consistent outcome. It’s logical because operations (e.g., debiting and crediting in a ₹50 transfer) must all complete or none to maintain data integrity.
  - **Context**: Described as a set of logical steps (e.g., reading Account A’s balance, updating it) in a specific sequence.
  - **Connection to Lecture 9**: Transactions use SQL commands like `SELECT` (read) and `UPDATE` (write) to perform operations.

- **How does a transaction ensure data integrity in a banking system?**
  - **Answer**: A transaction ensures all operations (e.g., debit ₹50 from Account A, credit ₹50 to Account B) complete successfully or are undone, preventing partial updates that could lead to inconsistent balances.
  - **Context**: Illustrated with a banking example transferring ₹50 between accounts.
  - **Connection to Lecture 9**: Relies on SQL `UPDATE` and `COMMIT` to apply changes.

### 2. ACID Properties
- **What are the ACID properties of a database transaction?**
  - **Answer**: ACID stands for:
    - **Atomicity**: All operations complete, or none are applied (e.g., both debit and credit in a ₹50 transfer).
    - **Consistency**: Database remains valid before and after (e.g., total balance stays constant).
    - **Isolation**: Transactions execute independently without interference.
    - **Durability**: Committed changes are permanently saved.
  - **Context**: Highlighted as essential for reliable transactions, especially in banking.
  - **Connection to Lecture 9**: Consistency relies on constraints (e.g., primary/foreign keys) from Lecture 9.

- **How does atomicity ensure a transaction’s reliability?**
  - **Answer**: Atomicity ensures all operations (e.g., debit and credit) complete successfully, or the transaction is rolled back to the original state, preventing partial updates (e.g., debiting Account A without crediting Account B).
  - **Context**: Explained with rollback if a ₹50 transfer fails midway.
  - **Connection to Lecture 9**: Uses SQL `ROLLBACK` (implied in Lecture 9) to undo changes.

- **What does consistency mean in the context of a transaction, and how is it maintained?**
  - **Answer**: Consistency ensures the database adheres to integrity constraints (e.g., total balance remains ₹2000 before and after a ₹50 transfer). It’s maintained by ensuring all operations comply with constraints or are rolled back.
  - **Context**: Emphasized with maintaining total balance in a banking system.
  - **Connection to Lecture 9**: Relies on constraints like primary/foreign keys (Lecture 9).

- **How does isolation prevent issues in concurrent transactions?**
  - **Answer**: Isolation ensures transactions run independently, preventing interference. For example, if two transactions try to debit ₹50 and ₹100 from Account A (balance ₹100), isolation ensures one completes before the other, avoiding incorrect balances.
  - **Context**: Shown with concurrent net banking transactions causing inconsistencies if not isolated.
  - **Connection to Lecture 9**: Involves SQL operations (`SELECT`, `UPDATE`) executed in a controlled sequence.

- **What is durability, and why is it critical for a transaction?**
  - **Answer**: Durability ensures committed changes (e.g., updated balances after a ₹50 transfer) are permanently saved to persistent storage (e.g., hard drive), even if the system fails. It’s critical to prevent data loss.
  - **Context**: Highlighted with saving changes after a successful transfer.
  - **Connection to Lecture 9**: Uses SQL `COMMIT` to finalize changes.

### 3. Transaction Operations
- **What is a read operation in a transaction, and how is it performed?**
  - **Answer**: A read operation retrieves data from the database into memory (e.g., buffer). For example, reading Account A’s balance (₹100) before a transfer.
  - **Context**: Described as copying data (e.g., balance) into memory for processing.
  - **Connection to Lecture 9**: Uses SQL `SELECT` for reading data.

- **What is a write operation, and where does it occur in a transaction?**
  - **Answer**: A write operation updates data, initially in memory (e.g., updating Account A’s balance to ₹50). It becomes permanent after a commit.
  - **Context**: Explained as a temporary update in RAM before committing to storage.
  - **Connection to Lecture 9**: Uses SQL `UPDATE` for writing changes.

- **What is the purpose of a commit operation in a transaction?**
  - **Answer**: A commit operation permanently saves all transaction changes to the database (e.g., saving updated balances after a ₹50 transfer).
  - **Context**: Described as finalizing changes to the physical database.
  - **Connection to Lecture 9**: Uses SQL `COMMIT` (implied in Lecture 9).

- **How does a rollback operation work, and when is it used?**
  - **Answer**: Rollback reverts all changes if a transaction fails, restoring the original state (e.g., restoring Account A’s balance to ₹100 if crediting Account B fails).
  - **Context**: Used when a transfer fails due to hardware or system issues.
  - **Connection to Lecture 9**: Uses SQL `ROLLBACK` (implied in Lecture 9).

### 4. Transaction States
- **What are the possible states of a database transaction?**
  - **Answer**: States include:
    - **Active**: Executing operations (e.g., reading or updating balances).
    - **Partially Committed**: Operations complete, changes in memory.
    - **Committed**: Changes permanently saved (`COMMIT`).
    - **Failed**: An error occurs (e.g., system crash).
    - **Aborted**: Transaction rolled back to original state.
  - **Context**: Explained with a ₹50 transfer progressing through states.
  - **Connection to Lecture 9**: States align with SQL operations (e.g., `UPDATE` in active, `COMMIT` in committed).

- **What happens if a transaction fails during execution?**
  - **Answer**: If a transaction fails (e.g., system crash after debiting Account A), it enters the failed state and is aborted, triggering a rollback to restore the original state (e.g., Account A’s balance to ₹100).
  - **Context**: Shown with a failed transfer requiring rollback.
  - **Connection to Lecture 9**: Rollback uses SQL mechanisms to undo `UPDATE` operations.

### 5. Concurrency and Isolation Issues
- **What problems can arise from concurrent transactions without isolation?**
  - **Answer**: Concurrent transactions can cause inconsistencies, such as incorrect balances. For example, if two transactions read Account A’s balance (₹100) and both deduct amounts (₹50 and ₹100), the final balance may be incorrect (e.g., ₹50 instead of ₹-50).
  - **Context**: Illustrated with simultaneous net banking transfers.
  - **Connection to Lecture 9**: Involves concurrent SQL `SELECT` and `UPDATE` operations.

- **How does isolation address concurrency issues in transactions?**
  - **Answer**: Isolation ensures transactions execute in a serial order (one completes before another starts) using mechanisms like locking, preventing interference and ensuring correct outcomes (e.g., proper balance updates).
  - **Context**: Explained with preventing overlapping transfers.
  - **Connection to Lecture 9**: Relates to SQL query execution and constraints ensuring data integrity.

- **What is an example of a concurrency issue in a banking system?**
  - **Answer**: Two transactions (T1: debit ₹50, T2: debit ₹100) read Account A’s balance (₹100) simultaneously. Without isolation, both update based on ₹100, leading to an incorrect final balance (e.g., ₹50 instead of ₹-50).
  - **Context**: Shown with net banking transfers causing inconsistencies.
  - **Connection to Lecture 9**: Involves SQL `UPDATE` operations needing controlled execution.

### 6. Recovery Mechanisms
- **What is the role of logging in transaction recovery?**
  - **Answer**: Logging records operations (e.g., “deduct ₹50 from Account A”) to track transaction progress, enabling rollback to restore the original state if a failure occurs (e.g., system crash before crediting Account B).
  - **Context**: Described as generating logs for operations to support recovery.
  - **Connection to Lecture 9**: Logging supports SQL operations like `UPDATE` to ensure reversibility.

- **How do checkpoints assist in transaction recovery?**
  - **Answer**: Checkpoints periodically save the database state, reducing recovery time by providing a known consistent state to revert to after a failure.
  - **Context**: Mentioned as a mechanism to restore the database state.
  - **Connection to Lecture 9**: Complements SQL `COMMIT` by ensuring saved states are recoverable.

- **What happens during a rollback in a transaction?**
  - **Answer**: Rollback uses logs to undo all changes, restoring the database to its state before the transaction (e.g., restoring Account A’s balance to ₹100 if crediting Account B fails).
  - **Context**: Explained with a failed transfer requiring rollback.
  - **Connection to Lecture 9**: Uses SQL `ROLLBACK` to revert `UPDATE` operations.

### 7. Practical Example: Banking System
- **How does a transaction work in a banking system for transferring money?**
  - **Answer**: For a ₹50 transfer from Account A (₹100) to Account B:
    - Read Account A’s balance (₹100).
    - Update Account A to ₹50 (deduct ₹50).
    - Read Account B’s balance.
    - Update Account B by adding ₹50.
    - Commit changes or rollback if any step fails.
  - **Context**: Core example of a banking transfer.
  - **Connection to Lecture 9 & 11**:
    - Lecture 9: Uses SQL `SELECT`, `UPDATE`, `COMMIT`/`ROLLBACK`.
    - Lecture 11: Assumes normalized tables (e.g., `Account` table) for consistent updates.

- **What happens if a banking transaction fails midway?**
  - **Answer**: If the system fails after debiting Account A but before crediting Account B, a rollback restores Account A’s balance to ₹100, ensuring no money is lost or created.
  - **Context**: Shown with a system crash during a transfer.
  - **Connection to Lecture 9**: Uses SQL `ROLLBACK` to undo changes.
