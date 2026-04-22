#include "Time_.h"

Time_::Time_()
{
	tm* info = new tm;
	auto curent = time(0);
	localtime_s(info, &curent);
	hour = info->tm_hour;
	minutes = info->tm_min;
	seconds = info->tm_sec;
	format = true;
	delete info;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	this-> format = format;
}

//Time_::Time_(const Time_& obj)
//{
//}
//
//Time_& Time_::operator=(const Time_& obj)
//{
//	// TODO: insert return statement here
//}
//
//Time_::~Time_()
//{
//}

void Time_::setHour(int hour)
{
	if(hour >=0 && hour <24)
		this->hour = hour;
}

int Time_::getHour() const
{
	return hour;
}

void Time_::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes <= 59)	
		this->minutes = minutes;
}

int Time_::getMinutes() const
{
	return minutes;
}

void Time_::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds <= 59)
		this->seconds = seconds;
}

int Time_::getSeconds() const
{
	return seconds;
}

void Time_::setFormat(bool format)
{
	this->format = format;
}

bool Time_::getFormat() const
{
	return format;
}

bool Time_::valid() const
{
	return (hour>=0 && hour < 24 && minutes >=0 && minutes <60 && seconds >=0 && seconds <60);
}

void Time_::tickTime()
{
	if (valid())
	{
		seconds++;
		if (seconds == 60)
		{
			seconds = 0;
			minutes++;
			if (minutes == 60)
			{
				minutes = 0;
				hour++;
				if (hour == 24)
					hour = 0;
			}
		}
	}
}

void Time_::untickTime()
{
	if (valid())
	{
		seconds--;
		if (seconds == -1)
		{
			seconds = 59;
			minutes--;
			if (minutes == -1)
			{
				minutes = 59;
				hour--;
				if (hour < 0)
					hour = 23;
			}
		}
	}
}

void Time_::showTime() const
{
	if (format)
	{
		cout << (hour < 10 ? "0":"")<<hour<<":"
			<< (minutes < 10 ? "0" : "") << minutes << ":"
			<< (seconds < 10 ? "0" : "") << seconds << endl;
	}
	else
	{
		int h = (hour > 12 ? hour - 12 : hour);
		if (h == 0) h = 12;

		cout <<(h<10 ? "0":"")<<h << ":"
			<< (minutes < 10 ? "0" : "") << minutes << ":"
			<< (seconds < 10 ? "0" : "") << seconds << " "
			<< (hour >= 12 ? "PM" : "AM") << endl;
	}	
}

bool Time_::operator==(const Time_& obj) const&
{
	return this->hour == obj.hour&&this->minutes == obj.minutes&&this->seconds==obj.seconds;
}

bool Time_::operator!=(const Time_& obj) const&
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
	if (this->hour > obj.hour)
	{
		return true;
	}
	else if(this->hour == obj.hour && this->minutes > obj.minutes)
	{
		return true;
	}
	else if(this->hour == obj.hour && this->minutes == obj.minutes && this->seconds > obj.seconds)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time_::operator<(const Time_& obj) const&
{
	return !(*this>obj)&& *this != obj;
}

bool Time_::operator>=(const Time_& obj) const&
{
	return (*this > obj) || *this == obj;
}

bool Time_::operator<=(const Time_& obj) const&
{
	return !(*this > obj);
}

Time_& Time_::operator+=(float s)
{
	for (int i = 0; i < s; i++)
	{
		tickTime();
	}
	return *this;
}

Time_& Time_::operator-=(float s)
{
	for (int i = 0; i < s; i++)
	{
		untickTime();
	}
	return *this;
}

Time_& Time_::operator+=(int m)
{
	this->minutes += m;
	while (this->minutes >= 60)
	{
		this->minutes -= 60;
		this->hour++;
	}
	if (hour >= 24)
		hour %= 24;
	return *this;
}

Time_& Time_::operator-=(int m)
{
	this->minutes -= m;
	while (this->minutes < 0)
	{
		this->minutes += 60;
		this->hour--;
	}
	if(hour <0)
		hour = (hour % 24 + 24) % 24;
	return *this;
}

Time_& Time_::operator+=(long h)
{
	this->hour = (this->hour + h) % 24;
	if (this->hour < 0)
		this->hour += 24;
	return *this;
}

Time_& Time_::operator-=(long h)
{
	this->hour = (this->hour - h) % 24;
	if (this->hour < 0)
		this->hour += 24;
	return *this;
}

Time_ Time_::operator+(float s) const&
{
	Time_ tmp = *this;
	tmp += s;
	return tmp;
}

Time_ Time_::operator-(float s) const&
{
	Time_ tmp = *this;
	tmp -= s;
	return tmp;
}

Time_ Time_::operator+(int m) const&
{
	Time_ tmp = *this;
	tmp += m;
	return tmp;
}

Time_ Time_::operator-(int m) const&
{
	Time_ tmp = *this;
	tmp -= m;
	return tmp;
}

Time_ Time_::operator+(long h) const&
{
	Time_ tmp = *this;
	tmp += h;
	return tmp;
}

Time_ Time_::operator-(long h) const&
{
	Time_ tmp = *this;
	tmp -= h;
	return tmp;
}

Time_& Time_::operator--()
{
	this->untickTime();
	return*this;
}

Time_ Time_::operator--(int)
{
	Time_ tmp = *this;
	this->untickTime();
	return tmp;
}

Time_& Time_::operator++()
{
	this->tickTime();
	return*this;
}

Time_ Time_::operator++(int)
{
	Time_ tmp = *this;
	this->tickTime();
	return tmp;
}

Time_ operator+(int seconds, const Time_& a)
{
	return a + seconds;
}

Time_ operator-(int seconds, const Time_& a)
{
	return a - seconds;
}

Time_ operator+(float minutes, const Time_& a)
{
	return a + minutes;
}

Time_ operator-(float minutes, const Time_& a)
{
	return a - minutes;
}

Time_ operator+(long hours, const Time_& a)
{
	return a + hours;
}

Time_ operator-(long hours, const Time_& a)
{
	return a - hours;
}

ostream& operator<<(ostream& os, const Time_& t)
{
	os << (t.hour < 10 ? "0" : "") << t.hour << ":"
		<< (t.minutes < 10 ? "0" : "") << t.minutes << ":"
		<< (t.seconds < 10 ? "0" : "") << t.seconds;
	return os;
}

istream& operator>>(istream& is, Time_& t)
{
	do {
		
		is >> t.hour >> t.minutes>> t.seconds;

	} while (!t.valid());
	return is;
}
