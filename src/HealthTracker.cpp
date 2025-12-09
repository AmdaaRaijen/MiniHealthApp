#include <iostream>
#include <iomanip>

using namespace std;

struct HealthData {
    int steps[7];
    int sleepHours[7];
    int waterIntake[7];
} weeklyData;

const int WATER_INTAKE_TARGET = 8;
const int STEP_TARGET = 5000;
const int MIN_SLEEP_TARGET = 7;
const int MAX_SLEEP_TARGET = 9;

void showMenu();
void inputData(HealthData &data);
void viewWeeklyStats(const HealthData &data);
void checkRecomendation(const HealthData &data);
void resetData(HealthData &data);

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

    float totalWater = 0, totalSteps = 0, totalSleep = 0;
    int daysWithData = 0;

    for (int i = 0; i < 7; i++) {
        cout << setw(3) << (i + 1) << " | " 
             << setw(11) << data.waterIntake[i] << " | " 
             << setw(5) << data.steps[i] << " | " 
             << setw(5) << data.sleepHours[i] << endl;

        if (data.waterIntake[i] > 0 || data.steps[i] > 0 || data.sleepHours[i] > 0) {
            totalWater += data.waterIntake[i];
            totalSteps += data.steps[i];
            totalSleep += data.sleepHours[i];
            daysWithData++;
        }
    }

    cout << string(45, '-') << endl;

    cout << "Averages:" << endl;
    if (daysWithData > 0) {
        cout << "Water Intake: " << (totalWater / daysWithData) << " cups/day" << endl;
        cout << "Steps: " << (totalSteps / daysWithData) << " steps/day" << endl;
        cout << "Sleep: " << (totalSleep / daysWithData) << " hours/day" << endl;
    } else {
        cout << "No data available to calculate averages." << endl;
    }

    cout << "Press Enter to continue..." << endl;
    cin.ignore(); cin.get();
}

void checkRecomendation(const HealthData &data) {
    float totalWater = 0, totalStep = 0, totalSleep = 0;
    int daysWIthData = 0;

    for (int i = 0; i < 7; i++) {
        if (data.waterIntake[i] > 0 || data.steps[i] > 0 || data.sleepHours[i] > 0) {
            totalWater += data.waterIntake[i];
            totalStep += data.steps[i];
            totalSleep += data.sleepHours[i];
            daysWIthData++;
        }
    }

    if (daysWIthData == 0 ) {
        cout << "NO data available to check health recomendation, please input data first!\n";
        cin.ignore(); cin.get();
        return;
    }

    float averageWaterIntake = totalWater/daysWIthData;
    float averageStep = totalStep/daysWIthData;
    float averageSleepHours = totalSleep/daysWIthData;

    cout << "3. Check Health Recomendation" << endl;
    cout << "=== RECOMENDATION (Based on average) ===" << endl;

    // 1. Water intake recomendation
    cout << "\n1. Water Intake" << endl;
    cout << "Target : " << WATER_INTAKE_TARGET << " cups/day" << endl;
    cout << "Yours  : " << averageWaterIntake << " cups/day" << endl;
    cout << "Status : ";
    if (averageWaterIntake >= WATER_INTAKE_TARGET) cout << " Great! You are hyrated" << endl;
    else if (WATER_INTAKE_TARGET - averageWaterIntake == 1) cout << " 1 more cup of water" << endl;
    else cout << WATER_INTAKE_TARGET - averageWaterIntake << " more cups of water." << endl;

    // 2. Total step recomendation
    cout << "\n2. Total step recomendation" << endl;
    cout << "Target : " << STEP_TARGET << " steps/day" << endl;
    cout << "Yours  : " << averageStep<< " steps/day" << endl;
    cout << "Status : ";
    if (averageStep >= STEP_TARGET) cout << "Great, target achieved! Keep it up!" << endl;
    else if (averageStep >= (STEP_TARGET - 500)) cout << "Almost there! Let's walk a little further!" << endl;
    else cout << "Not active enough! Let's walk more!" << endl;
    
    // 3. Sleep hours recomendation
    cout << "\n3. Sleep Hours" << endl;
    cout << "Target : " << MIN_SLEEP_TARGET << "-" << MAX_SLEEP_TARGET << " hours/day" << endl;
    cout << "Yours  : " << averageSleepHours << " hours/day" << endl;
    cout << "Status : ";
    if (averageSleepHours >= MIN_SLEEP_TARGET && averageSleepHours <= MAX_SLEEP_TARGET) 
        cout << "Good job! You have a healthy sleep pattern." << endl;
    else if (averageSleepHours < MIN_SLEEP_TARGET) 
        cout << "You need more sleep! Try to rest better." << endl;
    else 
        cout << "You are oversleeping! Try to maintain a regular sleep schedule." << endl;

    cout << "Press Enter to continue..." << endl;
    cin.ignore(); cin.get();
}

void resetData(HealthData &data) {
    char confirm;

    cout << "4. Reset Data" << endl;
    cout << "Are your sure you want do delete the data? (y/n): ";
    cin >> confirm;

    if(confirm == 'y' || confirm == 'Y') 
    {
        for (int i = 0; i < 7; i++) {
            data.waterIntake[i] = 0;
            data.steps[i] = 0;
            data.sleepHours[i] = 0;
        }
        cout << "Data reset successfully." << endl;
    } 
    else 
    {
        cout << "Data reset cancelled." << endl;
    }
    
    cout << "Press Enter to continue..." << endl;
    cin.ignore(); cin.get();
}