#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
class Vector
{
    public:
        Vector(int column, int row);
        void iterate(std::vector<int> steps);
        int iterateBlue();
        int iterateRed();
        int checkPos(int i,int j);
        void setPos(int i, int j,int value);
        void writeFile(int name);
        void destroy();
    protected:

    private:
        int column, row, *arr;

};

#endif // VECTOR_H
