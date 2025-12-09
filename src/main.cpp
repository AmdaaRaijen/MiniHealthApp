#include <iostream>
#include "HealthTracker.cpp"

using namespace std;

int main() {

  int selection = 0;
  
  do {
    showMenu();

    cout << "Selection: ";
    cin >> selection;

    // FIX: There is an error if selection is not an integer
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
      cout << "Invalid input. Please enter a number between 1 and 5." << endl;
      continue;
    }

    switch (selection)
    {
    case 1:
      inputData(weeklyData);
      break;
    case 2:
      // TODO: View weekly stats
      break;
    case 3:
      // TODO: Check health recomendations
      break;
    case 4:
      // TODO: Reset data
      break;
    case 5:
      cout << "Exiting the program." << endl;
      break;
    
    default:
      break;
    }
    
  } while (selection != 5);

  return 0;
}