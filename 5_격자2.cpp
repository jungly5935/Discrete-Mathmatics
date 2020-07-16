#include <stdio.h>

FILE* inp = fopen("grid2.inp", "rt");

FILE* out = fopen("grid2.out", "wt");

void position3(int n, int m, int number, int position, int count, int s, int t)
{
	int a = 0;

	for (int i = 1; i < n * m; i += 1) {

		if (count == s) {

			break;
		}

		if (position == 0) {

			number += 1;

			count += 1;

			if (m != 1 && n != 1) {

				if (number == m + (m - 1) * a) {

					position = 1;

				}

				else if (number == t + (m - 1) * a) {

					position = 1;

					a += 1;
				}
			}
		}

		else if (position == 1) {

			count += 1;

			if (m != 1 && n != 1) {

				number += m;

				if (number == n * m - (m + 1) * a) {

					position = 2;

				}

				else if (number == t - (m + 1) * a) {

					position = 2;

					a += 1;
				}
			}

			else if (n == 1) number -= 1;

			else number += 1;
		}

		else if (position == 2) {

			number -= 1;

			count += 1;

			if (m != 1 && n != 1) {

				if (number == (1 + (n - 1) * m) - (m - 1) * a) {

					position = 3;

				}

				else if (number == t - (m - 1) * a) {

					position = 3;

					a += 1;

				}
			}
		}

		else if (position == 3) {

			count += 1;

			if (m != 1 && n != 1) {

				number -= m;

				if (number == 1 + (m + 1) * a) {

					position = 0;

				}

				else if (number == t + (m + 1) * a) {

					position = 0;

					a += 1;

				}
			}

			else if (n == 1) number += 1;

			else number -= 1;
		}
	}
	fprintf(out, "%d\n", number);
}

void position4(int n, int m, int number, int position, int count, int s, int t)
{
	int a = 0;

	for (int i = 1; i < n * m; i += 1) {

		if (count == s) {

			break;

		}

		if (position == 0) {

			count += 1;

			if (m != 1 && n != 1) {

				number += 1;

				if (number == n * m - (m + 1) * a) {

					position = 3;

				}

				else if (number == t - (m + 1) * a) {

					position = 3;

					a += 1;

				}
			}
			else if (n == 1) number += 1;

			else number -= 1;
		}

		else if (position == 1) {

			count += 1;

			if (m != 1 && n != 1) {

				number += m;

				if (number == 1 + (n - 1) * m - (m - 1) * a) {

					position = 0;

				}

				else if (number == t - (m - 1) * a) {

					position = 0;

					a += 1;

				}
			}
			else if (n == 1) number += 1;

			else number += 1;
		}

		else if (position == 2) {

			count += 1;

			if (m != 1 && n != 1) {

				number -= 1;

				if (number == 1 + (m + 1) * a) {

					position = 1;

				}

				else if (number == t + (m + 1) * a) {

					position = 1;

					a += 1;

				}
			}
			else if (n == 1) number -= 1;

			else number += 1;
		}

		else if (position == 3) {

			count += 1;

			if (m != 1 && n != 1) {

				number -= m;

				if (number == m + (m - 1) * a) {

					position = 2;

				}
				else if (number == t + (m - 1) * a) {

					position = 2;

					a += 1;

				}
			}
			else if (n == 1) number -= 1;

			else number -= 1;
		}
	}
	fprintf(out, "%d\n", number);
}

void type3(int n, int m, int go, int s)
{
	int number;
	int position;
	int t;
	int count = 1;

	if (go == 1) {

		number = 1;

		position = 0;

		t = m + 1;

		position3(n, m, number, position, count, s, t);
	}

	else if (go == 2) {

		number = m;

		position = 1;

		t = m - 1;

		position3(n, m, number, position, count, s, t);
	}

	else if (go == 3) {

		number = n * m;

		position = 2;

		t = 1 + (n - 1) * m - 1;

		position3(n, m, number, position, count, s, t);
	}

	else if (go == 4) {

		number = 1 + (n - 1) * m;

		position = 3;

		t = 1 + (n - 1) * m + 1;

		position3(n, m, number, position, count, s, t);
	}
}

void type4(int n, int m, int go, int s)
{
	int number;
	int position;
	int t;
	int count = 1;

	if (go == 1) {

		number = 1;

		position = 1;

		t = 2;

		position4(n, m, number, position, count, s, t);
	}

	else if (go == 2) {

		number = m;

		position = 2;

		t = m * 2;

		position4(n, m, number, position, count, s, t);
	}

	else if (go == 3) {

		number = n * m;

		position = 3;

		t = n * m - 1;

		position4(n, m, number, position, count, s, t);
	}

	else if (go == 4) {

		number = 1 + (n - 1) * m;

		position = 0;

		t = 1 + m * (n - 1) - m;

		position4(n, m, number, position, count, s, t);
	}
}

int main()
{
	int test;
	int n;
	int m;
	int type;
	int go;
	int s;

	fscanf(inp, "%d", &test);

	for (int i = 0; i < test; i += 1)
	{
		fscanf(inp, "%d", &n);

		fscanf(inp, "%d", &m);

		fscanf(inp, "%d", &type);

		fscanf(inp, "%d", &go);

		fscanf(inp, "%d", &s);

		switch (type)
		{

		case 3: type3(n, m, go, s); break;

		case 4: type4(n, m, go, s);

		}
	}
	fclose(inp);

	fclose(out);

	return 0;
}