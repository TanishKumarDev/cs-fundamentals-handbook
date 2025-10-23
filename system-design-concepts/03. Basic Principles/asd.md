# **DRY, KISS, YAGNI**


## 1. **DRY (Don’t Repeat Yourself)**

**Meaning:**

* Avoid duplicating code or logic.
* Every piece of knowledge should have a **single, unambiguous representation** in your system.

**Why:**

* Easier to maintain: change it in one place, not many.
* Reduces bugs: fewer copies → fewer mistakes.
* Cleaner and more readable code.

**How to follow:**

* Use functions, classes, modules, or services.
* Reuse existing code instead of copy-pasting.
* Avoid repeating business logic in multiple places.

**Example:**

```cpp
// BAD (Repeated logic)
double calculateCircleArea(double r) { return 3.14 * r * r; }
double calculateCylinderVolume(double r, double h) { return 3.14 * r * r * h; }

// GOOD (DRY applied)
double circleArea(double r) { return 3.14 * r * r; }
double cylinderVolume(double r, double h) { return circleArea(r) * h; }
```

✅ Notice: The area logic is written **once** and reused.

---

## 2. **KISS (Keep It Simple, Stupid)**

**Meaning:**

* Simplicity is better than complexity.
* Don’t over-engineer solutions.

**Why:**

* Easier to understand and maintain.
* Fewer bugs.
* Better for team collaboration.

**How to follow:**

* Break complex problems into simple steps.
* Avoid unnecessary features.
* Use straightforward solutions over “clever” ones.

**Example:**

```cpp
// COMPLEX
if (!(a > 0 && b > 0) || !(a < 10 && b < 10)) { ... }

// SIMPLE (KISS)
if (a > 0 && a < 10 && b > 0 && b < 10) { ... }
```

✅ Clearer and easier to read.

---

## 3. **YAGNI (You Aren’t Gonna Need It)**

**Meaning:**

* Don’t implement features or add code **until it’s actually needed**.
* Avoid building for hypothetical future requirements.

**Why:**

* Saves time and effort.
* Reduces unnecessary complexity.
* Keeps system focused on current requirements.

**How to follow:**

* Only build what solves today’s problem.
* Avoid over-abstracting early.
* Refactor later when new needs actually appear.

**Example:**

```cpp
// NOT following YAGNI
class User {
    string name;
    int age;
    string address;
    string phoneNumber;
    string emergencyContact; // not needed now
};

// FOLLOWING YAGNI
class User {
    string name;
    int age;
    string address; // only what we need now
}
```

✅ Extra fields can be added later **when actually needed**.

---

## Summary Table

| Principle | Meaning                  | Key Idea                     | Example Focus               |
| --------- | ------------------------ | ---------------------------- | --------------------------- |
| **DRY**   | Don’t Repeat Yourself    | Reuse code, avoid duplicates | Functions, classes, modules |
| **KISS**  | Keep It Simple, Stupid   | Simple > complex             | Clear, readable logic       |
| **YAGNI** | You Aren’t Gonna Need It | Build only what’s needed     | Avoid speculative features  |

---

💡 **Tip for System Design:**

* DRY → Modular services / shared libraries
* KISS → Simple architecture & APIs
* YAGNI → Avoid over-engineered microservices or features before demand
