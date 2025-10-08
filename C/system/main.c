#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char name[20];
    int score;
    struct student* next;
};
int checkname(struct student*head,char name[])
{
    struct student* current=head;
    while(current!=NULL&&strcmp(current->name,name)!=0)
    {
        current=current->next;
    }
    if(current!=NULL&&strcmp(current->name,name)==0)
    {
        puts("姓名重复，请重新输入:\n"); 
        return 0;
    }
    return 1;
}
void clearInputBuffer() //清除缓存区
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
struct student* appendnode(struct student* head,char name[],int score)
{
    struct student* newnode=(struct student*)malloc(sizeof(struct student));
    strcpy(newnode->name,name);
    newnode->score=score;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct student*current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
    }
    return head;
}
struct student* enterstudent(struct student* head)
{
    puts("0.返回上一层");
    puts("请输入姓名和分数：\n");
    while(1)
    {
        int score;
        char name[20];  
        scanf("%s",name);
        if(name[0]=='0')
        {
            break;
        }
        scanf("%d",&score);
        if(checkname(head,name)==1)
            head=appendnode(head,name,score);
    }
    return head;

}
struct student* deletestudent(struct student* head) 
{
    struct student* current = head;
    struct student* previous = NULL;
    struct student* temp;
    char name[20];

    printf("请输入你要删除的学生的姓名:\n");
    clearInputBuffer();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // 移除换行符（如果存在）

    if (strcmp(name, head->name) == 0) 
    {
        temp = head;
        head = head->next;
        free(temp);
    } 
    else 
    {
        while (current != NULL && strcmp(name, current->name) != 0) 
        {
            previous = current;
            current = current->next;
        }
        if (current != NULL) 
        {
            temp = current;
            if (previous != NULL) 
            {
                previous->next = current->next;
            }
            free(temp);
        } 
        else 
        {
            printf("学生 %s 未找到\n", name);
        }
    }
    return head;
}
void insertstudent(struct student* head)
{


}
void displaystudent(struct student* head)
{
    struct student*current=head;
    printf("%-20s%-4s\n", "姓名", "成绩");
    while(current!=NULL)
    {
        printf("%-20s%-4d\n", current->name, current->score);
        current=current->next;
    }
    
}
int main()
{
    struct student* head=NULL;
    while(1)
    {   
        puts("请输入数字:\n");
        puts("1.录入学生信息\n");
        puts("2.删除学生信息\n");
        puts("3.插入学生信息\n");
        puts("4.展示学生信息\n");
        puts("5.退出系统");
        char n=getchar();
        switch(n)
        {
            case '1':
                head=enterstudent(head);
                break;
            case '2':
                head=deletestudent(head);
                break;
            case '3':
                insertstudent(head);
                break;
            case '4':
                displaystudent(head);
                break;
            case '5':
                return 0;
                break;
        }
    }
}
