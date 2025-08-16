#include <iostream>
#include <string>

// Interface for version control system
class IVersionControl {
public:
    virtual void commit(const std::string& message) = 0;
    virtual void push() = 0;
    virtual void pull() = 0;
};

// Git version control implementation
class GitVersionControl : public IVersionControl {
public:
    void commit(const std::string& message) override {
        std::cout << "Committing changes to Git with message: " << message << std::endl;
    }

    void push() override {
        std::cout << "Pushing changes to remote Git repository." << std::endl;
    }

    void pull() override {
        std::cout << "Pulling changes from remote Git repository." << std::endl;
    }
};

// Team class that relies on version control
class DevelopmentTeam {
private:
    IVersionControl* versionControl;

public:
    DevelopmentTeam(IVersionControl* vc) : versionControl(vc) {}

    void makeCommit(const std::string& message) {
        versionControl->commit(message);
    }

    void performPush() {
        versionControl->push();
    }

    void performPull() {
        versionControl->pull();
    }
};

int main() {
    GitVersionControl git;
    DevelopmentTeam team(&git);

    team.makeCommit("Initial commit");
    team.performPush();
    team.performPull();

    return 0;
}

// 5. Dependency Inversion Principle

// "High-level modules should not depend on low-level modules. Both should depend on abstractions". 

// Explanation of the above code:

// IVersionControl Interface: This defines the operations that any version control system should support, like commit, push, and pull. It serves as an abstraction that decouples high-level code from low-level implementations.
// GitVersionControl Class: This class implements the IVersionControl interface, providing specific functionality for managing version control using Git.
// DevelopmentTeam Class: This class relies on the IVersionControl interface, meaning it can work with any version control implementation that adheres to the interface. It does not need to know the details of how Git works internally.