#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual void GetValues() {};
};

class Circle : public Figure {
protected:
    float r = 0;
    int x = 0, y = 0;
public:
    Circle() : Circle(rand() % 99, rand() % 99, rand() % 99) {};

    Circle(int x, int y, float r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }

    void GetValues() {
        std::cout << "R: " << r << " center: (" << x << ", " << y << ") " << std::endl;
    }
};

class Ellipse : public Circle {
protected:
    float rx = 0, ry = 0;
public:
    Ellipse() : Ellipse(rand() % 99, rand() % 99, rand() % 99, rand() % 99) {};

    Ellipse(int x, int y, float rx, float ry) {
        Circle::Circle(x, y, 0);
        this->rx = rx;
        this->ry = ry;
    }
    void GetValues() {
        std::cout << "rx: " << rx << " ry: " << ry << " center: (" << x << ", " << y << ") " << std::endl;
    }
};

class Line : public Figure {
protected:
    int x1, y1, x2, y2;
    float length;

    void GetLineSize() {
        length = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

public:
    Line() : Line(rand() % 99, rand() % 99, rand() % 99, rand() % 99) {}

    Line(int x1, int y1, int x2, int y2) {
        SetValues(x1, y1, x2, y2);
    }

    void SetValues(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        GetLineSize();
    }

    void GetValues() {
        cout << "Line length: " << length << " | Point 1: (" << x1 << ", " << y1 << ") | Point 2: (" << x2 << ", " << y2 << ")" << endl;
    }
};

class Square : public Line {
protected:
    float P = 0, S = 0;

    void GetPerimeter() {
        this->P = length * 4;
    }

    void GetSquare() {
        this->S = length * length;
    }

public:
    Square() : Square(rand() % 99, rand() % 99, rand() % 99, rand() % 99) {}

    Square(int x1, int y1, int x2, int y2) {
        SetValues(x1, y1, x2, y2);
    }

    void SetValues(int x1, int y1, int x2, int y2) {
        Line::SetValues(x1, y1, x2, y2);
        GetPerimeter();
        GetSquare();
    }

    void GetValues() {
        cout << "P: " << this->P << " | S: " << this->S << " | ";
        Line::GetValues();
    }
};

class Rectangle : public Square {
protected:
    void GetPerimeter() {
        this->P = (abs(x1 - x2) + abs(y1 - y2)) * 2;
    }

    void GetSquare() {
        this->S = abs(x1 - x2) * abs(y1 - y2);
    }

public:
    Rectangle() : Rectangle(rand() % 99, rand() % 99, rand() % 99, rand() % 99) {}

    Rectangle(int x1, int y1, int x2, int y2) {
        SetValues(x1, y1, x2, y2);
    }

    void SetValues(int x1, int y1, int x2, int y2) {
        Line::SetValues(x1, y1, x2, y2);
        GetPerimeter();
        GetSquare();
    }
};

int main() {
    Line l(1, 2, 13, 4);
    Square s;
    Rectangle r(1, 2, 13, 4);
    Circle c;
    Ellipse e(2, 13, 4, 7);

    l.GetValues();
    s.GetValues();
    r.GetValues();
    c.GetValues();
    e.GetValues();

    // Создаем динамический массив из 3 объектов класса Rectangle
    Rectangle* rectangles = new Rectangle[3];

    // Инициализируем объекты класса Rectangle
    rectangles[0] = Rectangle(1, 1, 4, 4);
    rectangles[1] = Rectangle(1, 1, 4, 4);
    rectangles[2] = Rectangle(1, 1, 4, 4);

    // выводим периметры и площади для всех объектов
    for (int i = 0; i < 3; i++) {
        rectangles[i].GetValues();
    }

    // Удаляем динамический массив
    delete[] rectangles;


    return 0;
}
