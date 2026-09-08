#include<bits/stdc++.h>
using namespace std;

class Exams{
    private:
        string name;
        vector<float> marks;
    public:
        Exams(string n, vector<float> m){
            name = n;
            marks= m;
            
        }

        string getName(){return name;}
        float calCGPA(){
            float sum = 0;
            for(float val: marks){
                sum += val;
            }
            float cgpa = sum / marks.size();
            return cgpa;
        }
};

int main(){
    Exams* studentsExams = new Exams[5]{
        {"Ali", {3.66, 3.33, 4.0, 3.0, 2.66}},
        {"Hiba", {3.33, 3.0, 3.66, 3.0}},
        {"Asma", {4.0, 3.66, 2.66}},
        {"Zain", {2.66, 2.33, 4.0}},
        {"Faisal", {3.33, 3.66, 4.0, 3.0, 3.33}}
    };

    cout << fixed << setprecision(2);

    for (int i = 0; i < 5; i++)
    {
      cout << "CGPA of " << studentsExams[i].getName() << " is " << studentsExams[i].calCGPA() << endl;  
    }
    
    
      delete[] studentsExams;  
    
    
    return 0;
}