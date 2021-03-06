/*
//Chapter 1
//1.1 百钱白鸡问题
//描述：中国古代数学家张丘建在他的《算经》中提出了一个著名的“百钱白鸡问题”：
//	公鸡值五钱，一只母鸡值三钱，三只小鸡值一钱，
//	现在要用百钱买百鸡，请问公鸡、母鸡、小鸡各多少只？
//注意 rooster 和 hen 的最大数
#include <stdio.h>
#define TOTALNUM 100
#define TOTALMONEY 100
#define ROOSTERMONEY 5.0
#define HENMONEY 3.0
#define CHICKMONEY 1/3.0
int main()
{
	int roosterNum, henNum;

	for(roosterNum = 0;roosterNum < TOTALNUM/ROOSTERMONEY; roosterNum++)
		for(henNum = 0;henNum < TOTALNUM/HENMONEY; henNum++)
			if(roosterNum*ROOSTERMONEY + henNum*HENMONEY + (TOTALNUM - roosterNum - henNum)*CHICKMONEY == TOTALMONEY)
				printf("roosterNUM = %d\nhenNum = %d\nchickNum = %d\n\n",roosterNum, henNum, TOTALNUM - roosterNum - henNum);
	return 0;
}


//1.2 借书方案知多少
//描述：小明有 5 本新书，要借给 A、B、C 三位朋友，若每人每次只能借 1 本，则可以有多少种不同的借法？
//不是很清楚题意 5本都要借出去吗 每个人都必须要有一本吗
//参考答案：
#include <stdio.h>
#define NUM 5
int main()
{
	int a, b, c;
	int i = 0;
	for(a = 1; a <= NUM; a++)
		for(b = 1; b <= NUM; b++)
			for(c = 1; c <= NUM && a != b; c++)
				if(a != c && b != c)
				{
					printf("A:%2d B:%2d C:%2d	", a, b, c);
					i++;
					if(i % 4 == 0)
						printf("\n");
				}
	printf("%d methods in total\n", i);
	return 0;
}


//1.3 打鱼还是晒网
//描述：某人从1990年1月1日起开始 “三天打鱼两天晒网” 问这个人在以后的某一天中是打鱼还是晒网
//写过
//未考虑输入格式问题 仅从简处理
#include <stdio.h>
#include <string.h>
#define MAX 10
int main()
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char date[MAX];
	while(1)
	{
	int year, month, day;
	year = month = day = 0;
	gets(date);
	int i = 0;
	while(date[i] != '.')
		year = year*10 + date[i++] - '0';
	i++;
	while(date[i] != '.')
		month = month*10 + date[i++] - '0';
	i++;
	while(i < strlen(date))
		day = day*10 + date[i++] - '0';
	//printf("%d %d %d", year, month, day);
	int difYear, difMonth, difDay;
	difYear = year - 1990;
	difMonth = month - 1;
	difDay = day - 1;

	int numleap = (difYear+2) / 4; //闰年的次数 1992是闰年 1992 - 1990 = 2

	int nummonth = 0; //差几个月
	for(i = 0; i < difMonth; i++)
		nummonth += months[i];

	//共差几天
	int sum = difYear * 365 + numleap + nummonth + difDay;

	printf("difYear = %d\n, difMonth = %d\n, disDay = %d\n", difYear, difMonth, difDay);
	printf("numleap = %d\n, nummonth = %d\n, sum = %d\n", numleap, nummonth, sum);
	if(sum % 5  < 3)
		printf("In this day, he is fishing\n");
	else
		printf("In this day, he is dring net\n");
	}
	return 0;
}


//1.4 抓交通肇事犯
//描述：一辆卡车违反交通规则，撞人后逃跑，现场有三人目击该事件，但都没有记住车号，只记下一些特征
//  甲说：牌照的前两位数字是相同的
//  乙说：牌照的后两位是相同的，但与前两位不同
//  丙是数学家，他说：四位的车号刚好是一个整数的平方
//请求出车号
//注意车牌号可以首位为零
//如何确定平方根是整数
// 7744
#include <stdio.h>
#include <math.h>
int main()
{
	for(int a = 0; a < 10; a++)
		for(int b = 0; b < 10; b++)
			if(a != b)
				if(sqrt(a*1000 + a*100 + b*10 + b) - (int)(sqrt(a*1000 + a*100 + b*10 + b)) == 0)
					printf("It is %d\n", a*1000 + a*100 + b*10 + b);
	return 0;
}


//1.5兔子产子问题
//有一对兔子，从出生后的第 3 个月起每个月都生一对兔子， 小兔子长到第 3 个月后每个月又生一对兔子
//假设所有的兔子都不死，问 30 个月内每个月的兔子总数是多少？
//递归
//迭代
#include <stdio.h>
int recursion(int month)
{
	int num;
	if(month == 1 || month == 2)
		return 1;
	else
		num =  recursion(month - 1) + recursion(month - 2);
		return num;

}
int main()
{
	for(int i = 1;i <= 30; i++)
	{
		printf("%d:%-10d", i, recursion(i));
		if(i%5 == 0)
			printf("\n");
	}
	return 0;
}


//1.6牛顿迭代法求方程根
//描述：编写用牛顿迭代法求方程根的函数，方程为 ax^3 + bx^2 + cx + d = 0, 系数a, b, c, d由主函数输入， 求 x 在 1 附近的一个实根，由主函数输出
//公式为 x = x0 - f(x0)/f'(x0), 设迭代到 |x - x0| <= 10^(-5)时结束
#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c, d;
	float x, x0;
	scanf("%f %f %f %f",&a, &b, &c, &d);
	x0 = 20;
	x = x0 - (((a*x0+b)*x0+c)*x0+d) / ((3*a*x0+2*b)*x0+c);
	while(fabs(x - x0) > pow(10.0, -5))
	{
		x0 = x;
		x = x0 - (((a*x0+b)*x0+c)*x0+d) / ((3*a*x0+2*b)*x0+c);
	}
	printf("%f\n", x);
	return 0;
}


//1.7最佳存款方案
//描述：假设银行一年整存零取的月息为 0.63%。 现在某人手中有一笔钱， 他打算在今后的5年中的每年年底取出1000元 ， 到第 5 年时刚好取完
//请算出他存钱时应存入多少。
//本息和还是分开算
#include <stdio.h>
#include <math.h>
#define MONTH 5
#define MINOR 1000
#define RATE (0.63/100)
int main()
{
	float sum = 0;
	for(int i = 0; i < MONTH; i++)
	{
		sum += MINOR;
		sum /= pow((1+RATE), 12) ;
	}
	printf("1. %f\n", sum);
	for(int i = 0; i < MONTH; i++)
	{
		sum += MINOR;
		sum /= (1+ RATE *12) ;
	}
	printf("2. %f\n", sum);

	return 0;
}


//1.8冒泡排序
//对 N 个整数（数据由键盘输入）进行升序排列
//如 N 不固定， 可以用 malloc 分配
//呃我写的这个不是冒泡 是选择
#include <stdio.h>
#define N 15
int main()
{
	int array[] = {8, 7, 9, 5, 3, 10, 11, 20, 6, 11, 15, 21, 18, 22, 23};
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
			if(array[i] > array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
	for(int i = 0; i < N; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}


// answer
#include <stdio.h>
#define N 15
int main()
{
	int array[] = {8, 7, 9, 5, 3, 10, 11, 24, 6, 11, 15, 21, 18, 22, 23};
	for(int i = 1; i <= N - 1; i++)
		for(int j = 0; j < N - i; j++)
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	for(int i = 0; i < N; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}


//1.9折半查找
// N 个有序整数数列已放在一维数组中，利用二分查找法查找整数 m 在数组中的位置。若找到，则输出其下标值，反之输出 “Not be found!”
#include <stdio.h>
#define N 9
int main()
{
	int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int left, right, mid;

	int unkown;
	printf("input:");
	scanf("%d", &unkown);

	while(unkown != 100) //for test
	{
	left = 0;
	right = N - 1;
	mid = (left + right) / 2 + 1;
	while(left != mid)
	{
		if(unkown > array[mid])
		{
			left = mid;
			mid = (left + right) / 2 + 1; //这里不加一的话 取不到最后一个数

		}
		else if(unkown < array[mid])
		{
			right = mid;
			mid = (left + right) / 2;
		}
		else
			break;
	}
	if(unkown == array[mid])
		printf("%d\n", mid);
	else
		printf("Not be found!\n");

	printf("input:");
	scanf("%d", &unkown);
	}
	return 0;
	
}

//answer
#include <stdio.h>
#define N 9
int main()
{
	int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int left, right, mid;

	int unkown;
	printf("input:");
	scanf("%d", &unkown);

	while(unkown != 100) //for test
	{
		left = 0;
		right = N - 1;
		mid = (left + right) / 2;
		while(left <= right)
		{
			mid = (left + right) / 2;
			if(unkown > array[mid])
				left = mid + 1;
			else if(unkown < array[mid])
				right = mid - 1;
			else
				break;
		}
		if(unkown == array[mid])
			printf("%d\n", mid);
		else
			printf("Not be found!\n");

		printf("input:");
		scanf("%d", &unkown);
	}
	return 0;

}


//1.10 数制转换
//描述：给定一个 M 进制的数 x，实现对 x 向任意的一个非 M 进制的数的转换。
//M -> 10， 10 -> N
//处理比 10 大的进制又要判断字母 , 而且要用字符串来接收 以前在Mycalculator写过 不赘述
#include <stdio.h>
#include <math.h>

int main()
{
	int M, N, x;
	int Msum = 0; // M 进制的x 应表示为多大的 10进制数
	int Nsum = 0; // 10 进制的 Msum 表示为多大的 N 进制数
	int remainder = 0;
	int i = 0;
	printf("Input M:");
	scanf("%d", &M);
	printf("Input x:");
	scanf("%d", &x);
	printf("Input N:");
	scanf("%d", &N);

	do
	{
		remainder = x % 10;
		Msum += remainder * pow(M, i);
		i++;
		x /= 10;
	}while(x > 0);
	//printf("%d\n", Msum);

	i = 0;
	while(Msum > 0)
	{
		remainder = Msum % N;
		Nsum += remainder * pow(10, i);
		i++;
		Msum /= N;
	}
	printf("The answer is %d\n", Nsum);
	return 0;
}

//answer version



//Chapter 2 趣味数学问题
//2.1 个人所得税问题
//描述：编写一个计算个人所得税的程序，要求输入收入金额后，能够输出应缴的个人所得税，其征收办法为：
//起征点为 3500 元
//不超过 1500 元的部分， 征收 3%
//超过 1500 ~ 4500 元的部分，征收 10%
//超过 4500 ~ 9000 元的部分，征收 20%
//超过 9000 ~ 35000 元的部分，征收 25%
//超过 35000 ~ 55000 元的部分，征收 30%
//超过 55000 ~ 80000 元的部分，征收 35%
//超过 80000 元以上的，征收 45%
// 苛政猛于虎哉
// 一开始居然把税的计算方法搞错了
// 君子爱财 取之有道
#include <stdio.h>
#define LEVEL0 3500
#define Level0 0
#define RATE0 0.03

#define LEVEL1 1500
#define Level1 1
#define RATE1  0.1

#define LEVEL2 4500
#define Level2 2
#define RATE2  0.2

#define LEVEL3 9000
#define Level3 3
#define RATE3  0.25

#define LEVEL4 35000
#define Level4 4
#define RATE4  0.3

#define LEVEL5 55000
#define Level5 5
#define RATE5  0.35

#define LEVEL6 80000
#define Level6 6
#define RATE6  0.45

#define sumlevel1  (LEVEL1 * RATE0)
#define sumlevel2  (sumlevel1 + (LEVEL2 - LEVEL1) * RATE1)
#define sumlevel3  (sumlevel2 + (LEVEL3 - LEVEL2) * RATE2)
#define sumlevel4  (sumlevel3 + (LEVEL4 - LEVEL3) * RATE3)
#define sumlevel5  (sumlevel4 + (LEVEL5 - LEVEL4) * RATE4)
#define sumlevel6  (sumlevel5 + (LEVEL6 - LEVEL5) * RATE5)

int whichlevel(float income)
{
	if(income < 0)
		return -1;
	else if(income < LEVEL0)
		return Level0;
	else if(income < LEVEL2)
		return Level1;
	else if(income < LEVEL3)
		return Level2;
	else if(income < LEVEL4)
		return Level3;
	else if(income < LEVEL5)
		return Level4;
	else if(income < LEVEL6)
		return Level5;
	else
		return Level6;
}

int main()
{
	float income = 0;
	float tax = 0;

	while(1)
	{
		printf("Please input your income:");
		scanf("%f", &income);

		if(income > LEVEL0)
		{
			income -= 3500;
			switch (whichlevel(income))
			{
				case Level1: tax = sumlevel1 + (income - LEVEL1) * RATE1;
					break;
				case Level2: tax = sumlevel2 + (income - LEVEL2 - LEVEL1) * RATE2;
					break;
				case Level3: tax = sumlevel3 + (income - LEVEL3 - LEVEL2 - LEVEL1) * RATE3;
					break;
				case Level4: tax = sumlevel4 + (income - LEVEL4 - LEVEL3 - LEVEL2 - LEVEL1) * RATE4;
					break;
				case Level5: tax = sumlevel5 + (income - LEVEL5 - LEVEL4 - LEVEL3 - LEVEL2 - LEVEL1) * RATE5;
					break;
				case Level6: tax = sumlevel6 + (income - LEVEL6 - LEVEL5 - LEVEL4 - LEVEL3 - LEVEL2 - LEVEL1) * RATE6;
					break;
			}
		}

		printf("You should pay %f tax according to your income.\n", tax);
	}
	return 0;
}


//2.2 存钱问题
//描述：假设银行整存整取存款不同期限的月息利率为：
//0.63% 1年
//0.66% 2年
//0.69% 3年
//0.75% 5年
//0.84% 8年
//现已知某人手上有 2000 元，要求通过计算选择出一种存钱方案，使得存入 20 年后利息最多，假定银行对超出存款期限的那部分时间不付利息
//没思路哦
//是不是凑个整数年份就可以了
//请看答案
#include <stdio.h>
#include <math.h>
int main()
{
	int x1, x2, x3, x5, x8;
	int y1, y2, y3, y5, y8;
	double max = 0.0;
	double result;
	for(x8 = 0; x8 < 2; x8++)
		for(x5 = 0; x5 <= (20 - 8*x8)/5; x5++)
			for(x3 = 0; x3 <= (20 - 8*x8 - 5*x5)/3; x3++)
				for(x2 = 0; x2 <= (20 - 8*x8 - 5*x5 - 3*x3)/2; x2++)
				{
					x1 = 20 - 8*x8 - 5*x5 - 3*x3 - 2*x2; //存款期限限定条件

					//判断条件
					result = 2000.0 * pow((1+0.0063*12), x1)
									* pow((1+2*0.0066*12), x2)
									* pow((1+3*0.0069*12), x3)
									* pow((1+5*0.0075*12), x5)
									* pow((1+8*0.0084*12), x8);

					// y* 用于记录获利最多的存放方式
					if(result > max)
					{
						max = result;
						y1 = x1;
						y2 = x2;
						y3 = x3;
						y5 = x5;
						y8 = x8;
					}
				}

				printf("从 1 -》 8：%d, %d, %d, %d, %d\n本息合计共 %f 元", y1, y2, y3, y5, y8, result);
	return 0;
}


//2.3 分糖果
//描述：10个小孩围成一圈分糖果，老师分别分给 1 - 10号小孩  各 10, 2, 8, 22, 16, 4, 10, 6, 14, 20.
//然后所有的小孩同时将手中的糖分一半给右边的小孩，糖块数为奇数的人可向老师要一块
//问经过几次后大家手中的糖果一样多吗 各有多少块？
//还不知道会不会一样多
//largerthanlife
//17/03/2018
#include<stdio.h>
#define N 10

bool AllEqual(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		if(a[i] != a[0])
			return false;
	}
	return true;
}
int main()
{
	int children[N] = {10, 2, 8, 22, 16, 4, 10, 6, 14, 20};
	int temp[N] = {0};
	int right;
	while( !AllEqual(children, N))
	{
		for(int i = 0; i < N; i++)
		{
			if(i == N-1)
				right = 0;
			else
				right = i + 1;
				
			children[i] /= 2;
			temp[right] = children[i];
		}
		for(int i =0; i < N; i++)
		{
			children[i] += temp[i];
			if(children[i] % 2 == 1)
				children[i] += 1;
		}
	}	
	for(int i = 0; i < N; i++)
		printf("%d ", children[i]);
	printf("\n");
	return 0;
}


//2.4 三色球问题
//描述：一个口袋中放有12个球，已知其中三个是红的，三个是白的，六个是黑的，现从中任意取八个
//问有多少种可能的搭配？
//largerthanlife
//18/03/2018
#include<stdio.h>
#define REDNUM 3
#define WHITENUM 3
#define BLACKNUM 6
int main()
{
	for(int red = 0; red <= REDNUM ; red++)
		for(int white = 0; white <= WHITENUM ; white++)
			for(int black = 0; black <= BLACKNUM ; black++)
			{
				if(red + white + black == 8)
					printf("%d %d %d\n", red, white, black);
			}
	return 0;
}


//2.5出售金鱼
//描述：小明将养的一缸金鱼分 5 次出售
//  第一次卖出全部的一半加1/2条
//  第二次卖出余下的三分之一加1/3条
//  第三次卖出余下的四分之一加1/4条
//  第四次卖出余下的五分之一加1/5条
//  最后卖出剩余的11条
//  原来有多少条
//largerthanlife
//21/03/2018
#include<iostream>
#define N 5
#define LEFT 11
int main()
{
	int sum = LEFT;
	for(int i = N; i > 1; i--)
		sum = (sum + 1.0/i) * i / (i-1);
	printf("sum = %d\n", sum);

	return 0;
}


//2.6 求车速
//一辆以固定速度行驶的汽车，司机在上午 10 点看到里程表上的读数是一个对称数，为 95859，
//两小时后里程表上出现了一个新的对称数，该数仍为五位数，
//问该车的速度是多少，新的对称数是多少
//95959?????????
//largerthanlife
//22/03/2018
#include<stdio.h>
int main()
{
	int num[5] = {0};
	for(int i = 95859; i < 100000; i++)
	{
		num[4] = (i % 10) / 1;
		num[3] = (i % 100) / 10;
		num[2] = (i % 1000) / 100;
		num[1] = (i % 10000) / 1000;
		num[0] = (i % 100000) / 10000;
		if(num[0] == num[4] && num[3] == num[1])
		{
			printf("new numer:");
			for(int j = 0; j < 5; j++)
				printf("%d",num[j]);
			printf("\n");
			printf("its speed is %f km/h\n", (i - 95859)/ 2.0);
		}
	}
	return 0;
}


//2.7 爱因斯坦的数学题
//描述：爱因斯坦出了一道这样的数学题
// 有一条长阶梯，若每步跨 2 阶，则最后剩一阶，
// 若每步跨 3 阶，则最后剩 2 阶，
// 若每步跨 5 阶，则最后剩 4 阶，
// 若每步跨 6 阶，则最后剩 5 阶。
// 只有每次跨 7 阶， 最后才正好一阶不剩
// 请问在 1~N 内， 有多少个数能满足？
//largerthanlife
//23/03/2018
#include<stdio.h>
#define N 600
int main()
{
	int sum = 0;
	int i = 0;
	for(sum = 1; sum < N; sum+=2) // step = 2,肯定是奇数
		if( (sum % 2 == 1) && (sum % 3 == 2) && (sum % 5 == 4) && (sum % 6 == 5) && (sum % 7 == 0))
		{
			i++;
			printf("%d : %d\n", i, sum);
		}
	printf("between 1 ~ %d, %d number(s) is qualified\n", N, i);
	return 0;
}


// 2.8猜牌术
// 描述：魔术师利用一副牌中的 13 张黑桃，预先将它们排好后迭在一起，并使牌面朝下
// 然后他对观众说 我不看牌，只要数数就可以猜到每张牌是什么，我大声数数，你们听，不信？
// 你们就看，魔术师将最上面的那张牌数为 1 ， 把它翻过来正好是黑桃 A ，他将黑桃 A 放在桌子上
// 然后按顺序从上到下数手中的余牌，第二次数 1 、 2，将第一张牌放在这迭牌的下面，将第二张牌翻过来，正好是黑桃 2 ，
// 也将它放在桌子上， 第三次数 1 2 3 ，将前面两张依次放在这迭牌的下面，再翻第三张正好是黑桃 3，
// 这样依次进行， 将 13 张牌全部翻出来， 准确无误，
// 问魔术师手中的牌原始次序是怎样安排的？
// WTF is this



// 2.9 舍罕王的失算
//描述：国际象棋盘 64x64格，第一格一粒，之后 2 倍增长，依次放完
//共需多少
//largerthanlife
//24/03/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 64
int main()
{
	double sum = 0;
	for(int i = 0; i < N; i++)
		sum += pow(2,i);
	printf("%.0lf\n", sum);
	return 0;
}


//2.10 马克思手稿中的数学题
//描述：马克思手稿中有一道趣味数学题：
//有 30 个人，其中有男人、女人和小孩，他们在同一家饭店吃饭 总共花了50先令
//已知每个男人需要 3 先令，女人 2 ，小孩 1,
//请求出男人女人小孩各有几人
//largerthanlife
//24/03/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int numman, numwoman, numchild;
	for(numman = 1; numman <= 17; numman ++)
		for(numwoman = 1; numwoman <= 25; numwoman++)
			{
				numchild = 30 - numman - numwoman;
				if(numman * 3 + numwoman * 2 + numchild == 50)
					printf("man: %d\nwoman: %d\nchild: %d\n", numman, numwoman, numchild);
			}
	return 0;
}


//2.11换分币
//描述：将 5 元的人民币兑换成1 元、 5 角和 1 角的硬币，共有多少种不同的兑换方法
//题意不清，是否至少各一张？
//anyway it's easy
//largerthanlife
//24/03/2018
 #include <stdio.h>
#include <stdlib.h>
int main()
{
	int num1yuan;
	int num5jiao;
	int num1jiao;
	int count = 0;
	for(num1yuan = 0; num1yuan <= 5; num1yuan ++)
		for(num5jiao = 0; num5jiao <= 10; num5jiao++)
			for(num1jiao = 0; num1jiao <= 50; num1jiao++)
				if(num1yuan * 10 + num5jiao * 5 + num1jiao == 50)
				{
					count++;
					printf("%d:\n1 yuan: %d\n5 jiao: %d\n1 jiao: %d\n", count, num1yuan, num5jiao, num1jiao);

				}
	return 0;
}


//3.1完数
//描述：求某一范围内完数的个数
//如果一个数等于它的因子之和， 则称该数为“完数”
//范围是什么
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	bool find(int);
	int num;
	scanf("%d", &num);
	for(int i = 0; i <= num; i++)
		if(find(i))
			printf("%d is qualified\n", i);
	return 0;
}

bool find(int num)
{
	int sum = 1; // 1 肯定是因数之一
	for(int i = 2; i < num/2 + 1; i++) // i 直接从2开始 效率高啊  上限到 num 的一半就行
		if(num % i == 0)
			sum += i;
	return sum == num;
}


//3.2亲密数
//描述：如果整数 A 的全部因子（包括1，不包括 A 本身），之和等于 B，且 整数 B 的全部因子之和等于 A ，则将 A B 称为亲密数，求 3000 以内的全部亲密数
//会有这种事啊
//largerthanlife
//30/03/2018
//警告：这程序要跑将近一分钟
#include <stdio.h>
#include <stdlib.h>
#define MAX 3000
int main()
{
	bool find(int, int);
	for(int i = 1; i < MAX; i++)
		for(int j = 1; j < MAX; j++)
			if(find(i, j) && find(j, i))
				printf("%d and %d is qualified\n", i, j);
	return 0;
}

bool find(int num, int test)
{
	int sum = 1; // 1 肯定是因数之一
	for(int i = 2; i < num/2 + 1; i++) // i 直接从2开始 效率高啊  上限到 num 的一半就行
		if(num % i == 0)
			sum += i;
	return sum == test;
}


//3.3自守数
//描述：自守数是指一个数的平方的尾数等于该数自身的自然数
//如： 5^2 = 25, 25^2 = 625, 76^2 = 5776, 9376^2 = 87909376
// 求 100000 以内的自守数
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000
int main()
{
	bool istail(long, int);
	for(int i = 0; i < MAX; i++)
		if(istail(i*i, i))
			printf("%d is qualified\n", i);
	return 0;
}

int count(long num)
{
	int i;
	for(i = 1; num; i++)
		num /= pow(10, i);
	return i;
}

bool istail(long num, int find)
{
	int bit = count(num);
	for(; bit; bit--, num %= (int)(pow(10,bit)))
		if(num == find)
			return true;
	return false;
}


//answer version
//largerthanlife
//30/03/2018
// 6哦朋友
#include <stdio.h>
#include <stdlib.h>
int main()
{
	long mul, number, k, a, b;
	for(number = 0; number < 100000; number++)
	{
		for(mul=number, k = 1;(mul/=10)>0; k*=10);

		a = k*10;
		mul = 0;
		b = 10;
		while(k > 0)
		{
			mul = (mul+(number%(k*10))*(number%b - number%(b/10))) % a;
			k /= 10;
			b *= 10;
		}
		if(number == mul)
			printf("%ld	", number);
	}
	return 0;
}


//3.4回文数
//打印所有不超过 n（ n<256 ），的其平方具有对称性质的数
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 256
int main()
{
	bool find(int);
	for(int i = 1; i < MAX; i++)
		if(find(i*i))
			printf("%d is qualified(%d * %d = %d)\n", i, i, i, i*i);
	return 0;
}

bool find(int num)
{
	bool countbit(int);
	bool judge(int*, int length);
	
	int bit = countbit(num);
	//int *s = (int*)malloc(bit);
	int s[6] = {0};
	for(int i = bit - 1; i >= 0; num %= (int)pow(10, i), i--)
	{
		s[i] = num / (int)pow(10, i);
	}
	return judge(s, bit);
}

int countbit(int num)
{
	int i = 1;
	for(; num / 10; i++, num /= 10);
	return i;
}

bool judge(int *s , int length)
{
	for(int i = 0; i < length/2; i++)
		if(s[i] != s[length -1 -i])
		{
			return false;
		}
	return true;
}


//3.５　水仙花数
//描述：输出所有的水仙花数， 即指一个三位数 其各位数字的立方和等于该数本身
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	for(int i = 100; i < 999; i++)
	{
		int num = i;
		int a = num/100;
		num %= 100;
		int b = num/10;
		num %= 10;
		int c = num;
		if(a*a*a + b*b*b + c*c*c == i)
			printf("%d is qualified\n", i);
	}
	return 0;
}


//3.6 阿姆斯特朗数
//描述：如果一个整数等于其各个数字的立方和，则为阿姆斯特朗数
//求 1000 以内的 所有阿姆斯特朗数
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000
int main()
{
	int sum = 0;
	for(int i = 0; i < 1000; i++)
	{
		for(int num = i; num; num /= 10)
		{
			sum += pow(num%10, 3);
		}
		if(sum == i)
			printf("%d is qualified\n", i);
		sum = 0;
	}
	return 0;
}


//3.7 高次方数的尾数
//描述：求 13 的 13次方的最后三位数
//666
//largerthanlife
//01/04/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 13
#define N 13
#define TAIL 3
int main()
{
	int result = 1;
	for(int i = 0; i < N; i++)
		result = result * NUM % (int)pow(10, TAIL);
	printf("%d\n", result);
	return 0;
}

//answer version
//largerthanlife
//01/04/2018
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int i, x, y, last = 1;
//	printf("Input x and y:\n");
//	scanf("%d %d", &x, &y);
//	for(int i = 1; i <= y; i++)
//		last = last * x % 1000;
//	printf("The last three digit is:%d", last);
//	return 0;
//}



//3.8 黑洞数
//描述：黑洞数又称陷阱数，任何一个数字不全相同的整数， 经有限次重排求差的操作，总会得到某一个或某一些数，这些数即为黑洞数，重排操作是将组成一个数的各位数字重排得到的最大数减去最小数
//例如 207，： 702 - 027 = 675 …… 963 - 369 = 594 954 - 459 = 495
//再用 208 算一次， 也停止到 495，所以 495 是三位黑洞数
//有点不会做诶
//掉以轻心了
//answer version
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>

int maxof3(int a, int b, int c)
{
	int t;
	if(a<b)
	{
		t = a;
		a = b;
		b = t;
	}
	if(a<c)
	{
		t = a;
		a = c;
		c = t;
	}
	if(b<c)
	{
		t = b;
		b = c;
		c = t;
	}
	return a*100 + b * 10 + c;
}

int minof3(int a, int b, int c)
{
	int t;
	if(a<b)
	{
		t = a;
		a = b;
		b = t;
	}
	if(a<c)
	{
		t = a;
		a = c;
		c = t;
	}
	if(b<c)
	{
		t = b;
		b = c;
		c = t;
	}
	return c*100 + b * 10 + a;
}
int main()
{
	int i, k;
	int hun, oct, data, max, min, j, h;
	printf("enter a three-bits-number:");
	scanf("%d", &i);
	hun = i/100;
	oct = i%100/10;
	data = i%10;
	max = maxof3(hun, oct, data);
	min = minof3(hun, oct, data);
	j = max-min;
	for(k = 0;;k++)
	{
		h = j;
		hun = j/100;
		oct = j%100/10;
		data = j%10;
		max = maxof3(hun, oct, data);
		min = minof3(hun, oct, data);
		j = max - min;
		if(j == h)
		{
			printf("%d\n",j);
			break;
		}
	}
	return 0;
}


//3.9勾股数
//描述：求100以内所有的勾股数
//所谓勾股数，是指能够构成直角三角形三条边的三个正整数
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	for(int i = 1; i <= 100;i++)
		for(int j = 1; j <= 100; j++)
			for(int k = 1; k <= 100; k++)
				if(i*i + j*j == k*k)
					printf("%d %d %d\n", i, j, k); 
	return 0;
}

//3.10不重复的3位数
//描述：用1、 2、 3、 4共4个数字能组成多少个互不相同且无重复数字的三位数，分别是多少
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	for(int i = 1; i <= 4;i++)
		for(int j = 1; j <=4; j++)
			for(int k = 1; k <= 4; k++)
				if(i!=j && i!=k && j!=k)
					printf("%d%d%d\n", i, j, k);

	return 0;
}



//4.1最大公约数
//描述：求任意两个正整数的最大公约数(GCD)
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;
	int temp;
	int t;
	while(1)
{
	printf("input a and b:");
	scanf("%d %d", &a, &b);
	if(a <= b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while(a != b)
	{
		temp = a - b;
		if(b <= temp)
		{
			t = b;
			b = temp;
			temp = t;
		}
		a = b;
		b = temp;
	}

	printf("its %d\n", a);
}
	return 0;
}


//4.2 最小公倍数
//描述：求任意两个正整数的最小公倍数(LCM)
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
		int a, b;
		int n,m;
		int temp;
		int t;
		while(1)
		{
			printf("input a and b:");
			scanf("%d %d", &a, &b);
			n = a;
			m = b;
			if(a <= b)
			{
				temp = a;
				a = b;
				b = temp;
			}
			while(a != b)
			{
				temp = a - b;
				if(b <= temp)
				{
					t = b;
					b = temp;
					temp = t;
				}
				a = b;
				b = temp;
		}

		printf("its %d\n", n*m/a);
	}
	return 0;
}


//4.3歌星大奖赛
//描述：在歌星大奖赛中，有 10 个评委为参赛的选手打分，分数为 1~100 分，选手最后得分为去掉一个最高分和一个最低分后其余8个分数的平均值，请编写一个程序实现
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{

	float scores[N];
	float temp;
	for(int i = 0; i < N; i++)
		scanf("%f", &scores[i]);
	getchar();
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
			if(scores[j] < scores[i])
			{
				temp = scores[j];
				scores[j] = scores[i];
				scores[i] = temp;
			}
	float sum = 0;
	for(int i = 1; i < N-1; i++)
		sum += scores[i];
	printf("average = %f\n", sum/(N - 2));

	return 0;
}


//4.4将真分数分解为埃及分数
//描述：先输入一个真分数，请讲该分数分解为埃及分数（分子为 1 的分数）
//answer version
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	long int a, b, c;
	scanf("%ld/%ld", &a, &b);
	while(1)
	{
		if(b%a)
			c = b/a+1;
		else
		{
			c=b/a;
			a=1;
		}
		if(a==1)
		{
			printf("1/%ld\n", c);
			break;
		}
		else
			printf("1/%ld + ", c);
		a = a*c - b;
		b = b *c;
		if(a == 3 && b%2 == 0)
		{
			printf("1/%ld + 1/%ld\n", b/2, b);
			break;
		}
	}
	return 0;
}


//4.5列出真分数序列
//描述：按递增顺序依次列出所有分母为40，分子小于40的最简分数
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, temp, t;
	for(int i = 1; i < 40; i++)
	{
		a = i;
		b = 40;
		if(a <= b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		while(a != b)
		{
			temp = a - b;
			if(b <= temp)
			{
				t = b;
				b = temp;
				temp = t;
			}
			a = b;
			b = temp;
		}
		if(a == 1 )
			printf("%d/40\n", i);
	}
	return 0;
}

//4.6多项式之和
//描述：计算下列多项式的值
// s = 1 + 1/(1*2) + 1/(1*2*3)+ ... + 1/(1*2*3*...n)
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	float sum = 0;
	float temp = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
			temp *= j;
		sum += 1/temp;
		temp = 1;
	}
	printf("%f\n", sum);

	return 0;
}


//4.7分数比较
//比较两个分数的大小
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n1, a;
	int n2, b;
	int temp,t;
	printf("first :");
	scanf("%d/%d", &n1, &a);
	printf("second:");
	scanf("%d/%d", &n2, &b);

			int n = a;
			int m = b;
			if(a <= b)
			{
				temp = a;
				a = b;
				b = temp;
			}
			while(a != b)
			{
				temp = a - b;
				if(b <= temp)
				{
					t = b;
					b = temp;
					temp = t;
				}
				a = b;
				b = temp;
			}
	if(n1*(m/a) > n2*(n/a))
		printf("first is lager\n");
	else if(n1*(m/a) < n2*(n/a))
		printf("second is lager\n");
	else
		printf("ther are equal\n");
	return 0;
}


//4.8计算分数精确值
//使用数组精确计算 M/N (0<M<N<=100) 的值，加入 M/N 是无限循环小数，则计算并输出它的第一循环节，同时要求输出循环节的起止位置
//不会做
//answer vesion
//largerthanlife
//05/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m, n, i, j;
	int remainder[101] = {0},quotient[101] = {0};
	scanf("%d/%d", &m, &n);
	printf("0.");
	for(i = 1; i <= 100; i++)
	{
		remainder[m] = i;   //m：得到的余数， ramainder[m] ：该余数对应的商的位数
		m *= 10;
		quotient[i] = m/n;
		m = m % n;
		if(m == 0)
		{
			for(j = 1; j <= i; j++)
				printf("%d", quotient[j]);
				break;
		}
		if(remainder[m] != 0)
		{
			for(j = 1; j <= i; j++)
				printf("%d", quotient[j]);
			printf("\n\tand it is a infinite cyclic fraction from %d\n", remainder[m]);
			printf("\tdigit to %d digit after decimal point.\n", i);
			break;
		}
	}

	return 0;
}


//5.1素数
//求给定范围 start~end 之间的所有素数
//largerthanlife
//06/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	bool isprime(int);
	int start, end;
	scanf("%d %d", &start, &end);
	for(int num = start; num <= end; num++)
		if(isprime(num))
			printf("%d is prime\n", num);
	return 0;
}

bool isprime(int num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}

//扩展上题 找出最小的连续10个合数
//largerthanlife
//06/04/2018
#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
	bool isprime(int);
	int flag = 1, i, j;
	for(i = 1; flag ; i++)
	{
		for(j = i, flag = N; j < i + N; j++)
			if(!isprime(j))
				flag--;
	}
	printf("%d - %d\n", i, i+10);
	return 0;
}

bool isprime(int num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}


//5.2 哥德巴赫猜想
//描述： 验证：2000 以内的不小于 4 的正偶数都能够分解为两个素数之和
//largerthanlife
//06/04/2018
#include <stdio.h>
#include <stdlib.h>
#define N 2000
bool isprime(int num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}

int main()
{
	int a, b;
	for(int i = 4; i < N; i+=2)
		for(a = 1; a < i; a++)
			for(b = 1; b < i; b++)
				if(isprime(a) && isprime(b) && (a+b)==i)
					printf("%d + %d = %d\n", a, b, i);
	return 0;
}


//5.3要发就发
//描述：1898-要发就发 请将不超过1993的所有素数从小到大排成第一行，第二行上的每个数都等于它上面相邻两个素数之差
//编程求出：第二行中是否存在若干个连续的整数它们的和恰好为 1898？如果存在的话，又有几种情况？
//你直接问 1-(1993-1898) 和 1898-1993 有没有两个素数的差是1898就好了
//largerthanlife
//06/04/2018
#include <stdio.h>
#include <stdlib.h>
bool isprime(int num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}
int main()
{
	for(int i = 0; i <= 1993-1898; i++)
		if(isprime(i) && isprime(i+1898))
			printf("%d is quallified\n", i);
	
	return 0;
}


//5.4 可逆素数
//描述：请从小到大输出所有 4 位数的可逆素数
//可逆素数， 一个素数将其各位数字的顺序倒过来构成的反序数也是素数
//largerthanlife
//06/04/2018
#include <stdio.h>
#include <stdlib.h>
bool isprime(int num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}
int main()
{
	int temp[4] = {0};
	int num = 0;
	for(int i = 1000; i < 10000; i++)
	{
		num = 0;
		temp[0] = i % 10;
		temp[1] = (i/10) % 10;
		temp[2] = (i/100) % 10;
		temp[3] = i/1000;
		num = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
		//printf("%d and %d\n", i, num);
		if(isprime(i) && isprime(num))
			printf("%d is qualified\n", i);
	}

	return 0;
}


//5.5 回文素数
//描述：回文 且 素数 ， 1000以内
//largerthanlife
//07/04/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
bool isprime(int num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}

int bit(int num)
{
	int i= 0;
	while(num/(int)pow(10,  ++i));
	return i;
}

int main()
{
	int temp[4];
	for(int i = 0; i < N; i++)
	{
		int num = i, j;
		int length =bit(i);
		for(j = 0; j < length; j++, num /= 10)
			temp[j] = num%10;
		for(j = 0; j <= length/2; j++)
			if(temp[j] != temp[length -1 - j])
				break;
		if(j == length/2 + 1  && isprime(i))
			printf("%d is qualified\n", i);
	}
	return 0;
}


//5.6 孪生素数
//描述： 间隔为 2 的两个相邻素数， 3~1000以内
//largerthanlife
//07/04/2018
#include <stdio.h>
#include <stdlib.h>
bool isprime(int num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}
int main()
{
	for(int i = 3; i <= 1000; i++)
		if(isprime(i) && isprime(i+2))
			printf("(%d , %d)is qualified\n", i, i+2);
	return 0;
}


//5.7 梅森素数
//描述：梅森数指的是形如 2^n - 1的正整数， 其中 n 是素数，如果一个梅森数是素数，则称其为梅森素数
//求出指数 n < 20 的所有梅森素数
//largerthanlife
//07/04/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
bool isprime(long num)
{
	for(int i = 2; i <= num/2; i++)
		if(num % i == 0)
			return false;
	return true;
}
int main()
{
	long num = 0;
	for(int i = 0; i < 20; i++)
	{
			num = pow(2, i) - 1;
			if(isprime(i) && isprime(num))
				printf("%ld is qualified\n", num);
	}
	return 0;
}


//6.1 谁家孩子跑的最慢
//描述：假设有张王李三家，每家都有三个孩子，某一天，这三家的9个孩子一起比赛短跑
//规定不考虑年龄大小，第一名得 9 分， 第二名 8 分，以此类推
//结束后统计分数发现三家孩子的总分是相同的，限定这9个孩子不存在并列的情况，且同一家的孩子不会获得相连的名次
//现已知第一名是李家的孩子， 第二名是王家的孩子， 编程求出最后一名是哪家的孩子
//mmp这是要怎样 浪费时间
//largerthanlife
//08/04/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	bool flag = true;
	int num[9] = {9, 0, 0, 8, 0, 0, 0, 0, 0};
	for(num[1] = 1; num[1] < 8; num[1]++,flag = true)
		for(num[2] = 1; num[2] < 8 && flag; num[2]++)
			for(num[4] = 1; num[4]< 8 && flag;num[4]++)
				for(num[5] = 1; num[5] < 8 && flag ; num[5]++)
					for(num[6] = 1; num[6] < 8 && flag ; num[6]++)
						for(num[7] = 1; num[7] < 8 && flag ; num[7]++)
							for(num[8] = 1; num[8] < 8 && flag ; num[8]++)
								if( abs(num[0]-num[1]) > 1 && abs(num[0] - num[2]) > 1 && abs(num[1]-num[2]) > 1
								&& abs(num[3]- num[4]) > 1 && abs(num[3] - num[5]) > 1 && abs(num[4] - num[5]) > 1
								&& abs(num[6]- num[7])  > 1 && abs(num[6] - num[8]) > 1 && abs(num[7] - num[8]) > 1
								&& (num[0]+num[1]+num[2]) == (num[3]+num[4]+num[5])  && (num[0] + num[1] + num[2]) == (num[6]+num[7]+num[8]))
								{
									for(int i = 0; i < 8; i++)
										for(int j = i+1; j < 9; j++)
											if(num[i] == num[j])
												flag = false;

									if(flag)
									{
										printf("a1 = %d\ta2 = %d\ta3 = %d\nb1 = %d\tb2 = %d\tb3 = %d\nc1 = %d\tc2 = %d\tc3 = %d\n\n", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8]);
										flag = false;
									}

								
								}
	return 0;
}

//6.2 新郎和新娘
//描述：有三对情侣结婚， 假设 3 个新郎为 A B C， 3 个新娘为X Y Z，
// 有参加婚礼的人搞不清谁和谁结婚，所以去询问了这 6 位新人中的 3 位，得到的回答如下
// 新郎 A 说他要和新娘 X 结婚， 新娘 X 说她的未婚夫是新郎 C ，而 C说他要和新娘 Z 结婚，
//听到这样的回答后，提问者知道他们都是在开玩笑， 说的都是假话， 但他仍搞不清谁和谁结婚，
//请编程求出到底哪位新郎和哪位新娘结婚
//largerthanlife
//09/04/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int A, B, C;
	int X, Y, Z;
	for(A = 0; A < 3; A++)
		for(B = 0; B < 3;B++)
			for(C = 0; C<3; C++)
				for(X = 0; X < 3; X++)
					for(Y = 0; Y < 3; Y++)
						for(Z = 0; Z<3; Z++)
							if(A != X && X != C && C != Z && A!=B && A!= C && X!=Y && X!=Z && X+Y+Z+A+B+C == 6)
							{
								printf("%d %d %d %d %d %d\n", A, B, C, X, Y, Z);
							}

	return 0;
}


//提问者编程结束后发现，婚礼结束了
//可怕的是，他们其实说的都是真话


//answer version
#include <stdio.h>
int main()
{
	char x, y, z;
	for(x = 'A'; x <= 'C'; x++)
		for(y = 'A'; y <= 'C'; y++)
			for(z = 'A'; z <= 'C'; z++)
				if(x != 'A' && x != 'C' && z != 'C' && x != y && x != z && y != z)
				{
					printf("新娘 X 与 新郎 %c 结婚\n", x);
					printf("新娘 Y 与 新郎 %c 结婚\n", y);
					printf("新娘 Z 与 新郎 %c 结婚\n", z);
				}

	return 0;
}


//6.3谁在说谎
//描述：现有张三、李四、王五三个人，张三说李四在说谎，李四说王五在说谎，王五说张三和李四两个人都在说谎
//编程求出谁真谁假
//largerthanlife
//11/04/2018
//好难哦
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int zhang, li, wang;
	for(zhang = 0;  zhang <= 1; zhang++)
		for(li = 0; li <= 1; li++)
			for(wang = 0; wang <= 1; wang++)
				if( (zhang&&!li || !zhang&&li) && (li&&!wang || !li&&wang) && (wang&&zhang == 0 && li ==0 || !zhang&&(li+wang)!= 0 ))
				{
					printf("Zhang is %s.\n",zhang?"True":"False");
					printf("Li is %s.\n", li?"True":"False");
					printf("Wang is %s.\n", wang?"True":"False");
				}
	return 0;
}


//6.4谁是窃贼
//描述：警察审问 4 名窃贼嫌疑犯，现在已知，这 4 人当中仅有一名是窃贼， 还知道 4 个人中的每个人要么是诚实的，要么总是说谎
//甲："乙没有偷，是丁偷的。"
//乙说：“我没有偷，是丙偷的。”
//丙说：“甲没有偷，是乙偷的。”
//丁说：“我没有偷。”
//请根据这 4 个人的回答判断谁是窃贼
//largerthanlife
//20/04/2018
//不会 完全不会
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num = 0;
	int a, b, c, d;
	int atemp, btemp, ctemp, dtemp;
	for(a = 0,b = 0, c = 0, d = 0; a <= 1; a++, b++, c++, d++)
	{
		//atemp = a; btemp = b; ctemp = c; dtemp = d;
		if(a == 0)
		{
			btemp = 1;
			dtemp = 0;
		}
		else
		{
			btemp = 0;
			dtemp = 1;
		}
		if(b == 0)
		{
			btemp = 1;
			ctemp = 0;
		}
		else
		{
			btemp = 0;
			ctemp = 1;
		}
		if(c == 0)
		{
			atemp = 1;
			btemp = 0;
		}
		else
		{
			atemp = 0;
			btemp = 1;
		}
		if(d == 0)
		{
			dtemp = 1;
		}
		else
		{
			dtemp = 0;
		}
		if(atemp + btemp + ctemp + dtemp == 1)
		{
			if(atemp)
				printf("a is the one\n");
			if(btemp)
				printf("b is the one\n");
			if(ctemp)
				printf("c is the one\n");
			if(dtemp)
				printf("d is the one\n");
			break;
		}
	}


	return 0;
}


//answer version
//依然看不懂
#include <stdio.h>
int main()
{
	int i,  A = 1, B = 0, C = 0, D = 0;
	for(i = 1; i <= 4; i ++)
		if(B+D == 1 && B+C == 1 && A+B == 1)  // 测试甲乙丙丁谁是窃贼，符合该条件的即为窃贼 ？？？？？？？？？？？？？？？？？？？？？？
			break;
		else
		{
			if(i == 1)
			{
				A = 0; B = 1;
			}
			if(i == 2)
			{
				B = 0; C = 1;
			}
			if(i == 3)
			{
				C = 0; D = 1;
			}
		}
	if(i == 1)
		printf("a is the one\n");
	if(i == 2)
		printf("b is the one\n");
	if(i == 3)
		printf("c is the one\n");
	if(i == 4)
		printf("d is the one\n");
}


//6.5旅客国籍
//描述：在一个旅馆中住着 6 个不同国籍的人，他们分别来自美国、德国、英国、法国、俄罗斯和意大利这几个国家
//他们分别叫A B C D E F 现已知
//1. A 和 美国人是医生
//2. E 和 俄罗斯人是教师
//3. C 和 德国人是技师
//4. B 和 F 曾经当过兵，而德国人从未参过军
//5. 法国人比 A 年龄大， 意大利人比 C 年龄大
//6. B 同美国人下周要去西安旅行， 而 C 同法国人下周要去杭州度假
//现要求根据上述已知条件， 求出 A B C D E F 各是哪国人
//WTF……
//largerthanlife
//23/04/2018
//113种
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMERICAN 0
#define GERMAN 1
#define ENGLISH 2
#define FRENCH 3
#define RUSSIA 4
#define ITALIAN 5
//enum nameindex = {AMERICAN, GERMAN, ENGLISH, FRENCH, RUSSIA, ITALIAN};
const char *(namelist[6]) = {"American", "German", "English", "French", "Russia", "Italian"};
bool checklist(int A, int B, int C, int D, int E, int F)
{
	return A != AMERICAN && A != FRENCH
		&& B != AMERICAN && B != GERMAN
		&& C != GERMAN && C != FRENCH && C != ITALIAN
		&& E != RUSSIA
		&& F != GERMAN
		;
}

bool unequal(int A, int B, int C, int D, int E, int F)
{
	return A !=B && A != C && A != D && A != E && A != F
		&& B != C && B != D && B != E && B != F
		&& C != D && C != E && C != F
		&& D != E && D != F
		&& E != F
		;
}

int main()
{
	bool isfind = false;
	void printresult(int A, int B, int C, int D, int E, int F);
	bool checklist(int A, int B, int C, int D, int E, int F);
	bool check(int num);
	int A, B, C, D, E, F;
	for(A = AMERICAN; A <= ITALIAN; A ++)
		for(B = AMERICAN; B <= ITALIAN && !isfind ; B ++)
			for(C = AMERICAN; C <= ITALIAN && !isfind; C ++)
				for(D = AMERICAN; D <= ITALIAN && !isfind; D ++)
					for(E = AMERICAN; E <= ITALIAN && !isfind; E ++)
						for(F = AMERICAN; F <= ITALIAN && !isfind; F ++)
							if(checklist(A, B, C, D, E, F) && unequal(A, B, C, D, E, F))
							{
								printresult(A, B, C, D, E, F);
								isfind = true;
							}

	return 0;
}

void printresult(int A, int B, int C, int D, int E, int F)
{
	static int i = 1;
	printf("%d:******************\n", i++);
	printf("A is %s\n", namelist[A]);
	printf("B is %s\n", namelist[B]);
	printf("C is %s\n", namelist[C]);
	printf("D is %s\n", namelist[D]);
	printf("E is %s\n", namelist[E]);
	printf("F is %s\n", namelist[F]);
}
*/

//answer version
//23/04/2018
#include <stdio.h>
#include <stdlib.h>
char *m[7] = {" ", "American", "England", "French", "German", "Italy", "Russia"};
int main()
{
	int a[7][7], i, j, t, e, x, y;
	for(i = 0; i < 7; i++)		//初始化条件矩阵
		for(j = 0; j < 7; j++)		//行为人，列为国家，元素的值表示某人是该国人
			a[i][j] = j;
	for(i = 1; i < 7; i++)
		a[0][i] = 1;
	a[1][1] = a[2][1] = a[3][1] = a[5][1] = 0;
	a[1][3] = a[2][3] = a[3][3] = 0;
	a[1][4] = a[2][4] = a[3][4] = a[5][4] = a[6][4] = 0;
	a[3][5] = 0;
	a[1][6] = a[3][6] = a[5][6] = 0;
	while(a[0][1] + a[0][2] + a[0][3] + a[0][4] + a[0][5] + a[0][6] > 0)
	{
		/*当所有 6 列均处理完毕后退出循环*/
		for(i = 1; i < 7; i++) /*i: 列坐标*/
			if(a[0][i])	//若该列尚未处理， 则进行处理
			{
				for(e = 0, j = 1; j < 7; j++)	// j 变量保存行坐标， e 变量是该列中非零元素计数器
					if(a[j][i])
					{
						x = j;
						y = i;
						e++;
					}
				if(e == 1)
				{
					for(t = 1; t < 7; t++)
						if(t != i)
							a[x][t] = 0;
							a[0][y] = 0;
				}
			}
	}
	printf("final matrix:\n");
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 7; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\nresult : \n");
	for(i = 1; i < 7; i++)
	{
		printf("%c is from: ", 'A' - 1 + i);
		for(j = 1; j < 7; j++)
			if(a[i][j] != 0)
			{
				printf("%s.\n", m[a[i][j]]);
				break;
			}
	}
	return 0;
}
