#include <iostream>
#include <vector>

using namespace std;

void	printcap(vector<int> &vec)
{
	cout << "Capacity is " << vec.capacity() << endl;
}

int main(void)
{
	vector<int>	vec;
	int			i;
	int			n;
	int			old;

	n = 900000;
	i = 0;
	old = vec.capacity();
	printcap(vec);
	while (i < n)
	{
		if (vec.capacity() != old)
		{
			cout << "i = " << i << " : ";
			printcap(vec);
			old = vec.capacity();
		}
		vec.push_back(9);
		i++;
	}

	cout << "TRANSITION &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
	vec.clear();
	printcap(vec);
	/*

	i = 0;
	old = vec.capacity();
	printcap(vec);
	while (i < n)
	{
		if (vec.capacity() != old)
		{
			cout << "i = " << i << " : ";
			printcap(vec);
			old = vec.capacity();
		}
		vec.pop_back();
		i++;
	}
	*/
	return (0);
}
