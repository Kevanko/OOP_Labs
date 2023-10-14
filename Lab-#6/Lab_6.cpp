#include <iostream>
#include <cmath>

using namespace std;

int rand_() {
    return rand() % 10;
}

class Figure {
public:
    virtual void GetValues() = 0;
    virtual ~Figure() {};
};

class Circle : public Figure {
private:
    float r = 0;
protected:
    int x = 0, y = 0;
public:
    Circle() : Circle(rand_(), rand_(), rand_()) {};
    Circle(int x, int y, float r) : x(x), y(y), r(r) {};

    void GetValues() {
        std::cout << "[Circle]\tR: " << r << "\t| center: (" << x << ", " << y << ") " << std::endl;
    }
};

class Ellipse : public Circle {
private:
    float rx = 0, ry = 0;
public:
    Ellipse() : Ellipse(rand_(), rand_(), rand_(), rand_()) {};
    Ellipse(int x, int y, float rx, float ry) : rx(rx), ry(ry) { this->x = x, this->y = y; };

    void GetValues() {
        std::cout << "[Ellipse]\tRx: " << rx << "\t| Ry:" << ry <<"\t| center: (" << x << ", " << y << ") " << std::endl;
    }
};

class Line : public Figure {
private:
    float line_len = 0;

protected:
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    float GetLength(int x1, int y1, int x2, int y2) {
        float len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        return len;
    }

public:
    Line() : Line(rand_(), rand_(), rand_(), rand_()) {};
    Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2), line_len(GetLength(x1, y1, x2, y2)) {};
    void GetValues() {
        cout << "[Line]  \tLength: " << line_len << "\t| Point 1: (" << x1 << ", " << y1 << ")\t| Point 2: (" << x2 << ", " << y2 << ")" << endl;
    }

};

class Square : public Line {
protected:
    float S = 0, P = 0;

    float GetSquare(float first_side, float second_side) {
        return first_side * second_side;
    }

    float GetPerimetr(float first_side, float second_side) {
        return (first_side + second_side) * 2;
    }

public:
    Square() : Square(rand_(), rand_(), rand_(), rand_()) {};
    Square(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        float side_len = GetLength(x1, y1, x2, y2);
        S = GetSquare(side_len, side_len);
        P = GetPerimetr(side_len, side_len);
    };
    void GetValues() {
        cout << "[Square]\tS: " << S << "\t| P:" << P << "\t| Point 1: (" << x1 << ", " << y1 << ")\t| Point 2: (" << x2 << ", " << y2 << ")" << endl;
    }
};

class Rectangle : public Square {
private:
    static int createdCount;
    static int existingCount;

public:
    Rectangle() : Rectangle(rand_(), rand_(), rand_(), rand_()) {};

    Rectangle(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        float first_side = abs(x1 - x2), second_side = abs(y1 - y2);
        S = GetSquare(first_side, second_side);
        P = GetPerimetr(first_side, second_side);
        createdCount += 1;
        existingCount += 1;
    };

    void GetValues() {
        cout << "[Rectangle]\tS: " << S << "\t| P:" << P << "\t| Point 1: (" << x1 << ", " << y1 << ")\t| Point 2: (" << x2 << ", " << y2 << ")" << endl;
    }

    static int GetCreatedCount() {
        return createdCount;
    };

    static int GetExistingCount() {
        return existingCount;
    };

    ~Rectangle() {
        existingCount -= 1;
    }
};

int Rectangle::createdCount = 0;
int Rectangle::existingCount = 0;

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

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    Rectangle* pr;

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    pr = new Rectangle;

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    Figure* pf[4];
    pf[0] = new Square;
    pf[1] = new Rectangle;
    pf[2] = new Circle;
    pf[3] = new Ellipse;

    for (int i = 0; i < 4; i++) {
        pf[i]->GetValues();
    }

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;
    for (int i = 0; i < 4; i++) {
        delete pf[i];
    }

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    return 0;
}
