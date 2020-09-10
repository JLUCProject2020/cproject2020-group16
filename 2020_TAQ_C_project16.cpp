#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include <math.h>
//被积函数一共分成五种类型 指数型、三角函数（反三角函数）、幂指数型、对数型、分式型 
//指数型 x^t t=0;t=-1;t为其他
struct exponentType
{
	char xExpressionEPtr[30];//x表达式 
	double tNum;//指数x^t 中t的值 
};
typedef struct exponentType ExponentType;

//三角函数型 sin cos tan sec csc cot arcsin arccos arctan
struct trigonometricFunctionType
{
	char trigonometricFunction9;//类型9种  sinA cosB tanC secD cscE cotF arcsinG arccosH arctanI
	char xExpressionTPtr[30];//x表达式
};
typedef struct trigonometricFunctionType TrigonometricFunctionType;

//幂指数型 a^x (a>0) a=1或a=e
struct powerExponentType
{
	double aNum;//(a>0) a=1或a=e或a为其他
	char xExpressionPPtr[30];//x表达式 
}; 
typedef struct powerExponentType PowerExponentType;

//对数型 需要转化成自然对数ln 
struct logarithmType
{
	char xExpressionLPtr[30];//x表达式
}; 
typedef struct logarithmType LogarithmType;

//分式x/y对应c x和y都为x表达式对应d 
struct fractionType
{
	char numerator[30];//分子表达式
	char denominator[30];//分母表达式 
};
typedef struct fractionType FractionType;



//输入被积函数表达式 
//每种类型的函数在界面中会对应于这里的一种符号 以便编程进行 （界面只允许按顺序填写 不可任意插入） 
/*符号对应：
若式子有常数相 需要先按有关按键 对应n 单独存放 中途不能增加常数项 
指数x^y 底数含x即x^t对应a 幂含x即a^x对应b  无x^x情况（因为无法实现）  
分式x/y对应c  若只有y包含x或只有x包含x都对应a （需要建立函数实现转换）  若x和y都为x表达式对应d 
对数 全部转化为自然对数ln 对应e      若非自然对数 对应f 后为底数 只能是数字  >后真数 
三角函数中 sin对应A cos对应B tan对应C sec对应D csc对应E cot对应F arcsin对应G arccos对应H aretan对应I
()左右括号 点击时同时出现 显示直接输入括号中间内容 对应( 
右键对应符号>  （分割作用） 
如果是两式相乘 需要按右键两次 显示>> 
=号在程序中相当于 Enter键 对应'\n' 
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
	}//线性代数求最大公约数 
int main()
//超出计算器计算范围时返回值是0
//可以运算 返回值为1 
{
	initgraph(400, 400);	
	setfillcolor(EGERGB(0x54, 0x54, 0x54));
	bar(40,100,330,400);    
	setfillcolor(EGERGB(0xFC, 0xFC, 0xFC));//设置填充颜色，一般为图形内部颜色
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
	outtextxy(220, 358, "√");
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
	outtextxy(255, 358, "ln");//画一实心矩形
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
	outtextxy(298, 318, "空");
	bar(290,350,320,380);
	setcolor(0);
	setfontbkcolor(EGERGB(0xFC, 0xFC, 0xFC));
	setfont(15, 0, "arial");
	outtextxy(290, 358, "积|线");
	
	
	char calculus[50];
	int in=0;//用于储存不定积分内容 
	char xiandai[100];
	int im=0;//用于储存线代内容
	bool judge=true; 
	
	bool click_flag;
	int xClick, yClick;
	for (; is_run(); delay_fps(60)) 
	{
		//点击标志位清零
		click_flag = false;
		//处理鼠标消息
		while (mousemsg()) {
			mouse_msg msg = getmouse();
			//左键按下
			if (msg.is_left() && msg.is_down()) {
				//标志位置位，记录点击位置
				click_flag = true;
				xClick = msg.x;
				yClick = msg.y;
			}
		}		//检测到点击
		if (click_flag) {//输出鼠标点击坐标
			if(((290<xClick)&&(xClick<300))&&((350<yClick)&&(yClick<380))){
				printf("求不定积分\n");
				judge=true;
			}
			else if(((310<xClick)&&(xClick<320))&&((350<yClick)&&(yClick<380))){
				printf("请输入三维向量组\n");
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
				printf("√");	
				calculus[in]='√';
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
	printf("\n\n%s\n","不定积分求解思路：");
	int out=0;//将字符串中储存字符输出的计数器 
	
	char firstLetter;
	firstLetter=calculus[out];
	out++;
	char *connector=NULL;//用于储存加减号 以便知道是否需要重新运行程序 
	char *coefficient=NULL;//用于储存所有的系数 但这里只允许开头输入系数 但存在某些情况需要化简并产生系数 需要储存再coefficient里 
	                       //但其实这个程序里的运算方法并没有排除在n键输入完成之后 再输入常数的情况 需要使用者在使用过程中自行注意 
	char record[50];
	int recordNum=0;//用来记录所有的输入内容
	record[recordNum]=firstLetter;
	recordNum++; 
	
	//根据首字母选择对应类型结构体
	switch (firstLetter)
	{
		//三角函数及反三角函数情况 
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
			triPtr.trigonometricFunction9=firstLetter;//sin对应A cos对应B tan对应C sec对应D csc对应E cot对应F arcsin对应G arccos对应H aretan对应I
			
			//处理x表达式 
			char referenceTri[30];//参考数组 只允许ax+b形式
			
			//先处理 referenceTri[0]
			referenceTri[0]=calculus[out];
	        out++;
			record[recordNum]=referenceTri[0];
			recordNum++;
			if(referenceTri[0]!='0'&&referenceTri[0]!='1'&&referenceTri[0]!='2'&&referenceTri[0]!='3'&&referenceTri[0]!='4'&&
			   referenceTri[0]!='5'&&referenceTri[0]!='6'&&referenceTri[0]!='7'&&referenceTri[0]!='8'&&referenceTri[0]!='9'&&
			   referenceTri[0]!='x'&&referenceTri[0]!='+'&&referenceTri[0]!='-') 
			{
				printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算
				return 0;
			}//只能按顺序输入 此处不允许输入> (还不知道怎么实现)
			
			unsigned int counter=0;
			do //循环得出x表达式后面部分 
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
			    	printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算
			    	return 0;
			    }//排除不是ax+b情况 
			} while((!(referenceTri[counter-1]=='>'&&referenceTri[counter]=='>'))&&(referenceTri[counter]!='\n'));//当有>>或=时循环结束，不再getchar
			referenceTri[counter+1]='\0';
			
			//完善三角函数 
			char xExpressionCaseTriPtr[30];
			if(referenceTri[counter]=='\n')
			{
				strncpy(xExpressionCaseTriPtr,referenceTri,counter);
				xExpressionCaseTriPtr[counter]='\0';//使 xExpressionCaseTriPtr指向 x的表达式 
				strcpy(triPtr.xExpressionTPtr,xExpressionCaseTriPtr);//结构体中x表达式 完成
				
				if(strcmp(xExpressionCaseTriPtr,"x")==0)
				{
					printf("%s\n","用公式法计算");
					switch(firstLetter)
					{
						case 'A':
							printf("%s","∫sinxdx=-cosx+C");
							break;
						case 'B':
							printf("%s","∫cosxdx=sinx+C");
						    break;
						case 'C':
							printf("%s","∫tanxdx=-ln|cosx|+C");
							break;
						case 'D':
							printf("%s","∫secx==∫cosxdx/(cosx)^2=∫d(sinx)/[1-(sinx)^2]=用换元法=ln|secx+tanx|+C");
							break;
						case 'E':
						    printf("%s","∫cscxdx=∫dx/sinx=∫sinxdx/sin2x=-∫dcosx/(1-cos2x)=用换元法=ln|cscx-cotx|+C") ;
							break;
						case 'F':
						    printf("%s","∫cotxdx=ln|sinx|+C") ;
						    break;
						case 'G':
							printf("%s\n%s","反三角函数一般用分部积分法","∫arcsinx=xarcsinx+√(1-x^2)+C");
							break;
						case 'H':
							printf("%s\n%s","反三角函数一般用分部积分法","∫arccosx=xarccosx-√(1-x^2)+C");
							break;
						case 'I':
							printf("%s\n%s","反三角函数一般用分部积分法","∫arctanx=xarctanx+ln(√(1+x^2))+C");
							break;
					} //switch结束 
				}
				else
				{
					printf("%s%s\n","先用换元法计算，令u=",xExpressionCaseTriPtr);
					printf("%s\n","后用公式法计算");
					switch(firstLetter)
					{
						case 'A':
							printf("%s","∫sinxdx=-cosx+C");
							break;
						case 'B':
							printf("%s","∫cosxdx=sinx+C");
						    break;
						case 'C':
							printf("%s","∫tanxdx=-ln|cosx|+C");
							break;
						case 'D':
							printf("%s","∫secx==∫cosxdx/(cosx)^2=∫d(sinx)/[1-(sinx)^2]=用换元法=ln|secx+tanx|+C");
							break;
						case 'E':
						    printf("%s","∫cscxdx=∫dx/sinx=∫sinxdx/sin2x=-∫dcosx/(1-cos2x)=用换元法=ln|cscx-cotx|+C") ;
							break;
						case 'F':
						    printf("%s","∫cotxdx=ln|sinx|+C") ;
						    break;
						case 'G':
							printf("%s\n%s","反三角函数一般用分部积分法","∫arcsinx=xarcsinx+√(1-x^2)+C");
							break;
						case 'H':
							printf("%s\n%s","反三角函数一般用分部积分法","∫arccosx=xarccosx-√(1-x^2)+C");
							break;
						case 'I':
							printf("%s\n%s","反三角函数一般用分部积分法","∫arctanx=xarctanx+ln(√(1+x^2))+C");
							break;
					} //switch结束 
				} 
				break; 
			} 
			
			//此处是单个三角函数  后续需转至公式法或换元法 
			
			
			else
			{
				//三角函数后面还需要乘表达式的情况 
				//一共两种  sin和cos相乘   或者   sin/cos乘x的多项式 
				if(referenceTri[counter-1]=='>'&&referenceTri[counter]=='>')
				{
					strncpy(xExpressionCaseTriPtr,referenceTri,counter-1);
					xExpressionCaseTriPtr[counter-1]='\0';//使 xExpressionCaseTriPtr指向 x的表达式
					char secondLetter=calculus[out];
	                out++;
					record[recordNum]=secondLetter;
					recordNum++;
					if(secondLetter=='\n')
					{
						strcpy(triPtr.xExpressionTPtr,xExpressionCaseTriPtr);//结构体中x表达式 完成
						if(strcmp(xExpressionCaseTriPtr,"x")==0)
				        {
					        printf("%s\n","用公式法计算");
					        switch(firstLetter)
				        	{
						        case 'A':
							        printf("%s","∫sinxdx=-cosx+C");
							        break;
						        case 'B':
							        printf("%s","∫cosxdx=sinx+C");
						            break;
						        case 'C':
							        printf("%s","∫tanxdx=-ln|cosx|+C");
							        break;
						        case 'D':
							        printf("%s","∫secx==∫cosxdx/(cosx)^2=∫d(sinx)/[1-(sinx)^2]=用换元法=ln|secx+tanx|+C");
						        	break;
						        case 'E':
						            printf("%s","∫cscxdx=∫dx/sinx=∫sinxdx/sin2x=-∫dcosx/(1-cos2x)=用换元法=ln|cscx-cotx|+C") ;
							        break;
						        case 'F':
						            printf("%s","∫cotxdx=ln|sinx|+C") ;
						            break;
						        case 'G':
							        printf("%s\n%s","反三角函数一般用分部积分法","∫arcsinx=xarcsinx+√(1-x^2)+C");
							        break;
						        case 'H':
							        printf("%s\n%s","反三角函数一般用分部积分法","∫arccosx=xarccosx-√(1-x^2)+C");
							        break;
						        case 'I':
							        printf("%s\n%s","反三角函数一般用分部积分法","∫arctanx=xarctanx+ln(√(1+x^2))+C");
							        break;
					            } //switch结束 
				        }  
				        else
				        {
					        printf("%s%s\n","先用换元法计算，令u=",xExpressionCaseTriPtr);
					        printf("%s\n","后用公式法计算");
					        switch(firstLetter)
					        {
						        case 'A':
						        	printf("%s","∫sinxdx=-cosx+C");
						        	break;
						        case 'B':
						        	printf("%s","∫cosxdx=sinx+C");
						            break;
						        case 'C':
						        	printf("%s","∫tanxdx=-ln|cosx|+C");
						        	break;
						        case 'D':
							        printf("%s","∫secx==∫cosxdx/(cosx)^2=∫d(sinx)/[1-(sinx)^2]=用换元法=ln|secx+tanx|+C");
							        break;
					        	case 'E':
						            printf("%s","∫cscxdx=∫dx/sinx=∫sinxdx/sin2x=-∫dcosx/(1-cos2x)=用换元法=ln|cscx-cotx|+C") ;
							        break;
						        case 'F':
						            printf("%s","∫cotxdx=ln|sinx|+C") ;
						            break;
					        	case 'G':
						        	printf("%s\n%s","反三角函数一般用分部积分法","∫arcsinx=xarcsinx+√(1-x^2)+C");
							        break;
						        case 'H':
							        printf("%s\n%s","反三角函数一般用分部积分法","∫arccosx=xarccosx-√(1-x^2)+C");
							        break;
						        case 'I':
							        printf("%s\n%s","反三角函数一般用分部积分法","∫arctanx=xarctanx+ln(√(1+x^2))+C");
							        break;
					        } //switch结束 
				        } 
						break;
					}
					
					//此处是单个三角函数  后续需转至公式法或换元法 
					
					
					else
					{
						if(firstLetter!='A'&&firstLetter!='B') 
						{
							switch(firstLetter)//公式法sec x tan x = sec x；csc x cot x = -csc x 
							{
								case 'D':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='C')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","使用公式法","∫secx tanx dx=secx+C");
									}
									else
									printf("%s","超出计算器计算范围");
									break;
								case 'C':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='D')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","使用公式法","∫secx tanx dx=secx+C");
									}
									else
									printf("%s","超出计算器计算范围");
									break;
								case 'E':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='F')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","使用公式法","∫cscx cotx dx=-cscx+C");
									}
									else
									printf("%s","超出计算器计算范围");
									break;
								case 'F':
									if((record[1]=='x')&&(record[2]=='>')&&(record[3]=='>')&&(secondLetter=='E')&&(calculus[out]=='x')&&(calculus[out+1]=='\n'))
									{
										printf("%s\n%s","使用公式法","∫cscx cotx dx=-cscx+C");
									}
									else
									printf("%s","超出计算器计算范围");
									break;
								default:
									printf("%s","超出计算器计算范围");
									break;
							}
							return 0; 
						}
						else//sin和cos的情况 
						{
							if(secondLetter=='A'||secondLetter=='B')//sinsin sincos coscos 情况 
							{
								TrigonometricFunctionType triPtr2;//新一个三角函数结构体 
								triPtr2.trigonometricFunction9=secondLetter;//sin对应A cos对应B
								
								//x表达式   这里代码几乎与前面一样 但并没有写成函数形式 
								char referenceTri2[30]; //重新定义一个参考数组用于存贮>>后面部分 
								
								//先处理 referenceTri2[0]
		 	                    referenceTri2[0]=calculus[out];
	                            out++;
		 	                    record[recordNum]=referenceTri2[0];
		 	                    recordNum++;
			                    if(referenceTri2[0]!='0'&&referenceTri2[0]!='1'&&referenceTri2[0]!='2'&&referenceTri2[0]!='3'&&referenceTri2[0]!='4'&&
			                       referenceTri2[0]!='5'&&referenceTri2[0]!='6'&&referenceTri2[0]!='7'&&referenceTri2[0]!='8'&&referenceTri2[0]!='9'&&
			                       referenceTri2[0]!='x'&&referenceTri2[0]!='+'&&referenceTri2[0]!='-') 
			                    {
			                	    printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算
				                    return 0;
			                    }//只能按顺序输入 此处不允许输入> (还不知道怎么实现)
			                    
			                    unsigned int counter2=0;
			                    do //循环得出x表达式后面部分 
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
			    	                    printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算
			    	                    return 0;
			                        }//排除不是ax+b情况 
			                    } while((!(referenceTri2[counter2-1]=='>'&&referenceTri2[counter2]=='>'))&&(referenceTri2[counter2]!='\n'));
								        //当有>>或=时循环结束，不再getchar
			                    referenceTri2[counter2+1]='\0';
			                    
			                    //完善三角函数 
			                    char xExpressionCaseTriPtr2[30];
			                    
			                    if(referenceTri2[counter2]=='\n')
			                    {
				                    strncpy(xExpressionCaseTriPtr2,referenceTri2,counter2);
				                    xExpressionCaseTriPtr2[counter2]='\0';//使 xExpressionCaseTriPtr指向 x的表达式 
				                    strcpy(triPtr2.xExpressionTPtr,xExpressionCaseTriPtr2);//结构体中x表达式 完成
				                    
				                    printf("%s\n","先使用积化和差公式简化");
									printf("%s\n%s\n%s\n%s\n","sinacosb=1/2[sin(a+b)+sin(a-b)]",
									                          "cosasinb=1/2[sin(a+b)-sin(a-b)]",
															  "cosacosb=1/2[cos(a+b)+cos(a-b)]",
															  "sinasinb=-1/2[cos(a+b)-cos(a-b)]");
									printf("%s\n","之后依次 先换元后使用公式法");
									printf("%s\n%s","∫sinxdx=-cosx+C","∫cosxdx=sinx+C");
									
				                    break; 
			                    } 
			                    
			                    //此处是sinsin sincos coscos 两三角函数相乘  后续需转至 积化和差公式后 重新用公式法或换元法计算 
			                    
			                    
			                    else
			                    {
			                    	if(referenceTri2[counter2-1]=='>'&&referenceTri2[counter2]=='>')
				                    {
					                    strncpy(xExpressionCaseTriPtr2,referenceTri2,counter2-1);
					                    xExpressionCaseTriPtr2[counter2-1]='\0';//使 xExpressionCaseTriPtr指向 x的表达式
					                    secondLetter=calculus[out];
	                                    out++;
					                    if(secondLetter=='\n')
					                    {
						                    strcpy(triPtr2.xExpressionTPtr,xExpressionCaseTriPtr2);//结构体中x表达式 完成
						                    
						                    printf("%s\n","先使用积化和差公式简化");
									        printf("%s\n%s\n%s\n%s\n","sinacosb=1/2[sin(a+b)+sin(a-b)]",
									                                  "cosasinb=1/2[sin(a+b)-sin(a-b)]",
											        				  "cosacosb=1/2[cos(a+b)+cos(a-b)]",
											        				  "sinasinb=-1/2[cos(a+b)-cos(a-b)]");
									        printf("%s\n","之后依次 先换元后使用公式法");
									        printf("%s\n%s","∫sinxdx=-cosx+C","∫cosxdx=sinx+C");
									        
						                    break;
					                    }
					                    
					                    //此处是sinsin sincos coscos 两三角函数相乘  后续需转至 积化和差公式后 重新用公式法或换元法计算 
					                    
					                    
					                    else
					                    {
					                    	if(secondLetter=='+'||secondLetter=='-') 
					                    	{
					                    		strcpy(triPtr2.xExpressionTPtr,xExpressionCaseTriPtr2);//结构体中x表达式 完成
					                    		connector=&secondLetter; 
					                    		break;
											}
											//储存+-号 结束时判断 以便知道是否需要重新运行一遍程序
											
											else//其他情况 无法计算 
											{
												printf("%s","超出计算器计算范围"); 
												return 0;
											} 
										}
								    }
								}
							}
							else
							{
								if(secondLetter=='a')//sin/cos乘x的多项式形式 现已是()^t形式 
								{
									ExponentType expPtr;//x^t 结构体 
									char referenceExp[30];//参考数组
									
									//先处理 referenceExp[0]
			                        referenceExp[0]=calculus[out];
	                                out++;
			                        if(referenceExp[0]!='0'&&referenceExp[0]!='1'&&referenceExp[0]!='2'&&referenceExp[0]!='3'&&referenceExp[0]!='4'&&
			                           referenceExp[0]!='5'&&referenceExp[0]!='6'&&referenceExp[0]!='7'&&referenceExp[0]!='8'&&referenceExp[0]!='9'&&
			                           referenceExp[0]!='x'&&referenceExp[0]!='+'&&referenceExp[0]!='-') 
		                            {
				                        printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算(这里主要是因为无法实现符号运算)
			                        	return 0;
			                        }//只能按顺序输入 此处不允许输入> (还不知道怎么实现)
			
			                        unsigned int counter2=0;
			                        do //循环得出x表达式后面部分 
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
			    	                        printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算
			    	                        return 0;
			                            }//排除不是ax+b情况 
			                        } while(referenceExp[counter2]!='>');
									        //当有>时循环结束，不再getchar
			                        referenceExp[counter2+1]='\0';
			                        strncpy(expPtr.xExpressionEPtr,referenceExp,counter2);//x表达式输入完成
									
									//求x^t中t的值 为double类型 
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
											printf("%s","超出计算器计算范围");
											return 0;
										}//只能实现整数 
									}while(referenceExpT[counter3]!='\n');
									referenceExpT[counter3+1]='\0'; //字符串referenceExpT完成
									
									//再将字符串中含数字部分导出
									char *referenceExpTPtr;//这个字符串用于储存 字符串referenceExpT中数字后的剩余部分
									double  referenceTNum=strtod(referenceExpT,&referenceExpTPtr);
									if(referenceTNum!=1&&referenceTNum!=2&&referenceTNum!=3&&referenceTNum!=4&&referenceTNum!=5)
									{
										printf("%s","超出计算器计算范围");
										return 0;
									}
									else
									{
										expPtr.tNum=referenceTNum;
										
										printf("%s%s%s\n","先用换元法将sin/cos后的",xExpressionCaseTriPtr,"换元") ;
										printf("%s\n","再计算出（ax+b）^t中x的多项式 化成sin/cosx*(x^t+…+x+n)形式 依次计算");
										printf("%s\n%s","sin/cosx*x^t需要通过分部积分法求解","通常将sinx/cosx移至dx处变为d(-cosx)/dsinx后进行分部积分法") ;
										
										break;
									}
									//再管 字符串referenceExpT中数字后的剩余部分只有\n和>>两个可能 
									if(referenceExpTPtr[0]=='>')
									{
										if(referenceExpTPtr[2]!='\n')
										{
											printf("%s","超出计算器计算范围");
										    return 0;//sin/cos乘(ax+b)^t后不管接下来是什么都无法计算 
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
									
									//sin/cos乘(ax+b)^t形式 应用分部积分法 
									
								}
								else
								{
									if(secondLetter=='x')//sin/cos*x类型 
									{
										printf("%s","sin/cosx*x需要通过分部积分法求解","通常将sinx/cosx移至dx处变为d(-cosx)/dsinx后进行分部积分法");
										break;
									}
									else
									{
										printf("%s","超出计算器计算范围");
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
			//处理x表达式 
			char referenceExp[30];//参考数组
			unsigned int counter=0;
			
			//先处理 referenceTri[0]
			referenceExp[0]=calculus[out];
	        out++;
			record[recordNum]=referenceExp[0];
			recordNum++;
			
			if((referenceExp[0]=='A')||(referenceExp[0]=='B')||(referenceExp[0]=='D')||(referenceExp[0]=='E')||(referenceExp[0]=='C'))
			//三角函数情况 
			{
				do//将x^t表达式加>>符号或\n 全部保存至 referenceExp[30]中 
				{
	    			counter++;
					referenceExp[counter]=calculus[out];
	                out++;
					record[recordNum]=referenceExp[counter];
	                recordNum++;
				}while((!(referenceExp[counter]=='\n'))&&(!((referenceExp[counter-1]=='>')&&(referenceExp[counter]=='>'))));
                
				switch(referenceExp[0])
				{
					case 'D'://∫(secx)^2dx和 特殊情况 ∫(secx)^3dx
						if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='2')&&(referenceExp[4]=='\n'))
						{
							printf("%s\n%s","使用公式法","∫(secx)^2dx=tanx+C");
						}
						else
						{
							if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='3')&&(referenceExp[4]=='\n'))
							{
								printf("%s\n%s\n%s","有特殊计算方法",
								                  "∫(secx)^3dx=∫secxdtanx=分部积分法=secx*tanx-∫secx*(tanx)^2dx= secx*tanx-∫secx*(secx^2-1)dx= secx*tanx+ln|secx+tanx|-∫secx^3dx",
												  "移项后，两遍除以2  得∫secx^3dx=1/2(secx*tanx+ln|secx+tanx|)+C");
							}
							else
							{
								printf("%s","超出计算器计算范围");
								return 0;
							}
						}
						break;
					case 'E':// ∫(cscx)^2dx
						if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='2')&&(referenceExp[4]=='\n'))
						{
						printf("%s\n%s","使用公式法","∫(cscx)^2dx=-cotx+C");
					    }
					    else
						{
							printf("%s","超出计算器计算范围");
							return 0;
						}
					    break;
					case 'C':// ∫(tanx)^2dx也属于特殊情况 
						if((referenceExp[1]=='x')&&(referenceExp[2]=='>')&&(referenceExp[3]=='2')&&(referenceExp[4]=='\n'))
						{
						printf("%s\n%s\n%s","使用公式(tanx)^2=(secx)^2-1",
						                    "然后利用公式法计算，其中∫(secx)^2dx=tanx+C",
						                    "∫(tanx)^2dx=tanx-x+C");
					    }
					    else
						{
							printf("%s","超出计算器计算范围");
							return 0;
						}
					    break;
					case 'A'://sin的情况 
						if(referenceExp[counter]=='\n')//先讨论 (Sin x)^t
						{
							if((referenceExp[1]=='x')&&(referenceExp[2]=='>'))
							{
								for(int i=3;i<counter;i++)
								{
									if((referenceExp[i]!='0')&&(referenceExp[i]!='1')&&(referenceExp[i]!='2')&&(referenceExp[i]!='3')&&
									   (referenceExp[i]!='4')&&(referenceExp[i]!='5')&&(referenceExp[i]!='6')&&(referenceExp[i]!='7')&&
									   (referenceExp[i]!='8')&&(referenceExp[i]!='9'))
									{
									    printf("%s","超出计算器计算范围");
										return 0;
							        }
								}
								if((referenceExp[counter-1]=='1')||(referenceExp[counter-1]=='3')||(referenceExp[counter-1]=='5')||
								   (referenceExp[counter-1]=='7')||(referenceExp[counter-1]=='9'))
								{
									printf("%s\n%s\n%s","∫(sinx)^tdx形式，且t为奇数",
									                    "则有∫(sinx)^tdx=∫(sinx)^(t-1)*sinxdx=-∫(sinx)^(t-1)dcosx",
													    "此时，利用sinx^2=1-cosx^2，将cosx换元，可通过公式法计算");
								}
								else
								{
									printf("%s\n%s\n%s","∫(sinx)^tdx形式，且t为偶数",
									                    "这种情况需要通过降幂实现",
													    "利用公式sinx^2=(1-cos 2x)/2");
								}
							}
							else
							{
								printf("%s","超出计算器计算范围");
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
								printf("%s","使用分部积分法，将x变换至d后");
							    }
								else
								{
									printf("%s","超出计算器计算范围");
						            return 0;
								}
							}
							else
							{
								if(secondLetter=='a')
								{
									char referenceExp2[30];
						        	int counter2=0;
						        	
						        	//先处理 referenceTri[0]
			                        referenceExp2[0]=calculus[out];
	                                out++;
	                        		record[recordNum]=referenceExp2[0];
	                        		recordNum++;
	                        		
	                        		if((referenceExp2[0]!='x')&&(referenceExp2[0]!='B'))
	                        		{
	                        			printf("%s","超出计算器计算范围");
						        	    return 0;
									}
						        	
						        	do//将x^t或(cosx)^t2表达式加\n 全部保存至 referenceExp2[30]中 
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
							        		    printf("%s","超出计算器计算范围");
							        			return 0;
							                }
							        	}
							        	printf("%s","使用分部积分法"); 
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
							            		    printf("%s","超出计算器计算范围");
							            			return 0;
							                    } 
							            	}
							            	printf("%s\n%s\n%s","∫(sinx)^t1*(cosx)^t2dx形式",
												                "若t1、t2一奇一偶,则将奇数对应的三角函数换到d后，另一个偶数次利用sinx^2=1-cosx^2或cosx^2=1-sinx^2进行转化",
												    			"若t1、t2同为奇数或偶数，则利用三角函数公式降幂");
										}
										else
										{
											printf("%s","超出计算器计算范围");
							        		return 0;
										}
									}
                
								}
						    }
						}
						break; 
					case 'B':
						if(referenceExp[counter]=='\n')//先讨论 (cos x)^t
						{
							if((referenceExp[1]=='x')&&(referenceExp[2]=='>'))
							{
								for(int i=3;i<counter;i++)
								{
									if((referenceExp[i]!='0')&&(referenceExp[i]!='1')&&(referenceExp[i]!='2')&&(referenceExp[i]!='3')&&
									   (referenceExp[i]!='4')&&(referenceExp[i]!='5')&&(referenceExp[i]!='6')&&(referenceExp[i]!='7')&&
									   (referenceExp[i]!='8')&&(referenceExp[i]!='9'))
									{
									    printf("%s","超出计算器计算范围");
										return 0;
							        }
								}
								if((referenceExp[counter-1]=='1')||(referenceExp[counter-1]=='3')||(referenceExp[counter-1]=='5')||
								   (referenceExp[counter-1]=='7')||(referenceExp[counter-1]=='9'))
								{
									printf("%s\n%s\n%s","∫(cosx)^tdx形式，且t为奇数",
									                    "则有∫(cosx)^tdx=∫(cosx)^(t-1)*cosxdx=∫(cosx)^(t-1)dsinx",
													    "此时，利用cosx^2=1-sinx^2，将sinx换元，可通过公式法计算");
								}
								else
								{
									printf("%s\n%s\n%s","∫(cosx)^tdx形式，且t为偶数",
									                    "这种情况需要通过降幂实现",
													    "利用公式cosx^2=(1+cos 2x)/2");
								}
							}
							else
							{
								printf("%s","超出计算器计算范围");
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
								printf("%s","使用分部积分法，将x变换至d后");
							    }
								else
								{
									printf("%s","超出计算器计算范围");
						            return 0;
								}
							}
							else
							{
								if(secondLetter=='a')
								{
									char referenceExp2[30];
						        	int counter2=0;
						        	
						        	//先处理 referenceTri[0]
			                        referenceExp2[0]=calculus[out];
	                                out++;
	                        		record[recordNum]=referenceExp2[0];
	                        		recordNum++;
	                        		
	                        		if((referenceExp2[0]!='x')&&(referenceExp2[0]!='A'))
	                        		{
	                        			printf("%s","超出计算器计算范围");
						        	    return 0;
									}
						        	
						        	do//将x^t或(sinx)^t2表达式加\n 全部保存至 referenceExp2[30]中 
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
							        		    printf("%s","超出计算器计算范围");
							        			return 0;
							                }
							        	}
							        	printf("%s","使用分部积分法"); 
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
							            		    printf("%s","超出计算器计算范围");
							            			return 0;
							                    } 
							            	}
							            	printf("%s\n%s\n%s","∫(sinx)^t1*(cosx)^t2dx形式",
												                "若t1、t2一奇一偶,则将奇数对应的三角函数换到d后，另一个偶数次利用sinx^2=1-cosx^2或cosx^2=1-sinx^2进行转化",
												    			"若t1、t2同为奇数或偶数，则利用三角函数公式降幂");
										}
										else
										{
											printf("%s","超出计算器计算范围");
							        		return 0;
										}
									}
                
								}
						    }
						}
						break; 
					
				}
			}
			
			//(多项式)^t
			else
			{
			    if(referenceExp[0]!='0'&&referenceExp[0]!='1'&&referenceExp[0]!='2'&&referenceExp[0]!='3'&&referenceExp[0]!='4'&&
			       referenceExp[0]!='5'&&referenceExp[0]!='6'&&referenceExp[0]!='7'&&referenceExp[0]!='8'&&referenceExp[0]!='9'&&
		    	   referenceExp[0]!='x'&&referenceExp[0]!='+'&&referenceExp[0]!='-') 
		    	{
		    		printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算
		    		return 0;
		    	}//只能按顺序输入 此处不允许输入> (还不知道怎么实现)
			
		    	unsigned int counter=0;
		    	do //循环得出x表达式后面部分 
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
			        	printf("%s","超出计算器计算范围"); //不是ax+b形式都无法计算
			    	    return 0;
    			    }//排除不是ax+b情况 
	    		} while(!(referenceExp[counter]=='>'));//当有>时循环结束，不再getchar
		    	referenceExp[counter+1]='\0';
			 
    			char tNum[20];//数组储存x^t中t的数值 
	    		int counterT=0;
		    	do
			    {
    				tNum[counterT]=calculus[out];
	                out++;
		    		if((tNum[counterT]!='0')&&(tNum[counterT]!='1')&&(tNum[counterT]!='2')&&(tNum[counterT]!='3')&&
			    	   (tNum[counterT]!='4')&&(tNum[counterT]!='5')&&(tNum[counterT]!='6')&&(tNum[counterT]!='7')&&
				       (tNum[counterT]!='8')&&(tNum[counterT]!='9')&&(tNum[counterT]!='>')&&(tNum[counterT]!='\n'))
	    			{
		    			printf("%s","超出计算器计算范围"); 
			        	return 0;
				    }
		    		counterT++;
    			} while((!((tNum[counterT-2]=='>')&&(tNum[counterT-1]=='>')))&&(tNum[counterT-1]!='\n'));
	   		
	    		
		    	if((referenceExp[0]=='x')&&(counter==1))//ax+b型为x 
	    		{
		    		if(tNum[counterT-1]=='\n')
			    	{
    					printf("%s\n%s","使用公式法",
	    				                "∫x^tdx=x^(t+1)/(t+1)+C");
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
				    				printf("%s","使用分部积分法");
					    			break;
					    		case 'A':
								case 'B':
								    printf("%s","使用分部积分法");
					    			break;
					    		default:
					    			printf("%s","超出计算器计算范围"); 
			        	            return 0;
						    }
					    }
				    }
			    }
			    else
			    {
			    	printf("%s","先换元后公式法");
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
		    		printf("%s\n%s","使用公式法",
					                "∫xdx=x^2/2+C");
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
		    				printf("%s","使用分部积分法");
				        	break;
						case 'A':
						case 'B':
						    printf("%s","使用分部积分法");
					   		break;
					   	case '√':
					   		if((calculus[out]=='1')&&(calculus[out+1]=='-')&&(calculus[out+2]=='a')&&
							   (calculus[out+3]=='x')&&(calculus[out+4]=='>')&&(calculus[out+5]=='2')&&
							   (calculus[out+6]=='\n'))
							{ 
								printf("%s\n%s","凑微分换元, 使xdx 变为1/2d(x^2)",
								                "∫x√(1-x^2)dx=-1/2∫√(1-x^2)d(1-x^2)");
							}
				 		default:
			    			printf("%s","超出计算器计算范围"); 
	        	            return 0;
				    }
				} 
			}
			else
			{
				printf("%s","超出计算器计算范围"); 
			    return 0;
			}
			break;
	    }
	    default:
	    	printf("%s","超出计算器计算范围");
	    	break;
    }//switch反括号 
	
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
	//输入三组向量
	if(((x1*x2*x3*y1*y2*y3*z1*z2*z3)!=0)&&(((x1/y1)==(x2/y2)==(x3/y3))||((x1/z1)==(x2/z2)==(x3/z3))||((y1/z1)==(y2/z2)==(y3/z3)))){
		printf("\n不是线性无关向量组，不能单位正交化"); 
	}
	else if((y1==z1)&&(y2==z2)&&(y3==z3)){
		printf("\n不是线性无关向量组，不能单位正交化");
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
	printf("\n是正交向量组");
	// 输入即为正交向量组 
	else{
		if((b11==0)||(b22==0)||(b33==0)||(c11==0)||(c22==0)||(c33==0))
		printf("错误");
		else{
			printf("\n正交向量组为:\n");
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
			//求解正交向量组
			printf("单位正交向量组为:\n"); 
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
				printf("%10d/√%d ",a1,A);
				if(a2==0)
				printf("%10d ",0);
				else
				printf("%10d/√%d ",a2,A);
				if(a3==0)
				printf("%d\n",0);
				else
				printf("%10d/√%d\n",a3,A);
			}//第一行单位化//
			if((b1==0)&&(b2==0)&&(b3==0)){
				printf("%10d %10d %10d",0,0,0);
			}
			else{
			B11=b11*b11*b22*b22*b33*b33;
			B1=b22*b22*(b1*b1*b33*b33+b3*b3*b11*b11)+b2*b2*b11*b11*b33*b33;
			if(B1%B11==0){//平方和为整数// 
				B=B1/B11;
				if(B==(int)sqrt(B)*(int)sqrt(B)){//平方和为完全平方数// 
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
			else{//平方和不是完全平方数// 
				if((b1%b11==0)&&(b1!=0))
				printf("%10d/√%d ",b1/b11,B);
				else if(b1==0)
				printf("%10d ",0);
				else
				printf("%10d/%d√%d ",b1/gcd(b1,b11),b11/gcd(b1,b11),B);
				if((b2%b22==0)&&(b2!=0))
				printf("%10d/√%d ",b2/b22,B);
				else if(b2==0)
				printf("%10d ",0);
				else
				printf("%10d/%d√%d ",b2/gcd(b2,b22),b22/gcd(b2,b22),B);
				if((b3%b33==0)&&(b3!=0))
				printf("%10d/√%d\n",b3/b33,B);
				else if(b3==0)
				printf("%10d\n",0);
				else
				printf("%10d/%d√%d\n",b3/gcd(b3,b33),b33/gcd(b3,b33),B);
			}
		}
		else{//平方和不是整数//
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
				printf("%10d/√%d ",(b1*f)/b11,B1);
				else
				printf("%10d/%d√%d ",(b1*f)/gcd((b1*f),b11),b11/gcd((b1*f),b11),B1);
				if(b2==0)
				printf("%10d ",0);
				else if((b2!=0)&&((b2*f)%b22==0))
				printf("%10d/√%d ",(b2*f)/b22,B1);
				else
				printf("%10d/%d√%d ",(b2*f)/gcd((b2*f),b22),b22/gcd((b2*f),b22),B1);
				if(b3==0)
				printf("%10d\n",0);
				else if((b3!=0)&&((b3*f)%b33==0))
				printf("%10d/√%d\n",(b3*f)/b33,B1);
				else
				printf("%10d/%d√%d\n",(b3*f)/gcd((b3*f),b33),b33/gcd((b3*f),b33),B1);
			}
			else if((B11!=(int)sqrt(B11)*(int)sqrt(B11))&&(B1==(int)sqrt(B1)*(int)sqrt(B1))){
				if(b1==0)
				printf("%10d ",0);
				else
				printf("√%d %d/%d ",B11,b1/gcd(b1,(b11*h)),(b11*h)/gcd(b1,(b11*h)));
				if(b2==0)
				printf("%10d ",0);
				else
				printf("√%d %d/%d ",B11,b2/gcd(b2,(b22*h)),(b22*h)/gcd(b2,(b22*h)));
				if(b3==0)
				printf("%10d\n",0);
				else
				printf("√%d %d/%d\n",B11,b3/gcd(b3,(b33*h)),(b33*h)/gcd(b3,(b33*h)));
			}
			else{
				if(b1==0)
				printf("%10d ",0);
				else if(b1/b11==1)
				printf("√%d/√%d ");
				else if((b1/b11!=1)&&(b1!=0)&&(b1%b11==0))
				printf("%10d√%d/√%d ",b1/b11,B11,B1);
				else
				printf("%10d√%d/%d√%d ",b1/gcd(b1,b11),B11,b11/gcd(b1,b11),B1);
				if(b2==0)
				printf("%10d ",0);
				else if(b2/b22==1)
				printf("√%d/√%d ");
				else if((b2/b22!=1)&&(b2!=0)&&(b2%b22==0))
				printf("%10d√%d/√%d ",b2/b22,B11,B1);
				else
				printf("%10d√%d/%d√%d ",b2/gcd(b2,b22),B11,b22/gcd(b2,b22),B1);
				if(b3==0)
				printf("%10d\n",0);
				else if(b3/b33==1)
				printf("√%d/√%-10d\n");
				else if((b3/b33!=1)&&(b3!=0)&&(b3%b33==0))
				printf("%10d√%d/√%d\n",b3/b33,B11,B1);
				else
				printf("%10d√%d/%d√%d\n",b3/gcd(b3,b33),B11,b33/gcd(b3,b33),B1);
			}
		}//第二行单位化// 
	}
			if((c1==0)&&(c2==0)&&(c3==0)){
				printf("%10d %10d %10d",0,0,0);
			}
			else{
			C11=c11*c11*c22*c22*c33*c33;
			C1=c22*c22*(c1*c1*c33*c33+c3*c3*c11*c11)+c2*c2*c11*c11*c33*c33;
			if(C1%C11==0){//平方和为整数// 
				C=C1/C11;
				if(C==(int)sqrt(C)*(int)sqrt(C)){//平方和为完全平方数// 
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
			else{//平方和不是完全平方数// 
				if((c1%c11==0)&&(c1!=0))
				printf("%10d/√%d ",c1/c11,C);
				else if(c1==0)
				printf("%10d ",0);
				else
				printf("%10d/%d√%d ",c1/gcd(c1,c11),c11/gcd(c1,c11),C);
				if((c2%c22==0)&&(c2!=0))
				printf("%10d/√%d ",c2/c22,C);
				else if(c2==0)
				printf("%10d ",0);
				else
				printf("%10d/%d√%d ",c2/gcd(c2,c22),c22/gcd(c2,c22),C);
				if((c3%c33==0)&&(c3!=0))
				printf("%10d/√%d\n",c3/c33,C);
				else if(c3==0)
				printf("%10d\n",0);
				else
				printf("%10d/%d√%d\n",c3/gcd(c3,c33),c33/gcd(c3,c33),C);
			}
		}
		else{//平方和不是整数// 
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
				printf("%10d/√%d ",(c1*w)/c11,C1);
				else
				printf("%10d/%d√%d ",(c1*w)/gcd((c1*w),c11),c11/gcd((c1*w),c11),C1);
				if(c2==0)
				printf("%10d ",0);
				else if((c2!=0)&&((c2*w)%c22==0))
				printf("%10d/√%d ",(c2*w)/c22,C1);
				else
				printf("%10d/%d√%d ",(c2*w)/gcd((c2*w),c22),c22/gcd((c2*w),c22),C1);
				if(c3==0)
				printf("%10d\n",0);
				else if((c3!=0)&&((c3*w)%c33==0))
				printf("%10d/√%d\n",(c3*w)/c33,C1);
				else
				printf("%10d/%d√%d\n",(c3*w)/gcd((c3*w),c33),c33/gcd((c3*w),c33),C1);
			}
			else if((C11!=(int)sqrt(C11)*(int)sqrt(C11))&&(C1==(int)sqrt(C1)*(int)sqrt(C1))){
				if(c1==0)
				printf("%10d ",0);
				else
				printf("√%d %d/%d ",C11,c1/gcd(c1,(c11*r)),(c11*r)/gcd(c1,(c11*r)));
				if(c2==0)
				printf("%10d ",0);
				else
				printf("√%d %d/%d ",C11,c2/gcd(c2,(c22*r)),(c22*r)/gcd(c2,(c22*r)));
				if(c3==0)
				printf("%10d\n",0);
				else
				printf("√%d %d/%d\n",C11,c3/gcd(c3,(c33*r)),(c33*r)/gcd(c3,(c33*r)));
			}
			else{
				if(c1==0)
				printf("%10d ",0);
				else if(c1/c11==1)
				printf("√%d/√%d ");
				else if((c1/c11!=1)&&(c1!=0)&&(c1%c11==0))
				printf("%10d√%d/√%d ",c1/c11,C11,C1);
				else
				printf("%10d√%d/%d√%d ",c1/gcd(c1,c11),C11,c11/gcd(c1,c11),C1);
				if(c2==0)
				printf("%10d ",0);
				else if(c2/c22==1)
				printf("√%d/√%d ");
				else if((c2/c22!=1)&&(c2!=0)&&(c2%c22==0))
				printf("%10d√%d/√%d ",c2/c22,C11,C1);
				else
				printf("%10d√%d/%d√%d ",c2/gcd(c2,c22),C11,c22/gcd(c2,c22),C1);
				if(c3==0)
				printf("%10d\n",0);
				else if(c3/c33==1)
				printf("√%d/√%-10d\n");
				else if((c3/c33!=1)&&(c3!=0)&&(c3%c33==0))
				printf("%10d√%d/√%d\n",c3/c33,C11,C1);
				else
				printf("%10d√%d/%d√%d\n",c3/gcd(c3,c33),C11,c33/gcd(c3,c33),C1);
			}
		}
	}			
	}
}	
	}

}
}
