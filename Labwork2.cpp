#include <iostream>
using namespace std;

class vect {
	double* b;
	int dim;
	static int count;
public:
	int num;
	vect();
	vect(int n, double x[]);
	vect(vect& x);
	~vect();
	void print();
	void operator= (vect& r);
	vect operator +(vect& r);
	friend vect* operator-(vect& l, vect& r);
	vect operator-();
	friend vect* operator*(double k, vect& r);
	friend vect* operator*(vect& r, double k);
	friend vect* operator*(vect& r, vect& l);
};

int vect::count = 0;

vect::vect() {
	b = 0;
	dim = 0;
	count++;
	num = count;
	cout << "Konstruktor vect() sozdal vector - " << num << endl;
}

vect::vect(int n, double x[]) {
	count++;
	num = count;
	dim = n;
	b = new double[dim];
	for (int i = 0; i < dim; i++)
		b[i] = x[i];
	cout << "Konstruktor vect(int n, double x[]) sozdal vector - " << num << endl;
}

vect::vect(vect& x) {
	count++;
	num = count;
	dim = x.dim;
	b = new double[x.dim];
	for (int i = 0; i < dim; i++) {
		b[i] = x.b[i];
	}
	cout << "Konstruktor vect(vect &x) sozdal vector - " << num << endl;
}

void vect::print() {
	cout << "dim vectora:" << " " << dim << endl;
	cout << "Vector: ";
	cout << "{ ";
	for (int i = 0; i < dim; i++)
	{
		cout << b[i] << (i != dim - 1 ? ", " : "");

	}
	cout << " }" << endl;
}

vect::~vect() {
	delete[]b;
	cout << "Uni4tozhaem vector - " << num << endl;
}

void vect::operator=(vect& r) {
	if (b == NULL) {
		dim = r.dim;
		b = new double[dim];
	}
	for (int i = 0; i < dim; i++) {
		b[i] = r.b[i];
	}
	cout << "Peregruzka operatora =" << endl;

}

vect vect::operator+(vect& r) {
	cout << "Summirovanie: vector " << num << "+ vector " << r.num << endl;
	if (b == NULL) {
		dim = r.dim;
		b = new double[dim];
	}
	for (int i = 0; i < dim; i++) {
		b[i] += r.b[i];
	}
	cout << "Vypolnyaetsya slozhenie" << endl;
	return *this;
}

vect vect::operator-() {
	for (int i = 0; i < dim; i++) {
		b[i] = 0 - b[i];
	}
	cout << "Unarniy minus" << endl;
	return *this;
}

vect* operator *(vect& r, double k) {
	for (int i = 0; i < r.dim; i++) {
		r.b[i] = r.b[i] * k;
	}
	cout << "Peregruzka operatora *" << endl;
	return &r;
}

vect* operator *(double k, vect& r) {
	for (int i = 0; i < r.dim; i++) {
		r.b[i] = r.b[i] * k;
	}
	cout << "Peregruzka operatora *" << endl;
	return &r;
}

vect* operator *(vect& r, vect& l) {
	for (int i = 0; i < r.dim; i++) {
		r.b[i] = r.b[i] * l.b[i];
	}
	cout << "Peregruzka operatora *" << endl;
	return &r;
}

vect* operator-(vect& l, vect& r) {
	for (int i = 0; i < r.dim; i++) {
		l.b[i] = l.b[i] - r.b[i];
	}
	cout << "Peregruzka operatora -" << endl;
	return &l;
}

int main() {

	int dim = 3;
	double* b = new double[dim];
	b[0] = 3;
	b[1] = 3;
	b[2] = 3;


	int dim2 = 3;
	double* b1 = new double[dim2];
	b1[0] = 2;
	b1[1] = 2;
	b1[2] = 2;

	vect a1(dim, b);
	vect a2(dim2, b1);

	a1* a2;
	a1.print();
	a2.print();
	system("PAUSE");
	return 0;
}