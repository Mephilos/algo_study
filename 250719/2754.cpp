#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, double> score_map;

    score_map["A+"] = 4.3; 
    score_map["A0"] = 4.0; 
    score_map["A-"] = 3.7;
    score_map["B+"] = 3.3; 
    score_map["B0"] = 3.0; 
    score_map["B-"] = 2.7;
    score_map["C+"] = 2.3; 
    score_map["C0"] = 2.0; 
    score_map["C-"] = 1.7;
    score_map["D+"] = 1.3; 
    score_map["D0"] = 1.0; 
    score_map["D-"] = 0.7;
    score_map["F"] = 0.0;

    string grade;
    cin >> grade;

    cout << fixed;
    cout.precision(1);
    cout << score_map[grade] << '\n';

}