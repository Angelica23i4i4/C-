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
    double& operator[](int i); // Access element
    int size() const { return dim; } // Get dimension size
    friend class Matrix; // Allow Matrix class to access private members
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
    for (int i = 0; i < dim; i++) {
        cout << b[i] << (i != dim - 1 ? ", " : "");
    }
    cout << " }" << endl;
}

vect::~vect() {
    delete[] b;
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
    if (dim != r.dim) {
        cout << "Error: Dimensions do not match for addition!" << endl;
        exit(1);
    }
    vect result(*this);
    for (int i = 0; i < dim; i++) {
        result.b[i] += r.b[i];
    }
    cout << "Vypolnyaetsya slozhenie" << endl;
    return result;
}

vect vect::operator-() {
    for (int i = 0; i < dim; i++) {
        b[i] = 0 - b[i];
    }
    cout << "Unarniy minus" << endl;
    return *this;
}

vect* operator*(vect& r, double k) {
    for (int i = 0; i < r.dim; i++) {
        r.b[i] = r.b[i] * k;
    }
    cout << "Peregruzka operatora *" << endl;
    return &r;
}

vect* operator*(double k, vect& r) {
    for (int i = 0; i < r.dim; i++) {
        r.b[i] = r.b[i] * k;
    }
    cout << "Peregruzka operatora *" << endl;
    return &r;
}

vect* operator*(vect& r, vect& l) {
    if (r.dim != l.dim) {
        cout << "Error: Dimensions do not match for multiplication!" << endl;
        exit(1);
    }
    for (int i = 0; i < r.dim; i++) {
        r.b[i] = r.b[i] * l.b[i];
    }
    cout << "Peregruzka operatora *" << endl;
    return &r;
}

vect* operator-(vect& l, vect& r) {
    if (l.dim != r.dim) {
        cout << "Error: Dimensions do not match for subtraction!" << endl;
        exit(1);
    }
    for (int i = 0; i < r.dim; i++) {
        l.b[i] = l.b[i] - r.b[i];
    }
    cout << "Peregruzka operatora -" << endl;
    return &l;
}

double& vect::operator[](int i) {
    if (i >= dim || i < 0) {
        cout << "Index out of bounds" << endl;
        exit(1);
    }
    return b[i];
}

class Matrix {
    double** data;
    int rows, cols;
public:
    Matrix(int r, int c);
    Matrix(const Matrix& m);
    ~Matrix();
    void print();
    Matrix operator*(double k);
    Matrix operator*(const Matrix& m);
    vect operator*(const vect& v);
    Matrix operator=(const Matrix& m);
    double* operator[](int i) const; // Access row
};

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& m) : rows(m.rows), cols(m.cols) {
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void Matrix::print() {
    cout << "Matrix: " << rows << "x" << cols << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator*(double k) {
    Matrix result(*this);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] *= k;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& m) {
    if (cols != m.rows) {
        cout << "Error: Matrix dimensions do not match for multiplication!" << endl;
        exit(1);
    }
    Matrix result(rows, m.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    return result;
}

vect Matrix::operator*(const vect& v) {
    if (cols != v.size()) {
        cout << "Error: Matrix and vector dimensions do not match for multiplication!" << endl;
        exit(1);
    }
    double* resultData = new double[rows];
    for (int i = 0; i < rows; ++i) {
        resultData[i] = 0;
        for (int j = 0; j < cols; ++j) {
            resultData[i] += data[i][j] * v.b[j];
        }
    }
    vect result(rows, resultData);
    delete[] resultData;
    return result;
}

Matrix Matrix::operator=(const Matrix& m) {
    if (this == &m) return *this;
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
    rows = m.rows;
    cols = m.cols;
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
    return *this;
}

double* Matrix::operator[](int i) const {
    if (i >= rows || i < 0) {
        cout << "Index out of bounds" << endl;
        exit(1);
    }
    return data[i];
}

int main() {
    int dim = 3;
    double* b = new double[dim] { 3, 3, 3 };
    int dim2 = 3;
    double* b1 = new double[dim2] { 2, 2, 2 };

    vect a1(dim, b);
    vect a2(dim2, b1);

    double mat_data[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix m(3, 3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] = mat_data[i][j];

    Matrix m2 = m * 2.0;
    m2.print();

    Matrix m3 = m * m;
    m3.print();

    vect v3 = m * a1;
    v3.print();

    a1.print();
    a2.print();

    system("PAUSE");
    return 0;
}