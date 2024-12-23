#pragma once

#include <memory>
#include <stdexcept>

// Make PI accessible to tests and other code
constexpr double PI = 3.14;

enum class FigureType {
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual ~Figure() = default;  // Add virtual destructor for proper cleanup
    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect : public Figure {
private:
    double width;
    double height;

public:
    Rect(double width, double height);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Triangle : public Figure {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double sideA, double sideB, double sideC);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double radius);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

std::unique_ptr<Figure> make_figure(FigureType type, double paramA, double paramB = 0, double paramC = 0);

class WrongTriangle : public std::invalid_argument {
public:
    using std::invalid_argument::invalid_argument;
};

class LessThanZeroParam : public std::invalid_argument {
public:
    using std::invalid_argument::invalid_argument;
};
