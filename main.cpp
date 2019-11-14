#include"homeword.h"

int main()
{
	int a;
	int skill[4]={5,5,5,5};
	printf("-----------------------------Start Game-------------------------------------\n");
	printf("你是一個大一的男生，在學校裡你會遇到各式各樣的事情，每一種選擇將會影響到你。\n");
	printf("但是以下要注意\n");
	printf("   1)你和某位女生 A 感情很好 \n");
	printf("   2)男生 B 的學習能力比你強，你跟他是朋友 \n");
	printf("----------------------------------------------------------------------------\n");
	system("pause");
	system("CLS");
	topic_from_file(topic);
	reaction();
	do
	{
	    chang_the_color(skill[0]);
		printf("學業 ");
		chang_the_color(skill[1]);
		printf("心情 ");
		chang_the_color(skill[2]);
		printf("飢餓 ");
		chang_the_color(skill[3]);
		printf("愛情 \n\n");
		SetColor();
		RPG(skill);

	}while(times<10);
	printf("Your skill \n");
	printf("學業 = %d 心情 = %d 飢餓 = %d 愛情 = %d \n\n",skill[0],skill[1],skill[2],skill[3]);
	Endingstr ed;
	generate_end(&ed,skill[0],skill[1],skill[2],skill[3]);
	system("pause");
    system("CLS");

    printf("-----------------------------End Game---------------------------------------\n");
    printf("是否想要觀看你的選擇 (y/n) \n");
	if(getche()=='y')
        printft_the_chose();
	else
        printf("\n好吧那算了881 \n");
	printf("----------------------------------------------------------------------------\n");

	system("pause");
}

void RPG(int s[])
{
	int ans;
	printf("%s\n\n",topic[times].topic_one);
	printf("%s\n\n",topic[times].topic_two);
	printf("%s\n\n",topic[times].topic_three);
	printf("輸入你的選擇 : ");
	scanf("%d",&ans);
	if(ans==1)
	{
		for(int i=0;i<4;i++)
			s[i] = s[i] + topic[times].right_answer[i]-5;
        recordthechose( topic[times].topic_one ,topic[times].topic_two, ans);
        printf("%s \n",react[times].react_one);
	   	system("pause");
        times++;
	}
	else if(ans==2)
    {
        for(int i=0;i<4;i++)
			s[i] = s[i] + topic[times].error_answer[i]-5;
        recordthechose( topic[times].topic_one ,topic[times].topic_three, ans);
        printf("%s \n",react[times].react_two);
	   	system("pause");
        times++;
    }
	else
        times=times;
	system("CLS");
}

void generate_end(Endingstr *ending,int ln,int md,int hg,int lv){
    srand(time(NULL));
    const char *forlearn;
    const char *formood;
    const char *forhunger;
    const char *forlove;

	if(ln<5)
        forlearn = badforlearn[rand() % aysize];
    else
        forlearn = goodforlearn[rand() % 2 ];

    if(md<5)
        formood = badmood[rand() % aysize];
    else
        formood = goodmood[rand() % aysize];

    if(hg<5)
        forhunger = hungry[rand() % aysize];
    else
        forhunger = full[rand() % aysize];

    if(lv<5)
        forlove = badlove[rand() % aysize];
    else
        forlove = goodlove[rand() % aysize];

    ending->learn = (char *) malloc(20);
    ending->mood = (char *) malloc(20);
    ending->hunger = (char *) malloc(20);
    ending->love = (char *) malloc(20);
    strcpy(ending->learn,forlearn);
    strcpy(ending->mood,formood);
    strcpy(ending->hunger,forhunger);
    strcpy(ending->love,forlove);
    printf("學業:%s\n心情:%s\n飽食:%s\n愛情:%s\n",ending->learn,ending->mood,ending->hunger,ending->love);
}

void reaction()
{
	fp3 = fopen("1st reaction.txt","r");
	for(int i=0;i<10;i++)
	{
		fgets(react[i].react_one, 100, fp3);
	}
	fclose(fp3);
	fp4 = fopen("2nd reaction.txt","r");
	for(int i=0;i<10;i++)
	{
		fgets(react[i].react_two, 100, fp4);
	}
	fclose(fp4);
}

void topic_from_file(Topic k[])
{
	fp1 = fopen("topic.txt","r");
	fp2 = fopen("skill.txt","r");
	for(int i=0;i<10;i++)
	{
		fgets(k[i].topic_one, 100, fp1);
		int strl = strlen(k[i].topic_one);
		if (k[i].topic_one[strl - 1] == '\n')
			k[i].topic_one[strl - 1] = '\0';

		fgets(k[i].topic_two, 100, fp1);
		strl = strlen(k[i].topic_two);
		if (k[i].topic_two[strl - 1] == '\n')
			k[i].topic_two[strl - 1] = '\0';

		fgets(k[i].topic_three, 100, fp1);
		strl = strlen(k[i].topic_three);
		if (k[i].topic_three[strl - 1] == '\n')
			k[i].topic_three[strl - 1] = '\0';
	}

	int a,b;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<4;j++)
		{
			a =  fgetc(fp2);
			if(48<=a&&a<=57)
				k[i].right_answer[j] = a-48;
			else
			 	j--;
		}
		for(int j=0;j<4;j++)
		{
			b = fgetc(fp2);
			if(b>=48&&b<=57)
				k[i].error_answer[j] = b-48;
			else
				j--;
		}
	}
	fclose(fp1);
	fclose(fp2);

}

void recordthechose(char *one , char *two , int chose)
{
    Result *newptr;
    newptr = (struct Result *) malloc( sizeof( struct Result ) );
    newptr->result_one = one;
    newptr->result_two = two;
    newptr->anser = chose;
    newptr->next = NULL;
    if(result_head==NULL)
    {
        result_head=newptr;
        result_tail=newptr;
    }
    else
    {
        (result_tail)->next = newptr;
        result_tail = newptr;
    }

}

void printft_the_chose()
{
    printf("\n");
    for(int i=0; i<times; i++)
	{
	    system("pause");
        printf("第%d題 \n\n",i+1);
        printf("%s \n", result_head->result_one);
        printf("%s \n", result_head->result_two);
		printf("你的輸入 : %d \n\n",result_head->anser);
	    if(result_head->next != NULL)
			result_head = result_head->next;
		else
            break;
	}
}

void SetColor(int f,int b)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

void chang_the_color(int n)
{
    if(n<=2)
        SetColor(2,7);//green
    else if(3<=n && n<=4)
        SetColor(4,7);//red
    else if(n==5)
        SetColor(0,7);//while
    else
        SetColor(6,7);//yellow
}
