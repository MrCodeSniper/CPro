# pragma warning (disable:4819)
#include <iostream>

using namespace std;

class Line {
public:
    void setLength(double len);
    double getLength();
    Line();
    Line(double len);
    Line(int a,int b,int c);
    //xi gou method execute as object go delete
    ~Line();

private:
    double mLength;
    int x;
    int y;
    int z;
};

Line::Line(void){
    cout << "Object is being created"  << endl;
}

//as main method excute finish
Line::~Line(void) {
    cout << "Object is being deleted" << endl;
}

//constructor and init x=a y=b z=c
Line::Line(int a,int b,int c):x(a),y(b),z(c) {
    cout << "Object is being createdz: " << x <<"," << y <<"," << z << endl;
}

Line::Line(double len)
{
    cout << "Object is being created, length = " << len << endl;
    mLength = len;
}
void Line::setLength( double len )
{
    mLength = len;
}

double Line::getLength( void )
{
    return mLength;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    //one param constructor
    Line line(232.55);
    line.setLength(15.66);
    cout << "Length of line : " << line.getLength() <<endl;

    //No param constructor
    Line line2;
    line2.setLength(100);
    cout << "Length of line : " << line2.getLength() <<endl;


    Line line3(1,10,9);
    return 0;
}


