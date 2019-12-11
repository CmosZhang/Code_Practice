#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

//1186. TinyURL 的加密与解密
//

unordered_map<string, string> tinyToLongUrl;
hash<string> t;

string encode(string &longUrl) {
	// Encodes a URL to a shortened URL.
	string key = to_string(t(longUrl));
	tinyToLongUrl[key] = longUrl;
	return key;
}


string decode(string shortUrl) {
	// Decodes a shortened URL to its original URL.
	return tinyToLongUrl[shortUrl];
}


int main() {
	string str;
	cin >> str;
	cout << encode(str) << endl;
	cout << decode(encode(str)) << endl;
	system("pause");
	return 0;
}