#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <cmath>
#include <vector>

struct Book
{
	char title[100];
	char author[150];
	int pageNumber;
	float price;
};

int whiteFile(char fname[], Book books[], int size);
int readFile(char fname[], std::vector<Book>& books);
void printBooks(std::vector<Book>& books);

int main() {
	char fileName[] = "books.txt";

	const int size = 4;

	Book books[] = {
		{"Harry Poter", "Joanne Rowling", 534, 450},
		{"Book thief", "Markus Zukas", 506, 300},
		{"Project Venus", "Jacque Fresco", 503, 250},
		{"The Wither","Anjei Sapkovsky", 302, 540},
	};

	printf("Writing data to the file %s . . . \n", fileName);
	whiteFile(fileName, books, size);

	std::vector<Book> newBoooks;

	printf("Reading data to the file %s . . . \n", fileName);
	readFile(fileName, newBoooks);
	printBooks(newBoooks);
	return 0;
}

//int main() {
//	//int a;
//	//double b;
//	//char str[] = "Hello World!";
//
//	//printf("PI = %.5lf\n", M_PI);
//	//printf("int = %d\n", 10);
//	//printf("oct = %o\n", 10);
//	//printf("hex = %x\n", 10);
//	//printf("str = %s\n", str);
//
//	//scanf("%d", &a);
//	//printf("a = %d\n", a);
//	//scanf("%lf", &b);
//	//printf("b = %.0lf\n", b);
//	return 0;
//}

int whiteFile(char fname[], Book books[], int size)
{
	FILE* f;

	f = fopen(fname, "w");

	for (int i = 0; i < size; i++) {
		fprintf(f, "%s|%s|%d|%f\n", books[i].title, books[i].author, books[i].pageNumber, books[i].price);

	}
	
	fclose(f);
	return 0;
}

int readFile(char fname[], std::vector<Book>& books)
{
	FILE* f;

	f = fopen(fname, "r");

	char buff[256];
	while (fgets(buff, 256, f) != NULL) {
		Book b;
		printf("%s", buff);
		//title
		char* subStr = strtok(buff, "|\n");
		strcpy(b.title, subStr);
		//author
		subStr = strtok(NULL, "|\n");
		strcpy(b.author, subStr);
		// page number
		subStr = strtok(NULL, "|\n");
		int pageNumber = atoi(subStr);
		b.pageNumber = pageNumber;
		// price
		subStr = strtok(NULL, "|\n");
		float price = atof(subStr);
		b.price = price;

		books.push_back(b);
	}

	fclose(f);
	return 0;
}

void printBooks(std::vector<Book>& books)
{
	for (int i = 0; i < books.size(); i++) {
		printf("Title: %s, Authord: %s, page number: %d, price: %f\n",
			books[i].title, books[i].author, books[i].pageNumber, books[i].price);
	}
}
