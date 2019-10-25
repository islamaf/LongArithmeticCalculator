// Preprocessors
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Global Variables
vector<int> numbers_1;
vector<int> numbers_2;

// Addition function
int addition(){
  int first_number;
  int second_number;

  cin >> first_number;
  cin >> second_number;

  while(first_number > 0){
    int firstDigits = first_number % 10;
    first_number /= 10;
    numbers_1.push_back(firstDigits);
  }

  while(second_number > 0){
    int secondDigits = second_number % 10;
    second_number /= 10;
    numbers_2.push_back(secondDigits);
  }


  vector<int> result; // default-initialize to 10 elements

  //  cout << "Numbers_1 are (in reversed form):";
  int size = 0;
  while(size < numbers_1.size() && size < numbers_2.size()){
    for(auto i = numbers_1.begin(); i != numbers_1.end(); i++){
      for(auto j = numbers_2.begin(); j != numbers_2.begin(); j++){
        int carry = 0;
        result = *i + *j + carry;

        for(int i = 0; i < numbers_1.size();i++)
          result[i] += numbers_1[i];
          result[i] += numbers_2[i];

        if(result > 9){
          result -= 10;
          carry = 1;
        }

        cout << result;
        size++;
      }
    }
  }

//  cout << "\n";

  //  cout << "\nNumbers_2 are (in reversed form):";
//  for(auto j = numbers_2.begin(); j != numbers_2.end(); j++){
//    cout << *j;
//  }
//
//  cout << "\n";

  return 0;
}

// Driver function
int main(){
  int carry = 0;

  addition();

  return 0;
}
