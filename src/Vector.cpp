#include "Vector.h"
#include <fstream>
#include <cstdlib>
using namespace std;

Vector::Vector(int newrow, int newcolumn)
{
    row = newrow;
    column = newcolumn;
    //create array
    arr = new int[row*column];
    string test;
    int k = 0;
    int h = 0;
    int w;
    ifstream  st("problem.csv",ios::in);
    getline(st,test);
    //read matrix with cars in
    while(getline(st,test))
    {
        w = 0;
        h = 0;
        for (int i = 0; i < test.size(); i++)
        {
            if (test[i] == ','){
                arr[k*column + w] = atoi(test.substr(h,1).c_str());
                h = i+1;
                w++;
                }
            }
        arr[k*column + w] = atoi(test.substr(h,test.size()-h).c_str());
        k++;
    }
    st.clear();
    st.close();
}
//set value at given position
void Vector::setPos(int i,int j,int value){
    arr[column*i+j] = value;
    }

// returnsvalue at given position
int Vector::checkPos(int i,int j){
    return arr[column*i+j];
    }
// Writes the vector to a csv file
void Vector::writeFile(int name){
    stringstream ss;
    ss << name;
    string str = ss.str();
    str += ".csv";
    const char * c = str.c_str();
    ofstream outputf;
    outputf.open(c);
    for (int i = 0; i < this->row; i++){
        for (int j = 0; j < ((this->column)-1); j++){
            outputf << arr[column*i+j] << ",";
        }
        outputf << this->checkPos(i,column-1)<< "\n";
    }
    outputf.close();
    ss.clear();
}

int Vector::iterateRed(){
    for (int i = 0; i < row; i++){
        //bool to check if first position is free originally
        bool firstisFree = (this->checkPos(i, 0) == 0);
        for (int j = 0; j < this->column; j++)
        {
            if (this->checkPos(i,j)==2){
                if (j == this->column - 1 and !firstisFree) {
                    j++;
                }
                else if (this->checkPos(i,(j+1)%column) == 0)
                {
                    this->setPos(i,j,0);
                    this->setPos(i,(j+1)%column,2);
                    //jump an extra position
                    j++;

                }
            }

        }

    }
    return 1;
}

int Vector::iterateBlue(){
    for (int i = 0; i < column; i++){
        //bool to check if first position is free originally
        bool firstisFree = (this->checkPos(0, i) == 0);
        for (int j = 0; j < row; j++)
        {
            if (this->checkPos(j,i)==1){
                if (j == row - 1 and !firstisFree) {
                    break;
                }
                if (this->checkPos((j+1)%row,i) == 0)
                {
                    this->setPos(j,i,0);
                    this->setPos((j+1)%row,i,1);
                    //jump an extra position
                    j++;
                }
            }
        }

    }
    return 1;
}

void Vector::iterate(vector<int> steps){
    int i = 0;
        for (int j = 0; j < steps[i]+1; j++){
            // check to see if we need to write a file
            if (j == steps[i]){
                this->writeFile(steps[i]);
                i++;
                if (i == steps.size()){
                    break;
                    }
                }
            //move blue cars
            this->iterateBlue();
            j++;
            //check to see if we need to write a file
            if (j == steps[i]){
                this->writeFile(steps[i]);
                i++;
                if (i == steps.size()){
                    break;
                }
            }
            //move red cars
            this->iterateRed();
    }
}
void Vector::destroy(){
    delete arr;
}

