#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include <math.h>
//��������һ���ֳ��������� ָ���͡����Ǻ����������Ǻ���������ָ���͡������͡���ʽ�� 
//ָ���� x^t t=0;t=-1;tΪ����
struct exponentType
{
	char xExpressionEPtr[30];//x���ʽ 
	double tNum;//ָ��x^t ��t��ֵ 
};
typedef struct exponentType ExponentType;

//���Ǻ����� sin cos tan sec csc cot arcsin arccos arctan
struct trigonometricFunctionType
{
	char trigonometricFunction9;//����9��  sinA cosB tanC secD cscE cotF arcsinG arccosH arctanI
	char xExpressionTPtr[30];//x���ʽ
};
typedef struct trigonometricFunctionType TrigonometricFunctionType;

//��ָ���� a^x (a>0) a=1��a=e
struct powerExponentType
{
	double aNum;//(a>0) a=1��a=e��aΪ����
	char xExpressionPPtr[30];//x���ʽ 
}; 
typedef struct powerExponentType PowerExponentType;

//������ ��Ҫת������Ȼ����ln 
struct logarithmType
{
	char xExpressionLPtr[30];//x���ʽ
}; 
typedef struct logarithmType LogarithmType;

//��ʽx/y��Ӧc x��y��Ϊx���ʽ��Ӧd 
struct fractionType
{
	char numerator[30];//���ӱ��ʽ
	char denominator[30];//��ĸ���ʽ 
};
typedef struct fractionType FractionType;



//���뱻���������ʽ 
//ÿ�����͵ĺ����ڽ����л��Ӧ�������һ�ַ��� �Ա��̽��� ������ֻ����˳����д ����������룩 
/*���Ŷ�Ӧ��
��ʽ���г����� ��Ҫ�Ȱ��йذ��� ��Ӧn ������� ��;�������ӳ����� 
ָ��x^y ������x��x^t��Ӧa �ݺ�x��a^x��Ӧb  ��x^x�������Ϊ�޷�ʵ�֣�  
��ʽx/y��Ӧc  ��ֻ��y����x��ֻ��x����x����Ӧa ����Ҫ��������ʵ��ת����  ��x��y��Ϊx���ʽ��Ӧd 
���� ȫ��ת��Ϊ��Ȼ����ln ��Ӧe      ������Ȼ���� ��Ӧf ��Ϊ���� ֻ��������  >������ 
���Ǻ����� sin��ӦA cos��ӦB tan��ӦC sec��ӦD csc��ӦE cot��ӦF arcsin��ӦG arccos��ӦH aretan��ӦI
()�������� ���ʱͬʱ���� ��ʾֱ�����������м����� ��Ӧ( 
�Ҽ���Ӧ����>  ���ָ����ã� 
�������ʽ��� ��Ҫ���Ҽ����� ��ʾ>> 
=���ڳ������൱�� Enter�� ��Ӧ'\n' 
*/ 
int gcd(int n,int m){
	int temp,r;
	if(n<m){
	temp=n;
	n=m;
	m=temp;
	}
	while(m!=0){
	r=n%m;
	n=m;
	m=r; 
	}
	return n;
	}//���Դ��������Լ�� 
int main()
//�������������㷶Χʱ����ֵ��0
//�������� ����ֵΪ1 
{
	initgraph(400, 400);	
	setfillcolor(EGERGB(0x54, 0x54, 0x54));
	bar(40,100,330,400);    
	setfillcolor(EGERGB(0xFC, 0xFC, 0xFC));//���������ɫ��һ��Ϊͼ���ڲ���ɫ
	bar(50,190,80,220);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(56, 198, "sin");
	bar(50,230,80,260);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(60, 238, "1");
	bar(50,270,80,300);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(60, 278, "4");
	bar(50,310,80,340);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(60, 318, "7");
	bar(50,350,80,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(25, 0, "arial");
	outtextxy(62, 350, ".");
	bar(90,190,120,220);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(95, 198, "cos");
	bar(90,230,120,260);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(100, 238, "2");
	bar(90,270,120,300);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(100, 278, "5");
	bar(90,310,120,340);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(100, 318, "8");
	bar(90,350,120,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(100, 358, "0");
	bar(130,190,160,220);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(136, 198, "tan");
	bar(130,230,160,260);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(140, 238, "3");
	bar(130,270,160,300);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(140, 278, "6");
	bar(130,310,160,340);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(140, 318, "9");
	bar(130,350,160,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(142, 358, "=");
	bar(170,190,200,220);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(13, 0, "arial");
	outtextxy(170, 198, "arcsin");
	bar(170,230,200,260);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(20, 0, "arial");
	outtextxy(180, 238, "+");	
	bar(170,270,200,300);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(20, 0, "arial");
	outtextxy(180, 278, "-");
	bar(170,310,200,340);
	setcolor(0); 
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(20, 0, "arial");
	outtextxy(180, 318, "*");
	bar(170,350,200,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(20, 0, "arial");
	outtextxy(180, 358, "/");
	bar(210,190,240,220);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(13, 0, "arial");
	outtextxy(210, 198, "arccos");
	bar(210,230,240,260);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(220, 238, "(");
	bar(210,270,240,300);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(220, 278, "x^t");
	bar(210,310,240,340);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(223, 318, "x");
	bar(210,350,240,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(220, 358, "��");
	bar(250,190,280,220);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(13, 0, "arial");
	outtextxy(250, 198, "arctan");
	bar(250,230,280,260);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(260, 238, ")");	
	bar(250,270,280,300);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(255, 278, "a^x");
	bar(250,310,280,340);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(16, 0, "arial");
	outtextxy(260, 318, "->");
	bar(250,350,280,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(255, 358, "ln");//��һʵ�ľ���
	bar(290,190,320,220);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(295, 198, "csc");
	bar(290,230,320,260);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(295, 238, "sec");
	bar(290,270,320,300);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(295, 278, "cot");
	bar(290,310,320,340);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(298, 318, "��");
	bar(290,350,320,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(290, 358, "��|��");
	
	
	char calculus[50];
	int in=0;//���ڴ��治���������� 
	char xiandai[100];
	int im=0;//���ڴ����ߴ�����
	bool judge=true; 
	
	bool click_flag;
	int xClick, yClick;
	for (; is_run(); delay_fps(60)) 
	{
		//�����־λ����
		click_flag = false;
		//���������Ϣ
		while (mousemsg()) {
			mouse_msg msg = getmouse();
			//�������
			if (msg.is_left() && msg.is_down()) {
				//��־λ��λ����¼���λ��
				click_flag = true;
				xClick = msg.x;
				yClick = msg.y;
			}
		}		//��⵽���
		if (click_flag) {//������������
			if(((290<xClick)&&(xClick<300))&&((350<yClick)&&(yClick<380))){
				printf("�󲻶�����\n");
				judge=true;
			}
			else if(((310<xClick)&&(xClick<320))&&((350<yClick)&&(yClick<380))){
				printf("��������ά������\n");
				judge=false;
			}
			else if(((50<xClick)&&(xClick<80))&&((190<yClick)&&(yClick<220))){
				printf("sin");
				calculus[in]='A';
				in++;
			}
			else if(((50<xClick)&&(xClick<80))&&((230<yClick)&&(yClick<260))){
				printf("1");
				calculus[in]='1';
				xiandai[im]='1';
				in++;
				im++;
			}
			else if(((50<xClick)&&(xClick<80))&&((270<yClick)&&(yClick<300))){
				printf("4");
				calculus[in]='4';
				xiandai[im]='4';
				in++;
				im++;
			}
			else if(((50<xClick)&&(xClick<80))&&((310<yClick)&&(yClick<340))){
				printf("7");
				calculus[in]='7';
				xiandai[im]='7';
				in++;
				im++;
			}
			else if(((50<xClick)&&(xClick<80))&&((350<yClick)&&(yClick<380))){
				printf(".");
				calculus[in]='.';
				in++;
			}
			else if(((90<xClick)&&(xClick<120))&&((190<yClick)&&(yClick<220))){
				printf("cos");
				calculus[in]='B';
				in++;
			}
			else if(((90<xClick)&&(xClick<120))&&((230<yClick)&&(yClick<260))){
				printf("2");
				calculus[in]='2';
				xiandai[im]='2';
				in++;
				im++;
			}
			else if(((90<xClick)&&(xClick<120))&&((270<yClick)&&(yClick<300))){
				printf("5");
				calculus[in]='5';
				xiandai[im]='5';
				in++;
				im++;
			}
			else if(((90<xClick)&&(xClick<120))&&((310<yClick)&&(yClick<340))){
				printf("8");
				calculus[in]='8';
				xiandai[im]='8';
				in++;
				im++;
			}
			else if(((90<xClick)&&(xClick<120))&&((350<yClick)&&(yClick<380))){
				printf("0");
				calculus[in]='0';
				xiandai[im]='0';
				in++;
				im++;
			}
			else if(((130<xClick)&&(xClick<160))&&((190<yClick)&&(yClick<220))){
				printf("tan");
				calculus[in]='C';
				in++;
			}
			else if(((130<xClick)&&(xClick<160))&&((230<yClick)&&(yClick<260))){
				printf("3");
				calculus[in]='3';
				xiandai[im]='3';
				in++;
				im++;
			}
			else if(((130<xClick)&&(xClick<160))&&((270<yClick)&&(yClick<300))){
				printf("6");
				calculus[in]='6';
				xiandai[im]='6';
				in++;
				im++;
			}
			else if(((130<xClick)&&(xClick<160))&&((310<yClick)&&(yClick<340))){
				printf("9");
				calculus[in]='9';
				xiandai[im]='9';
				in++;
				im++;
			}
			else if(((130<xClick)&&(xClick<160))&&((350<yClick)&&(yClick<380))){
				calculus[in]='\n';
				xiandai[im]='\n';
				in++;
				im++;
			}
			else if(((170<xClick)&&(xClick<200))&&((190<yClick)&&(yClick<220))){
				printf("arcsin");
				calculus[in]='G';
				in++;
			}
			else if(((170<xClick)&&(xClick<200))&&((230<yClick)&&(yClick<260))){
				printf("+");
				calculus[in]='+';
				in++;
			}
			else if(((170<xClick)&&(xClick<200))&&((270<yClick)&&(yClick<300))){
				printf("-");
				calculus[in]='-';
				in++;
			}
			else if(((170<xClick)&&(xClick<200))&&((310<yClick)&&(yClick<340))){
				printf("*");
				calculus[in]='>';
				in++;
				calculus[in]='>';
				in++;
			}
			else if(((170<xClick)&&(xClick<200))&&((350<yClick)&&(yClick<380))){
				printf("/");
				calculus[in]='/';
				in++;
			}
			else if(((210<xClick)&&(xClick<240))&&((190<yClick)&&(yClick<220))){
				printf("arccos");	
				calculus[in]='H';
				in++;
			}
			else if(((210<xClick)&&(xClick<240))&&((230<yClick)&&(yClick<260))){
				printf("(");	
			}
			else if(((210<xClick)&&(xClick<240))&&((270<yClick)&&(yClick<300))){
				printf("x^t");	
				calculus[in]='a';
				in++;
			}
			else if(((210<xClick)&&(xClick<240))&&((310<yClick)&&(yClick<340))){
				printf("x");	
				calculus[in]='x';
				in++;
			}
			else if(((210<xClick)&&(xClick<240))&&((350<yClick)&&(yClick<380))){
				printf("��");	
				calculus[in]='��';
				in++;
			}
			else if(((250<xClick)&&(xClick<280))&&((190<yClick)&&(yClick<220))){
				printf("arctan");
				calculus[in]='I';
				in++;	
			}
			else if(((250<xClick)&&(xClick<280))&&((230<yClick)&&(yClick<260))){
				printf(")");
			}
			else if(((250<xClick)&&(xClick<280))&&((270<yClick)&&(yClick<300))){
				printf("a^x");	
				calculus[in]='b';
				in++;
			}
			else if(((250<xClick)&&(xClick<280))&&((310<yClick)&&(yClick<340))){
				printf("->");
				calculus[in]='>';
				in++;	
			}
			else if(((250<xClick)&&(xClick<280))&&((350<yClick)&&(yClick<380))){
				printf("ln");	
				calculus[in]='e';
				in++;
			}
			else if(((290<xClick)&&(xClick<320))&&((190<yClick)&&(yClick<220))){
				printf("csc");
				calculus[in]='E';
				in++;
			}
			else if(((290<xClick)&&(xClick<320))&&((230<yClick)&&(yClick<260))){
				printf("sec");
				calculus[in]='D';
				in++;
			}
			else if(((290<xClick)&&(xClick<320))&&((270<yClick)&&(yClick<300))){
				printf("cot");
				calculus[in]='F';
				in++;
			}
			else if(((290<xClick)&&(xClick<320))&&((310<yClick)&&(yClick<340))){
				printf(" ");
				xiandai[im]=' ';
				im++;
			}

		}

		
		if(calculus[in-1]=='\n')
		{
			calculus[in]='\0';
			break;
		}
    }

	//
	//
	//
	
	if(judge)
	{
	printf("\n\n%s\n","�����������˼·��");
	int out=0;//���ַ����д����ַ�����ļ����� 
	
	char firstLetter;
	firstLetter=calculus[out];
	out++;
	char *connector=NULL;//���ڴ���Ӽ��� �Ա�֪���Ƿ���Ҫ�������г��� 
	char *coefficient=NULL;//���ڴ������е�ϵ�� ������ֻ����ͷ����ϵ�� ������ĳЩ�����Ҫ���򲢲���ϵ�� ��Ҫ������coefficient�� 
	                       //����ʵ�������������㷽����û���ų���n���������֮�� �����볣������� ��Ҫʹ������ʹ�ù���������ע�� 
	char record[50];
	int recordNum=0;//������¼���е���������
	record[recordNum]=firstLetter;
	recordNum++; 
	
	//��������ĸѡ���Ӧ���ͽṹ��
	switch (firstLetter)
	{
		//���Ǻ����������Ǻ������ 
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
			{
			TrigonometricFunctionType triPtr;
			triPtr.trigonometricFunction9=firstLetter;//sin��ӦA cos��ӦB tan��ӦC sec��ӦD csc��ӦE cot��ӦF arcsin��ӦG arccos��ӦH aretan��ӦI
			
			//����x���ʽ 
			char referenceTri[30];//�ο����� ֻ����ax+b��ʽ
			
			//�ȴ��� referenceTri[0]
			referenceTri[0]=calculus[out];
	        out++;
			record[recordNum]=referenceTri[0];
			recordNum++;
			if(referenceTri[0]!='0'&&referenceTri[0]!='1'&&referenceTri[0]!='2'&&referenceTri[0]!='3'&&referenceTri[0]!='4'&&
			   referenceTri[0]!='5'&&referenceTri[0]!='6'&&referenceTri[0]!='7'&&referenceTri[0]!='8'&&referenceTri[0]!='9'&&
			   referenceTri[0]!='x'&&referenceTri[0]!='+'&&referenceTri[0]!='-') 
			{
				printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����
				return 0;
			}//ֻ�ܰ�˳������ �˴�����������> (����֪����ôʵ��)
			
			unsigned int counter=0;
			do //ѭ���ó�x���ʽ���沿�� 
			{
				counter++;
				referenceTri[counter]=calculus[out];
	            out++;
				record[recordNum]=referenceTri[counter];
				recordNum++;
				if(referenceTri[counter]!='0'&&referenceTri[counter]!='1'&&referenceTri[counter]!='2'&&referenceTri[counter]!='3'&&referenceTri[counter]!='4'&&
			       referenceTri[counter]!='5'&&referenceTri[counter]!='6'&&referenceTri[counter]!='7'&&referenceTri[counter]!='8'&&referenceTri[counter]!='9'&&
			       referenceTri[counter]!='x'&&referenceTri[counter]!='+'&&referenceTri[counter]!='-'&&referenceTri[counter]!='>'&&referenceTri[counter]!='\n')
			    {
			    	printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����
			    	return 0;
			    }//�ų�����ax+b��� 
			} while((!(referenceTri[counter-1]=='>'&&referenceTri[counter]=='>'))&&(referenceTri[counter]!='\n'));//����>>��=ʱѭ������������getchar
			referenceTri[counter+1]='\0';
			
			//�������Ǻ��� 
			char xExpressionCaseTriPtr[30];
			if(referenceTri[counter]=='\n')
			{
				strncpy(xExpressionCaseTriPtr,referenceTri,counter);
				xExpressionCaseTriPtr[counter]='\0';//ʹ xExpressionCaseTriPtrָ�� x�ı��ʽ 
				strcpy(triPtr.xExpressionTPtr,xExpressionCaseTriPtr);//�ṹ����x���ʽ ���
				
				if(strcmp(xExpressionCaseTriPtr,"x")==0)
				{
					printf("%s\n","�ù�ʽ������");
					switch(firstLetter)
					{
						case 'A':
							printf("%s","��sinxdx=-cosx+C");
							break;
						case 'B':
							printf("%s","��cosxdx=sinx+C");
						    break;
						case 'C':
							printf("%s","��tanxdx=-ln|cosx|+C");
							break;
						case 'D':
							printf("%s","��secx==��cosxdx/(cosx)^2=��d(sinx)/[1-(sinx)^2]=�û�Ԫ��=ln|secx+tanx|+C");
							break;
						case 'E':
						    printf("%s","��cscxdx=��dx/sinx=��sinxdx/sin2x=-��dcosx/(1-cos2x)=�û�Ԫ��=ln|cscx-cotx|+C") ;
							break;
						case 'F':
						    printf("%s","��cotxdx=ln|sinx|+C") ;
						    break;
						case 'G':
							printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arcsinx=xarcsinx+��(1-x^2)+C");
							break;
						case 'H':
							printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arccosx=xarccosx-��(1-x^2)+C");
							break;
						case 'I':
							printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arctanx=xarctanx+ln(��(1+x^2))+C");
							break;
					} //switch���� 
				}
				else
				{
					printf("%s%s\n","���û�Ԫ�����㣬��u=",xExpressionCaseTriPtr);
					printf("%s\n","���ù�ʽ������");
					switch(firstLetter)
					{
						case 'A':
							printf("%s","��sinxdx=-cosx+C");
							break;
						case 'B':
							printf("%s","��cosxdx=sinx+C");
						    break;
						case 'C':
							printf("%s","��tanxdx=-ln|cosx|+C");
							break;
						case 'D':
							printf("%s","��secx==��cosxdx/(cosx)^2=��d(sinx)/[1-(sinx)^2]=�û�Ԫ��=ln|secx+tanx|+C");
							break;
						case 'E':
						    printf("%s","��cscxdx=��dx/sinx=��sinxdx/sin2x=-��dcosx/(1-cos2x)=�û�Ԫ��=ln|cscx-cotx|+C") ;
							break;
						case 'F':
						    printf("%s","��cotxdx=ln|sinx|+C") ;
						    break;
						case 'G':
							printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arcsinx=xarcsinx+��(1-x^2)+C");
							break;
						case 'H':
							printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arccosx=xarccosx-��(1-x^2)+C");
							break;
						case 'I':
							printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arctanx=xarctanx+ln(��(1+x^2))+C");
							break;
					} //switch���� 
				} 
				break; 
			} 
			
			//�˴��ǵ������Ǻ���  ������ת����ʽ����Ԫ�� 
			
			
			else
			{
				//���Ǻ������滹��Ҫ�˱��ʽ����� 
				//һ������  sin��cos���   ����   sin/cos��x�Ķ���ʽ 
				if(referenceTri[counter-1]=='>'&&referenceTri[counter]=='>')
				{
					strncpy(xExpressionCaseTriPtr,referenceTri,counter-1);
					xExpressionCaseTriPtr[counter-1]='\0';//ʹ xExpressionCaseTriPtrָ�� x�ı��ʽ
					char secondLetter=calculus[out];
	                out++;
					record[recordNum]=secondLetter;
					recordNum++;
					if(secondLetter=='\n')
					{
						strcpy(triPtr.xExpressionTPtr,xExpressionCaseTriPtr);//�ṹ����x���ʽ ���
						if(strcmp(xExpressionCaseTriPtr,"x")==0)
				        {
					        printf("%s\n","�ù�ʽ������");
					        switch(firstLetter)
				        	{
						        case 'A':
							        printf("%s","��sinxdx=-cosx+C");
							        break;
						        case 'B':
							        printf("%s","��cosxdx=sinx+C");
						            break;
						        case 'C':
							        printf("%s","��tanxdx=-ln|cosx|+C");
							        break;
						        case 'D':
							        printf("%s","��secx==��cosxdx/(cosx)^2=��d(sinx)/[1-(sinx)^2]=�û�Ԫ��=ln|secx+tanx|+C");
						        	break;
						        case 'E':
						            printf("%s","��cscxdx=��dx/sinx=��sinxdx/sin2x=-��dcosx/(1-cos2x)=�û�Ԫ��=ln|cscx-cotx|+C") ;
							        break;
						        case 'F':
						            printf("%s","��cotxdx=ln|sinx|+C") ;
						            break;
						        case 'G':
							        printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arcsinx=xarcsinx+��(1-x^2)+C");
							        break;
						        case 'H':
							        printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arccosx=xarccosx-��(1-x^2)+C");
							        break;
						        case 'I':
							        printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arctanx=xarctanx+ln(��(1+x^2))+C");
							        break;
					            } //switch���� 
				        }  
				        else
				        {
					        printf("%s%s\n","���û�Ԫ�����㣬��u=",xExpressionCaseTriPtr);
					        printf("%s\n","���ù�ʽ������");
					        switch(firstLetter)
					        {
						        case 'A':
						        	printf("%s","��sinxdx=-cosx+C");
						        	break;
						        case 'B':
						        	printf("%s","��cosxdx=sinx+C");
						            break;
						        case 'C':
						        	printf("%s","��tanxdx=-ln|cosx|+C");
						        	break;
						        case 'D':
							        printf("%s","��secx==��cosxdx/(cosx)^2=��d(sinx)/[1-(sinx)^2]=�û�Ԫ��=ln|secx+tanx|+C");
							        break;
					        	case 'E':
						            printf("%s","��cscxdx=��dx/sinx=��sinxdx/sin2x=-��dcosx/(1-cos2x)=�û�Ԫ��=ln|cscx-cotx|+C") ;
							        break;
						        case 'F':
						            printf("%s","��cotxdx=ln|sinx|+C") ;
						            break;
					        	case 'G':
						        	printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arcsinx=xarcsinx+��(1-x^2)+C");
							        break;
						        case 'H':
							        printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arccosx=xarccosx-��(1-x^2)+C");
							        break;
						        case 'I':
							        printf("%s\n%s","�����Ǻ���һ���÷ֲ����ַ�","��arctanx=xarctanx+ln(��(1+x^2))+C");
							        break;
					        } //switch���� 
				        } 
						break;
					}
					
					//�˴��ǵ������Ǻ���  ������ת����ʽ����Ԫ�� 
					
					
					else
					{
						if(firstLetter!='A'&&firstLetter!='B') 
						{
							switch(firstLetter)//��ʽ��sec x tan x = sec x��csc x cot x = -csc x 
							{
								case 'D':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='C')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","ʹ�ù�ʽ��","��secx tanx dx=secx+C");
									}
									else
									printf("%s","�������������㷶Χ");
									break;
								case 'C':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='D')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","ʹ�ù�ʽ��","��secx tanx dx=secx+C");
									}
									else
									printf("%s","�������������㷶Χ");
									break;
								case 'E':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='F')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","ʹ�ù�ʽ��","��cscx cotx dx=-cscx+C");
									}
									else
									printf("%s","�������������㷶Χ");
									break;
								case 'F':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='E')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","ʹ�ù�ʽ��","��cscx cotx dx=-cscx+C");
									}
									else
									printf("%s","�������������㷶Χ");
									break;
								default:
									printf("%s","�������������㷶Χ");
									break;
							}
							return 0; 
						}
						else//sin��cos����� 
						{
							if(secondLetter=='A'||secondLetter=='B')//sinsin sincos coscos ��� 
							{
								TrigonometricFunctionType triPtr2;//��һ�����Ǻ����ṹ�� 
								triPtr2.trigonometricFunction9=secondLetter;//sin��ӦA cos��ӦB
								
								//x���ʽ   ������뼸����ǰ��һ�� ����û��д�ɺ�����ʽ 
								char referenceTri2[30]; //���¶���һ���ο��������ڴ���>>���沿�� 
								
								//�ȴ��� referenceTri2[0]
		 	                    referenceTri2[0]=calculus[out];
	                            out++;
		 	                    record[recordNum]=referenceTri2[0];
		 	                    recordNum++;
			                    if(referenceTri2[0]!='0'&&referenceTri2[0]!='1'&&referenceTri2[0]!='2'&&referenceTri2[0]!='3'&&referenceTri2[0]!='4'&&
			                       referenceTri2[0]!='5'&&referenceTri2[0]!='6'&&referenceTri2[0]!='7'&&referenceTri2[0]!='8'&&referenceTri2[0]!='9'&&
			                       referenceTri2[0]!='x'&&referenceTri2[0]!='+'&&referenceTri2[0]!='-') 
			                    {
			                	    printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����
				                    return 0;
			                    }//ֻ�ܰ�˳������ �˴�����������> (����֪����ôʵ��)
			                    
			                    unsigned int counter2=0;
			                    do //ѭ���ó�x���ʽ���沿�� 
			                    {
				                    counter2++;
				                    referenceTri2[counter2]=calculus[out];
	                                out++;
				                    record[recordNum]=referenceTri2[counter2];
				                    recordNum++;
				                    if(referenceTri2[counter2]!='0'&&referenceTri2[counter2]!='1'&&referenceTri2[counter2]!='2'&&referenceTri2[counter2]!='3'&&
									   referenceTri2[counter2]!='4'&&referenceTri2[counter2]!='5'&&referenceTri2[counter2]!='6'&&referenceTri2[counter2]!='7'&&
									   referenceTri2[counter2]!='8'&&referenceTri2[counter2]!='9'&&
			                           referenceTri2[counter2]!='x'&&referenceTri2[counter2]!='+'&&referenceTri2[counter2]!='-'&&
									   referenceTri2[counter2]!='>'&&referenceTri2[counter2]!='\n')
			                        {
			    	                    printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����
			    	                    return 0;
			                        }//�ų�����ax+b��� 
			                    } while((!(referenceTri2[counter2-1]=='>'&&referenceTri2[counter2]=='>'))&&(referenceTri2[counter2]!='\n'));
								        //����>>��=ʱѭ������������getchar
			                    referenceTri2[counter2+1]='\0';
			                    
			                    //�������Ǻ��� 
			                    char xExpressionCaseTriPtr2[30];
			                    
			                    if(referenceTri2[counter2]=='\n')
			                    {
				                    strncpy(xExpressionCaseTriPtr2,referenceTri2,counter2);
				                    xExpressionCaseTriPtr2[counter2]='\0';//ʹ xExpressionCaseTriPtrָ�� x�ı��ʽ 
				                    strcpy(triPtr2.xExpressionTPtr,xExpressionCaseTriPtr2);//�ṹ����x���ʽ ���
				                    
				                    printf("%s\n","��ʹ�û����Ͳʽ��");
									printf("%s\n%s\n%s\n%s\n","sinacosb=1/2[sin(a+b)+sin(a-b)]",
									                          "cosasinb=1/2[sin(a+b)-sin(a-b)]",
															  "cosacosb=1/2[cos(a+b)+cos(a-b)]",
															  "sinasinb=-1/2[cos(a+b)-cos(a-b)]");
									printf("%s\n","֮������ �Ȼ�Ԫ��ʹ�ù�ʽ��");
									printf("%s\n%s","��sinxdx=-cosx+C","��cosxdx=sinx+C");
									
				                    break; 
			                    } 
			                    
			                    //�˴���sinsin sincos coscos �����Ǻ������  ������ת�� �����Ͳʽ�� �����ù�ʽ����Ԫ������ 
			                    
			                    
			                    else
			                    {
			                    	if(referenceTri2[counter2-1]=='>'&&referenceTri2[counter2]=='>')
				                    {
					                    strncpy(xExpressionCaseTriPtr2,referenceTri2,counter2-1);
					                    xExpressionCaseTriPtr2[counter2-1]='\0';//ʹ xExpressionCaseTriPtrָ�� x�ı��ʽ
					                    secondLetter=calculus[out];
	                                    out++;
					                    if(secondLetter=='\n')
					                    {
						                    strcpy(triPtr2.xExpressionTPtr,xExpressionCaseTriPtr2);//�ṹ����x���ʽ ���
						                    
						                    printf("%s\n","��ʹ�û����Ͳʽ��");
									        printf("%s\n%s\n%s\n%s\n","sinacosb=1/2[sin(a+b)+sin(a-b)]",
									                                  "cosasinb=1/2[sin(a+b)-sin(a-b)]",
											        				  "cosacosb=1/2[cos(a+b)+cos(a-b)]",
											        				  "sinasinb=-1/2[cos(a+b)-cos(a-b)]");
									        printf("%s\n","֮������ �Ȼ�Ԫ��ʹ�ù�ʽ��");
									        printf("%s\n%s","��sinxdx=-cosx+C","��cosxdx=sinx+C");
									        
						                    break;
					                    }
					                    
					                    //�˴���sinsin sincos coscos �����Ǻ������  ������ת�� �����Ͳʽ�� �����ù�ʽ����Ԫ������ 
					                    
					                    
					                    else
					                    {
					                    	if(secondLetter=='+'||secondLetter=='-') 
					                    	{
					                    		strcpy(triPtr2.xExpressionTPtr,xExpressionCaseTriPtr2);//�ṹ����x���ʽ ���
					                    		connector=&secondLetter; 
					                    		break;
											}
											//����+-�� ����ʱ�ж� �Ա�֪���Ƿ���Ҫ��������һ�����
											
											else//������� �޷����� 
											{
												printf("%s","�������������㷶Χ"); 
												return 0;
											} 
										}
								    }
								}
							}
							else
							{
								if(secondLetter=='a')//sin/cos��x�Ķ���ʽ��ʽ ������()^t��ʽ 
								{
									ExponentType expPtr;//x^t �ṹ�� 
									char referenceExp[30];//�ο�����
									
									//�ȴ��� referenceExp[0]
			                        referenceExp[0]=calculus[out];
	                                out++;
			                        if(referenceExp[0]!='0'&&referenceExp[0]!='1'&&referenceExp[0]!='2'&&referenceExp[0]!='3'&&referenceExp[0]!='4'&&
			                           referenceExp[0]!='5'&&referenceExp[0]!='6'&&referenceExp[0]!='7'&&referenceExp[0]!='8'&&referenceExp[0]!='9'&&
			                           referenceExp[0]!='x'&&referenceExp[0]!='+'&&referenceExp[0]!='-') 
		                            {
				                        printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����(������Ҫ����Ϊ�޷�ʵ�ַ�������)
			                        	return 0;
			                        }//ֻ�ܰ�˳������ �˴�����������> (����֪����ôʵ��)
			
			                        unsigned int counter2=0;
			                        do //ѭ���ó�x���ʽ���沿�� 
			                        {
				                        counter2++;
				                        referenceExp[counter2]=calculus[out];
	                                    out++;
				                        if(referenceExp[counter2]!='0'&&referenceExp[counter2]!='1'&&referenceExp[counter2]!='2'&&
										   referenceExp[counter2]!='3'&&referenceExp[counter2]!='4'&&referenceExp[counter2]!='5'&&
										   referenceExp[counter2]!='6'&&referenceExp[counter2]!='7'&&referenceExp[counter2]!='8'&&
										   referenceExp[counter2]!='9'&&
			                               referenceExp[counter2]!='x'&&referenceExp[counter2]!='+'&&referenceExp[counter2]!='-'&&
										   referenceExp[counter2]!='>')
			                            {
			    	                        printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����
			    	                        return 0;
			                            }//�ų�����ax+b��� 
			                        } while(referenceExp[counter2]!='>');
									        //����>ʱѭ������������getchar
			                        referenceExp[counter2+1]='\0';
			                        strncpy(expPtr.xExpressionEPtr,referenceExp,counter2);//x���ʽ�������
									
									//��x^t��t��ֵ Ϊdouble���� 
									char referenceExpT[30];
									int counter3=-1;
									do
									{
										counter3++;
										referenceExpT[counter3]=calculus[out];
	                                    out++;
										if(referenceExpT[counter3]!='0'&&referenceExpT[counter3]!='1'&&referenceExpT[counter3]!='2'&&
										   referenceExpT[counter3]!='3'&&referenceExpT[counter3]!='4'&&referenceExpT[counter3]!='5'&&
										   referenceExpT[counter3]!='6'&&referenceExpT[counter3]!='7'&&referenceExpT[counter3]!='8'&&
										   referenceExpT[counter3]!='9'&&
										   referenceExpT[counter3]!='>'&&referenceExpT[counter3]!='\n')
										{
											printf("%s","�������������㷶Χ");
											return 0;
										}//ֻ��ʵ������ 
									}while(referenceExpT[counter3]!='\n');
									referenceExpT[counter3+1]='\0'; //�ַ���referenceExpT���
									
									//�ٽ��ַ����к����ֲ��ֵ���
									char *referenceExpTPtr;//����ַ������ڴ��� �ַ���referenceExpT�����ֺ��ʣ�ಿ��
									double  referenceTNum=strtod(referenceExpT,&referenceExpTPtr);
									if(referenceTNum!=1&&referenceTNum!=2&&referenceTNum!=3&&referenceTNum!=4&&referenceTNum!=5)
									{
										printf("%s","�������������㷶Χ");
										return 0;
									}
									else
									{
										expPtr.tNum=referenceTNum;
										
										printf("%s%s%s\n","���û�Ԫ����sin/cos���",xExpressionCaseTriPtr,"��Ԫ") ;
										printf("%s\n","�ټ������ax+b��^t��x�Ķ���ʽ ����sin/cosx*(x^t+��+x+n)��ʽ ���μ���");
										printf("%s\n%s","sin/cosx*x^t��Ҫͨ���ֲ����ַ����","ͨ����sinx/cosx����dx����Ϊd(-cosx)/dsinx����зֲ����ַ�") ;
										
										break;
									}
									//�ٹ� �ַ���referenceExpT�����ֺ��ʣ�ಿ��ֻ��\n��>>�������� 
									if(referenceExpTPtr[0]=='>')
									{
										if(referenceExpTPtr[2]!='\n')
										{
											printf("%s","�������������㷶Χ");
										    return 0;//sin/cos��(ax+b)^t�󲻹ܽ�������ʲô���޷����� 
										}
										else
										{
											break;
										} 
									}
									else
									{
										break;
									}
									
									//sin/cos��(ax+b)^t��ʽ Ӧ�÷ֲ����ַ� 
									
								}
								else
								{
									if(secondLetter=='x')//sin/cos*x���� 
									{
										printf("%s","sin/cosx*x��Ҫͨ���ֲ����ַ����","ͨ����sinx/cosx����dx����Ϊd(-cosx)/dsinx����зֲ����ַ�");
										break;
									}
									else
									{
										printf("%s","�������������㷶Χ");
										return 0;
									} 
								} 
							} 
						}
					}
				}
			}
			break;
		    }
		case 'a':
		{
			//����x���ʽ 
			char referenceExp[30];//�ο�����
			unsigned int counter=0;
			
			//�ȴ��� referenceTri[0]
			referenceExp[0]=calculus[out];
	        out++;
			record[recordNum]=referenceExp[0];
			recordNum++;
			
			if((referenceExp[0]=='A')||(referenceExp[0]=='B')||(referenceExp[0]=='D')||(referenceExp[0]=='E')||(referenceExp[0]=='C'))
			//���Ǻ������ 
			{
				do//��x^t���ʽ��>>���Ż�\n ȫ�������� referenceExp[30]�� 
				{
	    			counter++;
					referenceExp[counter]=calculus[out];
	                out++;
					record[recordNum]=referenceExp[counter];
	                recordNum++;
				}while((!(referenceExp[counter]=='\n'))&&(!((referenceExp[counter-1]=='>')&&(referenceExp[counter]=='>'))));
                
				switch(referenceExp[0])
				{
					case 'D'://��(secx)^2dx�� ������� ��(secx)^3dx
						if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='2')&&(referenceExp[4]=='\n'))
						{
							printf("%s\n%s","ʹ�ù�ʽ��","��(secx)^2dx=tanx+C");
						}
						else
						{
							if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='3')&&(referenceExp[4]=='\n'))
							{
								printf("%s\n%s\n%s","��������㷽��",
								                  "��(secx)^3dx=��secxdtanx=�ֲ����ַ�=secx*tanx-��secx*(tanx)^2dx= secx*tanx-��secx*(secx^2-1)dx= secx*tanx+ln|secx+tanx|-��secx^3dx",
												  "������������2  �á�secx^3dx=1/2(secx*tanx+ln|secx+tanx|)+C");
							}
							else
							{
								printf("%s","�������������㷶Χ");
								return 0;
							}
						}
						break;
					case 'E':// ��(cscx)^2dx
						if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='2')&&(referenceExp[4]=='\n'))
						{
						printf("%s\n%s","ʹ�ù�ʽ��","��(cscx)^2dx=-cotx+C");
					    }
					    else
						{
							printf("%s","�������������㷶Χ");
							return 0;
						}
					    break;
					case 'C':// ��(tanx)^2dxҲ����������� 
						if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='2')&&(referenceExp[4]=='\n'))
						{
						printf("%s\n%s\n%s","ʹ�ù�ʽ(tanx)^2=(secx)^2-1",
						                    "Ȼ�����ù�ʽ�����㣬���С�(secx)^2dx=tanx+C",
						                    "��(tanx)^2dx=tanx-x+C");
					    }
					    else
						{
							printf("%s","�������������㷶Χ");
							return 0;
						}
					    break;
					case 'A'://sin����� 
						if(referenceExp[counter]=='\n')//������ (Sin x)^t
						{
							if((referenceExp[1]=='x')&&(referenceExp[2]=='>'))
							{
								for(int i=3;i<counter;i++)
								{
									if((referenceExp[i]!='0')&&(referenceExp[i]!='1')&&(referenceExp[i]!='2')&&(referenceExp[i]!='3')&&
									   (referenceExp[i]!='4')&&(referenceExp[i]!='5')&&(referenceExp[i]!='6')&&(referenceExp[i]!='7')&&
									   (referenceExp[i]!='8')&&(referenceExp[i]!='9'))
									{
									    printf("%s","�������������㷶Χ");
										return 0;
							        }
								}
								if((referenceExp[counter-1]=='1')||(referenceExp[counter-1]=='3')||(referenceExp[counter-1]=='5')||
								   (referenceExp[counter-1]=='7')||(referenceExp[counter-1]=='9'))
								{
									printf("%s\n%s\n%s","��(sinx)^tdx��ʽ����tΪ����",
									                    "���С�(sinx)^tdx=��(sinx)^(t-1)*sinxdx=-��(sinx)^(t-1)dcosx",
													    "��ʱ������sinx^2=1-cosx^2����cosx��Ԫ����ͨ����ʽ������");
								}
								else
								{
									printf("%s\n%s\n%s","��(sinx)^tdx��ʽ����tΪż��",
									                    "���������Ҫͨ������ʵ��",
													    "���ù�ʽsinx^2=(1-cos 2x)/2");
								}
							}
							else
							{
								printf("%s","�������������㷶Χ");
							    return 0;
							}
						}
						else//(sinx)^t1*(cosx)^t2
						{
							char secondLetter;
							secondLetter=calculus[out];
	                        out++;
							record[recordNum]=secondLetter;
	                   		recordNum++;
							
							if(secondLetter=='x')//(sinx)^t*x
							{
								if(calculus[out]=='\n')
								{
								printf("%s","ʹ�÷ֲ����ַ�����x�任��d��");
							    }
								else
								{
									printf("%s","�������������㷶Χ");
						            return 0;
								}
							}
							else
							{
								if(secondLetter=='a')
								{
									char referenceExp2[30];
						        	int counter2=0;
						        	
						        	//�ȴ��� referenceTri[0]
			                        referenceExp2[0]=calculus[out];
	                                out++;
	                        		record[recordNum]=referenceExp2[0];
	                        		recordNum++;
	                        		
	                        		if((referenceExp2[0]!='x')&&(referenceExp2[0]!='B'))
	                        		{
	                        			printf("%s","�������������㷶Χ");
						        	    return 0;
									}
						        	
						        	do//��x^t��(cosx)^t2���ʽ��\n ȫ�������� referenceExp2[30]�� 
			                    	{
	    		                    	counter2++;
				                    	referenceExp2[counter2]=calculus[out];
	                                    out++;
				                     	record[recordNum]=referenceExp2[counter2];
	                                    recordNum++;
			                       	}while(!(referenceExp2[counter2]=='\n'));
			                       	
			                       	if((referenceExp2[0]=='x')&&(referenceExp2[1]=='>'))//sinx^t*x^t
			                       	{
			                       	    for(int i=2;i<counter2;i++)
							        	{
							        		if((referenceExp2[i]!='0')&&(referenceExp2[i]!='1')&&(referenceExp2[i]!='2')&&(referenceExp2[i]!='3')&&
							        		   (referenceExp2[i]!='4')&&(referenceExp2[i]!='5')&&(referenceExp2[i]!='6')&&(referenceExp2[i]!='7')&&
							        		   (referenceExp2[i]!='8')&&(referenceExp2[i]!='9'))
							        		{
							        		    printf("%s","�������������㷶Χ");
							        			return 0;
							                }
							        	}
							        	printf("%s","ʹ�÷ֲ����ַ�"); 
									}
									else
									{
										if((referenceExp2[0]=='B')&&(referenceExp2[1]=='x')&&(referenceExp2[2]=='>'))
										{//(sinx)^t1 (cosx)^t2
											for(int i=3;i<counter2;i++)
							            	{
							            		if((referenceExp2[i]!='0')&&(referenceExp2[i]!='1')&&(referenceExp2[i]!='2')&&(referenceExp2[i]!='3')&&
							            		   (referenceExp2[i]!='4')&&(referenceExp2[i]!='5')&&(referenceExp2[i]!='6')&&(referenceExp2[i]!='7')&&
							            		   (referenceExp2[i]!='8')&&(referenceExp2[i]!='9'))
							            		{
							            		    printf("%s","�������������㷶Χ");
							            			return 0;
							                    } 
							            	}
							            	printf("%s\n%s\n%s","��(sinx)^t1*(cosx)^t2dx��ʽ",
												                "��t1��t2һ��һż,��������Ӧ�����Ǻ�������d����һ��ż��������sinx^2=1-cosx^2��cosx^2=1-sinx^2����ת��",
												    			"��t1��t2ͬΪ������ż�������������Ǻ�����ʽ����");
										}
										else
										{
											printf("%s","�������������㷶Χ");
							        		return 0;
										}
									}
                
								}
						    }
						}
						break; 
					case 'B':
						if(referenceExp[counter]=='\n')//������ (cos x)^t
						{
							if((referenceExp[1]=='x')&&(referenceExp[2]=='>'))
							{
								for(int i=3;i<counter;i++)
								{
									if((referenceExp[i]!='0')&&(referenceExp[i]!='1')&&(referenceExp[i]!='2')&&(referenceExp[i]!='3')&&
									   (referenceExp[i]!='4')&&(referenceExp[i]!='5')&&(referenceExp[i]!='6')&&(referenceExp[i]!='7')&&
									   (referenceExp[i]!='8')&&(referenceExp[i]!='9'))
									{
									    printf("%s","�������������㷶Χ");
										return 0;
							        }
								}
								if((referenceExp[counter-1]=='1')||(referenceExp[counter-1]=='3')||(referenceExp[counter-1]=='5')||
								   (referenceExp[counter-1]=='7')||(referenceExp[counter-1]=='9'))
								{
									printf("%s\n%s\n%s","��(cosx)^tdx��ʽ����tΪ����",
									                    "���С�(cosx)^tdx=��(cosx)^(t-1)*cosxdx=��(cosx)^(t-1)dsinx",
													    "��ʱ������cosx^2=1-sinx^2����sinx��Ԫ����ͨ����ʽ������");
								}
								else
								{
									printf("%s\n%s\n%s","��(cosx)^tdx��ʽ����tΪż��",
									                    "���������Ҫͨ������ʵ��",
													    "���ù�ʽcosx^2=(1+cos 2x)/2");
								}
							}
							else
							{
								printf("%s","�������������㷶Χ");
							    return 0;
							}
						}
						else//(sinx)^t1*(cosx)^t2
						{
							char secondLetter;
							secondLetter=calculus[out];
	                        out++;
							record[recordNum]=secondLetter;
	                   		recordNum++;
							
							if(secondLetter=='x')//(cosx)^t*x
							{
								if(calculus[out]=='\n')
								{
								printf("%s","ʹ�÷ֲ����ַ�����x�任��d��");
							    }
								else
								{
									printf("%s","�������������㷶Χ");
						            return 0;
								}
							}
							else
							{
								if(secondLetter=='a')
								{
									char referenceExp2[30];
						        	int counter2=0;
						        	
						        	//�ȴ��� referenceTri[0]
			                        referenceExp2[0]=calculus[out];
	                                out++;
	                        		record[recordNum]=referenceExp2[0];
	                        		recordNum++;
	                        		
	                        		if((referenceExp2[0]!='x')&&(referenceExp2[0]!='A'))
	                        		{
	                        			printf("%s","�������������㷶Χ");
						        	    return 0;
									}
						        	
						        	do//��x^t��(sinx)^t2���ʽ��\n ȫ�������� referenceExp2[30]�� 
			                    	{
	    		                    	counter2++;
				                    	referenceExp2[counter2]=calculus[out];
	                                    out++;
				                     	record[recordNum]=referenceExp2[counter2];
	                                    recordNum++;
			                       	}while(!(referenceExp2[counter2]=='\n'));
			                       	
			                       	if((referenceExp2[0]=='x')&&(referenceExp2[1]=='>'))//sinx^t*x^t
			                       	{
			                       	    for(int i=2;i<counter2;i++)
							        	{
							        		if((referenceExp2[i]!='0')&&(referenceExp2[i]!='1')&&(referenceExp2[i]!='2')&&(referenceExp2[i]!='3')&&
							        		   (referenceExp2[i]!='4')&&(referenceExp2[i]!='5')&&(referenceExp2[i]!='6')&&(referenceExp2[i]!='7')&&
							        		   (referenceExp2[i]!='8')&&(referenceExp2[i]!='9'))
							        		{
							        		    printf("%s","�������������㷶Χ");
							        			return 0;
							                }
							        	}
							        	printf("%s","ʹ�÷ֲ����ַ�"); 
									}
									else
									{
										if((referenceExp2[0]=='A')&&(referenceExp2[1]=='x')&&(referenceExp2[2]=='>'))
										{//(sinx)^t1 (cosx)^t2
											for(int i=3;i<counter2;i++)
							            	{
							            		if((referenceExp2[i]!='0')&&(referenceExp2[i]!='1')&&(referenceExp2[i]!='2')&&(referenceExp2[i]!='3')&&
							            		   (referenceExp2[i]!='4')&&(referenceExp2[i]!='5')&&(referenceExp2[i]!='6')&&(referenceExp2[i]!='7')&&
							            		   (referenceExp2[i]!='8')&&(referenceExp2[i]!='9'))
							            		{
							            		    printf("%s","�������������㷶Χ");
							            			return 0;
							                    } 
							            	}
							            	printf("%s\n%s\n%s","��(sinx)^t1*(cosx)^t2dx��ʽ",
												                "��t1��t2һ��һż,��������Ӧ�����Ǻ�������d����һ��ż��������sinx^2=1-cosx^2��cosx^2=1-sinx^2����ת��",
												    			"��t1��t2ͬΪ������ż�������������Ǻ�����ʽ����");
										}
										else
										{
											printf("%s","�������������㷶Χ");
							        		return 0;
										}
									}
                
								}
						    }
						}
						break; 
					
				}
			}
			
			//(����ʽ)^t
			else
			{
			    if(referenceExp[0]!='0'&&referenceExp[0]!='1'&&referenceExp[0]!='2'&&referenceExp[0]!='3'&&referenceExp[0]!='4'&&
			       referenceExp[0]!='5'&&referenceExp[0]!='6'&&referenceExp[0]!='7'&&referenceExp[0]!='8'&&referenceExp[0]!='9'&&
		    	   referenceExp[0]!='x'&&referenceExp[0]!='+'&&referenceExp[0]!='-') 
		    	{
		    		printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����
		    		return 0;
		    	}//ֻ�ܰ�˳������ �˴�����������> (����֪����ôʵ��)
			
		    	unsigned int counter=0;
		    	do //ѭ���ó�x���ʽ���沿�� 
		    	{
		    		counter++;
		    		referenceExp[counter]=calculus[out];
	                out++;
			    	record[recordNum]=referenceExp[counter];
   				    recordNum++;
    				if(referenceExp[counter]!='0'&&referenceExp[counter]!='1'&&referenceExp[counter]!='2'&&referenceExp[counter]!='3'&&referenceExp[counter]!='4'&&
	    		       referenceExp[counter]!='5'&&referenceExp[counter]!='6'&&referenceExp[counter]!='7'&&referenceExp[counter]!='8'&&referenceExp[counter]!='9'&&
		    	       referenceExp[counter]!='x'&&referenceExp[counter]!='+'&&referenceExp[counter]!='-'&&referenceExp[counter]!='>')
			        {
			        	printf("%s","�������������㷶Χ"); //����ax+b��ʽ���޷�����
			    	    return 0;
    			    }//�ų�����ax+b��� 
	    		} while(!(referenceExp[counter]=='>'));//����>ʱѭ������������getchar
		    	referenceExp[counter+1]='\0';
			 
    			char tNum[20];//���鴢��x^t��t����ֵ 
	    		int counterT=0;
		    	do
			    {
    				tNum[counterT]=calculus[out];
	                out++;
		    		if((tNum[counterT]!='0')&&(tNum[counterT]!='1')&&(tNum[counterT]!='2')&&(tNum[counterT]!='3')&&
			    	   (tNum[counterT]!='4')&&(tNum[counterT]!='5')&&(tNum[counterT]!='6')&&(tNum[counterT]!='7')&&
				       (tNum[counterT]!='8')&&(tNum[counterT]!='9')&&(tNum[counterT]!='>')&&(tNum[counterT]!='\n'))
	    			{
		    			printf("%s","�������������㷶Χ"); 
			        	return 0;
				    }
		    		counterT++;
    			} while((!((tNum[counterT-2]=='>')&&(tNum[counterT-1]=='>')))&&(tNum[counterT-1]!='\n'));
	   		
	    		
		    	if((referenceExp[0]=='x')&&(counter==1))//ax+b��Ϊx 
	    		{
		    		if(tNum[counterT-1]=='\n')
			    	{
    					printf("%s\n%s","ʹ�ù�ʽ��",
	    				                "��x^tdx=x^(t+1)/(t+1)+C");
		    		}
			    	else
				    {
	    				if((tNum[counterT-2]=='>')&&(tNum[counterT-1]=='>'))
		    			{
			    			char secondLetter;
				    		secondLetter=calculus[out];
	                        out++;
		    				switch (secondLetter)
			    			{
				    			case 'e':
				    				printf("%s","ʹ�÷ֲ����ַ�");
					    			break;
					    		case 'A':
								case 'B':
								    printf("%s","ʹ�÷ֲ����ַ�");
					    			break;
					    		default:
					    			printf("%s","�������������㷶Χ"); 
			        	            return 0;
						    }
					    }
				    }
			    }
			    else
			    {
			    	printf("%s","�Ȼ�Ԫ��ʽ��");
				}
	       }
		    break;
		}
		case 'x':
		{
		    if(((calculus[out]=='>')&&(calculus[out+1]=='>'))||calculus[out]=='\n')
		    {
		    	if(calculus[out]=='\n')
		    	{
		    		printf("%s\n%s","ʹ�ù�ʽ��",
					                "��xdx=x^2/2+C");
				}
				else
				{
					out=out+2;
					char secondLetter;
					secondLetter=calculus[out];
					out++;
					switch (secondLetter)
			    	{
						case 'e':
		    				printf("%s","ʹ�÷ֲ����ַ�");
				        	break;
						case 'A':
						case 'B':
						    printf("%s","ʹ�÷ֲ����ַ�");
					   		break;
					   	case '��':
					   		if((calculus[out]=='1')&&(calculus[out+1]=='-')&&(calculus[out+2]=='a')&&
							   (calculus[out+3]=='x')&&(calculus[out+4]=='>')&&(calculus[out+5]=='2')&&
							   (calculus[out+6]=='\n'))
							{ 
								printf("%s\n%s","��΢�ֻ�Ԫ, ʹxdx ��Ϊ1/2d(x^2)",
								                "��x��(1-x^2)dx=-1/2�ҡ�(1-x^2)d(1-x^2)");
							}
				 		default:
			    			printf("%s","�������������㷶Χ"); 
	        	            return 0;
				    }
				} 
			}
			else
			{
				printf("%s","�������������㷶Χ"); 
			    return 0;
			}
			break;
	    }
	    default:
	    	printf("%s","�������������㷶Χ");
	    	break;
    }//switch������ 
	
	return 0;
	}
	if(!judge){
	int x1,x2,x3,y1,y2,y3,z1,z2,z3;
	x1=xiandai[0]-'0';
	x2=xiandai[2]-'0';
	x3=xiandai[4]-'0';
	y1=xiandai[6]-'0';
	y2=xiandai[8]-'0';
	y3=xiandai[10]-'0';
	z1=xiandai[12]-'0';
	z2=xiandai[14]-'0';
	z3=xiandai[16]-'0';
	//������������
	if(((x1*x2*x3*y1*y2*y3*z1*z2*z3)!=0)&&(((x1/y1)==(x2/y2)==(x3/y3))||((x1/z1)==(x2/z2)==(x3/z3))||((y1/z1)==(y2/z2)==(y3/z3)))){
		printf("\n���������޹������飬���ܵ�λ������"); 
	}
	else if((y1==z1)&&(y2==z2)&&(y3==z3)){
		printf("\n���������޹������飬���ܵ�λ������");
	}
	else{
	int X,Y,Z,M;
	int a1,a2,a3,b1,b2,b3,c1,c2,c3,k1,k2,k3,P,Q,b11,b22,b33,c11,c22,c33;
	int A,A0,B,B0,B1,B11,B2,B22,C,C0,C1,C11,C2,C22,f,h,w,r;
	X=x1*y1+x2*y2+x3*y3;
	Y=x1*z1+x2*z2+x3*z3;
	Z=y1*z1+y2*z2+y3*z3;
	M=x1*x1+x2*x2+x3*x3;
	a1=x1;
	a2=x2;
	a3=x3;
	k1=-X/M;
	b1=-X*x1+y1*M;
	b2=-X*x2+y2*M;
	b3=-X*x3+y3*M;
	b11=M;
	b22=M;
	b33=M;
	k2=-Y/M;
	P=z1*b1+z2*b2+z3*b3;
	Q=b1*b1+b2*b2+b3*b3;
	k3=-P/Q;
	c1=-Y*Q*a1+(-P)*b1*M+z1*Q*M;
	c2=-Y*Q*a2+(-P)*b2*M+z2*Q*M;
	c3=-Y*Q*a3+(-P)*b3*M+z3*Q*M;
	c11=M*Q;
	c22=M*Q;
	c33=M*Q;
	if((X==0)&&(Y==0)&&(Z==0))
	printf("\n������������");
	// ���뼴Ϊ���������� 
	else{
		if((b11==0)||(b22==0)||(b33==0)||(c11==0)||(c22==0)||(c33==0))
		printf("����");
		else{
			printf("\n����������Ϊ:\n");
			printf("%10d %10d %10d\n",a1,a2,a3);
			if(b1%b11==0)
			printf("%10d ",b1/b11);
			else
			printf("%10d/%d ",b1/gcd(b1,b11),b11/gcd(b1,b11));
			if(b2%b22==0)
			printf("%10d ",b2/b22);
			else
			printf("%10d/%d ",b2/gcd(b2,b22),b22/gcd(b2,b22));
			if(b3%b33==0)
			printf("%10d\n",b3/b33);
			else
			printf("%10d/%d\n",b3/gcd(b3,b33),b33/gcd(b3,b33));
			if(c1%c11==0)
			printf("%10d ",c1/c11);
			else
			printf("%10d/%d ",c1/gcd(c1,c11),c11/gcd(c1,c11));
			if(c2%c22==0)
			printf("%10d ",c2/c22);
			else
			printf("%10d/%d ",c2/gcd(c2,c22),c22/gcd(c2,c22));
			if(c3%c33==0)
			printf("%10d\n",c3/c33);
			else
			printf("%10d/%d\n",c3/gcd(c3,c33),c33/gcd(c3,c33));
			//�������������
			printf("��λ����������Ϊ:\n"); 
			A=a1*a1+a2*a2+a3*a3;
			if((A==(int)sqrt(A)*(int)sqrt(A))){
				A0=sqrt(A);
				if(a1%A0==0)
				printf("%10d ",a1/A0);
				else
				printf("%10d/%d ",a1/gcd(a1,A0),A0/gcd(a1,A0));
				if(a2%A0==0)
				printf("%10d ",a2/A0);
				else
				printf("%10d/%d ",a2/gcd(a2,A0),A0/gcd(a2,A0));
				if(a3%A0==0)
				printf("%10d\n",a3/A0);
				else
				printf("%10d/%d\n",a3/gcd(a3,A0),A0/gcd(a3,A0));
			}
			else{
				if(a1==0)
				printf("%10d ",0);
				else
				printf("%10d/��%d ",a1,A);
				if(a2==0)
				printf("%10d ",0);
				else
				printf("%10d/��%d ",a2,A);
				if(a3==0)
				printf("%d\n",0);
				else
				printf("%10d/��%d\n",a3,A);
			}//��һ�е�λ��//
			if((b1==0)&&(b2==0)&&(b3==0)){
				printf("%10d %10d %10d",0,0,0);
			}
			else{
			B11=b11*b11*b22*b22*b33*b33;
			B1=b22*b22*(b1*b1*b33*b33+b3*b3*b11*b11)+b2*b2*b11*b11*b33*b33;
			if(B1%B11==0){//ƽ����Ϊ����// 
				B=B1/B11;
				if(B==(int)sqrt(B)*(int)sqrt(B)){//ƽ����Ϊ��ȫƽ����// 
				B0=sqrt(B);
				if(b1%b11==0){
					if((b1/b11)%B0==0)
					printf("%10d ",(b1/b11)/B0);
					else
					printf("%10d/%d ",b1/b11,B0);
				}
				else
				printf("%10d/%d ",b1/gcd(b1,(b11*B0)),(b11*B0)/gcd(b1,(b11*B0)));
				if(b2%b22==0){
					if((b2/b22)%B0==0)
					printf("%10d ",(b2/b22)/B0);
					else
					printf("%10d/%d ",b2/b22,B0);
				}
				else
				printf("%10d/%d ",b2/gcd(b2,(b22*B0)),(b22*B0)/gcd(b2,(b22*B0)));
				if(b3%b33==0){
					if((b3/b33)%B0==0)
					printf("%10d\n",(b3/b33)/B0);
					else
					printf("%10d/%d\n",b3/b33,B0);
				}
				else
				printf("%10d/%d\n",b3/gcd(b3,(b33*B0)),(b33*B0)/gcd(b3,(b33*B0)));
				printf("%lf",B0);
			}
			else{//ƽ���Ͳ�����ȫƽ����// 
				if((b1%b11==0)&&(b1!=0))
				printf("%10d/��%d ",b1/b11,B);
				else if(b1==0)
				printf("%10d ",0);
				else
				printf("%10d/%d��%d ",b1/gcd(b1,b11),b11/gcd(b1,b11),B);
				if((b2%b22==0)&&(b2!=0))
				printf("%10d/��%d ",b2/b22,B);
				else if(b2==0)
				printf("%10d ",0);
				else
				printf("%10d/%d��%d ",b2/gcd(b2,b22),b22/gcd(b2,b22),B);
				if((b3%b33==0)&&(b3!=0))
				printf("%10d/��%d\n",b3/b33,B);
				else if(b3==0)
				printf("%10d\n",0);
				else
				printf("%10d/%d��%d\n",b3/gcd(b3,b33),b33/gcd(b3,b33),B);
			}
		}
		else{//ƽ���Ͳ�������//
			if((B11==(int)sqrt(B11)*(int)sqrt(B11))&&(B1==(int)sqrt(B1)*(int)sqrt(B1))){
				f=sqrt(B11);
				h=sqrt(B1);
				if(b1==0)
				printf("%10d ",0);
				else{
					printf("%10d/%d ",(b1*f)/gcd((b1*f),(b11*h)),(b11*h)/gcd((b1*f),(b11*h)));
					printf("%10d/%d ",(b2*f)/gcd((b2*f),(b22*h)),(b22*h)/gcd((b2*f),(b22*h)));
					printf("%10d/%d\n",(b3*f)/gcd((b3*f),(b33*h)),(b33*h)/gcd((b3*f),(b33*h)));
				}		
			}
			else if((B11==(int)sqrt(B11)*(int)sqrt(B11))&&(B1!=(int)sqrt(B1)*(int)sqrt(B1))){
				if(b1==0)
				printf("%10d ",0);
				else if((b1!=0)&&((b1*f)%b11==0))
				printf("%10d/��%d ",(b1*f)/b11,B1);
				else
				printf("%10d/%d��%d ",(b1*f)/gcd((b1*f),b11),b11/gcd((b1*f),b11),B1);
				if(b2==0)
				printf("%10d ",0);
				else if((b2!=0)&&((b2*f)%b22==0))
				printf("%10d/��%d ",(b2*f)/b22,B1);
				else
				printf("%10d/%d��%d ",(b2*f)/gcd((b2*f),b22),b22/gcd((b2*f),b22),B1);
				if(b3==0)
				printf("%10d\n",0);
				else if((b3!=0)&&((b3*f)%b33==0))
				printf("%10d/��%d\n",(b3*f)/b33,B1);
				else
				printf("%10d/%d��%d\n",(b3*f)/gcd((b3*f),b33),b33/gcd((b3*f),b33),B1);
			}
			else if((B11!=(int)sqrt(B11)*(int)sqrt(B11))&&(B1==(int)sqrt(B1)*(int)sqrt(B1))){
				if(b1==0)
				printf("%10d ",0);
				else
				printf("��%d %d/%d ",B11,b1/gcd(b1,(b11*h)),(b11*h)/gcd(b1,(b11*h)));
				if(b2==0)
				printf("%10d ",0);
				else
				printf("��%d %d/%d ",B11,b2/gcd(b2,(b22*h)),(b22*h)/gcd(b2,(b22*h)));
				if(b3==0)
				printf("%10d\n",0);
				else
				printf("��%d %d/%d\n",B11,b3/gcd(b3,(b33*h)),(b33*h)/gcd(b3,(b33*h)));
			}
			else{
				if(b1==0)
				printf("%10d ",0);
				else if(b1/b11==1)
				printf("��%d/��%d ");
				else if((b1/b11!=1)&&(b1!=0)&&(b1%b11==0))
				printf("%10d��%d/��%d ",b1/b11,B11,B1);
				else
				printf("%10d��%d/%d��%d ",b1/gcd(b1,b11),B11,b11/gcd(b1,b11),B1);
				if(b2==0)
				printf("%10d ",0);
				else if(b2/b22==1)
				printf("��%d/��%d ");
				else if((b2/b22!=1)&&(b2!=0)&&(b2%b22==0))
				printf("%10d��%d/��%d ",b2/b22,B11,B1);
				else
				printf("%10d��%d/%d��%d ",b2/gcd(b2,b22),B11,b22/gcd(b2,b22),B1);
				if(b3==0)
				printf("%10d\n",0);
				else if(b3/b33==1)
				printf("��%d/��%-10d\n");
				else if((b3/b33!=1)&&(b3!=0)&&(b3%b33==0))
				printf("%10d��%d/��%d\n",b3/b33,B11,B1);
				else
				printf("%10d��%d/%d��%d\n",b3/gcd(b3,b33),B11,b33/gcd(b3,b33),B1);
			}
		}//�ڶ��е�λ��// 
	}
			if((c1==0)&&(c2==0)&&(c3==0)){
				printf("%10d %10d %10d",0,0,0);
			}
			else{
			C11=c11*c11*c22*c22*c33*c33;
			C1=c22*c22*(c1*c1*c33*c33+c3*c3*c11*c11)+c2*c2*c11*c11*c33*c33;
			if(C1%C11==0){//ƽ����Ϊ����// 
				C=C1/C11;
				if(C==(int)sqrt(C)*(int)sqrt(C)){//ƽ����Ϊ��ȫƽ����// 
				C0=sqrt(C);
				if(c1%c11==0){
					if((c1/c11)%C0==0)
					printf("%10d ",(c1/c11)/C0);
					else
					printf("%10d/%d ",c1/c11,C0);
				}
				else
				printf("%10d/%d ",c1/gcd(c1,(c11*C0)),(c11*C0)/gcd(c1,(c11*C0)));
				if(c2%c22==0){
					if((c2/c22)%C0==0)
					printf("%10d ",(c2/c22)/C0);
					else
					printf("%10d/%d ",c2/c22,C0);
				}
				else
				printf("%10d/%d ",c2/gcd(c2,(c22*C0)),(c22*C0)/gcd(c2,(c22*C0)));
				if(c3%c33==0){
					if((c3/c33)%C0==0)
					printf("%10d\n",(c3/c33)/C0);
					else
					printf("%10d/%d\n",c3/c33,C0);
				}
				else
				printf("%10d/%d\n",c3/gcd(c3,(c33*C0)),(c33*C0)/gcd(c3,(c33*C0)));
			}
			else{//ƽ���Ͳ�����ȫƽ����// 
				if((c1%c11==0)&&(c1!=0))
				printf("%10d/��%d ",c1/c11,C);
				else if(c1==0)
				printf("%10d ",0);
				else
				printf("%10d/%d��%d ",c1/gcd(c1,c11),c11/gcd(c1,c11),C);
				if((c2%c22==0)&&(c2!=0))
				printf("%10d/��%d ",c2/c22,C);
				else if(c2==0)
				printf("%10d ",0);
				else
				printf("%10d/%d��%d ",c2/gcd(c2,c22),c22/gcd(c2,c22),C);
				if((c3%c33==0)&&(c3!=0))
				printf("%10d/��%d\n",c3/c33,C);
				else if(c3==0)
				printf("%10d\n",0);
				else
				printf("%10d/%d��%d\n",c3/gcd(c3,c33),c33/gcd(c3,c33),C);
			}
		}
		else{//ƽ���Ͳ�������// 
			if((C11==(int)sqrt(C11)*(int)sqrt(C11))&&(C1==(int)sqrt(C1)*(int)sqrt(C1))){
				w=(int)sqrt(C11);
				r=(int)sqrt(C1);
				if(c1==0)
				printf("%10d ",0);
				else{
					printf("%10d/%d ",(c1*w)/gcd((c1*w),(c11*r)),(c11*r)/gcd((c1*w),(c11*r)));
					printf("%10d/%d ",(c2*w)/gcd((c2*w),(c22*r)),(c22*r)/gcd((c2*w),(c22*r)));
					printf("%10d/%d\n",(c3*w)/gcd((c3*w),(c33*r)),(c33*r)/gcd((c3*w),(c33*r)));
				}		
			}
			else if((C11==(int)sqrt(C11)*(int)sqrt(C11))&&(C1!=(int)sqrt(C1)*(int)sqrt(C1))){
				if(c1==0)
				printf("%10d ",0);
				else if((c1!=0)&&((c1*w)%c11==0))
				printf("%10d/��%d ",(c1*w)/c11,C1);
				else
				printf("%10d/%d��%d ",(c1*w)/gcd((c1*w),c11),c11/gcd((c1*w),c11),C1);
				if(c2==0)
				printf("%10d ",0);
				else if((c2!=0)&&((c2*w)%c22==0))
				printf("%10d/��%d ",(c2*w)/c22,C1);
				else
				printf("%10d/%d��%d ",(c2*w)/gcd((c2*w),c22),c22/gcd((c2*w),c22),C1);
				if(c3==0)
				printf("%10d\n",0);
				else if((c3!=0)&&((c3*w)%c33==0))
				printf("%10d/��%d\n",(c3*w)/c33,C1);
				else
				printf("%10d/%d��%d\n",(c3*w)/gcd((c3*w),c33),c33/gcd((c3*w),c33),C1);
			}
			else if((C11!=(int)sqrt(C11)*(int)sqrt(C11))&&(C1==(int)sqrt(C1)*(int)sqrt(C1))){
				if(c1==0)
				printf("%10d ",0);
				else
				printf("��%d %d/%d ",C11,c1/gcd(c1,(c11*r)),(c11*r)/gcd(c1,(c11*r)));
				if(c2==0)
				printf("%10d ",0);
				else
				printf("��%d %d/%d ",C11,c2/gcd(c2,(c22*r)),(c22*r)/gcd(c2,(c22*r)));
				if(c3==0)
				printf("%10d\n",0);
				else
				printf("��%d %d/%d\n",C11,c3/gcd(c3,(c33*r)),(c33*r)/gcd(c3,(c33*r)));
			}
			else{
				if(c1==0)
				printf("%10d ",0);
				else if(c1/c11==1)
				printf("��%d/��%d ");
				else if((c1/c11!=1)&&(c1!=0)&&(c1%c11==0))
				printf("%10d��%d/��%d ",c1/c11,C11,C1);
				else
				printf("%10d��%d/%d��%d ",c1/gcd(c1,c11),C11,c11/gcd(c1,c11),C1);
				if(c2==0)
				printf("%10d ",0);
				else if(c2/c22==1)
				printf("��%d/��%d ");
				else if((c2/c22!=1)&&(c2!=0)&&(c2%c22==0))
				printf("%10d��%d/��%d ",c2/c22,C11,C1);
				else
				printf("%10d��%d/%d��%d ",c2/gcd(c2,c22),C11,c22/gcd(c2,c22),C1);
				if(c3==0)
				printf("%10d\n",0);
				else if(c3/c33==1)
				printf("��%d/��%-10d\n");
				else if((c3/c33!=1)&&(c3!=0)&&(c3%c33==0))
				printf("%10d��%d/��%d\n",c3/c33,C11,C1);
				else
				printf("%10d��%d/%d��%d\n",c3/gcd(c3,c33),C11,c33/gcd(c3,c33),C1);
			}
		}
	}			
	}
}	
	}

}
}
