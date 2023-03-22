#include "Number.h"

int Number::myatoi(const char*sir) {
	
		int nou = 0;
		int i = 0;
		if (sir[i] == '-')
			i++;
		for (; i < strlen(sir); ++i)
		{
			nou = nou * 10 + (sir[i] - '0');
		}
		if (sir[0] == '-')
			nou *= -1;
		return nou;

}


Number::Number(const char* value, int base) {
	this->base = base;
	int count = 0;
	this->value = new char[strlen(value)+1];
	for (int i = 0; i < strlen(value); i++) {
		this->value[i] = value[i];
	}
	this->value[strlen(value)] = '\0';

}

Number::Number(const Number& n) {
	base = n.base;
	value = new char[strlen(n.value) + 1];
	std::strcpy(value, n.value);

}

Number::Number(Number&& n) {
	value = n.value;
	n.value = nullptr;
	base = n.base;
}

Number::Number(int value) {
	int copy = value;
	this->base = 10;
	int count = 0;
	while (copy) {
		copy /= 10;
		++count;
	}
	
		count++;
		if (value < 0)
			count++;
		this->value = new char[count] {};
	
	int i = count-2;
	int value_temp = value;
	if(value<0)
		value_temp *= -1;
	while (value_temp) {
		int digit = value_temp % 10;
		value_temp /= 10;
		char c = digit + '0';
		this->value[i--] = c;
	}
	if (value < 0)
		this->value[0] = '-';
}

int Number::GetDigitsCount() {
	int nr = 0;
	for (int i = 0; i < strlen(this->value); i++)
	{
		nr++;
	}
	return nr;
}

void Number::SwitchBase(int newBase) {
	int i = 0;
	if (this->value[0] == '-')
		i++;
	
	if (newBase > 16 || newBase < 2) {
		printf("Erorr, choose a base between 2 and 16\n");
		return;
	}
	
	int decimalValue = 0;
	int power = 1;
	for (int j = strlen(value) - 1; j >= i; j--) {
		int digit = (isdigit(value[j])) ? (value[j] - '0') : (tolower(value[j]) - 'a' + 10);
		decimalValue += digit * power;
		power *= base;
	}
	
	char* newValue = new char[strlen(value)*4+2];
	int index = 0;
	if (this->value[0] == '-')
		index++;
	while (decimalValue != 0) {
		int remainder = decimalValue % newBase;
		newValue[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
		decimalValue /= newBase;
	}
	newValue[index] = '\0';
	int j = strlen(newValue) - 1;
	if (this->value[0] == '-')
		newValue[0] = '-';
	for (; (this->value[0]=='-' ?i - 1:i) < (strlen(newValue) - (this->value[0] == '-' ? 1 : 0)) / 2; i++) {
		std::swap(newValue[i], newValue[j--]);
	}
	
	base = newBase;
	delete[] value;
	value = newValue;
	
}

bool Number::operator>(const Number& other) {
	if (this->base != other.base) {
		printf("Cannot compare numbers with different bases.\n");
		return false;
	}
	if (strlen(this->value) > strlen(other.value)) {
		return true;
	}
	else if (strlen(this->value) < strlen(other.value)) {
		return false;
	}
	else {
		for (int i = 0; i < strlen(this->value); i++) {
			if (this->value[i] > other.value[i]) {
				return true;
			}
			else if (this->value[i] < other.value[i]) {
				return false;
			}
		}
		return false;
	}
}

bool Number::operator>=(const Number& other) {
	if (this->base != other.base) {
		printf("Cannot compare numbers with different bases.\n");
		return false;
	}
	if (strlen(this->value) > strlen(other.value)) {
		return true;
	}
	else if (strlen(this->value) < strlen(other.value)) {
		return false;
	}
	else {
		for (int i = 0; i < strlen(this->value); i++) {
			if (this->value[i] > other.value[i]) {
				return true;
			}
			else if (this->value[i] < other.value[i]) {
				return false;
			}
		}
		return true;
	}
}

bool Number::operator<(const Number& other) {
	return !(this->operator>=(other));
}

bool Number::operator<=(const Number& other) {
	return !(this->operator>(other));
}

bool Number::operator==(const Number& other) {
	if (this->base != other.base) {
		printf("Cannot compare numbers with different bases.\n");
		return false;
	}
	if (strlen(this->value) != strlen(other.value)) {
		return false;
	}
	else {
		for (int i = 0; i < strlen(this->value); i++) {
			if (this->value[i] != other.value[i]) {
				return false;
			}
		}
		return true;
	}
}

bool Number::operator!=(const Number& other) {
	return !(this->operator==(other));
}

Number operator+(const Number& left, const Number& right) {
	

	int resultBase = std::max(left.base, right.base);

	Number left_temp = left;
	Number right_temp = right;


	left_temp.SwitchBase(10);
	right_temp.SwitchBase(10);

	int x= Number::myatoi(left_temp.value);
	int y = Number::myatoi(right_temp.value);

	Number result(x + y);
	result.SwitchBase(resultBase);

	return result;

	
}

Number operator-(const Number& left, const Number& right) {
	int resultBase = std::max(left.base, right.base);

	Number left_temp = left;
	Number right_temp = right;


	left_temp.SwitchBase(10);
	right_temp.SwitchBase(10);

	int x = Number::myatoi(left_temp.value);
	int y = Number::myatoi(right_temp.value);

	Number result(x - y);
	result.SwitchBase(resultBase);

	return result;
}

Number& Number::operator=(const Number& n) {
	base = n.base;
	if (value != nullptr)
		delete[] value;
	value = new char[strlen(n.value) + 1];
	std::strcpy(value, n.value);

	return *this;
}


Number& Number::operator=(Number&& n) {	
	if (value != nullptr) {
		delete[] value;
	}
	value = n.value;
	n.value = nullptr;
	base = n.base;

	return *this;
}

Number Number::operator--() {
	memmove(value, value + 1, strlen(value));
	return *this;
}

Number Number::operator--(int) {
	value[strlen(value) - 1] = NULL;
	return *this;
}

Number Number::operator++() {
	*this = *this + Number("1", base);
	return *this;
}

Number Number::operator++(int) {
	Number temp(*this);
	++(*this);
	return temp;
}

char Number::operator[](int index) {
	if (index<0 || index>=this->GetDigitsCount())
	{
		printf("Erorr");
		return 0;
	}
	return value[index];
}



void Number::Print() {
	printf("%s\n", this->value);
}

int Number::GetBase() {
	return this->base;
}


Number::~Number() {
	if (value != nullptr) {
		delete[] value;
	}
	
}

