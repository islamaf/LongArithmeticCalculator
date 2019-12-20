#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <utility>
using namespace std;

// Making to_string alternative (in case c++11 not supported)
template <typename T>
string to_string(const T& value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

// Get input data
pair<string, string> get_data(){
    string x, y;

    cout << "Enter your first number: \n-> ";
    cin >> x;
    cout << "Enter your second number: \n-> ";
    cin >> y;

    return pair<string, string>(x, y);
}

// Main Calculator class
class calculator{
private:
    string x, y;
public:
    void get_mode();
    string addition(string a, string b);
    string subtraction(string a, string b);
    string multiplication(string a, string b);
    string check_division(string a, string b);
};

// Getting the mode
void calculator::get_mode(){
    int mode;
    cout << "****** Big Numbers Calculator ******\n";
    cout << "Choose the calculation mode to use:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n-> ";
    cin >> mode;

    pair<string, string> arg = get_data();

    calculator c;
    switch(mode){
    case 1:
        c.addition(arg.first, arg.second);
        break;
    case 2:
        c.subtraction(arg.first, arg.second);
        break;
    case 3:
        c.multiplication(arg.first, arg.second);
        break;
    case 4:
        cout << c.check_division(arg.first, arg.second) << endl;
        break;
    default:
        cout << "Invalid input! Choose from 1-5\n";
        get_mode();
    }
}

// Addition
string calculator::addition(string a, string b)
{
    //Check if a is smaller than b
    if(a.size() > b.size())
        swap(a, b);

    string res = ""; // Storing final result

    int n1 = a.size(), n2 = b.size(); //Getting sizes of both strings

    //Reversing both strings
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int sum = 0; //Setting sum of both strings

    int carry = 0; //The number of carries that occur
    for(int i = 0; i < n1; i++){
        sum = ((a[i]-'0') + (b[i]-'0') + carry);
        res.push_back(sum%10 + '0'); //Putting result in res

        carry = sum/10; //Iteration to the the next number
    }

    //Add what is left from the bigger number
    for(int i = n1; i < n2; i++){
        sum = ((b[i] - '0') + carry);
        res.push_back(sum%10 + '0');

        carry = sum/10;
    }

    //Add the carry left
    if(carry){
        res.push_back(carry + '0');
    }

    reverse(res.begin(), res.end()); //Reverse result

    cout << "=> " << res;
}

// Subtraction
string calculator::subtraction(string a, string b){
    get_data();

    //Check if a is smaller than b
    if(a.size() < b.size()){
        swap(a, b);
    }

    string res = ""; // Storing final result

    int n1 = a.size(), n2 = b.size(); //Getting sizes of both strings

    //Reversing both strings
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int borrow = 0; //Borrow factor

    for(int i = 0; i < n2; i++){
        int sub = ((a[i] - '0') - (b[i] - '0') - borrow);

        if(sub < 0){
            sub = sub + 10;
            borrow = 1;
        }else{
            borrow = 0;
        }

        res.push_back(sub + '0');
    }

    //Subtract what is left from the bigger number
    for(int i = n2; i < n1; i++){
        int sub = ((a[i] - '0') - borrow);

        if(sub < 0){
            sub = sub + 10;
            borrow = 1;
        }else{
            borrow = 0;
        }

        res.push_back(sub + '0');
    }

    reverse(res.begin(), res.end()); //Reverse result

    cout << "=> " << res;
}

//Multiplication
string calculator::multiplication(string a, string b){
    get_data();

    //Check if any of the strings are 0
    if(a.size() == 0 || b.size() == 0){
        return "0";
    }

    vector<int> res(a.size() + b.size(), 0); //Result vector

    //Position indexes used in the result
    int i_a1 = 0;
    int i_b1 = 0;

    // Go from right to left in a
    for(int i = a.size()-1; i >= 0; i--){
        int carry = 0;
        int a1 = a[i] - '0';

        //Shifts position to left after every multiplication in b
        i_b1 = 0;

        //Go from right to left in b
        for(int j = b.size()-1; j >= 0; j--){
            int b1 = b[j] - '0';

            int sum = a1 * b1 + res[i_a1 + i_b1] + carry;

            carry = sum/10; //Carry for next number

            res[i_a1 + i_b1] = sum%10; //Storing result

            i_b1++;
        }

        if(carry > 0){
            res[i_a1 + i_b1] += carry;
        }

        //Shift position to the left after every multiplication
        i_a1++;
    }

    //Ignoring 0s from the right
    int i = res.size() - 1;

    while(i >= 0 && res[i] == 0){
        i--;

        if(i == -1){
            cout << "=> 0";
        }
    }

    string res_s = "";

    while(i >= 0){
        res_s += to_string(res[i--]);
    }

    cout << "=> " << res_s;
}

//Division
string division(string a, string b){
//    get_data();

    //a: number
    //b: divisor
    string res; //Storing final result

    int index = 0;
    signed long long int temp = a[index] - '0';

    stringstream b_int(b);
    signed long long int x = 0;
    b_int >> x;

    while(temp < x){
        temp = temp * 10 + (a[++index] - '0');
//        cout << temp << endl;
    }

    while(a.size() > index){
        res += (temp / x) + '0';

//        cout << res << endl;

        //Take next digit
        temp = (temp % x) * 10 + a[++index] - '0';
//        cout << temp << endl;
    }

    //b > a?
    if(res.size() == 0){
//        cout << "=> 0";
        return 0;
    }else{
//        cout << "=> " << res;
        return res;
    }
}

string calculator::check_division(string a, string b){
    string res;
    if(b.size() > 19) {
        string dec_first;
        string dec_second = b;
        while(dec_second.size() > 19){
            dec_first = division(a, "100000000000000000");
            dec_second = division(b, "100000000000000000");
            a = dec_first;
        }
        res = division(dec_first, dec_second);
    }else{
        res = division(a, b);
    }

    return res;
}

int main(){
    calculator c;
    c.get_mode();

    cout << "\n";
    return main();
}
