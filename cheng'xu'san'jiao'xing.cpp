#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

using namespace std;


double maxArea = 0.0;
double maxzhouchang = 0.0;


double area_a = 0.0;
double area_b = 0.0;
double area_c = 0.0;


double perim_a = 0.0;
double perim_b = 0.0;
double perim_c = 0.0;



/*----------------------------------*
	 三角形相关信息
*-----------------------------------*/

//计算是否构成三角形
int isTriangle(const double &r1, const double &r2, const double&r3)
{
	if ((r1 + r2 > r3) && (r1 + r3 > r2) && (r2 + r3 > r1))
	{
		return 1;
	}
	else
		return 0;
}

//计算三角形周长
double zhouchang(const double &r1, const double &r2, const double&r3)
{
	return (r1 + r2 + r3);
}



//计算三角形面积
double area(const double &r1, const double &r2, const double&r3)
{

	double p = 0.5*(r1 + r2 + r3);


	return sqrt(p*(p - r1)*(p - r2)*(p - r3));


}





//搜索最大周长
int searchMaxLength(const double *p, const int n)
{
	bool canConstructTriangle = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{

				if (isTriangle(p[i], p[j], p[k]))
				{
					double tempzhouchang = zhouchang(p[i], p[j], p[k]);

					if (tempzhouchang > maxzhouchang)
					{
						maxzhouchang = tempzhouchang;

						//记录当前边长
						perim_a = p[i];
						perim_b = p[j];
						perim_c = p[k];

					}

					canConstructTriangle = true;//存在构成三角形的木棍

				}

				else
					continue;
			}

		}
	}

	if (canConstructTriangle == false)
	{
		cout << "提示: 木棍长度无法构成三角形!" << endl;
		return 0;
	}
	else
		return 1;

}

//搜索最大面积
int searchMaxArea(const double *p, const int n)
{
	bool canConstructTriangle = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{

				if (isTriangle(p[i], p[j], p[k]))
				{
					double tempArea = area(p[i], p[j], p[k]);


					if (tempArea > maxArea)
					{
						maxArea = tempArea;

						//记录当前边长
						area_a = p[i];
						area_b = p[j];
						area_c = p[k];

					}

					canConstructTriangle = 1;//存在构成三角形的木棍

				}

				else
					continue;
			}
		}
	}

	if (canConstructTriangle == 0)
	{
		cout << "提示: 木棍长度无法构成三角形!" << endl;
		return 0;

	}
	else
		return 1;


}
/*----------------------------------*
		  主函数
*-----------------------------------*/

int main()
{


	/*----------------------------------*
		   1. 输入木棍个数和长度
	*-----------------------------------*/
	cout << "-------------- 输入数据 --------------" << endl;

	cout << "请输入木棍的总个数 m = ";

	int m;
	cin >> m;

	// 动态分配内存空间，存储木棍长度

	double *len = new double[m];

	cout << "请依次输入" << m << "根木棍的长度" << endl;

	for (int i = 0; i < m; i++)
	{
		cout << "len[" << i << "] = ";
		cin >> len[i];


	}


	cout << endl << "-------------- 输出结果 --------------" << endl;


	/*----------------------------------*
		  2. 搜索最大周长,并输出周长
	*-----------------------------------*/


	int success = searchMaxLength(len, m); //复杂度高
	

	if (success == 1)
	{
		cout << "最大周长: " << maxzhouchang << " (边长为: " << perim_a << "," << perim_b << "," << perim_c << ")" << endl;

	}
	else
	{
		cout << 0 << endl;
		cout << "提示: 木棍长度无法构成三角形!" << endl;
	}


	/*----------------------------------*
		  3. 搜索最大面积,并输出面积
	*-----------------------------------*/

	int area_success = searchMaxArea(len, m);

	

	if (area_success == 1)
	{
		cout << "最大面积: " << maxArea << " (边长为: " << area_a << "," << area_b << "," << area_c << ")" << endl << endl;

	}
	else
	{
		cout << 0 << endl;
		cout << "提示: 木棍长度无法构成三角形!" << endl;
	}



	/*----------------------------------*
		   4.释放动态内存空间
	*-----------------------------------*/


	delete[] len;


	system("pause");

	return 0;
}