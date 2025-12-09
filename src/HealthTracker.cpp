#include <iostream>
#include <iomanip>

using namespace std;

struct HealthData {
    int steps[7];
    int sleepHours[7];
    int waterIntake[7];
} weeklyData;

void showMenu();
void inputData(HealthData &data);
void viewWeeklyStats(const HealthData &data);

void showMenu() {
    cout << "==== MINI HEALTH TRACKER ====" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. View Weekly Stats" << endl;
    cout << "3. Check Health Recommendations" << endl;
    cout << "4. Reset Data" << endl;
    cout << "5. Exit" << endl;
}

void inputData(HealthData &data) {
    int day;

    cout << "1. Input Health Data" << endl;
    cout << "Enter day of the week (1-7): ";

    if (!(cin >> day) || day < 1 || day > 7) {
        cout << "Invalid input. Please enter a number between 1 and 7." << endl;
        cin.ignore(); cin.get();
        return;
    }

    int index = day - 1;

    cout << "=== INPUT DATA FOR DAY " << day << " ===" << endl;
    cout << "1. Cups of Water Intake: ";
    cin >> data.waterIntake[index];
    cout << "2. Total Steps: ";
    cin >> data.steps[index];
    cout << "3. Sleep Hours: ";
    cin >> data.sleepHours[index];

    cout << "Data for day " << day << " recorded successfully." << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore(); cin.get();
}

void viewWeeklyStats(const HealthData &data) {
    cout << "2. View Weekly Stats" << endl;
    cout << "=== WEEKLY HEALTH STATS ===" << endl;

    cout << "Day | " << setw(11) << "Water (cups)" << " | " << setw(5) << "Steps" << " | " << setw(5) << "Sleep (hours)" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < 7; i++) {
        cout << setw(3) << (i + 1) << " | " 
             << setw(11) << data.waterIntake[i] << " | " 
             << setw(5) << data.steps[i] << " | " 
             << setw(5) << data.sleepHours[i] << endl;
    }

    cout << string(45, '-') << endl;

    cout << "Press Enter to continue..." << endl;
    cin.ignore(); cin.get();
}