#include <iostream>

// Base class for shapes (Rectangle)
class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Virtual function to calculate area
    virtual double area() const {
        return width * height;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    // Setters for dimensions
    virtual void setWidth(double w) {
        width = w;
    }

    virtual void setHeight(double h) {
        height = h;
    }
};

// Derived class for square
class Square : public Rectangle {
public:
    Square(double size) : Rectangle(size, size) {}

    // Override setters to keep square properties (width == height)
    void setWidth(double w) override {
        width = height = w;
    }

    void setHeight(double h) override {
        width = height = h;
    }
};

int main() {
    // Rectangle example
    Rectangle rect(5, 10);
    std::cout << "Rectangle area: " << rect.area() << std::endl;

    rect.setWidth(6);
    std::cout << "Updated Rectangle area: " << rect.area() << std::endl;

    // Square example
    Square square(4);
    std::cout << "Square area: " << square.area() << std::endl;

    square.setWidth(5);
    std::cout << "Updated Square area: " << square.area() << std::endl;

    return 0;
}

// 3. Liskov's Substitution Principle

// "Derived or child classes must be substitutable for their base or parent classes". This principle ensures that any class that is the child of a parent class should be usable in place of its parent without any unexpected behaviour.

// Explanation of the above code:

// Rectangle Class: This is the base class that has properties for width and height. It has methods for calculating the area and for setting width and height.
// Square Class: This class inherits from Rectangle but overrides the setWidth and setHeight methods to ensure that changing one dimension affects the other, maintaining the property that all sides are equal.

// LSP Violation Example:

// To see a potential violation of LSP, consider what would happen if you were to use the Square class in a context expecting a Rectangle:
// If you substitute a Square where a Rectangle is expected, changing just the width or height would lead to unexpected results because it will change both dimensions.