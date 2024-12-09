# Train Schedule Management System

## Overview
The Train Schedule Management System is a console-based application developed in C++. It allows users to manage and track train schedules, including departure and arrival times, as well as delays. The system provides real-time updates and predictions for train arrivals based on current delays.

## Features
- Store and display details of multiple trains.
- Calculate and predict arrival times based on current delays.
- User-friendly interface for querying train information by name.
- Simple and effective time management using a custom `Time` structure.

## Technologies Used
- **C++**: For implementing the logic and structure of the application.
- **Standard Library**: Utilizes STL containers like `vector` and `string`.

## How It Works
1. **Train Data**: The system initializes with sample train data, including names, scheduled departure and arrival times.
2. **Delay Handling**: Users can see the current delay for each train and how it affects the predicted arrival time.
3. **User Input**: Users can input a train name to retrieve its details, including scheduled times and predicted arrival.

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/train-schedule-management.git
   cd train-schedule-management
