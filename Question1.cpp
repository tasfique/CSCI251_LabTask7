//Name- Tasfique Enam
//Student ID-5886429
//Question1

#include <iostream>

using namespace std;

class Payment {
private:
    float payment;
public:
    Payment();
    Payment(float);
    void setFields(float);
    float getPayment();
    virtual void paymentDetails();


};

Payment::Payment() { //default constructor
    payment = 0.0;
}

Payment::Payment(float payment) : payment(payment) { //non default constructor.
}

void Payment::setFields(float payment) {
    this->payment = payment;
}

float Payment::getPayment() {
    return payment;
}

void Payment::paymentDetails()
{
	cout << "Pay : " << payment << endl;
}

class CashPayment : public Payment {
private:
    float balanceDue;
public:
    CashPayment();
    CashPayment(float, float);
    using Payment::setFields;
    void setFields(float, float);
    void paymentDetails() override;
};

CashPayment::CashPayment() : Payment() { //default constructor
    balanceDue = 0.0;
}

CashPayment::CashPayment(float payment, float balanceDue) : Payment(payment), balanceDue(balanceDue) { //non default constructor.

}

void CashPayment::setFields(float payment, float balanceDue) { //overloading
    setFields(payment);
    this->balanceDue = balanceDue;
}

void CashPayment::paymentDetails() {
    cout << "Payment : " << getPayment() << endl;
	cout << "Balance Due : " << balanceDue << endl;
	cout << endl;
}

class CreditCardPayment : public Payment
{
	private:
		string name;
		string expiryDate;
		string cardNo;

	public:
		CreditCardPayment();
		CreditCardPayment(float, string, string, string);
		using Payment::setFields;
		void setFields(float, string, string, string);
		void paymentDetails() override;
};

CreditCardPayment::CreditCardPayment() : Payment()
{
	name = "";
	expiryDate = "";
	cardNo = "";
}

CreditCardPayment::CreditCardPayment(float payment, string name, string expDate, string cardNo) : Payment(payment), name(name), expiryDate(expDate), cardNo(cardNo) {}

void CreditCardPayment::setFields(float payment, string name, string expiryDate, string cardNo)
{
	setFields(payment);
	this->name = name;
	this->expiryDate = expiryDate;
	this->cardNo = cardNo;
}

void CreditCardPayment::paymentDetails()
{
	cout << "Payment : " << getPayment() << endl;
	cout << "Card Name : " << name << endl;
	cout << "Card Expiration : " << expiryDate << endl;
	cout << "Card Number : " << cardNo << endl;
	cout << endl;
}



int main() {
    CashPayment cashPayment1(10, 20);
	CashPayment cashPayment2;
	cashPayment2.setFields(39, 60);

	CreditCardPayment creditCardPayment1(70, "Mary", "2021-01-22", "3243-2344-6787-9823");
	CreditCardPayment creditCardPayment2;
    creditCardPayment2.setFields(30, "Poo", "2020-11-01", "9733-3659-8763-3452");

	cashPayment1.paymentDetails();
	cashPayment2.paymentDetails();
	creditCardPayment1.paymentDetails();
	creditCardPayment2.paymentDetails();

    return 0;
}

