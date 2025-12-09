#include <iostream>
#include "HealthTracker.cpp"

using namespace std;

int main() {

  int selection = 0;
  
  do {
    showMenu();

    cout << "Selection: " << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
      // TODO: Input Data
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