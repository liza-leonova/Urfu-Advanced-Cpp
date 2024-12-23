#include "figures.hpp"
#include <cmath>

Rect::Rect(double width, double height) : width(width), height(height) {}

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return 2 * (width + height);
}

double Rect::Area() const {
    return width * height;
}

Triangle::Triangle(double sideA, double sideB, double sideC) 
    : sideA(sideA), sideB(sideB), sideC(sideC) {}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return sideA + sideB + sideC;
}

double Triangle::Area() const {
    double semiPerimeter = Perimeter() / 2;
    return std::sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
}

Circle::Circle(double radius) : radius(radius) {}

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const {
    return 2 * PI * radius;
}

double Circle::Area() const {
    return PI * radius * radius;
}

std::unique_ptr<Figure> make_figure(FigureType type, double paramA, double paramB, double paramC) {
    if (paramA < 0 || paramB < 0 || paramC < 0) {
        throw LessThanZeroParam("One or more parameters are less than zero");
    }

    switch (type) {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(paramA, paramB);
        
        case FigureType::TRIANGLE:
            if (paramA + paramB <= paramC || paramB + paramC <= paramA || paramA + paramC <= paramB) {
                throw WrongTriangle("Invalid triangle sides");
            }
            return std::make_unique<Triangle>(paramA, paramB, paramC);
        
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(paramA);
        
        default:
            return nullptr;
    }
}
