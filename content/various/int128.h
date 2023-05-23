/**
 * Author: Wenli
 * Date: 
 * License: 
 * Description: int128 manipulation
 * Status: probably tested
 */
string printint128(__int128 a) { // prints as decimal
	if (!a) return "0";
	string s;
	while (a) {
		s = char(llabs(a % 10) + '0') + s;
		if (-10 < a && a < 0) s = '-' + s;
		a /= 10;
	}
	return s;
}

__int128 parseint128(string s) { // parses decimal number
	__int128 a = 0, sgn = 1;
	for (char c : s) {
		if (c == '-') sgn *= -1; else a = a * 10 + sgn * (c - '0');
	}
	return a;
}