#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

// ---------- Data structure ----------
struct District {
    string name;
    double supplied;
    double billed;
    double nrwPercent;
    string severity;
};

// ---------- Function declarations ----------
District inputDistrict();
void calculateNRW(District &d);
void classifySeverity(District &d);
void sortBySeverity(vector<District> &districts);
void displayReport(const vector<District> &districts);
void saveToFile(const vector<District> &districts, const string &filename);

int main() {
    vector<District> districts;
    int count;

    cout << "===== NRW Monitoring & District Loss Analysis System =====\n";
    cout << "Ghana Water Limited - Non-Revenue Water Tracker\n\n";

    cout << "Enter number of districts: ";
    cin >> count;
    cin.ignore(); // clear leftover newline before first getline()

    for (int i = 0; i < count; i++) {
        cout << "\n--- District " << (i + 1) << " ---\n";
        District d = inputDistrict();
        districts.push_back(d);
    }

    for (size_t i = 0; i < districts.size(); i++) {
        calculateNRW(districts[i]);
        classifySeverity(districts[i]);
    }

    sortBySeverity(districts);
    displayReport(districts);

    char choice;
    cout << "\nSave this report to a file? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        saveToFile(districts, "nrw_report.txt");
    }

    cout << "\n            Thank you.            \n";
    return 0;
}

// ---------- Function definitions ----------

District inputDistrict() {
    District d;

    cout << "Enter district name: ";
    getline(cin, d.name);

    cout << "Enter water supplied (gallons): ";
    cin >> d.supplied;

    cout << "Enter water billed (gallons): ";
    cin >> d.billed;

    cin.ignore(); // clear leftover newline so next getline() works correctly

    return d;
}

void calculateNRW(District &d) {
    double nrw = d.supplied - d.billed;
    d.nrwPercent = (nrw / d.supplied) * 100;
}

void classifySeverity(District &d) {
    if (d.nrwPercent < 20)
        d.severity = "Low";
    else if (d.nrwPercent <= 40)
        d.severity = "Moderate";
    else
        d.severity = "Critical";
}

void sortBySeverity(vector<District> &districts) {
    sort(districts.begin(), districts.end(),
        [](const District &a, const District &b) {
            return a.nrwPercent > b.nrwPercent; // descending: worst first
        });
}

void displayReport(const vector<District> &districts) {
    cout << "\n================= NON-REVENUE WATER REPORT =================\n";
    cout << left << setw(24) << "District"
         << right << setw(14) << "Supplied(gal)"
         << setw(14) << "Billed(gal)"
         << setw(9) << "NRW%"
         << setw(12) << "Severity" << "\n";
    cout << string(73, '-') << "\n";

    for (size_t i = 0; i < districts.size(); i++) {
        cout << left << setw(24) << districts[i].name
             << right << setw(14) << fixed << setprecision(0) << districts[i].supplied
             << setw(14) << districts[i].billed
             << setw(8) << setprecision(1) << districts[i].nrwPercent << "%"
             << setw(12) << districts[i].severity << "\n";
    }
    cout << string(73, '-') << "\n";
}

void saveToFile(const vector<District> &districts, const string &filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: could not open file for writing.\n";
        return;
    }

    outFile << "NON-REVENUE WATER REPORT - Ghana Water Limited\n";
    outFile << left << setw(24) << "District"
            << right << setw(14) << "Supplied(gal)"
            << setw(14) << "Billed(gal)"
            << setw(9) << "NRW%"
            << setw(12) << "Severity" << "\n";
    outFile << string(73, '-') << "\n";

    for (size_t i = 0; i < districts.size(); i++) {
        outFile << left << setw(24) << districts[i].name
                << right << setw(14) << fixed << setprecision(0) << districts[i].supplied
                << setw(14) << districts[i].billed
                << setw(8) << setprecision(1) << districts[i].nrwPercent << "%"
                << setw(12) << districts[i].severity << "\n";
    }
    outFile.close();
    cout << "Report saved to " << filename << "\n";
}
