//============================================================================
// Name        : 240FactorialFun.cpp
// Author      : Jackson Ginn
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Factorial and combination calculator in C++
//============================================================================

#include <iostream>
#include <chrono>
using namespace std;

long long int factorial(long long int x){
	if(x <= 1){
		return 1;
	}
	return x * factorial(x-1);
}

long long int combination(long long int n, long long int r){
	long long int numerator = factorial(n);
	long long int denominator = (factorial(r)) * (factorial(n - r));
	return numerator/denominator;
}

int main(int argc, char *argv[]) {
	//argc is always 1 greater than number of arguments
	if(argc == 2){
		//1 actual argument
		//placeholder value to avoid variable not declared errors
		long long int n = -1;
		try{
			n = stoll(argv[1]);
		}
		catch(const invalid_argument& ia){
			cout << "Not a number." << endl;
			return 1;
		}
		if(n < 0){
			cout << "Negative argument." << endl;
			return 1;
		}
		else if(n > 20){
			cout << "Too large of an n." << endl;
			return 1;
		}
		auto start = std::chrono::steady_clock::now();
		cout << factorial(n) << endl;
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<long double> seconds = end - start;
		cout << "Time in seconds: " << seconds.count() << endl;
	}
	else if(argc == 3){
		//2 actual arguments
		long long int n = -1;
		long long int r = -1;
		try{
			n = stoll(argv[1]);
			r = stoll(argv[2]);
		}
		catch(const invalid_argument& ia){
			cout << "Not a number." << endl;
			return 1;
		}
		if(n < 0 || r < 0){
			cout << "Negative argument." << endl;
			return 1;
		}
		else if(r > n){
			cout << "Invalid r." << endl;
			return 1;
		}
		else if(n > 20){
			cout << "Too large of an n." << endl;
			return 1;
		}
		auto start = std::chrono::steady_clock::now();
		cout << combination(n,r) << endl;
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<long double> seconds = end - start;
		cout << "Time in seconds: " << seconds.count() << endl;
	}
	else{
		cout << "Invalid number of arguments." << endl;
		return 1;
	}
	return 0;
}
