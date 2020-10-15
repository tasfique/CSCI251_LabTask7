//Name-Tasfique Enam
//Student ID- 5886429
//Question2

#include <iostream>
using namespace std;

class House
{
	private:
		string address;
		float size;

	public:
		House();
		House(string, float);
		void displayHouse();
};

House::House()
{
	address="";
	size=0.0;
}

House::House(string address, float size) : address(address), size(size) {}

void House::displayHouse()
{
	cout << "Address : " << address << endl;
	cout << "Size : " << size << endl;
}

class Investment
{
	private:
		float initialValue;
		float currentValue;
		float profit;
		float percentageProfit;

	public:
		Investment();
		Investment(float, float);
		void displayInvestment();
};

Investment::Investment()
{
	initialValue=0.0;
	currentValue=0.0;
	profit=0.0;
	percentageProfit=0.0;
}

Investment::Investment(float initialValue, float currentValue)
{
	this->initialValue=initialValue;
	this->currentValue=currentValue;
	this->profit=currentValue-initialValue;
	this->percentageProfit=profit/initialValue;
}

void Investment::displayInvestment()
{
	cout << "Initial Value : " << initialValue << endl;
	cout << "Current value : " << currentValue << endl;
	cout << "Profit : " << profit << endl;
	cout << "Profit Percentage : " << percentageProfit<< "%" << endl;
}

class HouseInvest : public Investment, public House
{
	public:
		HouseInvest();
		HouseInvest(float, float, string, float);
};

HouseInvest::HouseInvest() : Investment(), House() {}

HouseInvest::HouseInvest(float initialValue, float currentValue, string address, float size) : Investment(initialValue, currentValue), House(address, size) {}

int main()
{
	HouseInvest houseinvest(800, 2000, "SS15", 1000);
	houseinvest.displayInvestment();
	houseinvest.displayHouse();
	return 0;
}

