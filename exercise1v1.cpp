//not finished!!!
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


bool pairCompare(const std::pair<int, int>& firstElem, const std::pair<int, int>& secondElem) {
	return firstElem.first < secondElem.first;

}
//using namespace std;
int main()
{
	std::vector <std::pair <int,int>> mass;
	//std::vector <int> lengths;
	int n_mas;
	std::cin >> n_mas;
	mass.reserve(n_mas);
	for (int i = 0;i < n_mas;i++) {
		int left,right;
		std::cin >> left>>right;
		mass.push_back({ left,right });
	}

	int left, right;

	std::sort(mass.begin(), mass.end(), pairCompare);
	//left = mass[0].first;
	//right = mass[0].second;
	int lenght=0;
	int cycler=0;
	for (int n = 0;n < n_mas;) {

		left = mass[n].first;
		right = mass[n].second;
		for (int k = n;k < n_mas;k++) {
			if (mass[k].first >= right){//
				left = mass[k].first;
				right = mass[k].second;
				break;
			}
			cycler++;
			if (mass[k].first<right ) {
				if(mass[k].second > right){
					right = mass[k].second;
				}
			}
				
		}
		lenght += right-left;
		n = n + cycler;
		cycler = 0;

		}

	
	//vector[1].
	


	std::cout << "\n\n\nдлина равна=" << lenght << "\n";
	getchar();
	getchar();
	return 0;
}

