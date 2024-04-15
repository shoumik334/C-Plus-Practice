#ifndef BOX_H
#define BOX_H

class Box
{
    public:
    Box();
    Box (double ,double ,double );
    void setvalue(double,double,double);
    void getvalue();
    double volume();

    private:
    double height;
    double width;
    double depth;

};
//#endif

