#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Vector {
	public: int* coords[6];
	
	public: Vector(int* _v) {
		coords[6] = _v;
	}
	
	public: int* x1() {
		int* res = this->coords[0];
		return res;
	}	
	public: string toString() {
		char res[100];
		snprintf(res, sizeof(res), "Vector coords %dx%dx%d - %dx%dx%d\n", coords[0],coords[1],coords[2],coords[3],coords[4],coords[5]);
		string result = res;
		return result;
	}

	
};

	Vector operator * (const Vector &v1, const Vector &v2)
	{
		int r1 = &v1.x1();
		int r2 = 2;
		int r3 = r1 + r2;
		int _c[6] = { v1.coords[0], v1.coords[1], v1.coords[2], r3, v1.coords[4] + v2.coords[4], v1.coords[5] + v2.coords[5] };
		Vector _v = Vector(_c[6]);
		return _v;
	}

int main()
{
	int c1[6] = { 1,2,3,4,5,6 };
	int c2[6] = { 7,8,9,8,7,6 };
	int i = 2;
	Vector v1 = Vector(c1);
	Vector v2 = Vector(c2);
	cout << v1.toString();
	cout << v2.toString();
	v1 = v1 * v2;
	cout << v1.toString();
	cout << " ";
	system("pause");
    return 0;
}
