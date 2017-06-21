
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 127

void init(char pre[][LEN], char ans[][LEN], char all[]);
void scpy(char cpy[][LEN], char *p, int c, int c2);
char *sum1(char data[][LEN], int len, char k);
char *sum2(char data[][LEN], char k);
char *add(char x[], char y[], int xl, int yl);
char *strrev(char *s);
void ito(int value, char *buff);

int main(void)
{
	char pre[63][LEN] = {0};
	char ans[2][LEN] = {0};
	char all[LEN];
	char dig[11] = "0123456789";
	char ans1[128] = {0};
	char ans2[128] = {0};
	char *p, *q, *r;
	int c, c2, c3, c4, c5;
	int pr, an;
	int i, f;
	
	while(scanf("%s", all) != EOF) {
		f = 0;
		p = all;
		q = all;
		c = strlen(all);
		pr = 0;
		an = 0;
		c2 = 0;
		c4 = 0;
		i = 0;
		while(c != c2) {
			if(*p != '+' && *p != '=') {
				p++;
			} else {
				r = p;
				c3 = r - q;
				scpy(pre, q, c3, pr++);
				c4++;
				p++;
				q = p;
				c5 = c2;
			}
			c2++;
		}
		scpy(ans, q, c2 - c5, an++);
		while(i != 10) {
			strcpy(ans1, sum1(pre, c4, dig[i]));
			strcpy(ans2, sum2(ans, dig[i]));
//			printf("%s\t%s\n", ans1, ans2);
			if(ans1[0] != NULL && ans2[0] != NULL) {
				if(strcmp(ans1, ans2) == 0) {
					printf("%d\n", i);
					f = 1;
					break;
				}
			}
			i++;
		}
		if(f == 0) {
			puts("NA");
		}
			
		init(pre, ans, all);
	}
	return 0;
}

void init(char pre[][LEN], char ans[][LEN], char all[])
{
	int i, j;
	for(i=0;i<63;i++) {
		for(j=0;j<LEN;j++) {
			pre[i][j] = NULL;
		}
	}
	for(i=0;i<2;i++) {
		for(j=0;j<LEN;j++) {
			ans[i][j] = NULL;
		}
	}
	for(j=0;j<LEN;j++) {
		all[j] = NULL;
	}
}

void scpy(char cpy[][LEN], char *p, int c, int c2)
{
	int c1 = 0, c3 = 0;
	while(c3 != c) {
		cpy[c2][c1++] = *p++;
		c3++;
	}
}

char *sum1(char data[][LEN], int len, char k)
{
	int c = 0, i;
	char pre[63][LEN] = {0};
	char sum[128] = {0};
	char *s = sum;
	int sl, pl;
	
	while(len != c) {
		strcpy(pre[c], data[c]);
		if(strlen(pre[c]) >= 2 && k == '0')  {
			if(pre[c][0] == 'X') {
				*s = NULL;
				break;
			}
		}
		i = 0;
		while(pre[c][i] != '\0') {
			if(pre[c][i] == 'X') {
				pre[c][i] = k;
			}
			i++;
		}
		sl = strlen(sum);
		pl = strlen(pre[c]);
		
		strcpy(sum, add(sum, pre[c], sl, pl));
		c++;
	}
	
	return s;
}

char *sum2(char data2[][LEN], char k)
{
	int i = 0, sl, pl, flag = 0;
	char sum[128] = {0};
	char *s = sum;
	char pra[2][LEN] = {0};
	strcpy(pra[0], data2[0]);
	while(pra[0][i] != '\0') {
		if(strlen(pra[0]) >= 2 && k == '0')  {
			if(pra[0][0] == 'X') {
				*s = NULL;
				flag = 2;
				break;
			}
			
		}
		if(pra[0][i] == 'X') {
			pra[0][i] = k;
		}
		i++;
	}
	if(flag == 0) {
		sl = strlen(sum);
		pl = strlen(pra[0]);
		strcpy(sum, add(sum, pra[0], sl, pl));
	}
	
	return s;
}

char *add(char x[], char y[], int xl, int yl) {
	
	char ans[1000] = "";
	char ans2[1000] = "";
	char *res = ans2;
	int i = 0, j = 0, tl, tmp = 0, xt, yt;
	
	while(xl != 0 || yl != 0) {
		if(xl != 0) {
			xt = x[xl-1] - '0';
		} else {
			xt = 0;
		}
		if(yl != 0) {
			yt = y[yl-1] - '0';
		} else {
			yt = 0;
		}
		tmp = tmp + xt + yt;
		if(tmp >= 10) {
			tmp = tmp % 10;
			ito(tmp, &ans[i]);
			tmp = 1;
			ito(tmp, &ans[i+1]);
			i++;
		} else {
			ito(tmp, &ans[i]);
			tmp = 0;
			i++;
		}
		if(xl != 0) {
			xl--;
		}
		if(yl != 0) {
			yl--;
		}
	}
		
	tl = strlen(ans);
	for(i=tl;i>0;i--) {
		ans2[j] = ans[i-1];
		j++;
	}
	
	return res;
}
	

void ito(int value, char *buff) {
	char *p;
	int mod;

	if( 0 > value ) {
		*buff++ = '-';
		value = -value;
	}
	p = buff;

	do {
		mod = value % 10 + 48;
		*p++ = (char)mod;
		value /= 10;
	} while(value);

	*p = '\0';
	strrev(buff);
}

char *strrev(char *s) {
	char *ret = s;
	char *t = s;
	char c;

	while( *t != '\0' )
		t++;
		t--;

	while(t > s) {
		c = *s;
		*s = *t;
		*t = c;
		s++;
		t--;
	}
	return ret;
}

