#include <string>
#include <iostream>
using namespace std;
#include <string.h>

class Text {
	string font;
	int size;
	string color;
	string data;
	
	public: Text(string _f, int _s, string _c, string _d) {
		font = _f;
		size = _s;
		color = _c;
		data = _d;
	}
	
	public: SetText(string _s) {
		data = _s;
	}
	
	public: PrintText() {
		cout << data << endl;
	}
	
	public: string GetFont() {
		return font;
	}
	
	public: int GetSize() {
		return size;
	}
	
	public: string GetTextColor() {
		return color;
	}
	
	public: string GetText() {
		return data;
	}
	
	
};

class Box {
	int width;
	int height;
	int border;
	string color;
	
	public: Box(int _w, int _h, int _b, string _c) {
		width = _w;
		height = _h;
		border = _b;
		color = _c;
	}
	
	public: SetBoxWidth(int _w) {
		width = _w;
	}
	public: SetBoxHeght(int _h) {
		height = _h;
	}
	public: SetBoxBorder(int _b) {
		border = _b;
	}
	public: SetBoxColor(string _c) {
		color = _c;
	}			
	public: int GetWidth() {
		return width;
	}
	
	public: int GetHeight() {
		return height;
	}
	
	public: int GetBorder() {
		return border;
	}
	
	public: string GetBoxColor() {
		return color;
	}
	
	public: PrintBox() {
		cout << "W=" << width << " H=" << height << " B=" << border << " C=" << color << endl;
	}
};	

class TextBox : public Box, public Text {
	
	public: TextBox(string _f, int _s, string _cT, string _d, int _w, int _h, int _b, string _cB ) : Text(_f, _s, _cT, _d), Box(_w, _h, _b, _cB) {
		cout << "> create " << _f << " " << _s << " " << _cT << " " << _d << " " << _w << " " << _h << " " << _b << " " << _cB << endl;
	}
	
	public: SetTextBox() {
	}
	
	public: PrintTextBox() {
		PrintText();
		PrintBox();
	}

	
};

int main()
{
	TextBox t = TextBox("Courier New",12,"Black","This is demo text",200,100,1,"White");
	t.PrintTextBox(); //Call TextBox class function
	t.PrintText(); //Call Text class function
	t.PrintBox(); //Call Box class function
	cout << t.GetTextColor() << " " << t.GetBoxColor() << endl; //Get color params of fathers classes
	cout << " ";
	system("pause");
    //return 0;
}

