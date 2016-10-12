// BDOI16A - Guess the Queue
// http://www.spoj.com/problems/BDOI16A/

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#define MY_SIZE 200010
using namespace std;

int queue[MY_SIZE];
int front_idx, back_idx;
map <int, int> my_map;

int main() {
	int t, n, operation_type, tmp_id, tmp_nb;
	string x_str;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cout << "Case " << (z + 1) << ":\n";
		cin >> n;
		my_map.clear();
		front_idx = 0;
		back_idx = 0;
		for (int tmp_idx = 0; tmp_idx < n; tmp_idx++) {
			cin >> operation_type;
			x_str = "";
			while (x_str == "")
				cin >> x_str;
			switch (operation_type) {
				case 1:
					cin >> tmp_id;
					if (x_str == "B") {
						queue[back_idx] = tmp_id;
						my_map[tmp_id] = back_idx;
						back_idx = (back_idx + 1) % MY_SIZE;
					}
					else {
						if (front_idx == 0)
							front_idx = MY_SIZE - 1;
						else
							front_idx = (front_idx - 1);
						queue[front_idx] = tmp_id;
						my_map[tmp_id] = front_idx;
					}					
					break;
				case 2:
					if (x_str == "B") {
						if (back_idx == 0)
							back_idx = MY_SIZE - 1;
						else
							back_idx = (back_idx - 1);
					}
					else
						front_idx = (front_idx + 1) % MY_SIZE;
					break;
				case 3:
					cin >> tmp_nb;
					if (x_str == "D") {
						cout << queue[(front_idx + tmp_nb - 1) % MY_SIZE] << "\n";
					} else {
						int tmp_pos = my_map[tmp_nb];
						int ans = -1;
						if (tmp_pos >= front_idx)
							ans = (tmp_pos - front_idx) + 1;
						else
							ans = (tmp_pos + MY_SIZE - front_idx) + 1;
						cout << ans << "\n";
					}
					break;
			}		
		}
	}
}