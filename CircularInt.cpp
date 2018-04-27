#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "CircularInt.hpp"
using namespace std;

CircularInt::CircularInt(int a, int b) {		//Constructor
	low = a;
	high = b;
	current = a;
	range=(b-a)+1;
}

ostream& operator <<(ostream& os, const CircularInt& m) {	// cout overloading
	return os << m.current;
}

istream& operator >>(istream& os, const CircularInt& m) {	//  overloading
	return os >> m;
}

CircularInt& operator+=(CircularInt& t, int a) {		//+= overloading
	if ((t.current + a) > t.high) {
		t.current = (t.current + a) % t.range;
	} else {
		t.current = t.current + a;
	}
	return t;
}

CircularInt& operator+=(CircularInt& a, CircularInt& b) {
	int temp=b.current;
	a+=temp;
	return a;
}	//fix

CircularInt& operator-=(CircularInt& t, int a) {		//-= overloading
	if ((t.current - a) < t.low) {
		t.current = (t.current - a) + t.high;
	} else {
		t.current = t.current - a;
	}
	return t;
}

CircularInt& operator-=(CircularInt& a, CircularInt& b) {		//-= overloading
	int temp=b.current;
	a-=temp;
	return a;
}

CircularInt& operator++(CircularInt& t, int) {		//+1 overloading (++) postfix
	if ((t.current + 1) > t.high) {
		t.current = (t.current + 1) % t.range;
		return t;
	} else
		return (t += 1);
}	//fix

CircularInt& operator--(CircularInt& t, int) {		//+1 overloading (--) postfix
	if ((t.current - 1) < t.low || (t.current-1)>t.high) {
		t.current = (t.current - 1);// + t.high;
		while(t.current<t.low)
			t.current+=t.high;
		if(t.current>t.high)
			t.current=t.current%t.range;
		return t;
	} else
		return (t -= 1);
}	// fix

int operator+(CircularInt&a, CircularInt&b) {	//	cout of + overloading
	a.current=(a.current+b.current)%a.range;
	return a.current;
}

int operator-(CircularInt &t) {		// cout of '-' overloading
	return t.high - t.current;
}

int operator-(int num, CircularInt& t) {//minus overloading between integer and circularInt
	int answer=0;
	answer=num-t.current;
	if(answer<t.low){
		while(answer<t.low)
			answer=answer+t.range;
	}
	return answer;
}

CircularInt& operator-(CircularInt& t, int num) {//minus overloading between circularInt and integer
	t.current = t.high + ((num - t.current) * (-1));
	if (t.current > t.high) {
		t.current = t.current - t.high;
	}
	return t;
}

CircularInt& operator-(CircularInt&a, CircularInt&b){	//minus overloading between circularInt and circularInt
if((a.current-b.current)<a.low){
	a.current=(a.current-b.current)+a.high;
}
else{
	a.current=a.current-b.current;}
return a;
}

CircularInt& operator*=(CircularInt &t, int num) {		//	*= overloading	//114 - 147
	cout<<"naor1"<<endl;
	if(t.current*num<t.low){
		t.current = (t.current * num);
		while(t.current<t.low)
			t.current = (t.current + t.range);
	}
	else if((t.current*num)>t.high){
		if(((t.current * num) % t.range)==0)
			t.current=t.high;
		else
			t.current = (t.current * num) % t.range;
	}
	else
		t.current = (t.current * num);
	return t;
}

CircularInt& operator*=(CircularInt &a, CircularInt&b) {		//	*= overloading
	cout<<"naor2"<<endl;
	int temp=b.current;
	a*=temp;
	return a;
}

int operator*(CircularInt&a, CircularInt&b){
	//cout<<"naor3"<<endl;
	int answer=0;
	if((a.current*b.current)%a.range==0)
		answer=a.high;
	else
		answer=(a.current*b.current)%a.range;
	return answer;
//a.current=(a.current*b.current) %a.range;
//return a;
}

CircularInt& operator*(CircularInt&a, int b){
	//cout<<"naor4"<<endl;
	if(a.current*b>a.high){
		if(((a.current * b) % a.range)==0)
			a.current=a.high;
		else
			a.current = (a.current * b) % a.range;
	}
	else
		a.current *= b;
	return a;
	/*int answer=0;
	if(((a.current*b)%a.range)==0)
		answer=a.high;
	else
		answer=(a.current*b)%a.range;
	return answer;
	//a*=b;
	//return a;
	/*
	 * if (a.current + b > a.high)
		a.current = (a.current + b) % a.range;
	else
		a.current += b;
	return a;
	 */
}

int operator*(int a, CircularInt& b){
	cout<<"naor5"<<endl;
	int answer=0;
	if((a*b.current)%b.range==0)
		answer=b.high;
	else
		answer=(a*b.current)%b.range;
	return answer;
	//b*=a;
	//return b;
}

bool operator==(CircularInt& a, CircularInt& b) {		//	== overloading
	return a.current == b.current;
}

CircularInt& operator/(CircularInt& t, int num) {	// divide overloading with try+catch
	//cout << "shoval and naorrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr";
	/*int b = t.current / num;
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
	if ((t.current / num > t.low) && (t.current / num < t.high)) {
		return str;
	}*/
	/*else if((t.current / num > t.high)){
		t.current=(t.current/num)%t.range;
	}*/
/*
	else
		return "there is no number " + str + " in {1,12} such that " + str + "*"
				+ str3 + "=" + str2;*/
	CircularInt* temp = new CircularInt(t.low,t.high);
	if(t.current%num!=0)
		throw string(string("There is no number x in { "));// + to_string(t.low) + string(",") + to_string(t.high) + " } such that x * " + to_string(t.current) + " = " + to_string(t.high));
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

int operator+(int a, CircularInt& b){	//+operator between integer and cirInt
	int answer=0;
	answer=a+b.current;
	if(answer>b.high){
		answer=answer%b.range;
	}
	return answer;
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
	if(b.current==a)
		return true;
	else
		return false;
}

CircularInt& CircularInt::operator=(int b){	// = overloading
	this->current=b;
	return *this;
}

CircularInt& CircularInt::operator=(string b){
	int temp=atoi(b.c_str());
	this->current=temp;
	if(this->current<this->low)
		this->current=this->current+this->range;
	else if(this->current>this->high)
		this->current=this->current%this->range;
	return *this;
}

/*CircularInt& CircularInt::operator=(CircularInt& a){	// = overloading
	this->current=a.current;
	return *this;
}*/

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
	if(a!=b.current)
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
	bool answer=true;
	if(a.current<b.current)
		answer=false;
	return answer;
}

bool operator>=(CircularInt&a, int b){
	bool answer=true;
	if(a.current<b)
		answer=false;
	return answer;
}

bool operator>=(int a, CircularInt& b){
	bool answer=true;
	if(a<b.current)
		answer=false;
	return answer;
}

bool operator<=(CircularInt&a, CircularInt &b){
	bool answer=true;
	if(a.current>b.current)
		answer=false;
	return answer;
}

bool operator<=(CircularInt&a, int b){
	bool answer=true;
	if(a.current>b)
		answer=false;
	return answer;
}

bool operator<=(int a, CircularInt& b){
	bool answer=true;
	if(a>b.current)
		answer=false;
	return answer;
}
