#include <iostream>
#include <queue>
#include <string>
using namespace std;

int findGCD(int small, int large) {
	if (small == 0) return large;
	return findGCD(large % small, small);
}


string pairWithGCD(int small, int large, int gcd) {
	string pair = "false";

	if (findGCD(small, large) == gcd) {
		pair = "(";
		pair.append(to_string(small));
		pair.append(", ");
		pair.append(to_string(large));
		pair.append(")");
	}

	return pair;
}

queue <string> findPairsWithGCD(int start, int end, int gcd) {
	queue <string> pairsWithGCD;
	string pair;

	for (int i = start; i <= end; i++) {
		for (int t = i; t <= end; t++) {
			pair = pairWithGCD(i, t, gcd);

			if (pair != "false") {
				pairsWithGCD.push(pair);
			}
		}
	}

	return pairsWithGCD;
}


void displayStringQueue(queue <string> someQueue) {
	while (!someQueue.empty()) {
		cout << someQueue.front() << endl;
		someQueue.pop();
	}
}


int main() {
	queue <string> pairsWithGCD5;
	int start, end, gcd;
	cout << "Enter starting range: ", cin >> start;
	cout << "Enter ending range: ", cin >> end;
	cout << "Enter GCD: ", cin >> gcd;

	pairsWithGCD5 = findPairsWithGCD(start, end, gcd);
	displayStringQueue(pairsWithGCD5);
	cout << "Numer of pairs: " << pairsWithGCD5.size() << endl;


	system("pause");
	return 0;
}
