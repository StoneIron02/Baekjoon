#include <iostream>
#include <string>
using namespace std;

void recursion(int n, string prefix) {
	cout << prefix << "\"����Լ��� ������?\"" << endl;
	if (n == 0) {
		cout << prefix << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		return;
	}
	cout << prefix << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
	cout << prefix << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
	cout << prefix << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
	recursion(n - 1, prefix + "____");
	cout << prefix << "____" << "��� �亯�Ͽ���." << endl;
}

int main() {
	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	recursion(n, "");
	cout << "��� �亯�Ͽ���." << endl;
}