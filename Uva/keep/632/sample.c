#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class StringReference {
public:

	int cursor;
	int length;

	string *pbuffer;

	StringReference( string &ref, int cur, int len ) {
		pbuffer = &ref;
		cursor = cur, length = len;
	}

	bool operator < ( const StringReference &r ) const {
		const string &buffer = *pbuffer;

		for ( int i = 0; i < length; i++ ) {
			if ( buffer[cursor+i] < buffer[r.cursor+i] ) return true;
			if ( buffer[cursor+i] > buffer[r.cursor+i] ) return false;
		}
		return false;
	}

	char getLastCharacter() {
		return (*pbuffer)[cursor+length-1];
	}

};

class TCompressionII {
public:

	vector<StringReference> stringrefs;

	int length, S;
	string buffer, compressed;
	string cyclicBuffer;

	void input() {
		string line;

		cin >> length;
		getline(cin, line);

		buffer.erase();
		while ( buffer.size() < length )
			getline(cin, line), buffer.append(line);
		assert(buffer.size() == length);
	}

	void work() {
		cyclicBuffer = buffer + buffer;

		stringrefs.clear();
		for ( int cursor = 0; cursor < length; cursor++ )
			stringrefs.push_back(StringReference(cyclicBuffer, cursor, length));
		stable_sort(stringrefs.begin(), stringrefs.end());

		compressed.erase();
		for ( int i = 0; i < stringrefs.size(); i++ )
			compressed += stringrefs[i].getLastCharacter();

		for ( S = 0; S < stringrefs.size(); S++ )
			if ( stringrefs[S].cursor == 1 ) break;
		assert( S < stringrefs.size() );
	}

	void output() {
		cout << S;
		for ( int cursor = 0; cursor < compressed.size(); cursor++ ) {
			if ( cursor % 50 == 0 ) cout << endl;
			cout << compressed[cursor];
		}
		cout << endl;
	}

};

int main() {
	TCompressionII TCII;
	int nrecord;

	cin >> nrecord;

	for ( int ncase = 0; ncase < nrecord; ncase++ ) {
		TCII.input();
		TCII.work();

		if ( ncase > 0 ) cout << endl;
		TCII.output();
	}

	return 0;
}
