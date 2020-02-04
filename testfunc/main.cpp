#include <iostream>
#define num 9
using namespace std;

bool calcPlus(int a, int b, int c)
{
	if ((b + c) == a) return true;
	else if ((a + c) == b) return true;
	else if ((a + b) == c) return true;
	else return false;
}

int main()
{
	int arr[num] = { 1,2,3,4,5,6,7,8,9 };
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i];
	}
	cout << "sum: " << sum << endl;

	int arr1[3], tmp[6], arr2[3], arr3[3], index1[3], index2[3];
	static int count = 0;
	
	int i, j, k, x, y, z, l, m;
	
	//get arr1 3 of 9 index
	for (i = 0; i < 9; i++)
	{
		//get index
		index1[0] = i;
		for (j = i+1; j < 9; j++)
		{
			index1[1] = j;

			for (k = j + 1; k < 9; k++)
			{
				index1[2] = k;
				
				//get arr1
				for (l = 0; l < 3; l++)
				{
					arr1[l] = arr[index1[l]];
				}

				//check sum
				if (!calcPlus(arr1[0], arr1[1], arr1[2]))
				{
					count++;
					continue;
				}
				
				// get tmp arr
				m = 0;
				for (l = 0; l < 9; l++)
				{
					if (arr[l] == arr1[0]) continue;
					if (arr[l] == arr1[1]) continue;
					if (arr[l] == arr1[2]) continue;
					else
					{
						tmp[m] = arr[l];
						m++;
					}
				}

				///////////////////////////////////////////////////////
				// get arr2
				for (x = 0; x < 6; x++)
				{
					index2[0] = x;
					for (y = x + 1; y < 6; y++)
					{
						index2[1] = y;

						for (z = y + 1; z < 6; z++)
						{
							index2[2] = z;

							//get arr2
							for (l = 0; l < 3; l++) arr2[l] = tmp[index2[l]];

							//check arr2 sum
							if (!calcPlus(arr2[0], arr2[1], arr2[2]))
							{
								count++;
								continue;
							}

							//**************************************************
							// get arr3
							m = 0;
							for (l = 0; l < 6; l++)
							{
								if (tmp[l] == arr2[0]) continue;
								if (tmp[l] == arr2[1]) continue;
								if (tmp[l] == arr2[2]) continue;
								else
								{
									arr3[m] = tmp[l];
									m++;
								}
							}

							//check arr3 sum
							if (!calcPlus(arr3[0], arr3[1], arr3[2]))
							{
								count++;
								continue;
							}
							else
							{
								count++;
								cout << "get ok" << endl;
								cout << "arr1: " << arr1[0] << " " << arr1[1] << " " << arr1[2] << endl;
								cout << "arr2: " << arr2[0] << " " << arr2[1] << " " << arr2[2] << endl;
								cout << "arr3: " << arr3[0] << " " << arr3[1] << " " << arr3[2] << endl;
							}
							//****************************************************
						}
					}
				}
				/////////////////////////////////////////////////////////
			}
		}
	}
	cout << "calc count: " << count << endl;
	return 0;
}


