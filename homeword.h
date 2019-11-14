#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstring>
#include<conio.h>
#include<windows.h>
#include<string.h>

struct Topic
{
	char topic_one[100];
	char topic_two[100];
	char topic_three[100];
	int right_answer[4];
	int error_answer[4];
};

struct React
{
	char react_one[100];
	char react_two[100];
};

struct Result
{
    char *result_one;
    char *result_two;
    int anser;
	struct Result *next;
};

struct Endingstr{
    char *learn;
    char *mood;
    char *hunger;
    char *love;
};

//學業<5
const char *badforlearn[] = {" 你有被二一的危險喔"," 你快去看書啦"};
//學業>=5
const char *goodforlearn[] = {" 你根本就是學霸吧"," 欸欸期末靠你了"};
//心情<5
const char *badmood[] = {" 建議你去一趟輔導室"," 自殺防治專線0800788998"};
//心情>=5
const char *goodmood[] = {" 你可以不要這麼High嗎"," 就看你期末能不能也這麼快樂"};
//飢餓<5
const char *hungry[] = {" 快餓死了啦"," 兄弟你沒有胃嗎"};
//飢餓>=5
const char *full[] = {" 吃東西不揪喔"," 剛剛吃什麼好料啊"};
//愛情<5
const char *badlove[] = {" 不期不待不受傷害"," 右手是最棒的"};
//愛情>=5
const char *goodlove[] = {" 很會撩喔"," 汁起來汁起來"};

FILE *fp1,*fp2,*fp3,*fp4;
Topic topic[10];
React react[10];
Result *result_head=NULL;
Result *result_tail=NULL;
int times=0;
const int aysize = 2;

//開啟檔案輸入題目 (負責人：胡展碩
void topic_from_file(Topic k[]);

//每次題輸出       (負責人：胡展碩
void RPG(int s[]);

//遊戲結束輸出結果 (負責人：莊果麟
void generate_end(Endingstr *ending,int ln,int md,int hg,int lv);

//每題選擇結束輸出 (負責人：蔡溢義
void reaction();

//記錄每題輸入結果 (負責人：胡展碩
void recordthechose(char *one , char *two , int chose);

//輸出每次的選擇   (負責人：胡展碩
void printft_the_chose();

//換顏色           (負責人：胡展碩
void SetColor(int f=7,int b=0);

void chang_the_color(int n);
