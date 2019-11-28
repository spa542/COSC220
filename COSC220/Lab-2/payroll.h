#ifndef PAYROLL_H_
#define PAYROLL_H_
#include <string>

class PayRoll {
private:
	std::string name;
	int payrate;
	double hours;
public:	
	PayRoll();
	PayRoll(std::string, int);
	void setHours(double);
	double calculatePay();
	void printInfo();
	std::string getName();
};

#endif
