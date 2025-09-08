#include<iostream>

class Point{
public:
    int x;
    int y;

    Point(int a = 0, int b = 0) : x(a), y(b) {
    }

    Point operator+(const Point& other){
        return(Point(x + other.x, y + other.y));
    }

    void ShowData()
    {
        std::cout<<"X = "<< x << " Y = " << y <<std::endl;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(4, 4);

    Point p3 = p1 + p2;

    p3.ShowData();

    return 0;
}
