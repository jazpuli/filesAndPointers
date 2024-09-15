//input inclusions as needed
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm> 
using namespace std;

//create student class with name and grade 
class Student {
public:
	string name;
	vector<double> grades;
};

//create findMax to thow (continue code)
double findMax(const vector<double>& arr) {
	if (arr.empty()) {
        	throw invalid_argument("Grade cannot be negative");
	}
	double max = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
	}
    return max;
}

//create findMin to throw 
double findMin(const vector<double>& arr) {
	if (arr.empty()) {
		throw invalid_argument("Grade cannot be negative");
	}
	double min = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] < min) {
			min = arr[i];
        }
	}
return min;
}

//create sorting
void bubbleSort(vector<double>& arr) {
	int size = arr.size();
	for (int i = 0; i < size - 1; ++i) {
	for (int j = 0; j < size - i - 1; ++j) {
		if (arr[j] > arr[j + 1]) {
		// Swap elements
		swap(arr[j], arr[j + 1]);
		}
	}
	}
}
//start main
int main() {
	ifstream inputFile;
	string line;
	vector<Student> students;

	inputFile.open("students_scores.txt");
	if (!inputFile) {
		cout << "Error opening file." << endl;
	return 1;
	}
	while (getline(inputFile, line)) {
        	// Create a Student object for each student
        	Student student;
        	student.name = line;  // Read the student's name from the current line

        	getline(inputFile, line); // Read the line with grades
        	stringstream ss(line);
        	char comma;
        	double grade;
        	bool invalidGrades = false; // Flag to track invalid grades

        // Process grades for the student
        while (ss >> grade) {
		if (grade < 0) {
                	cerr << "Grades for student " << student.name << " are invalid, negative number detected!" << endl;
                	invalidGrades = true; // Set the flag to true for invalid grades
                	break; // Exit the loop on invalid grade
            }
		student.grades.push_back(grade); // Add valid grade to the student's grades vector
		ss >> comma; // Consume the comma separator
        }

        // If grades are not invalid, add the student to the vector
        if (!invalidGrades) {
		students.push_back(student);
        }
}
	inputFile.close();

	// Loop through the students to find max, min, and sort grades
	for (const auto& student : students) {
        if (!student.grades.empty()) {
		double max = findMax(student.grades);
            	double min = findMin(student.grades);

           	 cout << "Student " << student.name << " has a high score of " << max << " and a low score of " << min << endl;

            	vector<double> sortedGrades = student.grades;
            	bubbleSort(sortedGrades);

            	cout << "Sorted array: ";
            	for (int i = 0; i < sortedGrades.size(); ++i) {
                	cout << sortedGrades[i];
                if (i < sortedGrades.size() - 1) {
                    	cout << ", ";
                }
		}	
	cout << endl;
	}
	}

    return 0;
}

