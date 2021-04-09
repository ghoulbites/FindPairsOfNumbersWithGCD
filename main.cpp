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

	if (large != 100) {
		if (findGCD(small, large) == gcd && findGCD(small, 100) == gcd && findGCD(large, 100) == gcd) {
			pair = "(";
			pair.append(to_string(small));
			pair.append(", ");
			pair.append(to_string(large));
			pair.append(")");
		}
	}
	else {
		if (findGCD(small, large) == gcd) {
			pair = "(";
			pair.append(to_string(small));
			pair.append(", ");
			pair.append(to_string(large));
			pair.append(")");
		}
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

	pairsWithGCD5 = findPairsWithGCD(0, 100, 5);
	displayStringQueue(pairsWithGCD5);

	return 0;
}