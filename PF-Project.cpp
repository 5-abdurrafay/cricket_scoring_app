#include<iostream>
using namespace std;

int main() {
    int n, score = 0, j;
    int balls = 0;
    string batsman1 = "", batsman2 = "", striker;
    int runs1 = 0, runs2 = 0;

    do {
        cout << "\n1. Start Scoring" << endl
             << "2. Show Scorecard" << endl
             << "3. Exit" << endl;
        cin >> j;

        if(j == 1) {
            if (batsman1 == "" && batsman2 == "") {
                cout << "Enter name of Batsman 1: ";
                cin >> batsman1;
                cout << "Enter name of Batsman 2: ";
                cin >> batsman2;
                cout << "Who is on strike? (" << batsman1 << "/" << batsman2 << "): ";
                cin >> striker;
            }

            do {
                cout << "Enter score (0-6), 7 for wide, 8 for OUT, 9 to stop scoring: ";
                cin >> n;

                if(n >= 0 && n <= 6) {
                    score += n;

                    if(striker == batsman1) {
                        runs1 += n;
                    } else if(striker == batsman2) {
                        runs2 += n;
                    }
                    balls++;
                    if(n % 2 == 1) {
                        if(striker == batsman1)
                            striker = batsman2;
                        else
                            striker = batsman1;
                    }
                    if(balls % 6 == 0) {
                        if(striker == batsman1)
                            striker = batsman2;
                        else
                            striker = batsman1;
                    }

                } else if(n == 7) {
                    score += 1;
                } else if(n == 8) {
                    string outBatsman, newBatsman;
                    cout << "Who is out? (" << batsman1 << " or " << batsman2 << "): ";
                    cin >> outBatsman;

                    if(outBatsman == batsman1) {
                        cout << "Enter new batsman name: ";
                        cin >> newBatsman;
                        batsman1 = newBatsman;
                        runs1 = 0;
                        striker = batsman1;
                    }
                    else if(outBatsman == batsman2) {
                        cout << "Enter new batsman name: ";
                        cin >> newBatsman;
                        batsman2 = newBatsman;
                        runs2 = 0;
                        striker = batsman2;
                    }
                    else {
                        cout << "Invalid batsman name entered!" << endl;
                    }

                    balls++;
                } else if(n != 9) {
                    cout << "Invalid input. Try again.\n";
                }

            } while(n != 9);
        }

        else if(j == 2) {
            int overs = balls / 6;
            int remBalls = balls % 6;

            cout << "\n=== SCORECARD ===" << endl;
            cout << "Total Score: " << score << " in " << overs << "." << remBalls << " overs." << endl;
            if(batsman1 != "") cout << batsman1 << ": " << runs1 << " runs" << (striker == batsman1 ? " (on strike)" : "") << endl;
            if(batsman2 != "") cout << batsman2 << ": " << runs2 << " runs" << (striker == batsman2 ? " (on strike)" : "") << endl;
            
        }

    } while(j != 3);

    return 0;
}
