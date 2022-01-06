#ifndef FUNCTION_HPP
#define FUNCTION_HPP

class Demo{
public:
    Demo(){x = 1;}
    virtual ~Demo(){}
    
    int MulX(int a);
    void AddX(int a);
    void SetX(int a);
    int GetX();

private:
    int x;
};

#endif