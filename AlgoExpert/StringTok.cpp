#include <iostream>

char* strtok1(char* str, const char* delim) {
	static char* _buffer;
	if (str != NULL) _buffer = str;
	if (_buffer[0] == '\0') return NULL;

	char* ret = _buffer, *b;
	const char* d;

	for (b = _buffer; *b != '\0'; b++) {
		for (d = delim; *d != '\0'; d++) {
			if (*b == *d) {
				*b = '\0';
				_buffer = b + 1;

				// skip the beginning delimiters
				if (b == ret) {
					ret++;
					continue;
				}
				return ret;
			}
		}
	}

	return ret;
}


//int main()
//{
//	char str[] = "- This, a sample string.";
//	char* pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok1(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok1(NULL, " ,.-");
//	}
//	return 0;
//}