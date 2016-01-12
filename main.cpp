#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ostream>
#include <cstdlib>
#include <sstream>
using namespace std;
int count_comma(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++)
            if (s[i] == ',') count++;

        return count;
}

vector<vector<int> > create_vector(int z,int j)
{
    string test;
    cout << z;
    int k = 0;
    int h = 0;
    vector<vector<int> > vec(z,vector<int>(j));
    ifstream  st("twee.csv");
    getline(st,test);
    while(getline(st,test))
    {
        int count = 0;
        cout << test << "\n";
        h = 0;
        for (int i = 0; i < test.size(); i++)
        {
            if (test[i] == ','){
                vec[k][count] = atoi(test.substr(h,1).c_str());
                h = i+1;
                count++;
                }
            }
        vec[k][count] = atoi(test.substr(h,test.size()-h).c_str());

        k++;
    }
    return vec;
}

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
int write(vector<vector<int> > vec,int name){
    stringstream ss;
    ss << name;
    string str = ss.str();
    str += ".csv";
    const char * c = str.c_str();
    cout << "name" << name;
    cout << str;
    ofstream outputf;
    outputf.open(c);
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < (vec[0].size()-1); j++){
            outputf << vec[i][j] << ",";
        }
        outputf << vec[i][(vec[0].size()-1)] << "\n";
    }

    outputf.close();
    return 0;
}




vector<vector<int> > iteratered(vector<vector<int> > vec){

    vector<vector<int> > second(vec);
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == 2){
                if (vec[i][(j+1)%(vec[0].size())] == 0)
                {
                    second[i][j] = 0;
                    second[i][(j+1)%(vec[0].size())] = 2;
                }
            }
        }
    }
    return second;
}

vector<vector<int> > iterateblue(vector<vector<int> > vec){

    vector<vector<int> > second(vec);
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == 1){
                if (vec[(i+1)%(vec.size())][j] == 0)
                {
                    second[i][j] = 0;
                    second[(i+1)%(vec.size())][j] = 1;
                }
            }
        }
    }
    return second;
}

vector<vector<int> > iterate(vector<vector<int> > vec,string info){
    vector<int> steps = parse(info);
    cout << "steps" << steps.size();
    int i = 0;
        for (int j = 0; j < steps[i]+1; j++){
        cout << "shizzle" << j;
            if (j == steps[i]){
                write(vec,steps[i]);
                i++;
                cout << "steps2" << i;
                if (i == steps.size()){

                    break;
                    }
                }
            vec = iterateblue(vec);
            j++;
            if (j == steps[i]){
                write(vec,steps[i]);
                i++;
                cout << "steps2" << i;
                if (i == steps.size()){

                    break;
                }
            }
            vec = iteratered(vec);


    }
    return vec;
}

int main()
{
    int i,j;
    ifstream  data("twee.csv");
    string line,info;
    getline(data,info);

    cout << info << "\n";
    i = 0;
    while(getline(data,line))
    {
        i+=1;
        }

    j = count_comma(line) + 1;

    free(data);
    vector<vector<int> > vec = create_vector(i,j);
    iterate(vec,info);
    return 0;
    }



