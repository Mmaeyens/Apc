#include "Vector.h"

#include <fstream>
#include <cstdlib>
using namespace std;

Vector::Vector(int i, int j)
{
    row = i;
    column = j;
    arr = new int[row*column];
    string test;
    int k = 0;
    int h = 0;
    int count;
    ifstream  st("twee.csv");
    getline(st,test);
    while(getline(st,test))
    {
        count = 0;
        h = 0;
        for (int i = 0; i < test.size(); i++)
        {
            if (test[i] == ','){
                this->arr[k*column + count] = atoi(test.substr(h,1).c_str());
                cout << arr[k*column + count];
                h = i+1;
                count++;
                }
            }
        this->arr[k*column + count] = atoi(test.substr(h,test.size()-h).c_str());
        cout << arr[k*column + count] << "\n";
        k++;
    }

}
void Vector::setPos(int i,int j,int value){
    arr[column*i+j] = value;
    }


int Vector::checkPos(int i,int j){
    return arr[column*i+j];
    }

void Vector::writeFile(int name){
    cout << "lets write \n";
    stringstream ss;
    ss << name;
    string str = ss.str();
    str += ".csv";
    const char * c = str.c_str();
    ofstream outputf;
    outputf.open(c);
    for (int i = 0; i < this->row; i++){
        for (int j = 0; j < ((this->column)-1); j++){
            cout << arr[column*i+j];
            outputf << arr[column*i+j] << ",";
        }
        cout << arr[column*i+column -1] << "last \n";
        outputf << this->checkPos(i,column-1)<< "\n";
    }


    outputf.close();
    ss.clear();
}

int Vector::iterateRed(){
    for (int i = 0; i < this->row; i++){
        for (int j = 0; j < this->column; j++)
        {
            if (this->checkPos(i,j)==2){
                if (this->checkPos(i,(j+1)%this->column) == 0)
                {
                    this->setPos(i,j,0);
                    this->setPos(i,(j+1)%this->column,2);
                    j++;
                }
            }
        }
    }
    return 1;
}

int Vector::iterateBlue(){
    for (int i = 0; i < this->column; i++){
        for (int j = 0; j < this->row; j++)
        {
            if (this->checkPos(j,i)==1){
                if (this->checkPos((j+1)%row,i) == 0)
                {
                    this->setPos(j,i,0);
                    this->setPos((j+1)%row,i,1);
                    j++;
                }
            j++;
            }
        }
    }
    return 1;
}

void Vector::iterate(vector<int> steps){
    int i = 0;
        for (int j = 0; j < steps[i]+1; j++){
            cout <<  "eerste \n";
            if (j == steps[i]){
                this->writeFile(steps[i]);
                i++;
                if (i == steps.size()){

                    break;
                    }
                }
            this->iterateBlue();
            j++;
            if (j == steps[i]){
                this->writeFile(steps[i]);
                i++;
                if (i == steps.size()){

                    break;
                }
            }
            this->iterateRed();


    }
}
void Vector::destroy(){
    delete arr;
}

