#include <string>
#include <iostream>
#include <string.h>
using namespace std;


class Time {
	
	public: Time operator ++ (int)
	{
   		second++;
   		CheckTime();
   		return* this;
	}
	
	public: Time operator -- (int)
	{
   		second--;
		CheckTime();
   		return* this;
	}
	
	public: Time operator ++ ()
	{
   		minute++;
		CheckTime();
   		return* this;
	}

	
	public: Time operator -- ()
	{
   		minute--;
		CheckTime();
   		return* this;
	}
	

	public: CheckTime() {
		if (this->second < 0) {
			second = 59;
			minute--;
		}
		if(this->second>59) {
			second = 0;
			minute++;
		}
		if(this->minute<0) {
			minute = 59;
			hour--;
		}
		if(this->minute > 59) {
			minute = 00;
			hour++;
		}
		if (this->hour<0) {
			hour = 23;
		}
		if (this->hour>23) {
			hour = 0;
		}
	}
			
	int hour;
	int minute;
	int second;
	public: Time(int _hour, int _minute, int _second) {
		hour = _hour;
		minute = _minute;
		second = _second;
		if (_hour > 24 || _hour < 0) {
			hour = 0;
		}
		if (_minute > 59 || _minute < 0) {
			minute = 0;
		}
		if (_second > 59 || _second < 0) {
			second = 0;
		}
	}
	
	
	
	
	public: string toString() {
		char res[9];
		snprintf(res, sizeof(res), "%02d:%02d:%02d", hour, minute, second);
		string result = res;
		return result;
	}	
	
	
};

bool operator > (const Time& t1, const Time& t2) {
		if (t1.hour * 10000 + t1.minute * 100 + t1.second > t2.hour * 10000 + t2.minute * 100 + t2.second) {
			return true;
		} else {
			return false;
		}
	}

bool operator < (const Time& t1, const Time& t2) {
		if (t1.hour * 10000 + t1.minute * 100 + t1.second < t2.hour * 10000 + t2.minute * 100 + t2.second) {
			return true;
		} else {
			return false;
		}
	}
	
bool operator >= (const Time& t1, const Time& t2) {
		if (t1.hour * 10000 + t1.minute * 100 + t1.second >= t2.hour * 10000 + t2.minute * 100 + t2.second) {
			return true;
		} else {
			return false;
		}
	}
	
bool operator <= (const Time& t1, const Time& t2) {
		if (t1.hour * 10000 + t1.minute * 100 + t1.second <= t2.hour * 10000 + t2.minute * 100 + t2.second) {
			return true;
		} else {
			return false;
		}
	}
	
bool operator == (const Time& t1, const Time& t2) {
		if (t1.hour * 10000 + t1.minute * 100 + t1.second == t2.hour * 10000 + t2.minute * 100 + t2.second) {
			return true;
		} else {
			return false;
		}
	}	
	
bool operator != (const Time& t1, const Time& t2) {
		if (t1.hour * 10000 + t1.minute * 100 + t1.second != t2.hour * 10000 + t2.minute * 100 + t2.second) {
			return true;
		} else {
			return false;
		}
	}	
int main()
{
	Time t = Time(12,0,59);
	Time t1 = Time(13,0,0);
	cout << t.toString() << "\n";
	t++;
	cout << t.toString() << "\n";
	t--;
	t--;
	cout << t.toString() << "\n";
	++t;
	++t;
	cout << "Time t = " << t.toString() << "\n";
	cout << "Time t1 = " << t1.toString() << "\n";
	cout << "Comapre result t > t1 results in " << (t > t1) << "\n";
	cout << "Comapre result t < t1 results in " << (t < t1) << "\n";
	cout << "Comapre result t >= t1 results in " << (t >= t1) << "\n";
	cout << "Comapre result t <= t1 results in " << (t <= t1) << "\n";
	cout << "Comapre result t == t1 results in " << (t == t1) << "\n";	
	cout << "Comapre result t != t1 results in " << (t != t1) << "\n";
	cout << " ";
	system("pause");
    return 0;
}
