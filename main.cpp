#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
using namespace std;

ifstream inputFileObj;
ofstream outputFileObj;

int main() {
	namespace fs = std::filesystem;
	double sum = 0;
	double average = 0;
	// long numberbuffer = 0;
	std::string stringbuffer;
	vector<long> values;
	vector<std::string> lines;
	
	fs::path nums_path("numbers.txt");
	fs::path input_strings_path("InputStrings.txt");
	fs::path input_random_strings_path("RandomStrings.txt");
	
	inputFileObj.open(nums_path);
	
	if (inputFileObj.is_open()) {
		
		cout << "Contents of file numbers.txt:" << endl;
		
		while (std::getline(inputFileObj, stringbuffer)) {
			if (stringbuffer.empty()) {
				continue;
			}
			
			cout << "[" << stringbuffer << "]" << endl;
			
			values.push_back(std::stol(stringbuffer));
		}
		
		for (long num : values) {
			sum += num;
		}
		
		average = sum / values.size();
		
		inputFileObj.close();
	} else { cerr << "Error opening file.\n"; }
	
	
	cout << "\n[=][=][=][=][=][=][=][=][=][=][=][=][=][=][=][=][=][=]\n" << endl;
	
	
	inputFileObj.open(input_strings_path);
	
	if (inputFileObj.is_open()) {
		
		cout << "Contents of file InputStrings.txt:" << endl;
		while (std::getline(inputFileObj, stringbuffer)) {
			if (stringbuffer.empty()) {
				continue;
			}
			
			cout << "[" << stringbuffer << "]" << endl;
			
			lines.push_back(stringbuffer);
		}
	} else { cerr << "Error opening file.\n"; }
	
	cout << endl;
	
	
	
	cout << "Strings in InputStrings.txt:" << endl;
	for (std::string line : lines) {
		cout << line << endl;
	}
	
	cout << endl;
	
	printf("Number of values: %d \n", (int) values.size());
	printf("Sum of values: %.2f \n", sum);
	printf("Average of values: %.2f \n", average);
	
	//Creates a file called "RandomStrings.txt" in the project's DerivedData folder.
	outputFileObj.open(input_random_strings_path);
	for (int i = 0; i < 1000; i++) {
		outputFileObj << "Whooooaaaa duuuude!!\n";
	}
	outputFileObj.close();
	
	printf("Program done!\n");
	
	return EXIT_SUCCESS;
}
