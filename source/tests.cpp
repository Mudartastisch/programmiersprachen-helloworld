#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include <catch.hpp>
#include <iostream>
#include "tests.h"
#include <cmath>

//1.3
int scm() {
	int i = 2; //kann nicht bei 0 starten da if sonnst true
	while (true) {
		
		if (i % 11 == 0 && i % 12 == 0 && i % 13 == 0 && i % 14 == 0 && 
			i % 15 == 0 && i % 16 == 0 && i % 17 == 0 && i % 18 == 0 &&
			i % 19 == 0 && i % 20 == 0) {
			return i;
		}
		i = i++;
	}

}
//1.8
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
//1.9
int checkSum(int i) {
	int result = 0;
	int temp;
	while (i > 0) {
		temp = i % 10;
		i = i / 10;
		result = result + temp;
	}
	if (result > 10) {
		return checkSum(result);
	}
	else {
		return result;
	}
}
// 1.10
int sumMultiples(int a, int b) {
	int sum = 0; // storage
	for (int run = a; run <= b; run++) {
		if (run % 3 == 0 || run % 5 == 0) {
			sum = sum + run;
		}
	}
	return sum;
}

//1.12
int print_volume_area(float radius, float hight) {
	std::cout << "Area: " << 2 * M_PI*radius*radius + 2 * M_PI*radius*hight;
	std::cout << " Volume: " << M_PI*radius*radius*hight;
	return 0;
}

//1.13
int factorial(int i) {
	if (i == 1) {
		return 1;
	}
	else {
		return i*(factorial(i - 1));
	}
}
//1.14
int binomial(int n, int k) {
	int temp = (factorial(n) / (factorial(k)*(factorial(n - k))));
	return temp;
}
//1.15
bool isPrime(int s) {
	if (s == 2 || s == 1) {
		return true;
	}
	if (s % 2 == 0) {
		return false;
	}
	for (int i = 3; i*i <= s; i = i + 2) {
		if (s%i == 0) { 
			return false;
		}
	}
	return true;
}

TEST_CASE(" describe_gcd ", "[gcd]")
{
	REQUIRE(gcd(2, 4) == 2);
	REQUIRE(gcd(9, 6) == 3);
	REQUIRE(gcd(3, 7) == 1);
	REQUIRE(sumMultiples(1, 1000) == 234168);
	REQUIRE(checkSum(117516) == 3);
	REQUIRE(factorial(1) == 1);
	REQUIRE(factorial(2) == 2);
	REQUIRE(factorial(3) == 6);
	REQUIRE(isPrime(6427) == true);
	REQUIRE(isPrime(1) == true);
	REQUIRE(isPrime(2) == true);
	REQUIRE(isPrime(3) == true);
	REQUIRE(isPrime(4) == false);
	REQUIRE(isPrime(7) == true);
	REQUIRE(isPrime(42) == false);
	REQUIRE(binomial(10, 6) == 210);  
}

int main(int argc, char* argv[]){
	//std::cout << scm(); // 232,792,560
	//std::cout << sumMultiples(1, 1000); //234,168
	//std::cout << checkSum(117516);
	//print_volume_area(2.0, 1.5);

	
	return Catch::Session().run(argc, argv);
	return 0;
}