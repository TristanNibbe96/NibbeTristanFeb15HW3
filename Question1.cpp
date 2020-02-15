#include "Question1.h"

int main(){
	std::vector<float> data = initializeVector();
	float sum = takeSumOfData(data);
	float average = takeAverageOfData(sum,data.size());
	float standardDev = takeStandardDeviationOfData(data,average);

	printf("Sum: %f \nAverage: %f\nStandard Deviation: %f\n",sum,average,standardDev );
		
}

float takeSumOfData(std::vector<float> dataToSum){
	float sum = 0;

	for(int i = 0; i < dataToSum.size(); i++){
		sum += dataToSum.at(i);
	}

	return sum;
}

float takeAverageOfData(float sumToAverage, int numberOfElements){
	return sumToAverage/numberOfElements;
}

float takeStandardDeviationOfData(std::vector<float> data, float average){
	float standardDeviationLocal = 0;

	for(int i = 0; i < data.size(); i++){
		standardDeviationLocal += pow((data.at(i) - average),2);
	}

	standardDeviationLocal = standardDeviationLocal / data.size();
	standardDeviationLocal = pow(standardDeviationLocal,.5);

	return standardDeviationLocal;
}

std::vector<float> initializeVector(){
	std::vector<float> data;
	data = enterDataToVector(data, setInputFile());
	return data;
}

std::vector<float> enterDataToVector(std::vector<float> dataField, std::fstream inputFile){
	std::cout << "Filling vector with given data...\n";

	float tempFloat;

	while(inputFile >> tempFloat){
		std::cout << tempFloat;
		std::cout << "\n";
		dataField.push_back(tempFloat);
	}

	inputFile.close();
	return dataField;
}

std::fstream setInputFile(){
	std::cout << "Please enter path of file that has data in it: ";
	std::string fileName;
	std::cin >> fileName;

	std::fstream inputFile;
	inputFile.open(fileName);
	return inputFile;
}

