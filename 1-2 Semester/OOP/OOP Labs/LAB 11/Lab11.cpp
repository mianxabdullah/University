#include <iostream>
#include <cmath>
using namespace std;

const int MAX_RECTANGLES = 100;
const float PI = 3.141592653589793f;
enum color{black, blue, green, red, white, yellow};

class shapes 
{
  public:
  color c;
  shapes()
  {
    c=black;
  }
  void setColor(color cl)
  {
    c=cl;
  }
  string getColor()
  {
    if(c==black) return "black";
    else if(c==blue) return "blue";
    else if(c==green) return "green";
    else if(c==red) return "red";
    else if(c==white) return "white";
    else if(c==yellow) return "yellow";
    else throw 99;
  }

};

class Point2D {
public:
    float x;
    float y;

    Point2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const Point2D& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

class Rectangle : public shapes
{
private:
    Point2D topLeft;
    float width;
    float height;

public:
    Rectangle(const Point2D& tl = Point2D(), float w = 0.0f, float h = 0.0f)
        : topLeft(tl), width(w), height(h) {}

    float area() const {
        return width * height;
    }

    float perimeter() const {
        return 2 * (width + height);
    }
    
    void display()
    {
       cout <<"Rectangle at " << topLeft
           << ", width: " << width
           << ", height: " << height
           << ", area: " << area()
           << ", perimeter: " << perimeter()
           << ", color: "<< getColor();
    }

    friend ostream& operator<<(ostream& os, const Rectangle& rect) {
        os << "Rectangle at " << rect.topLeft
           << ", width: " << rect.width
           << ", height: " << rect.height
           << ", area: " << rect.area()
           << ", perimeter: " << rect.perimeter();
        return os;
    }
};

class Circle {
private:
    Point2D center;
    float radius;

public:
    Circle(const Point2D& c = Point2D(), float r = 0.0f)
        : center(c), radius(r) {}

    float area() const {
        return PI * radius * radius;
    }

    float perimeter() const {  // Circumference
        return 2 * PI * radius;
    }

    friend ostream& operator<<(ostream& os, const Circle& circle) {
        os << "Circle at " << circle.center
           << ", radius: " << circle.radius
           << ", area: " << circle.area()
           << ", perimeter: " << circle.perimeter();
        return os;
    }
};

class Canvas : public shapes
{
private:
    Rectangle rectangles[MAX_RECTANGLES];
    int count;

public:
    Canvas() : count(0) {}

    bool addRectangle(const Rectangle& rect) {
        if (count < MAX_RECTANGLES) {
            rectangles[count++] = rect;
            return true;
        }
        return false;
    }
    
    friend ostream& operator<<(ostream& os, const Canvas& canvas) {
        os << "Canvas contains " << canvas.count << " rectangles:\n";
        for (int i = 0; i < canvas.count; ++i) {
            os << "  " << canvas.rectangles[i] << "\n";
        }
        return os;
    }
    void setColor(int i,color clr)
    {   
        if(i<=MAX_RECTANGLES)  rectangles[i].setColor(clr);
    }

    void display()
    {
      for(int i=0;i<count;i++)
      {
        rectangles[i].display();
        cout<<endl;
      }
    }

};


// Example usage
int main() {
    Canvas canvas;

    // Add multiple rectangles
    canvas.addRectangle(Rectangle(Point2D(0, 0), 5, 10));
    canvas.addRectangle(Rectangle(Point2D(2, 3), 3, 6));
    canvas.addRectangle(Rectangle(Point2D(5, 5), 4, 4));
    canvas.addRectangle(Rectangle(Point2D(-2, -1), 2, 8));
    canvas.addRectangle(Rectangle(Point2D(10, 0), 6, 3));
    canvas.setColor(1,blue);
    canvas.setColor(0,green);
    canvas.setColor(3,red);
    // Output canvas and circle info
   // cout << "Canvas info: " << canvas << endl;
    canvas.display();
    // Create a circle separately
    Circle c1(Point2D(1, 1), 4);
    cout << "Circle info: " << c1 << endl;
    
   

    return 0;
}
