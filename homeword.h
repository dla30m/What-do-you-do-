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

//�Ƿ~<5
const char *badforlearn[] = {" �A���Q�G�@���M�I��"," �A�֥h�ݮѰ�"};
//�Ƿ~>=5
const char *goodforlearn[] = {" �A�ڥ��N�O���Q�a"," ���ٴ����a�A�F"};
//�߱�<5
const char *badmood[] = {" ��ĳ�A�h�@�뻲�ɫ�"," �۱����v�M�u0800788998"};
//�߱�>=5
const char *goodmood[] = {" �A�i�H���n�o��High��"," �N�ݧA�����ण��]�o��ּ�"};
//���j<5
const char *hungry[] = {" �־j���F��"," �S�̧A�S���G��"};
//���j>=5
const char *full[] = {" �Y�F�褣����"," ���Y����n�ư�"};
//�R��<5
const char *badlove[] = {" �������ݤ����ˮ`"," �k��O�̴Ϊ�"};
//�R��>=5
const char *goodlove[] = {" �ܷ|����"," �İ_�ӥİ_��"};

FILE *fp1,*fp2,*fp3,*fp4;
Topic topic[10];
React react[10];
Result *result_head=NULL;
Result *result_tail=NULL;
int times=0;
const int aysize = 2;

//�}���ɮ׿�J�D�� (�t�d�H�G�J�i��
void topic_from_file(Topic k[]);

//�C���D��X       (�t�d�H�G�J�i��
void RPG(int s[]);

//�C��������X���G (�t�d�H�G���G��
void generate_end(Endingstr *ending,int ln,int md,int hg,int lv);

//�C�D��ܵ�����X (�t�d�H�G�����q
void reaction();

//�O���C�D��J���G (�t�d�H�G�J�i��
void recordthechose(char *one , char *two , int chose);

//��X�C�������   (�t�d�H�G�J�i��
void printft_the_chose();

//���C��           (�t�d�H�G�J�i��
void SetColor(int f=7,int b=0);

void chang_the_color(int n);
