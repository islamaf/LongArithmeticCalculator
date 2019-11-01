#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

// Making to_string alternative (in case c++11 not supported)
template <typename T>
string to_string(const T& value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

// Main Calculator class
class calculator{
private:
    string a, b;
    int mode;
public:
    void get_mode(){
        cout << "****** Big Numbers Calculator ******\n";
        cout << "Choose the calculation mode to use:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n-> ";
        cin >> mode;

        calculator c;

        switch(mode){
        case 1:
            c.addition();
            break;
        case 2:
            c.subtraction();
            break;
        case 3:
            c.multiplication();
            break;
        case 4:
            c.division();
            break;
        default:
            cout << "Invalid input! Choose from 1-4\n";
            get_mode();
        }
    }

    void get_data(){
        cout << "Enter your first number: \n-> ";
        cin >> a;
        cout << "Enter your second number: \n-> ";
        cin >> b;
    }

    // Addition
    string addition()
    {
        get_data();

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
    string subtraction(){
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
    string multiplication(){
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
    string division(){
        get_data();

        //a: number
        //b: divisor
        string res; //Storing final result

        int index = 0;
        int temp = a[index] - '0';

        stringstream b_int(b);
        int x = 0;
        b_int >> x;

        while(temp < x){
            temp = temp * 10 + (a[++index] - '0');
        }

        while(a.size() > index){
            res += (temp / x) + '0';

            //Take next digit
            temp = (temp % x) * 10 + a[++index] - '0';
        }

        //b > a?
        if(res.size() == 0){
            cout << "=> 0";
        }else{
            cout << "=> " << res;
        }
    }
};

int main(){
    calculator c;
    c.get_mode();

    return 0;
}
