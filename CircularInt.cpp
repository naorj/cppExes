#include <iostream>
#include <string>
#include <algorithm>
#include "CircularInt.hpp"
using namespace std;

CircularInt::CircularInt(int a, int b) {	//Constructor
	low = a;
	high = b;
	current = a;
	range = (b - a) + 1;
}

ostream& operator <<(ostream& os, const CircularInt& m) {	// cout overloading
	return os << m.current;
}

istream& operator >>(istream& os, const CircularInt& m) {	// cin overloading
	return os >> m;
}

CircularInt& operator+=(CircularInt& t, int a) {//+= overloading between cirInt and integer
	if ((t.current + a) > t.high) {
		t.current = (t.current + a) % t.range;
	} else {
		t.current = t.current + a;
	}
	return t;
}

CircularInt& operator+=(CircularInt& a, CircularInt& b) {//	+= overloading between cirInt and cirInt
	int temp = b.current;
	a += temp;
	return a;
}

CircularInt& operator-=(CircularInt& t, int a) {//-= overloading between cirInt and integer
	if ((t.current - a) < t.low) {
		t.current = (t.current - a) + t.high;
	} else {
		t.current = t.current - a;
	}
	return t;
}

CircularInt& operator-=(CircularInt& a, CircularInt& b) {//-= overloading between cirInt and cirInt
	int temp = b.current;
	a -= temp;
	return a;
}

CircularInt& operator++(CircularInt& t, int) {	//+1 overloading (++) - postfix
	if ((t.current + 1) > t.high) {
		t.current = (t.current + 1) % t.range;
		return t;
	} else
		return (t += 1);
}

CircularInt& operator--(CircularInt& t, int) {	//-1 overloading (--) postfix
	if ((t.current - 1) < t.low || (t.current - 1) > t.high) {
		t.current = (t.current - 1);		// + t.high;
		while (t.current < t.low)
			t.current += t.high;
		if (t.current > t.high)
			t.current = t.current % t.range;
		return t;
	} else
		return (t -= 1);
}

int operator+(CircularInt&a, CircularInt&b) {//	+ overloading between cirInt and cirInt
	a.current = (a.current + b.current) % a.range;
	return a.current;
}

int operator-(CircularInt &t) {		//  '-' overloading
	return t.high - t.current;
}

int operator-(int num, CircularInt& t) {// minus overloading between integer and circularInt
	int answer = 0;
	answer = num - t.current;
	if (answer < t.low) {
		while (answer < t.low)
			answer = answer + t.range;
	}
	return answer;
}

CircularInt& operator-(CircularInt& t, int num) {// minus overloading between circularInt and integer
	t.current = t.high + ((num - t.current) * (-1));
	if (t.current > t.high) {
		t.current = t.current - t.high;
	}
	return t;
}

CircularInt& operator-(CircularInt&a, CircularInt&b) {// minus overloading between circularInt and circularInt
	if ((a.current - b.current) < a.low) {
		a.current = (a.current - b.current) + a.high;
	} else {
		a.current = a.current - b.current;
	}
	return a;
}

CircularInt& operator*=(CircularInt &t, int num) {//	*= overloading between cirInt and integer
	int temp = t.current * num;
	t.current = ((temp - t.low) % (t.high + 1 - t.low) + t.high + 1 - t.low)
			% (t.high + 1 - t.low) + t.low;
	return t;
}

CircularInt& operator*=(CircularInt &a, CircularInt&b) {//	*= overloading between cirInt and cirInt
	int temp = a.current * b.current;
	a.current = ((temp - a.low) % (a.high + 1 - a.low) + a.high + 1 - a.low)
			% (a.high + 1 - a.low) + a.low;
	return a;
}

CircularInt& operator*(CircularInt&a, CircularInt&b) {// * overloading between cirInt and cirInt
	CircularInt* temp = new CircularInt(a.low, a.high);
	int result = a.current * b.current;
	temp->current = ((result - a.low) % (a.high + 1 - a.low) + a.high + 1
			- a.low) % (a.high + 1 - a.low) + a.low;
	return *temp;
}

CircularInt& operator*(CircularInt&a, int b) {// * overloading between cirInt and integer
	CircularInt* temp = new CircularInt(a.low, a.high);
	int result = a.current * b;
	temp->current = ((result - a.low) % (a.high + 1 - a.low) + a.high + 1
			- a.low) % (a.high + 1 - a.low) + a.low;
	return *temp;
}

int operator*(int a, CircularInt& b) {// * overloading between integer and cirInt
	int answer = 0;
	if ((a * b.current) % b.range == 0)
		answer = b.high;
	else
		answer = (a * b.current) % b.range;
	return answer;
}

bool operator==(CircularInt& a, CircularInt& b) {//	== overloading, returns boolean
	return a.current == b.current;
}

CircularInt& operator/(CircularInt& t, int num) {// divide overloading with try+catch
	CircularInt* temp = new CircularInt(t.low, t.high);
	if (t.current % num != 0)
		throw string(string("There is no suitable number"));
	int result = t.current / num;
	temp->current = result;
	return *temp;
}

CircularInt& operator+(CircularInt& a, int b) { //+operator between cirInt and integer
	if (a.current + b > a.high)
		a.current = (a.current + b) % a.range;
	else
		a.current += b;
	return a;
}

int operator+(int a, CircularInt& b) {	//+operator between integer and cirInt
	int answer = 0;
	answer = a + b.current;
	if (answer > b.high) {
		answer = answer % b.range;
	}
	return answer;
}

CircularInt& operator/(int a, CircularInt& b) { //	operator /  between and integer and cirInt
	b.current = a / b.current;
	return b;
}

CircularInt& operator/=(CircularInt&a, int b) {	//	operator /=  between cirInt and integer
	if (a.current % b != 0)
		throw string(string("There is no suitable number"));
	int result = a.current / b;
	a.current = result;
	return a;
}

bool operator==(CircularInt&a, int b) { 	// operator == between cirInt and integer , returns boolean
	if (a.current == b)
		return true;
	else
		return false;
}

bool operator==(int a, CircularInt& b) {	// operator == between integer and cirInt
	if (b.current == a)
		return true;
	else
		return false;
}

CircularInt& CircularInt::operator=(int b) {	// = overloading
	this->current = ((b - this->low) % (this->high + 1 - this->low) + this->high
			+ 1 - this->low) % (this->high + 1 - this->low) + this->low;
	return *this;
}

bool operator!=(CircularInt&a, CircularInt& b) {//	!= overloading between cirInt and cirInt
	if (a.current != b.current)
		return true;
	else
		return false;
}

bool operator!=(CircularInt& a, int b) { //	!= overloading between cirInt and integer
	if (a.current != b)
		return true;
	else
		return false;
}

bool operator!=(int a, CircularInt& b) {//	!= overloading between integer and cirInt
	if (a != b.current)
		return true;
	else
		return false;
}

bool operator>(CircularInt&a, CircularInt &b) {	//	> overloading between cirInt and cirInt
	if (a.current > b.current)
		return true;
	else
		return false;
}

bool operator>(CircularInt&a, int b) {//	> overloading between cirInt and Integer
	if (a.current > b)
		return true;
	else
		return false;
}

bool operator>(int a, CircularInt&b) {//	> overloading between Integer and cirInt
	if (a > b.current)
		return true;
	else
		return false;
}

bool operator<(CircularInt&a, CircularInt &b) {	//	< overloading between cirInt and cirInt
	if (a.current < b.current)
		return true;
	else
		return false;
}

bool operator<(CircularInt&a, int b) {// < overloading between cirInt and Integer
	if (a.current < b)
		return true;
	else
		return false;
}

bool operator<(int a, CircularInt&b) {//	< overloading between Integer and cirInt
	if (a < b.current)
		return true;
	else
		return false;
}

bool operator>=(CircularInt&a, CircularInt &b) {//	>= overloading between cirInt and cirInt
	bool answer = true;
	if (a.current < b.current)
		answer = false;
	return answer;
}

bool operator>=(CircularInt&a, int b) {	// >= overloading between cirInt and integer
	bool answer = true;
	if (a.current < b)
		answer = false;
	return answer;
}

bool operator>=(int a, CircularInt& b) {// >= overloading between integer and cirInt
	bool answer = true;
	if (a < b.current)
		answer = false;
	return answer;
}

bool operator<=(CircularInt&a, CircularInt &b) {// <= overloading between cirInt and cirInt
	bool answer = true;
	if (a.current > b.current)
		answer = false;
	return answer;
}

bool operator<=(CircularInt&a, int b) {	// <= overloading between cirInt and integer
	bool answer = true;
	if (a.current > b)
		answer = false;
	return answer;
}

bool operator<=(int a, CircularInt& b) {// <= overloading between integer and cirInt
	bool answer = true;
	if (a > b.current)
		answer = false;
	return answer;
}
