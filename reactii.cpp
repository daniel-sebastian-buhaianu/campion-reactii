#include <fstream>

#define NMAX 15000

using namespace std;

ifstream fin("reactii.in");
ofstream fout("reactii.out");

struct interval { int min, max; };

int main()
{
	interval stv[NMAX], ss;

	int n, m, j, vf, i;

	fin >> n >> m;
	
	for (j = 0; j < m; j++)
	{
		vf = 0;

		fin >> stv[vf].min;

		stv[vf].max = stv[vf].min;

		for (i = 1; i < n; i++)
		{
			fin >> ss.min;

			ss.max = ss.min;
			
			while (vf >= 0)
			{
				if (ss.max+1 == stv[vf].min)
				{
					ss.max = stv[vf].max;

					vf--;
				}
				else if (ss.min-1 == stv[vf].max)
				{
					ss.min = stv[vf].min;

					vf--;
				}
				else
				{
					break;
				}
			}

			stv[++vf] = ss;
		}

		fout << (vf == 0) << '\n';
	}
	
	fin.close();

	fout.close();

	return 0;
}
// scor 100
