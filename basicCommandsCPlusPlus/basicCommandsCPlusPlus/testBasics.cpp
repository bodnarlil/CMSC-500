// always include the next two lines: 
	#include <iostream>
	#include <string>
	#include <vector>
	using namespace std;

// main function to store commands
	int main() {
		// print hello world
			cout << "Hello World!\n";

		cout << "\n";
		cout << "\n";

		// print a tab and a  new line
			cout << "this\tis a tab and a new\nline. \n";
		// print a " and \ character
			cout << "this prints a \\ and a \" character. \n";

		cout << "\n";
		cout << "\n";

		// variable stuff
			int x = 1;
			//double myFloatNum = 5.99;
			string word = "horse";
			char letter = 'a';
			bool boolean = true;
			cout << "the int x is " << x;
			cout << "\n";
			//cout << "\nthe double y is " + myFloatNum;
			cout << "the string word is " << word;
			cout << "\n";
			cout << "the char letter is " << letter;
			cout << "\n";
			cout << "the bool boolean is " << boolean;
			cout << "\n";

			cout << "\n";
			cout << "\n";

		// math stuff
			int a = 1;
			int b = 2;
			int c = 3;

			cout << "a=" << a << ", b=" << b << ", and c=" << c;
			cout << "\n";

			int d = a + b;
			cout << "d = a + b. thus, d = " << d;
			cout << "\n";

			d = a * b;
			cout << "now, d = a * b. thus, d = " << d;
			cout << "\n";

			d = 2 / b;
			cout << "now, d = 2 / b. thus, d = " << d;
			cout << "\n";

			d = a - b;
			cout << "now, d = a - b. thus, d = " << d;

			cout << "\n";
			cout << "\n";

		// declare multiple ints at a time
			int p = 5, q = 6, r = 50;
			cout << "if int p = 5, q = 6, r = 50, then p+q+r = ";
			cout << p + q + r;

			cout << "\n";
			cout << "\n";

		// can also assign same work to multiple variables at a time
			string m, n, o = "Hello";
			cout << "These were all initialized on the same line: " << m << n << o;
			// length is not working
			cout << "\nThe length of the string m = \"hello\" is " << m.length();

			cout << "\n";
			cout << "\n";

		// constants
			const int myNum = 15;  // myNum will always be 15
			cout << "myNum: " << myNum << " is a constant and will never change";

			cout << "\n";
			cout << "\n";

			int v;
			cout << "enter a random int: ";
			cin >> v;
			cout << "Your number is: " << v;

			cout << "\n";
			cout << "\n";







			cout << "finished running successfully";

			cout << "\n";
			cout << "\n";

			return 0; // to end program
	}