#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  std::cout << "Hello World!\n";
  string filename;
  cout << "Enter the input filename: ";
  cin >> filename;
  ifstream infile(filename);
  if (!infile) {
  cerr << "Error opening file: " << filename << endl;
  ifstream infile(filename);
  return 1;
  }
  // Variables to hold input data
  string firstName, lastName;
  double baseSalary, commissionPercent, totalSales, expenses;
  // Read data from file
  infile >> firstName >> lastName;
  infile >> baseSalary >> commissionPercent;
  infile >> totalSales;
  infile >> expenses;

  infile.close();
  // Calculate commission amount
  double commissionAmount = (commissionPercent / 100.0) * totalSales;
  // Calculate total pay (gross pay)
  double totalPay = baseSalary + commissionAmount - expenses;
  // Output formatted payroll data
  cout << fixed << setprecision(2);
  cout << "Payroll data for " << firstName << " " << lastName << "\n\n";
  cout << left << setw(15) << "Base Salary:" << right << setw(10) << baseSalary << "\n";
  cout << left << setw(15) << "Commission:" << right << setw(7) << commissionAmount << " (" << fixed << setprecision(1) << commissionPercent << "% of " << fixed << setprecision(2) << totalSales << ")\n";
  cout << left << setw(15) << "Expenses:" << right << setw(10) << expenses << "\n";
  cout << "---------------\n";
  cout << left << setw(15) << "Total:" << right << setw(10) << totalPay << "\n";
  return 0; 
}
