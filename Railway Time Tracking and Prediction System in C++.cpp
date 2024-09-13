#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Structure to hold time in HH:MM format
struct Time
{
    int hour;
    int minute;

    // Convert time to minutes for easy calculations
    int toMinutes() const
    {
        return hour * 60 + minute;
    }

    // Display time in HH:MM format
    void display() const
    {
        printf("%02d:%02d", hour, minute);
    }
};

// Train class to store train details
class Train
{
public:
    string trainName;
    Time departureTime;
    Time arrivalTime;
    int delayMinutes; // Delay in minutes

    Train(string name, Time dep, Time arr)
        : trainName(name), departureTime(dep), arrivalTime(arr), delayMinutes(0) {}

    // Function to predict arrival time based on delay
    Time predictArrival() const
    {
        Time predictedArrival = arrivalTime;
        int predictedMinutes = predictedArrival.toMinutes() + delayMinutes;

        predictedArrival.hour = predictedMinutes / 60;
        predictedArrival.minute = predictedMinutes % 60;

        return predictedArrival;
    }

    // Display train details
    void display() const
    {
        cout << "Train Name: " << trainName << endl;
        cout << "Scheduled Departure: ";
        departureTime.display();
        cout << endl;
        cout << "Scheduled Arrival: ";
        arrivalTime.display();
        cout << endl;
        cout << "Current Delay: " << delayMinutes << " minutes" << endl;
        cout << "Predicted Arrival: ";
        predictArrival().display();
        cout << endl
             << endl;
    }
};

// Function to find and display train details by name
void displayTrainByName(const vector<Train> &trains, const string &name)
{
    bool found = false;
    for (const auto &train : trains)
    {
        if (train.trainName == name)
        {
            train.display();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Train not found. Please check the train name and try again." << endl;
    }
}

// Main function
int main()
{
    vector<Train> trains;

    // Sample train data
    trains.push_back(Train("Express 101", {9, 30}, {12, 0}));
    trains.push_back(Train("Regional 202", {10, 15}, {13, 45}));
    trains.push_back(Train("Intercity 303", {11, 0}, {14, 30}));

    // Simulate real-time updates and predictions
    trains[0].delayMinutes = 15; // First train is delayed by 15 minutes
    trains[1].delayMinutes = 5;  // Second train is delayed by 5 minutes
    trains[2].delayMinutes = 20; // Third train is delayed by 20 minutes

    // User input for train name
    string trainName;
    cout << "Enter the train name: ";
    getline(cin, trainName);

    // Display train details based on user input
    displayTrainByName(trains, trainName);

    return 0;
}