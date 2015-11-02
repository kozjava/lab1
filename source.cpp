#include<iostream>
#include<cmath>

#define PI 3.14159
class ArrayOfCircles;
using namespace std;
class Circle
{
private:
	int x;
	int y;
	int radius;
public:
	friend class ArrayOfCircles;
	Circle::Circle()
	{
		cout << "Constructor" << endl;
	}
	Circle(int X, int Y, int R)
	{
		x = X;
		y = Y;
		radius = R;
	}
	bool setx(int X)
	{
		x = X;
		return true;
	}
	bool sety(int Y)
	{
		y = Y;
		return true;
	}
	bool setr(int R)
	{
		radius = R;
		return true;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int getr()
	{
		return radius;
	}
	bool check(int x, int y, int radius)
	{
		int x0 = 0;
		int y0 = 0;
		if (pow((x - x0), 2) + pow((y - y0), 2) == radius)
		{
			cout << "Correct...." << endl;
			cout << endl;
			return true;
		}
		else
		{
			cout << "Error.... Please try again: " << endl;
			cout << endl;
			return false;
		}
	}
	float square()
	{
		cout << "The area of a circle: " << PI *pow(radius, 2) << " square units." << endl;
		cout << endl;
		return PI *pow(radius, 2);
	}
	float length()
	{
		cout << "Circumference: " << 2 * PI * radius << " units" << endl;
		cout << endl;
		return PI *pow(radius, 2);
	}
	void Circle::show()
	{
		cout << this->x << "  " << this->y << "  " << this->radius << endl;
	}
};
class ArrayOfCircles
{
private: Circle*array[256];
		 int num = 0;
public:
	Circle zz;
	void add()
	{
		
		int X, Y, R;
		int count = 0;
		cout << "Enter count: "; cin >> count; num = count;
		for (int i = 0; i < count&&count < 256; i++)
		{
			cout << "Please Enter x: "; cin >> X; cout << endl;
			cout << "Please Enter y: "; cin >> Y; cout << endl;
			cout << "Please Enter R: "; cin >> R; cout << endl;
			Circle *pp = new Circle;
			if (zz.check(X, Y, R) == true)
			{
				if (pp->setx(X) && pp->sety(Y) && pp->setr(R))
				{
					array[i] = pp;
				}
				else
				{
					i--;
					cout << "Error... Please try again" << endl;
				}
			}
		}

	}
	void out(int radius)
	{
		for (int i = 0; i <num&&num < 256; i++)
		{
			cout << "x  y  R" << endl;
			cout << endl;
			array[i]->show();
			cout << "---------" << endl;
			array[i]->length();
			array[i]->square();
			cout << "---------" << endl;
		}
	}
	void CheckOnALine()
	{
		int a,b,c;
		cout << "Enter the line (x or y): " << endl;
		cin >> c;
		if (c == 1)
		{
			cout << "Enter x: "; cin >> a;
			for (int i = 0; i < num; i++)
			{
				if (array[i]->getx() == a)
				{
					array[i]->show();
					cout << "----------" << endl;		
				}
				if(array[i]->getx() != a)
				{
					cout << "Error...." << endl;
				}
			}
		}
		if (c == 2)
		{
			cout << "Enter y: "; cin >> a;
			for (int i = 0; i < num; i++)
			{
				if (array[i]->gety() == a)
				{
					array[i]->show();
					cout << "----------" << endl;
				}
				if (array[i]->gety() != a)
				{
					cout << "Error...." << endl;
				}

			}
		}
	}
	void CheckSquare()
	{
		double max = 0;
		for (int i = 0; i < num; i++)
		{
			array[i]->getr();
			if (array[i]->square() > max)
			{
				max = array[i]->square();
				//cout << "max: " << max << endl;
			}
		}
		cout << "max: " << max <<" square units."<< endl;
		cout << endl;
	}

	void firstquarter()
	{
		cout << "Circumferentially's that located in the first quarter: " << endl;
		for (int i = 0; i < num; i++)
		{
			if (array[i]->getx() && array[i]->gety() >= 0)
			{

				array[i]->show();
				cout << "----------" << endl;

			}
			else
			{
				cout << "Error... Some circles are located out of first quarter" << endl;
			}
		}
	}
};
int main(int x,int y,int radius,int count)
{
	Circle obj;
	ArrayOfCircles qq;
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "1 - Array of data's " << endl;
		cout << "2 - Show array(Calculate the area of a circle + Calculate circumference)" << endl;
		cout << "3 - Check coordinate axis" << endl;
		cout << "4 - Compare squares" << endl;
		cout << "5 - Check first quarter" << endl;
		cout << endl;
		cout << "Choose something: "; cin >> flag;
		switch (flag)
		{
		case 1:qq.add(); break;
		case 2:qq.out(radius); break;
		case 3:qq.CheckOnALine(); break;
		case 4:qq.CheckSquare(); break;
		case 5:qq.firstquarter(); break;
		default: flag = 0;
			break;
		}
	}
	system("pause");
	return 0;
}
