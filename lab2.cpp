bool get_word(const string& prompt, string& word, bool(*is_valid)(const string &));
bool get_int(const string& prompt, int& n, bool(*is_valid)(int));