#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <time.h>
#include <map>
using namespace std;
class lc {
public:lc() { system("chcp 1251>nul"); }
	   ~lc() { cin.get();cin.get(); }
}qweeeerfgfdg;
void SetColor(WORD wAttributes)
{
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}
void SetPos(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		cd);
}
enum  // безымянное перечисление
{
	ESC = 27,         // const int ESC = 27;
	ENTER = 13,
	SPACE = 32,

	CURSOR1 = 0,
	CURSOR2 = 224,
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGTH = 77,
	HOME = 71,
	END = 79,
	PG_UP = 73,
	PG_DOWN = 81,
};
struct menu {
	int colordefault = 0x0A;
	int colorselect = 0xBD;
	int select = 0;
};


struct kvs {
	//int x;
	//int y;
	char c = ' ';
	//kvs() :x(), y() {}
};
class glass {
public:
	kvs mas[28][24];
	int score = 0;
public:
	glass() {
		for (int i = 0;i < 28;i++) {
			for (int j = 0;j < 24;j++) {
				if (i == 27)mas[i][j].c = '@';
				else if (j == 0 || j == 23)mas[i][j].c = '$';
				else mas[i][j].c = ' ';
			}
		}
		//mas[12][11].c = '$';
		//mas[13][11].c = '$';
	}
	void show() {
		SetColor(9);
		SetPos(0, 0);
		for (int i = 0;i < 28;i++) {
			for (int j = 0;j < 24;j++) {
				if (mas[i][j].c == '$' || i == 27)SetColor(10);
				else SetColor(2);
				cout << mas[i][j].c;
			}
			cout << endl;
		}
	} //show()		
	void drop() {
		int r = 0;
		for (int i = 1;i < 27;i++) {
			r = 0;
			for (int j = 1;j < 23;j++) {
				if (mas[i][j].c == '@')r++;
			}
			if (r == 22) {
				for (int q = i;q > 1;q--) {
					for (int w = 1;w < 23;w++) {
						mas[q][w].c = mas[q - 1][w].c;
					}
				}
				score++;
			}
		}
	}
	template <class T>
	int add(T&t);
	//friend   void A::up(glass&st);
	//friend  void D::up(glass&st);
};



class kv {
public:
	int x;
	int y;
	char c = 'o';
	kv() :x(), y() {}
};

class Figure {
public:
	kv*mas = new kv[4];
	virtual void Set() {}
	virtual void look() {}
	virtual void left(glass&st) { }
	virtual void right(glass & st) { }
	virtual void down() {  }
	virtual void up(glass &st) = 0;
	virtual int GetStatus() { return 1; }
	virtual int getMasx(int i) { return mas[i].x; }
	virtual int getMasy(int i) { return mas[i].y; }
};

class A :virtual public Figure {
public:
	A() { Set(); }
	virtual void Set() {
		mas[0].x = 4;mas[0].y = 2;
		mas[1].x = 5;mas[1].y = 2;
		mas[2].x = 5;mas[2].y = 1;
		mas[3].x = 6;mas[3].y = 2;
	}
	virtual void look() {
		SetColor(8);
		SetPos(mas[0].x, mas[0].y);
		cout << mas[0].c;
		SetPos(mas[1].x, mas[1].y);
		cout << mas[1].c;
		SetPos(mas[2].x, mas[2].y);
		cout << mas[2].c;
		SetPos(mas[3].x, mas[3].y);
		cout << mas[3].c;
	}
	virtual void left(glass & st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x - 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x - 1].c == '$')return;
		}
		mas[0].x--;mas[1].x--;mas[2].x--;mas[3].x--;
	}
	virtual void right(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x + 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x + 1].c == '$')return;
		}
		mas[0].x++;mas[1].x++;mas[2].x++;mas[3].x++;
	}
	virtual void down() {
		mas[0].y++;mas[1].y++;mas[2].y++;mas[3].y++;
	}
	virtual void up(glass&st);
	virtual int GetStatus() {
		if (mas[1].y > mas[2].y) { return 0; }
		if (mas[1].y < mas[2].y) { return 2; }
		if (mas[1].x > mas[2].x) { return 3; };
		return 1;
	}

};
void A::up(glass&st) {
	if (GetStatus() == 0) {
		if (st.mas[mas[1].y][mas[1].x].c == '@')return;
		mas[2].x++;mas[2].y++;
		mas[0].x++;mas[0].y--;
		mas[3].x--;mas[3].y++;
	}
	else if (GetStatus() == 1) {
		if (st.mas[mas[1].y - 1][mas[1].x - 1].c == '@'
			|| st.mas[mas[1].y - 1][mas[1].x - 1].c == '$')return;
		mas[3].x--;mas[3].y--;
		mas[2].x--;mas[2].y++;
		mas[0].x++;mas[0].y++;
	}
	else if (GetStatus() == 2) {
		mas[3].x++;mas[3].y--;
		mas[2].x--;mas[2].y--;
		mas[0].x--;mas[0].y++;
	}
	else if (GetStatus() == 3) {
		if (st.mas[mas[1].y - 1][mas[1].x + 1].c == '@'
			|| st.mas[mas[1].y - 1][mas[1].x + 1].c == '$')return;
		mas[3].x++;mas[3].y++;
		mas[2].x++;mas[2].y--;
		mas[0].x--;mas[0].y--;
	}
}
class D :virtual public A {
public:
	D() { Set(); }
	virtual void Set() {
		mas[0].x = 5;mas[0].y = 4;
		mas[1].x = 5;mas[1].y = 3;
		mas[2].x = 5;mas[2].y = 2;
		mas[3].x = 5;mas[3].y = 1;
	}
	virtual void look() {
		SetColor(11);
		SetPos(mas[0].x, mas[0].y);
		cout << mas[0].c;
		SetPos(mas[1].x, mas[1].y);
		cout << mas[1].c;
		SetPos(mas[2].x, mas[2].y);
		cout << mas[2].c;
		SetPos(mas[3].x, mas[3].y);
		cout << mas[3].c;
	}
	virtual void left(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x - 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x - 1].c == '$')return;
		}
		mas[0].x--;mas[1].x--;mas[2].x--;mas[3].x--;
	}
	virtual void right(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x + 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x + 1].c == '$')return;
		}
		mas[0].x++;mas[1].x++;mas[2].x++;mas[3].x++;
	}
	virtual void down() { mas[0].y++;mas[1].y++;mas[2].y++;mas[3].y++; }
	virtual void up(glass&st);
	virtual int GetStatus() {
		if (mas[1].y > mas[2].y) { return 0; }
		return 1;
	}
};
void D::up(glass&st) {
	if (GetStatus() == 0) {
		if (st.mas[mas[2].y][mas[2].x - 2].c == '@' ||
			st.mas[mas[2].y][mas[2].x - 1].c == '@' ||
			st.mas[mas[2].y][mas[2].x - 2].c == '$' ||
			st.mas[mas[2].y][mas[2].x - 1].c == '$' ||
			st.mas[mas[2].y][mas[2].x + 1].c == '$' ||
			st.mas[mas[2].y][mas[2].x + 1].c == '@')return;
		mas[0].x -= 2;mas[0].y -= 2;
		mas[3].x++;mas[3].y++;
		mas[1].x--;mas[1].y--;
	}
	else if (GetStatus() == 1) {
		if (st.mas[mas[2].y + 2][mas[2].x].c == '@' ||
			st.mas[mas[2].y + 1][mas[2].x].c == '@' ||
			st.mas[mas[2].y][mas[2].x].c == '@')return;
		mas[3].x--;mas[3].y--;
		mas[1].x++;mas[1].y++;
		mas[0].x += 2;mas[0].y += 2;
	}
}
class B :virtual public A {
public:
	B() { Set(); }
	virtual void Set() {
		mas[0].x = 10;mas[0].y = 2;
		mas[1].x = 10;mas[1].y = 1;
		mas[2].x = 11;mas[2].y = 2;
		mas[3].x = 12;mas[3].y = 2;
	}
	virtual void look() {
		SetColor(9);
		SetPos(mas[0].x, mas[0].y);
		cout << mas[0].c;
		SetPos(mas[1].x, mas[1].y);
		cout << mas[1].c;
		SetPos(mas[2].x, mas[2].y);
		cout << mas[2].c;
		SetPos(mas[3].x, mas[3].y);
		cout << mas[3].c;
	}
	virtual void left(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x - 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x - 1].c == '$')return;
		}
		mas[0].x--;mas[1].x--;mas[2].x--;mas[3].x--;
	}
	virtual void right(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x + 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x + 1].c == '$')return;
		}
		mas[0].x++;mas[1].x++;mas[2].x++;mas[3].x++;
	}
	virtual void down() { mas[0].y++;mas[1].y++;mas[2].y++;mas[3].y++; }
	virtual void up(glass&st);
	virtual int GetStatus() {
		if (mas[0].y > mas[1].y)return 0;
		else if (mas[0].x < mas[1].x)return 1;
		else if (mas[0].y < mas[1].y)return 2;
		else if (mas[0].x > mas[1].x)return 3;
	}
};
void B::up(glass&st) {
	if (GetStatus() == 0) {
		if (st.mas[mas[2].y + 1][mas[2].x].c == '@' ||
			st.mas[mas[2].y][mas[2].x].c == '@' ||
			st.mas[mas[2].y - 1][mas[2].x + 1].c == '@' ||
			st.mas[mas[2].y - 1][mas[2].x + 1].c == '$')return;
		mas[0].x++;mas[0].y--;
		mas[1].x += 2;
		mas[3].x--;mas[3].y++;
	}
	else if (GetStatus() == 1) {
		if (st.mas[mas[2].y][mas[2].x + 1].c != ' ' ||
			st.mas[mas[2].y + 1][mas[2].x + 1].c != ' ' ||
			st.mas[mas[2].y][mas[2].x - 1].c != ' ')return;
		mas[0].x++;mas[0].y++;
		mas[1].y += 2;
		mas[3].x--;mas[3].y--;
	}
	else if (GetStatus() == 2) {
		if (st.mas[mas[2].y + 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y - 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y + 1][mas[2].x - 1].c != ' ')return;
		mas[0].x--;mas[0].y++;
		mas[1].x -= 2;
		mas[3].x++;mas[3].y--;
	}
	else if (GetStatus() == 3) {
		if (st.mas[mas[2].y][mas[2].x + 1].c != ' ' ||
			st.mas[mas[2].y][mas[2].x - 1].c != ' ' ||
			st.mas[mas[2].y - 1][mas[2].x - 1].c != ' ')return;
		mas[0].x--;mas[0].y--;
		mas[1].y -= 2;
		mas[3].x++;mas[3].y++;
	}
}

class C :virtual public A {
public:
	C() { Set(); }
	virtual void Set() {
		mas[0].x = 10;mas[0].y = 2;
		mas[1].x = 10;mas[1].y = 1;
		mas[2].x = 11;mas[2].y = 1;
		mas[3].x = 11;mas[3].y = 2;
	}
	virtual void look() {
		SetColor(12);
		SetPos(mas[0].x, mas[0].y);
		cout << mas[0].c;
		SetPos(mas[1].x, mas[1].y);
		cout << mas[1].c;
		SetPos(mas[2].x, mas[2].y);
		cout << mas[2].c;
		SetPos(mas[3].x, mas[3].y);
		cout << mas[3].c;
	}
	virtual void left(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x - 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x - 1].c == '$')return;
		}
		mas[0].x--;mas[1].x--;mas[2].x--;mas[3].x--;
	}
	virtual void right(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x + 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x + 1].c == '$')return;
		}
		mas[0].x++;mas[1].x++;mas[2].x++;mas[3].x++;
	}
	virtual void down() { mas[0].y++;mas[1].y++;mas[2].y++;mas[3].y++; }
	virtual void up(glass&st) { return; }
};

class E :virtual public A {
public:
	E() { Set(); }
	virtual void Set() {
		mas[0].x = 10;mas[0].y = 2;
		mas[1].x = 11;mas[1].y = 2;
		mas[2].x = 11;mas[2].y = 1;
		mas[3].x = 12;mas[3].y = 1;
	}
	virtual void look() {
		SetColor(13);
		SetPos(mas[0].x, mas[0].y);
		cout << mas[0].c;
		SetPos(mas[1].x, mas[1].y);
		cout << mas[1].c;
		SetPos(mas[2].x, mas[2].y);
		cout << mas[2].c;
		SetPos(mas[3].x, mas[3].y);
		cout << mas[3].c;
	}
	virtual void left(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x - 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x - 1].c == '$')return;
		}
		mas[0].x--;mas[1].x--;mas[2].x--;mas[3].x--;
	}
	virtual void right(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x + 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x + 1].c == '$')return;
		}
		mas[0].x++;mas[1].x++;mas[2].x++;mas[3].x++;
	}
	virtual void down() { mas[0].y++;mas[1].y++;mas[2].y++;mas[3].y++; }
	virtual void up(glass&st);
	virtual int GetStatus() {
		if (mas[1].y == mas[2].y) { return 1; }
		return 0;
	}
};
void E::up(glass&st) {
	if (GetStatus() == 0) {
		if (st.mas[mas[2].y + 1][mas[2].x + 1].c != ' ' ||
			st.mas[mas[2].y - 1][mas[2].x].c != ' ')return;
		mas[0].x += 2;
		mas[3].x--;mas[3].y--;
		mas[1].x++;mas[1].y--;
	}
	else if (GetStatus() == 1) {
		if (st.mas[mas[2].y + 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y + 1][mas[2].x - 1].c != ' ')return;
		mas[3].x++;mas[3].y++;
		mas[1].x--;mas[1].y++;
		mas[0].x -= 2;
	}
}

class F :virtual public A {
public:
	F() { Set(); }
	virtual void Set() {
		mas[0].x = 10;mas[0].y = 1;
		mas[1].x = 11;mas[1].y = 2;
		mas[2].x = 11;mas[2].y = 1;
		mas[3].x = 12;mas[3].y = 2;
	}
	virtual void look() {
		SetColor(14);
		SetPos(mas[0].x, mas[0].y);
		cout << mas[0].c;
		SetPos(mas[1].x, mas[1].y);
		cout << mas[1].c;
		SetPos(mas[2].x, mas[2].y);
		cout << mas[2].c;
		SetPos(mas[3].x, mas[3].y);
		cout << mas[3].c;
	}
	virtual void left(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x - 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x - 1].c == '$')return;
		}
		mas[0].x--;mas[1].x--;mas[2].x--;mas[3].x--;
	}
	virtual void right(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x + 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x + 1].c == '$')return;
		}
		mas[0].x++;mas[1].x++;mas[2].x++;mas[3].x++;
	}
	virtual void down() { mas[0].y++;mas[1].y++;mas[2].y++;mas[3].y++; }
	virtual void up(glass&st);
	virtual int GetStatus() {
		if (mas[0].y == mas[2].y) { return 0; }
		return 1;
	}
};
void F::up(glass&st) {
	if (GetStatus() == 0) {
		if (st.mas[mas[2].y - 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y - 1][mas[2].x - 1].c != ' ')return;
		mas[3].x -= 2;
		mas[0].x++;mas[0].y--;
		mas[1].x--;mas[1].y--;
	}
	else if (GetStatus() == 1) {
		if (st.mas[mas[2].y + 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y + 1][mas[2].x + 1].c != ' ')return;
		mas[3].x += 2;
		mas[1].x++;mas[1].y++;
		mas[0].x--;mas[0].y++;
	}
}

class G :virtual public A {
public:
	G() { Set(); }
	virtual void Set() {
		mas[0].x = 12;mas[0].y = 2;
		mas[1].x = 12;mas[1].y = 1;
		mas[2].x = 11;mas[2].y = 2;
		mas[3].x = 10;mas[3].y = 2;
	}
	virtual void look() {
		SetColor(15);
		SetPos(mas[0].x, mas[0].y);
		cout << mas[0].c;
		SetPos(mas[1].x, mas[1].y);
		cout << mas[1].c;
		SetPos(mas[2].x, mas[2].y);
		cout << mas[2].c;
		SetPos(mas[3].x, mas[3].y);
		cout << mas[3].c;
	}
	virtual void left(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x - 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x - 1].c == '$')return;
		}
		mas[0].x--;mas[1].x--;mas[2].x--;mas[3].x--;
	}
	virtual void right(glass&st) {
		for (int q = 0;q < 4;q++) {
			if (st.mas[mas[q].y][mas[q].x + 1].c == '@' ||
				st.mas[mas[q].y][mas[q].x + 1].c == '$')return;
		}
		mas[0].x++;mas[1].x++;mas[2].x++;mas[3].x++;
	}
	virtual void down() { mas[0].y++;mas[1].y++;mas[2].y++;mas[3].y++; }
	virtual void up(glass&st);
	virtual int GetStatus() {
		if (mas[0].x > mas[2].x)return 0;
		else if (mas[0].y > mas[2].y)return 1;
		else if (mas[0].x < mas[2].x)return 2;
		else if (mas[0].y < mas[2].y)return 3;
	return -1;
	}
};
void G::up(glass&st) {
	if (GetStatus() == 0) {
		if (st.mas[mas[2].y - 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y + 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y + 1][mas[2].x + 1].c != ' ')return;
		mas[0].x--;mas[0].y++;
		mas[1].y += 2;
		mas[3].x++;mas[3].y--;
	}
	else if (GetStatus() == 1) {
		if (st.mas[mas[2].y][mas[2].x - 1].c != ' ' ||
			st.mas[mas[2].y][mas[2].x + 1].c != ' ' ||
			st.mas[mas[2].y + 1][mas[2].x - 1].c != ' ')return;
		mas[0].x--;mas[0].y--;
		mas[1].x -= 2;
		mas[3].x++;mas[3].y++;
	}
	else if (GetStatus() == 2) {
		if (st.mas[mas[2].y + 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y - 1][mas[2].x].c != ' ' ||
			st.mas[mas[2].y - 1][mas[2].x - 1].c != ' ')return;
		mas[0].x++;mas[0].y--;
		mas[1].y -= 2;
		mas[3].x--;mas[3].y++;
	}
	else if (GetStatus() == 3) {
		if (st.mas[mas[2].y][mas[2].x + 1].c != ' ' ||
			st.mas[mas[2].y][mas[2].x - 1].c != ' ' ||
			st.mas[mas[2].y - 1][mas[2].x + 1].c != ' ')return;
		mas[0].x++;mas[0].y++;
		mas[1].x += 2;
		mas[3].x--;mas[3].y--;
	}
}



template <class T>
int glass::add(T&t) {
	//if (strcmp(typeid(t).name(), "class A") == 0) {
	for (int q = 0;q < 4;q++) {
		for (int i = 0;i < 28;i++) {
			for (int j = 0;j < 24;j++) {
				if (mas[i][j].c == '@' && t.mas[q].x == j && t.mas[q].y == i) {
					mas[t.getMasy(0) - 1][t.getMasx(0)].c = '@';
					mas[t.getMasy(1) - 1][t.getMasx(1)].c = '@';
					mas[t.getMasy(2) - 1][t.getMasx(2)].c = '@';
					mas[t.getMasy(3) - 1][t.getMasx(3)].c = '@';
					return 1;
				}
			}
		}
		//}
	}
	return 0;
}
void show(int r1, glass&st) {
	for (int i = 2;i < 6;i++) {
		for (int j = 27;j < 31;j++) {
			SetPos(j, i);
			cout << " ";
		}
	}
	SetPos(28, 6);
	SetColor(18);
	cout << "score: " << st.score;
	SetColor(11);
	if (r1 == 1) {
		SetPos(27, 3);cout << "*";
		SetPos(28, 3);cout << "*";
		SetPos(29, 3);cout << "*";
		SetPos(28, 2);cout << "*";
	}
	else if (r1 == 2) {
		SetPos(28, 2);cout << "*";
		SetPos(28, 3);cout << "*";
		SetPos(28, 4);cout << "*";
		SetPos(28, 5);cout << "*";
	}
	else if (r1 == 3) {
		SetPos(27, 2);cout << "*";
		SetPos(27, 3);cout << "*";
		SetPos(28, 3);cout << "*";
		SetPos(29, 3);cout << "*";
	}
	else if (r1 == 4) {
		SetPos(28, 2);cout << "*";
		SetPos(29, 3);cout << "*";
		SetPos(28, 3);cout << "*";
		SetPos(29, 2);cout << "*";
	}
	else if (r1 == 5) {
		SetPos(27, 3);cout << "*";
		SetPos(28, 3);cout << "*";
		SetPos(28, 2);cout << "*";
		SetPos(29, 2);cout << "*";
	}
	else if (r1 == 6) {
		SetPos(27, 2);cout << "*";
		SetPos(28, 2);cout << "*";
		SetPos(28, 3);cout << "*";
		SetPos(29, 3);cout << "*";
	}
	else if (r1 == 7) {
		SetPos(29, 2);cout << "*";
		SetPos(29, 3);cout << "*";
		SetPos(28, 3);cout << "*";
		SetPos(27, 3);cout << "*";
	}
}
int Exit(int r1,int rand1,glass& st,int score,Figure* t) {
	menu m;
	system("cls");
	SetPos(30, 5);
	cout << "Выйти из игры?";
	m.select = 0;
	int key;
	while (1) {
		if (m.select == 0) SetColor(m.colorselect);
		else SetColor(m.colordefault);
		SetPos(10, 7);
		cout << "Нет";
		if  (m.select == 1)SetColor(m.colorselect);
		else SetColor(m.colordefault);
		SetPos(15, 7);
		cout << "Да";
		key = _getch();		
		switch (key) {
			key = _getch();
		case LEFT: {if (m.select > 0)m.select--;break;}
		case RIGTH:{if (m.select < 1)m.select++;break;}
		case ENTER: {if (m.select == 0) {
			{system("cls");return 0;}}
					else { system("cls"); throw -1;}break;}
		case ESC: {system("cls");return 0 ;}
		}
	}
}
void main() {
	srand(time(0));
	int key;
	glass st;
	int lk = 0;
	int rand1 = 1 + rand() % (7 - 1 + 1);
	int r1 = 0 + 0;
	Figure*t = nullptr;	
	while (1) {
		r1 = 1 + rand() % (7 - 1 + 1);		
		if (rand1 == 1)t = new A;
		else if (rand1 == 2)t = new D;
		else if (rand1 == 3)t = new B;
		else if (rand1 == 4)t = new C;
		else if (rand1 == 5)t = new E;
		else if (rand1 == 6)t = new F;
		else if (rand1 == 7)t = new G;
		while (1) {
			show(r1, st);
			st.show();
			if (_kbhit()) {
				key = _getch();
				key = _getch();
				switch (key) {
				case LEFT: {t[0].left(st);break;}
				case RIGTH: {t[0].right(st);break;}
				case UP: {t[0].up(st);break;}
				case ESC: {try {Exit(r1, rand1, st, st.score, t); }
						  catch (int a) { if (a == -1)return; }
						  break;}
				default: {cin.get();break;}
				} //switch
			} //KBHIT			  
			lk = st.add(t[0]);
			if (lk == 1)break;
			t[0].look();
			t[0].down();
			Sleep(200);
		}
		st.drop();
		rand1 = r1;	
	}
}

