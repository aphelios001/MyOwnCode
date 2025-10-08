#ifndef stuinfo_h
#define stuinfo_h

#include <stdio.h>
#include <vector>
using namespace std;


typedef struct
{
	int  no;
	char name[64];
	char sex[5];
	int  age;
	int  phone;
	char addr[256];
} info_t;

enum CHOOSE 
{
	PrtAllInfo=1,
	AddStuInfo,
	DelStuInfo,
	UpdStuInfo,
	FindStuInfo,
	ClearStuInfo,
	Quit,
};

class StudentInfo
{
public:
	StudentInfo();
	~StudentInfo();

public:
	int  printMenu();
	
private:
	void doChoose(int n);
	void printAllInfo();
	void addInfo();
	void delInfo();
	void updInfo();
	void findInfo();
	void clearInfo();
	void quitSysterm();

	void importDataFromFile();
	void exportDataToFile();
	
private:
	vector<info_t>	 m_StuInfoVct;
};


#endif