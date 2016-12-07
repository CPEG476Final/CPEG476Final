char decodeNumber(int n) {
	n = n - 1;
    n = (n + 13) % 26;
    char c = n + 65;
    return c;
}

string decodeWord(String input) {
    
}