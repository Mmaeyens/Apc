#include "Vector.h"
#include <omp.h>
#include <fstream>
#include <cstdlib>
#include <mpi.h>
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
    int tag = 666;
    MPI_Comm_rank(MPI_COMM_WORLD, &tid);
    MPI_Comm_size(MPI_COMM_WORLD, &nthreads);
    for (int k=0; k < nthreads;k++){
        if (k== tid){
            for (int i = 0; i < column/nthreads + (column%nthreads)/(tid+1); i++){
                for (int j = 0; j < this->column; j++){
                    if (this->checkPos(i*nthreads + tid,j)==2){
                        if (this->checkPos(i*nthreads + tid,(j+1)%column) == 0){
                            this->setPos(i*nthreads + tid,j,0);
                            this->setPos(i*nthreads + tid,(j+1)%column,2);
                            j++;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int Vector::iterateBlue(){
    int nthreads, tid;
    int tag = 666;
    MPI_Comm_rank(MPI_COMM_WORLD, &tid);
    MPI_Comm_size(MPI_COMM_WORLD, &nthreads);
    for (int k=0; k< nthreads;k++){
        if (k== tid){
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
    }
    return 1;
}
//need different scatters for red and blue
//Either make different vectors to store displacements for row or column
//or go thread approach
void Vector::iterate(vector<int> steps){
    MPI_Init(NULL,NULL);

//    int nthreads;
//    MPI_Init (&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &nthreads);
//    int countscolumn[nthreads] = {0};
//    int displacementscolumn[nthreads] = {0};
//    for (int i = 0; i<column;i++){
//        counts[i%nthreads] += column;
//    }
//    int sumcolumn = 0;
//    for (int i = 0; i < nodes; i++){
//        displacementscolumn[i] = sumcolumn;
//        sumcolumn += countscolumn[i];
//    }
//    int countsrow[nthreads] = {0};
//    int displacementsrow[nthreads] = {0};
//    for (int i = 0; i<row;i++){
//        counts[i%nthreads] += row;
//    }
//    int sumrow = 0;
//    for (int i = 0; i < nodes; i++){
//        displacementsrow[i] = sumrow;
//        sumrow += countsrow[i];
//    }
//    int *rec_buf = new int[79];
//    MPI_Scatterv(&arr, counts, displacements, MPI_INT, rec_buf, counts[tid], MPI_INT, 0, MPI_COMM_WORLD);
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
    MPI_Finalize();
}
void Vector::destroy(){
    delete arr;
}

