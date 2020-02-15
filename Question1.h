#include <vector>
#include <iostream>
#include <cmath>
#include <fstream> 

std::vector<float> initializeVector();
float takeSumOfData(std::vector<float> dataToSum);
float takeAverageOfData(float sumToAverage, int numberOfElements);
float takeStandardDeviationOfData(std::vector<float> data, float average);
std::vector<float>  enterDataToVector(std::vector<float> dataField, std::fstream file);
std::fstream setInputFile();
