#include<iostream>
#include <string>
#include <algorithm>	
using namespace std;

int main()
{
	int num_test_case, smallest_index,temp;
	string str;
	bool found = false;
	char s_temp;
	cin >> num_test_case;


	for (int i = 0; i < num_test_case; i++)
	{
		cin >> str;
		for (int i = str.length()-1; i >= 1; i--) {
			
			if ((str[i] - 'a') > (str[i - 1] - 'a')){
				found = true;

				temp = str[i] - 'a';
				smallest_index = i;
				for (int j = i + 1; j < str.length(); j++) {

					if ((str[j] - 'a') < temp && ((str[j]- 'a') > str[i-1]-'a')) {
						smallest_index = j;
						temp = str[j] - 'a';
					}
				}//if
				
				s_temp = str[i-1];
				str[i-1] = str[smallest_index];
				str[smallest_index] = s_temp;//swap_3
				sort(str.begin() + i, str.end());
				break;
			}
		}
		if (!found) {
			cout << "no answer" << endl;
		}
		else {
			cout << str << endl;
		}
		found = false;
	}
	return 0;
}
