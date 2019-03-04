#include <stdio.h>
#include <stdlib.h>

int st[50], n;

int valid(int k) {

    for (int i = 1; i < k; i++)
        if ((st[i] == st[k]) || (abs(st[i] - st[k]) == k - i))
            return 0;

    return 1;
}

void print(int k) {

	for (int i = 1; i <= k; i++)
		printf("%d ", st[i]);
	printf("\n");
}

void bk(int k) {

	if (k == n + 1)
		print(k - 1);
	else {

		for (int i = 1; i <= n; i++) {

			st[k] = i;
			if (valid(k))
				bk(k + 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	bk(1);
	return 0;
}