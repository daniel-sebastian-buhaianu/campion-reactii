#include <fstream>

#define NMAX 15000

using namespace std;

ifstream fin("reactii.in");
ofstream fout("reactii.out");

struct subsecventa { int min, max; };

subsecventa ss[NMAX];

int main()
{
	int n, m, i, nr, rct, j;

	fin >> n >> m;
	
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			fin >> ss[i].min;

			ss[i].max = ss[i].min;
		}

		nr = n;

		do
		{	
			rct = 0;

			for (i = 0; i < nr-1; i++)
			{
				if (ss[i].max == ss[i+1].min-1)
				{
					ss[i].max = ss[i+1].max;

					rct = 1;
				}
				else if (ss[i].min-1 == ss[i+1].max)
				{
					ss[i].min = ss[i+1].min;

					rct = 1;
				}

				if (rct)
				{
					for (i++; i < nr-1; i++)
					{
						ss[i] = ss[i+1];
					}

					nr--;

					break;
				}
			}
		}
		while (rct);

		if (nr == 1)
		{
			fout << 1;
		}
		else
		{
			fout << 0;
		}

		fout << '\n';
	}
	
	fin.close();

	fout.close();

	return 0;
}

// scor 50
