#include "Vector.h"
#include <omp.h>
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
    ifstream  st("problem.csv");
    getline(st,test);
    //read matrix with cars in
    while(getline(st,test))
    {
        count = 0;
        h = 0;
        for (int i = 0; i < test.size(); i++)
        {
            if (test[i] == ','){
                this->arr[k*column + count] = atoi(test.substr(h,1).c_str());
                h = i+1;
                count++;
                }
            }
        this->arr[k*column + count] = atoi(test.substr(h,test.size()-h).c_str());
        k++;
    }

}
void Vector::setPos(int i,int j,int value){
    arr[column*i+j] = value;
    }


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
    int nthreads, tid;
    #pragma omp parallel private(tid)
    {

    nthreads = omp_get_num_threads();
    tid = omp_get_thread_num();
    for (int i = 0; i < column/nthreads + (column%nthreads)/(tid+1); i++){
        for (int j = 0; j < this->column; j++)
        {
            if (this->checkPos(i*nthreads + tid,j)==2){
                if (this->checkPos(i*nthreads + tid,(j+1)%column) == 0)
                {
                    this->setPos(i*nthreads + tid,j,0);
                    this->setPos(i*nthreads + tid,(j+1)%column,2);
                    j++;
                }
            }
        }
    }
    }
    return 1;
}

int Vector::iterateBlue(){
    int nthreads, tid;
    /* Fork a team of threads with each thread having a private tid variable */
    #pragma omp parallel private(tid)
    {
    nthreads = omp_get_num_threads();
    tid = omp_get_thread_num();
    for (int i = 0; i < column/nthreads + (column%nthreads)/(tid+1); i++){
        for (int j = 0; j < row; j++)
        {
            if (this->checkPos(j,i*nthreads + tid)==1){
                if (this->checkPos((j+1)%row,i*nthreads + tid) == 0)
                {
                    this->setPos(j,i*nthreads + tid,0);
                    this->setPos((j+1)%row,i*nthreads + tid,1);
                    j++;
                }
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

