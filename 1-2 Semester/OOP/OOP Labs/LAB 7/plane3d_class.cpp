#include<iostream>
#include<cmath>
using namespace std;
#include"Point3d.h"
class plane3d
{
	protected:
		float a,b,c,d;
	public:
		plane3d(float _a,float _b,float _c,float _d)
		{
			this->a=_a;
			this->b=_b;
			this->c=_c;
			this->d=_d;
		}
		bool ispointonplane(const Point3d& point)
		{
			return (abs(a*point.getX() + b*point.getY() + c*point.getZ() + d)==0);
		}
		bool operator==(const plane3d & other)
		{
			double ratioA = a / other.a;
            double ratioB = b / other.b;
            double ratioC = c / other.c;
            double ratioD = d / other.d;
			return (ratioA==ratioB&&ratioA==ratioC&&ratioA==ratioD&&
			        ratioB==ratioC&&ratioB==ratioD&&
					ratioC==ratioD );
		}
		bool isParallel(const plane3d & other)
		{
			double ratioA = a / other.a;
            double ratioB = b / other.b;
            double ratioC = c / other.c;
            
			return (ratioA==ratioB&&ratioA==ratioC&&ratioB==ratioC );
		}
		double distanceFromPoint(const Point3d& point)
		{
			double num=abs(a*point.getX() + b*point.getY() + c*point.getZ() + d);
			double den=sqrt(a*a+b*b+c*c);
			return num/den;
		}
		
};

int main()
{
	plane3d plane1(1, 2, 3, 4);
    plane3d plane2(2, 4, 6, 8);
    Point3d point(1, -1, 1);

    cout << "Point lies on plane1: " << (plane1.ispointonplane(point) ? "Yes" : "No") << endl;
    cout << "Plane1 equals Plane2: " << (plane1 == plane2 ? "Yes" : "No") << endl;
    cout << "Plane1 is parallel to Plane2: " << (plane1.isParallel(plane2) ? "Yes" : "No") <<endl;
    cout << "Distance of point from Plane1: " << plane1.distanceFromPoint(point) << endl;


}