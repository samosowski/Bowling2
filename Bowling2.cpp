//Samantha Osowski 
//Week 7 Programming Assignment
//In this program we will calculate a bowling league's average bowling score
//We will then modify week 6 assignment to sotre an array to store to bowlers scores 

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//creating a struct for bowlers scores
struct Bowler {
    string name;
    int scores[5]{};
    int avgScore{};
};
//calling functions
bool GetBowlingData(const string& fileName, Bowler bowlers[], int& count);
void GetAverageScore(Bowler bowlers[], int count);
void PrettyPrintResults(Bowler bowlers[], int count);

int main() {
//declaring variables
    int count = 0;

//setting the file and bowlers
    string fileName = "BowlingScores.txt";
    Bowler bowlers[100];

//getting the file
    if (GetBowlingData(fileName, bowlers, count)) {
            GetAverageScore(bowlers, count);
            PrettyPrintResults(bowlers, count);
        }
    else {
    }
return 0;
}

//getting the data from the file or ending if failed to open 
bool GetBowlingData(const string& fileName, Bowler bowlers[], int& count) {
    ifstream infile;
    infile.open("BowlingScores.txt");
    if (infile.fail()) {
        return false;
    }
    else {
        while (infile >> bowlers[count].name) {
            for (int& score : bowlers[count].scores) {
                infile >> score;
            }
            count++;
        }
        infile.close();
    }
    return true;

}

//getting the average scores of players using array 
void GetAverageScore(Bowler bowlers[], int count) {
    double total;
    for (int i = 0; i < count; i++) {
        total = 0;
        for (int score : bowlers[i].scores) {
            total += score;
        }
        bowlers[i].avgScore = (int)(total / 4);
    }
}

//printing the results using array
void PrettyPrintResults(Bowler bowlers[], int count) {
    cout << left << setw(15) << "Name" << "Score 1\t Score 2\t Score 3\t Score 4\t Score 5\t Average Score" << endl;

    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << bowlers[i].name;
        for (int score : bowlers[i].scores) {
            cout << score << "\t";
        }
        cout << bowlers[i].avgScore << endl;
    }
}

