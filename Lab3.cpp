#include <iostream>
#include <cmath>

// Абстрактный класс Точка
class Point {
public:
    virtual void draw() const = 0;
    virtual void erase() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;

    virtual double getX() const = 0;
    virtual double getY() const = 0;

    virtual ~Point() {}
};

// Реализация класса Точка
class ConcretePoint : public Point {
private:
    double x, y;

public:
    ConcretePoint(double x, double y) : x(x), y(y) {}

    void draw() const override {
        std::cout << "Drawing point at (" << x << ", " << y << ")" << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing point at (" << x << ", " << y << ")" << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }

    void rotate(double angle) override {
        double rad = angle * 3.14159265358979323846 / 180.0;
        double newX = x * cos(rad) - y * sin(rad);
        double newY = x * sin(rad) + y * cos(rad);
        x = newX;
        y = newY;
    }

    double getX() const override {
        return x;
    }

    double getY() const override {
        return y;
    }
};

// Класс Линия
class Line : public Point {
private:
    ConcretePoint p1, p2;

public:
    Line(double x1, double y1, double x2, double y2) : p1(x1, y1), p2(x2, y2) {}

    void draw() const override {
        std::cout << "Drawing line from (" << p1.getX() << ", " << p1.getY() << ") to (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing line from (" << p1.getX() << ", " << p1.getY() << ") to (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    }

    void move(double dx, double dy) override {
        p1.move(dx, dy);
        p2.move(dx, dy);
    }

    void rotate(double angle) override {
        p1.rotate(angle);
        p2.rotate(angle);
    }

    double getX() const override {
        return p1.getX();
    }

    double getY() const override {
        return p1.getY();
    }
};

// Класс Квадрат
class Square : virtual public Point {
protected:
    ConcretePoint p1, p2, p3, p4;

public:
    Square(double x, double y, double side)
        : p1(x, y), p2(x + side, y), p3(x + side, y + side), p4(x, y + side) {}

    void draw() const override {
        std::cout << "Drawing square with corners at ("
            << p1.getX() << ", " << p1.getY() << "), ("
            << p2.getX() << ", " << p2.getY() << "), ("
            << p3.getX() << ", " << p3.getY() << "), ("
            << p4.getX() << ", " << p4.getY() << ")" << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing square" << std::endl;
    }

    void move(double dx, double dy) override {
        p1.move(dx, dy);
        p2.move(dx, dy);
        p3.move(dx, dy);
        p4.move(dx, dy);
    }

    void rotate(double angle) override {
        p1.rotate(angle);
        p2.rotate(angle);
        p3.rotate(angle);
        p4.rotate(angle);
    }

    double getX() const override {
        return p1.getX();
    }

    double getY() const override {
        return p1.getY();
    }
};

// Класс Прямоугольник
class Rectangle : public Square {
protected:
    ConcretePoint p5, p6;

public:
    Rectangle(double x, double y, double width, double height)
        : Square(x, y, width), p5(x + width, y + height), p6(x, y + height) {}

    void draw() const override {
        std::cout << "Drawing rectangle with corners at ("
            << p1.getX() << ", " << p1.getY() << "), ("
            << p2.getX() << ", " << p2.getY() << "), ("
            << p5.getX() << ", " << p5.getY() << "), ("
            << p6.getX() << ", " << p6.getY() << ")" << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing rectangle" << std::endl;
    }

    void move(double dx, double dy) override {
        Square::move(dx, dy);
        p5.move(dx, dy);
        p6.move(dx, dy);
    }

    void rotate(double angle) override {
        Square::rotate(angle);
        p5.rotate(angle);
        p6.rotate(angle);
    }
};

// Класс Треугольник
class Triangle : public Point {
private:
    ConcretePoint p1, p2, p3;

public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : p1(x1, y1), p2(x2, y2), p3(x3, y3) {}

    void draw() const override {
        std::cout << "Drawing triangle with corners at ("
            << p1.getX() << ", " << p1.getY() << "), ("
            << p2.getX() << ", " << p2.getY() << "), ("
            << p3.getX() << ", " << p3.getY() << ")" << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing triangle" << std::endl;
    }

    void move(double dx, double dy) override {
        p1.move(dx, dy);
        p2.move(dx, dy);
        p3.move(dx, dy);
    }

    void rotate(double angle) override {
        p1.rotate(angle);
        p2.rotate(angle);
        p3.rotate(angle);
    }

    double getX() const override {
        return p1.getX();
    }

    double getY() const override {
        return p1.getY();
    }
};

// Класс Ромб
class Rhombus : public Square {
public:
    Rhombus(double x, double y, double side) : Square(x, y, side) {}

    void draw() const override {
        std::cout << "Drawing rhombus with corners at ("
            << p1.getX() << ", " << p1.getY() << "), ("
            << p2.getX() << ", " << p2.getY() << "), ("
            << p3.getX() << ", " << p3.getY() << "), ("
            << p4.getX() << ", " << p4.getY() << ")" << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing rhombus" << std::endl;
    }
};

// Класс Параллелограмм с использованием виртуального наследования от Квадрата
class Parallelogram : public virtual Square {
private:
    double angle;

public:
    Parallelogram(double x, double y, double side, double angle)
        : Square(x, y, side), angle(angle) {}

    void draw() const override {
        std::cout << "Drawing parallelogram with corners at ("
            << p1.getX() << ", " << p1.getY() << "), ("
            << p2.getX() << ", " << p2.getY() << "), ("
            << p3.getX() << ", " << p3.getY() << "), ("
            << p4.getX() << ", " << p4.getY() << ") and angle " << angle << " degrees" << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing parallelogram" << std::endl;
    }

    void move(double dx, double dy) override {
        Square::move(dx, dy);
    }

    void rotate(double angle) override {
        Square::rotate(angle);
    }
};

int main() {
    ConcretePoint point(0, 0);
    point.draw();
    point.move(1, 1);
    point.draw();
    point.rotate(45);
    point.draw();
    point.erase();

    Line line(0, 0, 1, 1);
    line.draw();
    line.move(1, 1);
    line.draw();
    line.rotate(45);
    line.draw();
    line.erase();

    Square square(0, 0, 2);
    square.draw();
    square.move(1, 1);
    square.draw();
    square.rotate(45);
    square.draw();
    square.erase();

    Rectangle rectangle(0, 0, 2, 4);
    rectangle.draw();
    rectangle.move(1, 1);
    rectangle.draw();
    rectangle.rotate(45);
    rectangle.draw();
    rectangle.erase();

    Triangle triangle(0, 0, 1, 1, 0.5, 1.5);
    triangle.draw();
    triangle.move(1, 1);
    triangle.draw();
    triangle.rotate(45);
    triangle.draw();
    triangle.erase();

    Rhombus rhombus(0, 0, 2);
    rhombus.draw();
    rhombus.move(1, 1);
    rhombus.draw();
    rhombus.rotate(45);
    rhombus.draw();
    rhombus.erase();

    Parallelogram parallelogram(0, 0, 2, 30);
    parallelogram.draw();
    parallelogram.move(1, 1);
    parallelogram.draw();
    parallelogram.rotate(45);
    parallelogram.draw();
    parallelogram.erase();

    return 0;
}
