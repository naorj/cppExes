#include <iostream>
#include <sstream>
#include "CircularInt.hpp"
using namespace std;

CircularInt::CircularInt(int a, int b) {		//Constructor
	low = a;
	high = b;
	current = a;
}

ostream& operator <<(ostream& os, const CircularInt& m) {	// cout overloading
	return os << m.current;
}

CircularInt& operator+=(CircularInt& t, int a) {		//+= overloading
	if ((t.current + a) > t.high) {
		t.current = (t.current + a) % t.high;
	} else {
		t.current = t.current + a;
	}
	return t;
}

CircularInt& operator++(CircularInt& t, int) {		//+1 overloading (++)
	if ((t.current + 1) > t.high) {
		t.current = (t.current + 1) % t.high;
		return t;
	} else
		return (t += 1);
}

int operator+(CircularInt&a, CircularInt&b) {	//	cout of + overloading
	return (a.current + b.current) % a.high;
}

int operator-(CircularInt &t) {		// cout of '-' overloading
	return t.high - t.current;
}

CircularInt& operator-(int num, CircularInt& t) {//minus overloading between integer and circularInt
	t.current = t.high + (num - t.current);
	if (t.current > t.high) {
		t.current = t.current - t.high;
	}
	return t;
}

CircularInt& operator-(CircularInt& t, int num) {//minus overloading between circularInt and integer
	t.current = t.high + ((num - t.current) * (-1));
	if (t.current > t.high) {
		t.current = t.current - t.high;
	}
	return t;
}

CircularInt& operator-(CircularInt&a, CircularInt&b){	//minus overloading between circularInt and circularInt
if(a.current-b.current<a.low){
	a.current=(a.current-b.current)+a.high;
}
else{
	a.current=a.current-b.current;
}
return a;
}

CircularInt& operator*=(CircularInt &t, int num) {		//	*= overloading
	t.current = (t.current * num) % t.high;
	return t;
}

bool operator==(CircularInt& a, CircularInt& b) {		//	== overloading
	return a.current == b.current;
}

string operator/(CircularInt& t, int num) {	// divide overloading with try+catch
	int b = t.current / num;
	string str;
	string str2;
	string str3;
	ostringstream temp;
	ostringstream temp1;
	ostringstream temp2;
	temp2 << num;
	temp1 << t.current;
	temp << b;
	str = temp.str();
	str2 = temp1.str();
	str3 = temp2.str();
	if ((t.current / num > 0) && (t.current / num < 13)) {
		return str;
	} else
		return "there is no number " + str + " in {1,12} such that " + str + "*"
				+ str3 + "=" + str2;
}

CircularInt& operator+(CircularInt& a, int b) { //+operator between cirInt and integer
	if (a.current + b > 12)
		a.current = (a.current + b) % a.high;
	else
		a.current += b;
	return a;
}

CircularInt& operator/(int a, CircularInt& b) { //operator /  between and integer and cirInt
	b.current = a / b.current;
	return b;
}

CircularInt& operator/=(CircularInt&a, int b) {	//operator /  between cirInt and integer
	a.current = a.current / b;
	return a;
}

bool operator==(CircularInt&a, int b) { // operator == between cirInt and integer
	if (a.current == b)
		return true;
	else
		return false;
}

bool operator==(int a, CircularInt& b) {	// operator == between integer and cirInt
	return b == a;
}

void CircularInt::operator=(int b){	// = overloading
	this->current=b;
}

bool operator!=(CircularInt&a, CircularInt& b) {	//	!= overloading
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

bool operator!=(int a, CircularInt& b) {	//	!= overloading between cirInt and integer
	return b != a;
}

bool operator>(CircularInt&a, CircularInt &b) {	//	> overloading between cirInt and cirInt
	if (a.current > b.current)
		return true;
	else
		return false;
}

bool operator>(CircularInt&a, int b) {	//	> overloading between cirInt and Integer
	if (a.current > b)
		return true;
	else
		return false;
}

bool operator>(int a, CircularInt&b) {	//	> overloading between Integer and cirInt
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

bool operator<(CircularInt&a, int b) {	// < overloading between cirInt and Integer
	if (a.current < b)
		return true;
	else
		return false;
}

bool operator<(int a, CircularInt&b) {	//	< overloading between Integer and cirInt
	if (a < b.current)
		return true;
	else
		return false;
}

bool operator>=(CircularInt&a, CircularInt &b){
	return ((a.current>b.current) && (a==b));
}

bool operator>=(CircularInt&a, int b){
	return ((a.current>b) && (a==b));
}

bool operator>=(int a, CircularInt& b){
	return ((a>b) && (a==b));
}

bool operator<=(CircularInt&a, CircularInt &b){
	return ((a.current<b.current) && (a==b));
}

bool operator<=(CircularInt&a, int b){
	return ((a.current<b) && (a==b));
}

bool operator<=(int a, CircularInt& b){
	return ((a<b) && (a==b));
}
