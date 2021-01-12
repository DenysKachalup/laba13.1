//////////////////////////////////////////////////////////////////////////////
// Lab 13.1.cpp
// головний файл проекту – функція main
#include <iostream>
#include <math.h>
#include <iomanip>
#include "dod.h"
#include "sum.h"
#include "var.h"
using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;
int main()
{
	cout << "x_p = "; cin >> x_p;
	cout << "x_k = "; cin >> x_k;
	cout << "dx = "; cin >> dx;
	cout << "e = "; cin >> e;
	cout << endl;
	x = x_p;
	while (x <= x_k) {
		nsSum::sum();
		cout << x << " "
			<< s << " "
			<< exp(x) << " "
			<< n << endl;
		x += dx;
	}
	cin.get();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
// var.h
// заголовочний файл – оголошення глобальних змінних
#pragma once
namespace nsVar {

	extern int n;
	extern double x, x_p, x_k, dx, e, a, s;
};
//////////////////////////////////////////////////////////////////////////////
// var.cpp
// файл реалізації – визначення глобальних зміннихnamespace nsVar { 
int n;
double x, x_p, x_k, dx, e, a, s;
};
//////////////////////////////////////////////////////////////////////////////
// dod.h
// заголовочний файл – оголошення функції
#pragma once
namespace nsDod {
	void dod();
};
//////////////////////////////////////////////////////////////////////////////
// dod.cpp
// файл реалізації функції#include "dod.h"
#include "var.h" 
using namespace nsVar;
void nsDod::dod() {
	a *= (-x) / n;
}
//////////////////////////////////////////////////////////////////////////////
// sum.h
// заголовочний файл – оголошення функції
#pragma once
namespace nsSum {
	void sum();
};
//////////////////////////////////////////////////////////////////////////////
// sum.cpp
// файл реалізації функції
#include <math.h>
#include "dod.h"
#include "sum.h"
#include "var.h"
using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
	n = 0;
	a = 1;
	s = a;
	do {
		n++;
		dod();
		s += a;
	} while (fabs(a) > e);
}
