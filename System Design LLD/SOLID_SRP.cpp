#include <iostream>
#include <string>

// Class for baking bread
class BreadBaker {
public:
    void bakeBread() {
        std::cout << "Baking high-quality bread..." << std::endl;
    }
};

// Class for managing inventory
class InventoryManager {
public:
    void manageInventory() {
        std::cout << "Managing inventory..." << std::endl;
    }
};

// Class for ordering supplies
class SupplyOrder {
public:
    void orderSupplies() {
        std::cout << "Ordering supplies..." << std::endl;
    }
};

// Class for serving customers
class CustomerService {
public:
    void serveCustomer() {
        std::cout << "Serving customers..." << std::endl;
    }
};

// Class for cleaning the bakery
class BakeryCleaner {
public:
    void cleanBakery() {
        std::cout << "Cleaning the bakery..." << std::endl;
    }
};

int main() {
    BreadBaker baker;
    InventoryManager inventoryManager;
    SupplyOrder supplyOrder;
    CustomerService customerService;
    BakeryCleaner cleaner;

    // Each class focuses on its specific responsibility
    baker.bakeBread();
    inventoryManager.manageInventory();
    supplyOrder.orderSupplies();
    customerService.serveCustomer();
    cleaner.cleanBakery();

    return 0;
}


// 1. Single Responsibility Principle

// "A class should have only one reason to change" which means every class should have a single responsibility or single job or single purpose. In other words, a class should have only one job or purpose within the software system.

// In the above example:
// BreadBaker Class: Responsible solely for baking bread. This class focuses on ensuring the quality and standards of the bread without being burdened by other tasks.
// InventoryManager Class: Handles inventory management, ensuring that the bakery has the right ingredients and supplies available.
// SupplyOrder Class: Manages ordering supplies, ensuring that the bakery is stocked with necessary items.
// CustomerService Class: Takes care of serving customers, providing a focused approach to customer interactions.
// BakeryCleaner Class: Responsible for cleaning the bakery, ensuring a hygienic environment.