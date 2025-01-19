#include <iostream>
using namespace std;


string calculateBy2(string input){
	int carryFlag = 0, number, j = 0;
	string totalBy2 = input;
	for(int i = 0; i < input.length(); i++){
		//if there is carry, add 10 and then divide the number
		if(carryFlag) {
			number = 10 + (input.at(i) - 48);
			carryFlag = 0;
		}
		else number = (input.at(i) - 48);

		//if number is odd, set the carry flag
		if(number % 2 != 0) carryFlag = 1;
		totalBy2.at(i) = (number/2) + 48;
	}
	return totalBy2;
}



string addString(string first, string second){
	int length = first.length();
	string sum = "";
	for(int i = 0; i < length; i++){
		sum += "0";
	}
	int carry = 0;
	int num;
	for(int i = (length - 1) ; i > -1; i--){
		num = (first.at(i) - 48) + (second.at(i) - 48) + carry;
		carry = num/10;
		sum.at(i) = (num % 10) + 48;
	}
	return sum;
}





string minusString(string first, string second){
	int length = first.length();
	string difference = "";
	for(int i = 0; i < length; i++){
		difference += "0";
	}
	int subtract = 0;
	int num, firstNum;
	for(int i = (length - 1) ; i > -1; i--){
		if(subtract){
			if (first.at(i) == '0') {
				first.at(i) = '9';
				subtract = 1;
				firstNum = first.at(i) - 48;
			}
			else {
				first.at(i) = ((first.at(i) - 48) - 1) + 48;
				subtract = 0;
				if(first.at(i) < second.at(i)) {
					firstNum = 10 + (first.at(i) - 48);
					subtract = 1;
				}
				else {
					firstNum = first.at(i) - 48;
					subtract = 0;
				}
			}

		}
		else {
			if(first.at(i) < second.at(i)) {
				firstNum = 10 + (first.at(i) - 48);
				subtract = 1;
			}
			else {
				firstNum = first.at(i) - 48;
				subtract = 0;
			}
		}

		num = firstNum - (second.at(i) - 48);
		difference.at(i) = num + 48;
	}
	return difference;

}






int main() {
	string a = "123456";
	string b = "543256";
	cout<<addString(a,b)<<"\n";
	cout<<minusString(b,a)<<"\n";
	cout<<calculateBy2(b);
	return 0;
}
