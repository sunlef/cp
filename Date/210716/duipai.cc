#include <iostream>
using namespace std;
int main()
{
	int i;
	for (i = 1;; i++) {
		printf("The result of No. %d Case is:  ", i);
		system("./data > data.txt");
		system("./std < data.txt > std.out");
		system("./test < data.txt > test.out");
		if (system("diff std.out test.out")) {
			printf("Wrong Answer\n");
			return 0;
		}
		else {
			printf("Accepted\n");
		}
	}
	return 0;
}