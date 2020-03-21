# pragma warning (disable:4819)
#include <iostream>
#include <thread>         // std::thread
#include <mutex>          // std::mutex

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



/**
 * facotry model
 * @return
 */

enum class shape_type{
    circle,triangle,rectangle
};

class shape{
private:
    int width;
    int height;
};


class circle:public shape{
    int radius;
};

class triangle:public shape{
    int angle;
};

class rectange:public shape{
    int volume;
};


//this one should take memory leak  we should wrap
shape* create_shape(shape_type types){
    switch (types){
        case  shape_type::circle:
            return new circle();
        case  shape_type::triangle:
            return new triangle();
        case  shape_type::rectangle:
            return new rectange();
    }
}

//
class shape_wrapper{
public:
    //construct and init ptr_=passing ptr
    explicit shape_wrapper( shape* ptr = nullptr) : ptr_(ptr) {}

    ~shape_wrapper(){
        delete ptr_;
    }

    //const like java final cannot modify
    shape* get() const {
        return ptr_;
    }
private:
    shape* ptr_;
};




std::mutex mtx;
void some_func(){
    mtx.lock();
    // 做需要同步的工作……
    // 如果发生异常或提前返回，
    // 下面这句不会自动执行。
    mtx.unlock();
}


void test(){
    shape_wrapper wrapper=shape_wrapper(create_shape(shape_type::circle));
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






























