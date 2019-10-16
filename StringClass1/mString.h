#ifndef MSTRING_H
#define MSTRING_H

class mString
{
	
private: 
	char* data;
	
public:
	
	mString();
	mString(char* data);
	mString(const mString&);
	~mString();
	
	mString& operation= (const char*);
	mString& operation= (const mString&);
	mString operation+ (const mString&);
	mString& operation+= (const mString&);
	bool operator== (const char*);
	bool operator==(const mString&);
	bool operator< (const char*);
	bool operator< (const mString&);
	
	char& operator[] (const int);
	
	int size();
	
	mString substring(int, int);
	
	char* c_str();
	
	friend std::ostream& operator<< (std::ostream&, const mString&);
};

#endif // MSTRING_H
