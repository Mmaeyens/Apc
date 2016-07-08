

#include <fstream>
#include <stdlib.h>
#include <ostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include "Vector.h"
using namespace std;

// Parses a string to get the steps out of it.
vector<int> parse(string info,int j){
    int grootte = j;
    vector<int> steps(grootte);
    int h=0;
    int w= 0;
        for (int i = 0; i < info.size(); i++){
            if (info[i] == ',') {
                steps[w] = atoi(info.substr(h,i-h).c_str());
                h = i+1;
                w++;
            }
        }
        steps[w] = atoi(info.substr(h,info.size()-h).c_str());
        return steps;
}

int main()
{
    int i,j;
    ifstream  data("problem.csv",ios::in);
    string line,info,number;
    // Read the first line
    getline(data,info);
    i = 0;
    j = 0;
    // Get the amount of columns and rows.
    while(getline(data, line)){
        istringstream streamline(line);
        if (i == 0) {
            while(getline(streamline, number, ',')){
                ++j;
            }
        }
        ++i;
    }
    data.clear();
    data.close();
    //Get steps from the first line
    vector<int> steps = parse(info,j);
    //Create vector
    Vector vec(i,j);

    //Iterate over vector
    vec.iterate(steps);
    //delete the vector
    vec.destroy();
    return 0;
    }



