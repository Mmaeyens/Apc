

#include <fstream>
#include <stdlib.h>
#include <ostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include "Vector.h"
using namespace std;
// counts the commas in a string
int count_comma(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == ',') count++;
        return count;
}


// Parses a string to get the steps out of it.
vector<int> parse(string info){
    int grootte = count_comma(info);
    grootte = grootte + 2;
    vector<int> steps(grootte);
    int h=0;
    int count = 0;
        for (int i = 0; i < info.size(); i++){
            if (info[i] == ',') {
                steps[count] = atoi(info.substr(h,i-h).c_str());
                h = i+1;
                count++;
            }
        }
        steps[count] = atoi(info.substr(h,info.size()-h).c_str());

        return steps;

}
int main()
{
    int i,j;
    ifstream  data("problem.csv");
    string line,info;
    // Read the first line
    getline(data,info);
    i = 0;
    // Get the amount of columns and rows.
    while(getline(data,line))
    {
        i+=1;
        }

    j = count_comma(line) + 1;
    data.clear();
    data.close();
    //Get steps from the first line
    vector<int> steps = parse(info);
    //Create vector
    Vector vec(i,j);
    //Iterate over vector
    vec.iterate(steps);
    vec.destroy();
    return 0;
    }


