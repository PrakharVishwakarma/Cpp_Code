#include <iostream>
using namespace std;
class Demo
{
public:
    int a;
    int b;
    int *p;

    Demo()
    {
        p = new int;
    }
    Demo(const Demo &srcobj)
    {
        this->a = srcobj.a;

        this->b = srcobj.b;
        
        this->p = new int;
        *this->p = *(srcobj.p);
    }
    void setdata(int x, int y, int z)
    {
        a = x;
        b = y;
        *p = z;
    }
    void showdata()
    {
        std::cout << "value of a is : " << a << std::endl;
        std::cout << "value of b is : " << b << std::endl;
        std::cout << "value of *p is : " << *p << std::endl;
    }
};
int main()
{
    Demo d1;
    d1.setdata(4, 5, 7);
    d1.showdata();
    cout<<endl;
    Demo d2 = d1;
    d2.showdata();
    return 0;
}