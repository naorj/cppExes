using namespace std;
class CircularInt;

class CircularInt {

	int low;
	int high;
	int current;
	int range;

public:
	CircularInt(int a, int b);
	friend ostream& operator <<(ostream& os, const CircularInt& m);
	friend istream& operator >>(istream& os, const CircularInt& m);
	friend CircularInt& operator+=(CircularInt& t, int a);
	friend CircularInt& operator++(CircularInt& t, int);
	friend int operator-(CircularInt &t);
	friend int operator-(int num, CircularInt& t);
	friend int operator+(CircularInt&a, CircularInt&b);
	friend CircularInt& operator*=(CircularInt &t, int num);
	friend string operator/(CircularInt& t, int num);
	friend bool operator==(CircularInt& a, CircularInt& b);
	friend CircularInt& operator--(CircularInt& t, int);
	friend CircularInt& operator-(CircularInt& t,int num);
	friend CircularInt& operator+(CircularInt& a, int b);
	friend int operator+(int a, CircularInt& b);
	friend CircularInt& operator/(int a, CircularInt& b);
	friend CircularInt& operator/=(CircularInt&a , int b);
	friend bool operator==(CircularInt&a ,int b);
	friend bool operator==(int a ,CircularInt& b);
	friend bool operator!=(CircularInt&a , CircularInt& b);
	friend bool operator!=(CircularInt& a, int b);
	friend bool operator!=(int a, CircularInt& b);
	friend bool operator>(CircularInt&a , CircularInt &b);
	friend bool operator>(CircularInt&a, int b);
	friend bool operator>(int a, CircularInt& b);
	friend bool operator<(CircularInt&a , CircularInt &b);
	friend bool operator<(CircularInt&a, int b);
	friend bool operator<(int a, CircularInt& b);
	friend bool operator>=(CircularInt&a, CircularInt &b);
	friend bool operator>=(CircularInt&a, int b);
	friend bool operator>=(int a, CircularInt& b);
	friend bool operator<=(CircularInt&a, CircularInt &b);
	friend bool operator<=(CircularInt&a, int b);
	friend bool operator<=(int a, CircularInt& b);
	friend CircularInt& operator-(CircularInt&a, CircularInt&b);
	friend CircularInt& operator-=(CircularInt& t, int a);
	friend CircularInt& operator-=(CircularInt& a, CircularInt& b);
	CircularInt& operator=(int b);
	CircularInt& operator=(string b);
	//CircularInt& operator=(CircularInt& a);
	friend CircularInt& operator*(CircularInt&a, CircularInt&b);
	friend CircularInt& operator*(CircularInt&a, int b);
	friend CircularInt& operator*(int a, CircularInt& b);
	friend CircularInt& operator+=(CircularInt& a, CircularInt& b);
	friend CircularInt& operator*=(CircularInt &a, CircularInt&b);
};
