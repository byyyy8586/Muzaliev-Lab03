#include <iostream>
#include <iomanip>
#include <cmath>

const double PI = 3.14159265358979323846;

class Figure {
public:
    virtual double area() const = 0;      // площа
    virtual double perimeter() const = 0; // периметр

    // Віртуальний деструктор
    virtual ~Figure() = default;

    // Допоміжний метод для виведення інформації
    virtual void print() const {
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Площа: " << area() << "\n";
        std::cout << "Периметр: " << perimeter() << "\n\n";
    }
};

//Прямокутник
class Rectangle : public Figure {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void print() const override {
        std::cout << "=== Прямокутник ===\n";
        std::cout << "Ширина: " << width << ", Висота: " << height << "\n";
        Figure::print();
    }
};

//Коло
class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * PI * radius;
    }

    void print() const override {
        std::cout << "=== Коло ===\n";
        std::cout << "Радіус: " << radius << "\n";
        Figure::print();
    }
};

//Трапеція
class Trapezium : public Figure {
private:
    double base1;     // нижня основа
    double base2;     // верхня основа
    double height; 
    double leg1;      // ліва бічна сторона
    double leg2;      // права бічна сторона

public:
    Trapezium(double b1, double b2, double h, double l1, double l2)
        : base1(b1), base2(b2), height(h), leg1(l1), leg2(l2) {}

    double area() const override {
        return (base1 + base2) / 2.0 * height;   // S = (a + b) / 2 * h
    }

    double perimeter() const override {
        return base1 + base2 + leg1 + leg2;
    }

    void print() const override {
        std::cout << "=== Трапеція ===\n";
        std::cout << "Основа1: " << base1 << ", Основа2: " << base2 
                  << ", Висота: " << height << "\n";
        std::cout << "Бічні сторони: " << leg1 << " і " << leg2 << "\n";
        Figure::print();
    }
};

int main() {
    std::cout << "Демонстрація класів фігур\n\n";

    Figure* f1 = new Rectangle(5.0, 3.0);
    Figure* f2 = new Circle(4.0);
    Figure* f3 = new Trapezium(6.0, 4.0, 5.0, 5.0, 5.0);

    f1->print();
    f2->print();
    f3->print();

    // звільнення пам'яті
    delete f1;
    delete f2;
    delete f3;

    return 0;
}