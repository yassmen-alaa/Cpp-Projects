#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m, int s) {
        if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hour = h;
            minute = m;
            second = s;
        } else {
            hour = 0;
            minute = 0;
            second = 0;
            cout << "Invalid time input! Defaulted to 00:00:00." << endl;
        }
    }

    void displayTime() const {
        cout << setfill('0') << setw(2) << hour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << endl;
    }

    bool tick() {
        second++;
        if (second == 60) {
            second = 0;
            minute++;
            if (minute == 60) {
                minute = 0;
                hour++;
                if (hour == 24) {
                    return false;
                }
            }
        }
        return true;
    }

    void run() {
        while (true) {
            system("cls");
            displayTime();
            Sleep(1000);

            if (!tick()) {
                cout << "\nDay has ended!" << endl;
                break;
            }
        }
    }
};

int main() {
    cout << "Simple Clock Program " << endl;
    int h, m, s;

    cout << "Enter Hour (0-23): ";
    cin >> h;
    cout << "Enter Minute (0-59): ";
    cin >> m;
    cout << "Enter Second (0-59): ";
    cin >> s;

    Clock myClock(h, m, s);
    myClock.run();

    return 0;
}