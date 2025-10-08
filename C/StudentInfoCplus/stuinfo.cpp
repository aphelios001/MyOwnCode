/**
 * 项目名称：学生信息管理系统（C++ 容器vector）
 * 项目功能：学生信息的增删改查（按姓名|学号）、二进制导入导出数据、程序正常退出时才更新本地db文件
 * 当前版本：2024.03.29.01 
 * 完成时间：2024年03月29日
 * 初始作者：Tianwx tianwx2106@163.com
 * 最后修改：Tianwx
 */
#include "stuinfo.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define DatabaseFile	"stuinfo.db"


StudentInfo::StudentInfo()
{
	m_StuInfoVct.clear();
	importDataFromFile();
}

StudentInfo::~StudentInfo()
{
	exportDataToFile();
	m_StuInfoVct.clear();
}

int StudentInfo::printMenu()
{
	int chioce;
	printf("\n\n*******************************\n");
	printf("*\t1、显示所有学生信息\n");
	printf("*\t2、添加学生信息\n");
	printf("*\t3、删除学生信息\n");
	printf("*\t4、更新学生信息\n");
	printf("*\t5、查找学生信息\n");
	printf("*\t6、清空所有学生信息\n");
	printf("*\t7、退出学生信息系统\n");
	printf("*******************************\n");
	printf("请输入你的选择：");
	scanf("%d", &chioce);
	if (chioce < PrtAllInfo || chioce > Quit)
	{
		printf("请输入正确的选项\n");
		printMenu();
	}
	
	doChoose(chioce);
}

void StudentInfo::doChoose(int n)
{
	switch(n)
	{
	case PrtAllInfo:   printAllInfo(); break;
	case AddStuInfo:   addInfo(); 	   break;
	case DelStuInfo:   delInfo(); 	   break;
	case UpdStuInfo:   updInfo(); 	   break;
	case FindStuInfo:  findInfo(); 	   break;
	case ClearStuInfo: clearInfo();    break;
	case Quit:         quitSysterm();  break;
	default: break;
	}
}

void StudentInfo::printAllInfo()
{	
	for (int i=0; i<m_StuInfoVct.size(); i++)
	{
		printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
			m_StuInfoVct[i].no,
			m_StuInfoVct[i].name,
			m_StuInfoVct[i].sex,
			m_StuInfoVct[i].age,
			m_StuInfoVct[i].phone,
			m_StuInfoVct[i].addr );
	}
	printf("共展示 %d 名学生的个人信息\n", m_StuInfoVct.size());
}

void StudentInfo::addInfo()
{	
	info_t info;
	memset(&info, 0, sizeof(info_t));

INPUT:
	printf("请输入学号：");
	scanf("%d", &info.no);
	
	for (int i=0; i<m_StuInfoVct.size(); i++)
	{
		if (m_StuInfoVct[i].no == info.no)
		{
			printf("该学号已存在，请重新输入！\n");
			goto INPUT;
		}
	}
	
	printf("请输入学生姓名：");
	scanf("%s", info.name);
	printf("请输入学生性别：");
	scanf("%s", info.sex);
	printf("请输入学生年龄：");
	scanf("%d", &info.age);
	printf("请输入学生联系方式：");
	scanf("%d", &info.phone);
	printf("请输入学生家庭地址：");
	scanf("\n%[^\n]", info.addr);
	
	m_StuInfoVct.push_back(info);
	
	printf("学生信息添加完成：\n");
	printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
			m_StuInfoVct[m_StuInfoVct.size()-1].no,
			m_StuInfoVct[m_StuInfoVct.size()-1].name,
			m_StuInfoVct[m_StuInfoVct.size()-1].sex,
			m_StuInfoVct[m_StuInfoVct.size()-1].age,
			m_StuInfoVct[m_StuInfoVct.size()-1].phone,
			m_StuInfoVct[m_StuInfoVct.size()-1].addr );
}

void StudentInfo::delInfo()
{
	int i, chioce, no, index;
	printf("1、根据学号删除学生信息\n");
	printf("2、根据姓名删除学生信息\n");
	printf("请选择删除方式：");
	scanf("%d", &chioce);
	if (chioce != 1 && chioce != 2)
	{
		printf("输入有误，请重新输入\n");
		delInfo();
	}
	
	// 按学号删除学生信息
	if (chioce == 1)
	{
		printf("请输入要删除的学号：");
		scanf("%d", &no);
		
		printf("查询结果如下：\n");
		for (i=0,index=-1; i<m_StuInfoVct.size(); i++)
		{
			if (no == m_StuInfoVct[i].no)
			{
				index = i;
				
				printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
				m_StuInfoVct[index].no,
				m_StuInfoVct[index].name,
				m_StuInfoVct[index].sex,
				m_StuInfoVct[index].age,
				m_StuInfoVct[index].phone,
				m_StuInfoVct[index].addr );
				break;
			}
		}
		if (index == -1)
		{
			printf("未查找到学号 %d\n", no);
			return;
		}
		printf("确定删除？（yes or no）：");
		char s[5] = {0};
		scanf("%s", s);
		if (!strcmp(s, "yes"))
		{
			m_StuInfoVct.erase(m_StuInfoVct.begin() + index);
			printf("已删除\n");
		}
		return;
	}
	
	// 按姓名删除学生信息
	char iName[64] = {0};
	char sNo[128] = {0};
	vector<int>  idxVct;
	printf("请输入学生姓名：");
	scanf("%s", iName);
	printf("查询结果如下：\n");
	for (i=0,no=1,index=-1; i<m_StuInfoVct.size(); i++)
	{
		if (strcmp(iName, m_StuInfoVct[i].name) != 0)
			continue;
		
		index = i;
		idxVct.push_back(index);
		printf("%d、\t%d\t%s\t%s\t%d\t%d\t%s\n", 
			no++,
			m_StuInfoVct[index].no,
			m_StuInfoVct[index].name,
			m_StuInfoVct[index].sex,
			m_StuInfoVct[index].age,
			m_StuInfoVct[index].phone,
			m_StuInfoVct[index].addr );
	}
	if (index == -1)
	{
		printf("未查找到姓名 %s\n", iName);
		return;
	}
	printf("请输入要删除信息的序号（使用空格分隔）：");
	scanf("\n%[^\n]", sNo);
	
	for (int i=0,sum=0,del=0; i<=strlen(sNo); i++)
	{
		if ((isspace(sNo[i]) || !sNo[i]) && sum > 0)
		{
			if (sum >= no)
			{
				printf("输入参数 %d 有误，跳过！\n", sum);
				sum = 0;
				continue;
			}
			
			index = idxVct[sum-1] - del;
			if (strcmp(m_StuInfoVct[index].name, iName) == 0)
			{
				printf("删除\t%d\t%s\t%s\t%d\t%d\t%s\n",
					m_StuInfoVct[index].no,
					m_StuInfoVct[index].name,
					m_StuInfoVct[index].sex,
					m_StuInfoVct[index].age,
					m_StuInfoVct[index].phone,
					m_StuInfoVct[index].addr );
				
				m_StuInfoVct.erase(m_StuInfoVct.begin() + index);
				del += 1;
			}
			sum = 0;
			continue;
		}
		
		if (isdigit(sNo[i]))
			sum = sum*10 + sNo[i] - '0';
	}
}

void StudentInfo::updInfo()
{
	int i, chioce, no, index;
	printf("1、根据学号更新学生信息\n");
	printf("2、根据姓名更新学生信息\n");
	printf("请选择更新方式：");
	scanf("%d", &chioce);
	if (chioce != 1 && chioce != 2)
	{
		printf("输入有误，请重新输入\n");
		updInfo();
	}
	
	// 按学号更新学生信息
	if (chioce == 1)
	{
		printf("请输入要更新的学号：");
		scanf("%d", &no);
		
		printf("查询结果如下：\n");
		for (i=0,index=-1; i<m_StuInfoVct.size(); i++)
		{
			if (no == m_StuInfoVct[i].no)
			{
				index = i;
				
				printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
				m_StuInfoVct[index].no,
				m_StuInfoVct[index].name,
				m_StuInfoVct[index].sex,
				m_StuInfoVct[index].age,
				m_StuInfoVct[index].phone,
				m_StuInfoVct[index].addr );
				break;
			}
		}
		if (index == -1)
		{
			printf("未查找到学号 %d\n", no);
			return;
		}
		printf("确定更新？（yes or no）：");
		char s[16] = {0};
		scanf("%s", s);
		if (!strcmp(s, "yes"))
		{
			info_t info;
			memset(&info, 0, sizeof(info_t));
			
			info.no = m_StuInfoVct[index].no;
			printf("请输入学生姓名：");
			scanf("%s", info.name);
			printf("请输入学生性别：");
			scanf("%s", info.sex);
			printf("请输入学生年龄：");
			scanf("%d", &info.age);
			printf("请输入学生联系方式：");
			scanf("%d", &info.phone);
			printf("请输入学生家庭地址：");
			scanf("\n%[^\n]", info.addr);
			
			printf("新信息如下：\n");
			printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
				info.no, info.name, info.sex, info.age, info.phone, info.addr );
			
			printf("确定更新？（yes or no）：");
			memset(s, 0, sizeof(s));
			scanf("%s", s);
			if (!strcmp(s, "yes"))
			{
				m_StuInfoVct[index] = info;
				printf("更新完成\n");
			}
		}
		return;
	}
	
	// 按姓名更新学生信息
	char iName[64] = {0};
	int  iNo;
	vector<int> idxVct;
	printf("请输入学生姓名：");
	scanf("%s", iName);
	printf("查询结果如下：\n");
	for (i=0,no=1,index=-1; i<m_StuInfoVct.size(); i++)
	{
		if (strcmp(iName, m_StuInfoVct[i].name) != 0)
			continue;
		
		index = i;
		idxVct.push_back(index);
		printf("%d、\t%d\t%s\t%s\t%d\t%d\t%s\n", 
			no++,
			m_StuInfoVct[index].no,
			m_StuInfoVct[index].name,
			m_StuInfoVct[index].sex,
			m_StuInfoVct[index].age,
			m_StuInfoVct[index].phone,
			m_StuInfoVct[index].addr );
	}
	if (index == -1)
	{
		printf("未查找到姓名 %s\n", iName);
		return;
	}
	printf("请输入要更新信息的序号：");
	scanf("%d", &iNo);
	
	printf("选择信息如下：\n");
	index = idxVct[iNo-1];
	printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
		m_StuInfoVct[index].no,
		m_StuInfoVct[index].name,
		m_StuInfoVct[index].sex,
		m_StuInfoVct[index].age,
		m_StuInfoVct[index].phone,
		m_StuInfoVct[index].addr );
	
	printf("确认更新？（yes or no）：");
	char s[16] = {0};
	scanf("%s", s);
	if (!strcmp(s, "yes"))
	{
		info_t info;
		memset(&info, 0, sizeof(info_t));
		
		info.no = m_StuInfoVct[index].no;
		printf("请输入学生姓名：");
		scanf("%s", info.name);
		printf("请输入学生性别：");
		scanf("%s", info.sex);
		printf("请输入学生年龄：");
		scanf("%d", &info.age);
		printf("请输入学生联系方式：");
		scanf("%d", &info.phone);
		printf("请输入学生家庭地址：");
		scanf("\n%[^\n]", info.addr);
		
		printf("新信息如下：\n");
		printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
			info.no, info.name, info.sex, info.age, info.phone, info.addr );
		
		printf("确定更新？（yes or no）：");
		memset(s, 0, sizeof(s));
		scanf("%s", s);
		if (!strcmp(s, "yes"))
		{
			m_StuInfoVct[index] = info;
			printf("更新完成\n");
		}
	}
}

void StudentInfo::findInfo()
{
	int i, chioce, no, index;
	printf("1、根据学号查询学生信息\n");
	printf("2、根据姓名查询学生信息\n");
	printf("请选择查询方式：");
	scanf("%d", &chioce);
	if (chioce != 1 && chioce != 2)
	{
		printf("输入有误，请重新输入\n");
		findInfo();
	}
	
	// 按学号查询学生信息
	if (chioce == 1)
	{
		printf("请输入要查询的学号：");
		scanf("%d", &no);
		printf("查询结果如下：\n");
		for (i=0,index=-1; i<m_StuInfoVct.size(); i++)
		{
			if (no == m_StuInfoVct[i].no)
			{
				index = i;
				
				printf("%d\t%s\t%s\t%d\t%d\t%s\n", 
					m_StuInfoVct[index].no,
					m_StuInfoVct[index].name,
					m_StuInfoVct[index].sex,
					m_StuInfoVct[index].age,
					m_StuInfoVct[index].phone,
					m_StuInfoVct[index].addr );
				break;
			}
		}
		if (index == -1)
			printf("未查找到学号 %d\n", no);
		return;
	}
	
	// 按姓名查询学生信息
	char iName[64] = {0};
	printf("请输入学生姓名：");
	scanf("%s", iName);
	printf("查询结果如下：\n");
	for (i=0, no=1, index=-1; i<m_StuInfoVct.size(); i++)
	{
		if (strcmp(iName, m_StuInfoVct[i].name) != 0)
			continue;
		
		index = i;
		printf("%d、\t%d\t%s\t%s\t%d\t%d\t%s\n", 
			no++,
			m_StuInfoVct[index].no,
			m_StuInfoVct[index].name,
			m_StuInfoVct[index].sex,
			m_StuInfoVct[index].age,
			m_StuInfoVct[index].phone,
			m_StuInfoVct[index].addr );
	}
	if (index == -1)
		printf("未查找到姓名 %s\n", iName);
}

void StudentInfo::clearInfo()
{
	char s[16] = {0}; 
	printf("数据珍贵，请谨慎操作！确认删除（yes or no）\n");
	scanf("%s", s);
	
	if (!strcmp(s, "yes"))
		m_StuInfoVct.clear();
	else
		printf("已取消清空所有学生信息.\n");
}

void StudentInfo::quitSysterm()
{
	exportDataToFile();
	exit(0);
}

void StudentInfo::importDataFromFile()
{
	FILE *fp = fopen(DatabaseFile, "r");
	if (!fp)
	{
		printf("导入数据失败\n");
		return;
	}
	
	int i, iCount = 0;
	fread(&iCount, sizeof(iCount), 1, fp);
	if (iCount <= 0)
	{
		printf("数据有误\n");
		fclose(fp);
		return;
	}
	
	info_t info = {0};
	for (i=0; i<iCount; i++)
	{
		fread(&info, sizeof(info_t), 1, fp);
		m_StuInfoVct.push_back(info);
	}
	printf("数据导入完成，目标 %d，导入 %d\n", iCount, i);
	fclose(fp);
}

void StudentInfo::exportDataToFile()
{
	if (m_StuInfoVct.empty())
		return;
	
	FILE *fp = fopen(DatabaseFile, "w");
	if (!fp) return;
	
	int ncount = m_StuInfoVct.size();
	int len = sizeof(info_t)*ncount + sizeof(ncount);
	char *pSaveBuf = (char*)malloc(len);
	if (!pSaveBuf) return;
	memset(pSaveBuf, 0, len);
	
	char *pStart = pSaveBuf;
	memcpy(pStart, &ncount, sizeof(ncount));
	pStart += sizeof(ncount);
	
	for (int i=0; i<ncount; i++)
	{
		memcpy(pStart, &m_StuInfoVct[i], sizeof(info_t));
		pStart += sizeof(info_t);
	}
	
	int n = fwrite(pSaveBuf, len, 1, fp);
	printf("数据总长 %d 字节，成功写入文件 %d 字节\n", len, n*len);
	fclose(fp);
}



#if 1
int main(int argc, char *argv[])
{
	StudentInfo sys;
	
	for ( ; ; )
	{
		sys.printMenu();
	}
}
#endif