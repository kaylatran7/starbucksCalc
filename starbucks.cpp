//Name: Kayla Tran
//Program Description: Reading data in a file to output to user
//Input: the .txt file
//Ouput: the item that has the most carbohydrates, and the average amount of fat in each item
//Kaggle for the .txt file
//https://www.kaggle.com/starbucks/starbucks-menu/code

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//function declarations
bool openFile (string fileName, ifstream &inFile);
void welcome ();
void mostCarbohydrates (ifstream &inFile, string &carbName, int &mostCarbs);
void calcAvg (ifstream &inFile, int &averageCalories);
//main 
int main(){
ifstream inFile;
string fileName, itemName;
int itemValue = 0;

cout << "Enter file name: ";
getline (cin, fileName);
//an if statement to terminate the program if file could not be open / could not be found
if (!openFile(fileName, inFile)){
  cout << "File could not open, program terminating" << endl;
return 0;
}
welcome ();
mostCarbohydrates (inFile, itemName, itemValue);
cout << itemName << " has the most amount of carbohydrates: " << itemValue << " grams of carbohydrates." << endl;
calcAvg (inFile, itemValue);
cout << "The average amount of calories among Starbucks food items is: " << itemValue << " calories." << endl;
return 0;
}

bool openFile (string fileName, ifstream &inFile){
  inFile.open(fileName);
  if (!inFile){
    return false;
  }
  return true;
}

void welcome (){
  cout << "Welcome to my Starbucks Food Analysis Program!!" << endl;
  cout << "This program will tell you what Starbucks food contains the most carbohydrates." << endl;
  cout << "It will also tell you the average amount of calories among the food items." << endl;
}

void mostCarbohydrates(ifstream &inFile, string &carbName, int &mostCarbs)
{
	string foodName;
  mostCarbs = 0;
	int calories = 0, fat = 0, carb = 0, fiber = 0, protein = 0, discard = 0;
	inFile.ignore(200, '\n');
	//inFile >> foodName >> discard >> discard >> carb >> discard >> discard; 
//while in file is not end of file
	while (!inFile.eof()){
    inFile >> foodName >> discard >> discard >> carb >> discard >> discard; 
	   if (carb > mostCarbs){
       mostCarbs = carb;
       carbName = foodName;
	   }
	   inFile >> foodName >> calories >> fat >> carb >> fiber >> protein;
     //break; 
}
inFile.clear();
inFile.seekg(0); //clear for the next output 
}
//calculating average of calories
void calcAvg (ifstream &inFile, int &averageCalories){
  inFile.ignore(200, '\n');
  averageCalories = 0;
  int sumCals = 0;
  int count = 0;
  string foodName;
  string strDiscard; 
  int calories = 0, fat = 0, carb = 0, fiber = 0, protein = 0, discard = 0;
  
  while (!inFile.eof()){
    inFile >> strDiscard >> calories >> discard >> discard >> discard >> discard;
    sumCals = sumCals + calories;
    count++;
  }
  averageCalories = sumCals / count;
  inFile.clear();
}
