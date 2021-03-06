#include <iostream>
#include <list>
using namespace std;

template<class T> void showListElements(const list<T>& l) {
	if (!l.empty()) {
		for (auto it = l.cbegin(); it != l.cend(); it++)
		{
			cout << *it << " ";
		}
	}
	else {
		cout << "Danh sach rong";
	}
	cout << endl;
}

template<class T> bool greaterCompare(const T& a, const T& b) {
	return a > b;
}

int main()
{
	list<string> friends = { "Nam", "Loan", "Minh", "Long", "Huong" };
	friends.push_back("Long");
	friends.push_back("Long");
	friends.push_back("Long");
	friends.push_back("Long");
    list<int> numbers; // tạo ra một list rỗng
	cout << "Danh sach ngay sau khi tao: " << endl;
	showListElements(numbers);
	numbers.push_front(20);
	numbers.push_front(30);
	numbers.push_front(10);
	cout << "Danh sach phan tu sau khi push_front: ";
	showListElements(numbers);
	numbers.push_back(50);
	numbers.push_back(50);
	numbers.push_back(50);
	numbers.push_back(50);
	numbers.push_back(60);
	numbers.push_back(99);
	numbers.push_back(8);
	cout << "Danh sach sau khi push_back(8): ";
	showListElements(numbers);

	// sắp xếp
	numbers.sort();
	cout << "Sau khi sap xep tang: ";
	showListElements(numbers);
	// sắp xếp giảm dần các phần tử
	numbers.sort(greaterCompare<int>);
	cout << "Sau khi sap xep giam: ";
	showListElements(numbers);

	friends.sort(greaterCompare<string>);
	cout << "Danh sach ban be sau khi sap xep z-a: ";
	showListElements(friends);

	// loại bỏ các phần tử có giá trị bằng x ra khỏi list
	numbers.remove(50);
	cout << "Sau khi xoa 50: ";
	showListElements(numbers);

	friends.remove("Long");
	cout << "Sau khi xoa Long: ";
	showListElements(friends);

	numbers.clear();
	friends.clear();
	showListElements(numbers);
	showListElements(friends);

	return 0;
}